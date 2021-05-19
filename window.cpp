#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include <QWidget>

#include "window.h"
#include "game.h"


Window::Window(QString color, int width, int height,
               int ax, int ay, QWidget *parent): QWidget(parent){
    setFixedSize(width, height);
    move(ax, ay);
    setStyleSheet("background-color:"+color+" ;");

    createWidgets();
    setPositions();
    setConnections();
}

void Window::setPositions(){

    int marginTop =20, marginMid= 150, marginBottom = 340, padding = 20;
    int marginLeft = (difficultyButton->width()-randButton->width())/2+padding, marginMain=200;
    int btnHeight = randButton->height(), up = marginTop+difficultyButton->height()+padding;

    difficultyButton->move(padding, marginTop);
    scoreLabel->move(width()-scoreLabel->width()-padding, marginTop);

    randButton->move(marginLeft, up);
    addButton->move(marginLeft, up+(btnHeight+padding));
    subButton->move(marginLeft, up+2*(btnHeight+padding));
    multButton->move(marginLeft, up+3*(btnHeight+padding));
    divButton->move(marginLeft, up+4*(btnHeight+padding));

    taskLabel->move(marginMain, marginMid);
    answer->move(marginMain+taskLabel->width()+padding, marginMid);
    checkButton->move(marginMain+taskLabel->width()+answer->width()+2*padding, marginMid);
    for (int i=0; i<2; i++){
        commentLabel[i]->move(marginMain+taskLabel->width()+answer->width()+2*padding, marginMid);
        commentLabel[i]->hide();
    }

    finishButton->move(width()-finishButton->width()-padding, marginBottom);
}

void Window::createWidgets(){
    randButton = new OperatorButton("Random", this);
    addButton = new OperatorButton("+", this);
    subButton = new OperatorButton("-", this);
    multButton = new OperatorButton("*", this);
    divButton = new OperatorButton("%", this);

    difficultyButton = new AttentionButton("Difficulty: easy", this);
    taskLabel = new BasicLabel("", Qt::AlignRight, this);

    checkButton = new BasicButton("check", this);
    answer = new BasicTextEdit(this);

    commentLabel[0] = new BasicLabel("Correct!", "#82F06E", this);
    commentLabel[1] = new BasicLabel("Wrong!", "#FF9709", this);

    scoreLabel = new BasicLabel("Score: 0", this);

    finishButton = new BasicButton("Finish", this);
    finishButton->setToolTip("Exit the training and see statistics");
}

void Window::setConnections(){
    connect(checkButton, SIGNAL(clicked()), Game::instance(), SLOT(check()));
    connect(answer, SIGNAL(returnPressed()), Game::instance(), SLOT(check()));

    QWidget* operButton[]={randButton, addButton, subButton, multButton, divButton};
    for (int i=0; i<5; i++){
        connect(operButton[i], SIGNAL(clicked_(QString)), Game::instance(), SLOT(setOperator(QString)));
    }
    connect(difficultyButton, SIGNAL(clicked()), Game::instance(), SLOT (changeDifficulty()));

    connect(finishButton, SIGNAL(clicked()), Game::instance(), SLOT(endGame()));
}

void Window::setDifficulty(QString level){
    difficultyButton->setText("Difficulty: " + level);
}

void Window::setNewTask(QString expression){
    taskLabel->setText(expression);
}

void Window::rightReact(int score){
    int duration =1000;
    commentLabel[0]->show();
    scoreLabel->setText("Score: "+QString::number(score));
    QTimer::singleShot(duration, commentLabel[0], &QWidget::hide);
}

void Window::falseReact(){
    int duration = 1000;
    commentLabel[1]->show();
    QTimer::singleShot(duration, commentLabel[1], &QWidget::hide);
}

void deleteArr(QWidget* arr[], int size){
    for (int i=0; i<size; i++){
        delete arr[i];
        arr[i]=nullptr;
    }
}

QString Window::getAnswer(){
    QString textAnswer = answer->text();
    answer->clear();
    return textAnswer;
}

Window::~Window(){
    QWidget *arrWidgets[] ={randButton, addButton, subButton,
                           multButton, divButton, difficultyButton,
                           taskLabel, scoreLabel, finishButton,
                           checkButton, answer};
    deleteArr(arrWidgets, 11);
    deleteArr(commentLabel, 2);
}



