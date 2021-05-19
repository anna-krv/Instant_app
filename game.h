#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QDateTime>
#include <QSqlDatabase>
#include "mathHandler.h"
#include "window.h"
#include "windowStats.h"

// Class the manages gaming process.
class Game: public QApplication{
    Q_OBJECT
public slots:
    // Save results to the db. Show window with the game stats.
    void endGame();
    // Check answer and update score.
    void check();
    // Update operator in MathHandler object. Show new expression in window.
    void setOperator(QString text);
    // Change difficulty in cycle Easy->Medium->Hard->Easy.
    void changeDifficulty();
public:
    Game(int argc, char *argv[]);
    ~Game();
private:
    // Save information about the game to the database.
    void saveToDb();
    // Read user's answer and increase score if answer is correct.
    void updateScore();
    // Get string with description of game session results.
    QString resToStr();
    // Store results of game.
    void fixResults();
    Window* window;
    WindowStats* windowStats;
    QSqlDatabase db;
    MathHandler mathHandler;
    unsigned score, attempted;
    QDateTime sessionStart, sessionEnd;
    int duration; // duration of game in seconds
    float successRate, speed;
};

#endif // GAME_H
