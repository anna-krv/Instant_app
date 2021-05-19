#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "widgets.h"

// Class that is responsible for creating and laying out widgets for game execution.
class Window: public QWidget{
    Q_OBJECT
public:
    explicit Window(QString color, int width=560, int height=400,
                    int ax=500, int ay=200, QWidget *parent=0);
    ~Window();
    // Set given expression in taskLabel.
    void setNewTask(QString expression);
    // React to correct answer.
    void rightReact(int score);
    // React to wrong answer.
    void falseReact();
    // Get answer from answer line edit. Clear answer line edit.
    QString getAnswer();
    // Change text that indicates difficulty of game.
    void setDifficulty(QString level);
signals:
    void endSession(int score);
private: 
    // Position widgets in window.
    void setPositions();
    // Set connections between widgets' signals and window's or app's slots.
    void setConnections();
    // Create labels, text edits and buttons.
    void createWidgets();

    QPushButton *randButton, *addButton, *subButton, *multButton, *divButton,
    *finishButton, *difficultyButton, *checkButton;
    QLabel *scoreLabel, *taskLabel;
    QLineEdit *answer;
    QWidget* commentLabel[2];
};

#endif // WINDOW_H
