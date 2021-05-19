#ifndef MATHHANDLER_H
#define MATHHANDLER_H

#include <QString>

class MathHandler{
public:
    MathHandler();
    // Generate an expression with random numbers and operator.
    // Post: rightAnswer = calculated result of generated expression.
    QString getExpression();
    // Return true if user's answer was correct.
    bool checkAnswer(QString answerText);
    // Set operator choice based on string representation of it.
    void setOperator(QString text);
    // Get chosen level difficulty as a string.
    QString getLevelDisplay();
    // Change difficulty in loop 1-2-3-1-...
    void changeDifficulty();
private:
    // Types of operators; if RAND then on each iteration
    // a random one is chosen.
    enum OPERTYPE{RAND, PLUS, MINUS, MULT, DIV};
    // Level of difficulty of generated expressions.
    enum LEVELTYPE{EASY, MEDIUM, HARD};
    // Get upper bound on numbers for + and - operations. Depends on the level difficulty.
    int getMaxLim();
    // Get upper bound on numbers to use in task. Depends on the level difficulty.
    // Should be used for * and % operations.
    int getMaxLimStrict();
    // Build expression from number x,y using given operation.
    // Post:: store answer in rightAnswer.
    QString buildExpression(OPERTYPE op, int x, int y);
    // Get random number, the upper bound depends on difficulty level and operation.
    int getNum(OPERTYPE op);
    // Get a random operator if operatorChoice is RAND, else get a chosen operator.
    OPERTYPE getOperator();
    OPERTYPE operatorChoice;
    int rightAnswer;
    LEVELTYPE diffLevel;
};

#endif // MATHHANDLER_H
