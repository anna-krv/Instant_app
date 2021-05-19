#include <cmath>
#include <QDateTime>
#include <QtSql>
#include <QTimer>
#include "game.h"


Game::Game(int argc, char *argv[]):QApplication(argc, argv), mathHandler(), score(0),
            attempted(0), sessionStart(QDateTime::currentDateTime()) {
    QString color="#E3FED1";
    window = new Window(color);
    window->setNewTask(mathHandler.getExpression());
    windowStats = new WindowStats(color);

    window->show();
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/sqlite/InstantApp.db");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }
    windowStats->hide();
}

void Game::changeDifficulty(){
    mathHandler.changeDifficulty();
    window->setDifficulty(mathHandler.getLevelDisplay());
}

void Game::setOperator(QString text){
    mathHandler.setOperator(text);
    window->setNewTask(mathHandler.getExpression());
}

void Game::saveToDb(){
    QSqlQuery query;
    query.prepare("Insert into Results Values (?, ?, ?, ?, ?, ?);");
    query.addBindValue(sessionEnd.toString("yyyy-MM-dd hh:mm:ss"));
    query.addBindValue(duration);
    query.addBindValue(score);
    query.addBindValue(attempted);
    query.addBindValue(successRate);
    query.addBindValue(speed);
    query.exec();
}

void Game::check(){
    updateScore();
    window->setNewTask(mathHandler.getExpression());
}

void Game::updateScore(){
    attempted += 1;
    if (mathHandler.checkAnswer(window->getAnswer())){
        score += 1;
        window->rightReact(score);
    } else {
        window->falseReact();
    }
}

QString Game::resToStr(){
    QString results = "Your results:\n";
    results += "SCORE: "+QString::number(score)+"\n";
    results += "ATTEMPTED: "+QString::number(attempted)+"\n";
    results += "Time: "+QString::number(round(duration/6.)/10.)+" minutes\n";
    results += "Succes rate: "+QString::number(round(successRate))+"%";
    return results;
}

void Game::fixResults(){
    sessionEnd = QDateTime::currentDateTime();
    duration=sessionStart.secsTo(sessionEnd);
    successRate = float(score)/attempted*100;
    speed = float(score)/duration*60.;
}

void Game::endGame(){
    fixResults();
    saveToDb();
    window->hide();
    windowStats->updateText(resToStr());
    windowStats->show();
}


Game::~Game(){
    delete window;
    delete windowStats;
    db.close();
    QSqlDatabase::removeDatabase("QSQLITE");
}
