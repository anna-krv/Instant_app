#include <map>
#include "mathHandler.h"

MathHandler::MathHandler(): operatorChoice(RAND), diffLevel(EASY){}

void MathHandler::changeDifficulty(){
    diffLevel = LEVELTYPE((diffLevel+1)%3);
}

QString MathHandler::getLevelDisplay(){
    QString display[]={"easy", "medium", "hard"};
    return display[diffLevel];
}

void MathHandler::setOperator(QString text){
    std::map<QString, OPERTYPE> operMap;
    operMap["RAND"]=RAND;
    operMap["+"]=PLUS;
    operMap["-"]=MINUS;
    operMap["*"]=MULT;
    operMap["%"]=DIV;
    operatorChoice =operMap[text];
}

MathHandler::OPERTYPE MathHandler::getOperator(){
  OPERTYPE currentOperator;
  if (operatorChoice == RAND){
      currentOperator =OPERTYPE(rand()%4+1);
  } else {
      currentOperator = operatorChoice;
  }
  return currentOperator;
}

QString MathHandler::buildExpression(OPERTYPE op, int x, int y){
    QString operDisplay[]={"?", "+", "-", "*", "%"};
    int sum;
    switch (op)
    {
    case PLUS:
        rightAnswer = x + y;
        break;
    case MINUS:
        sum = x + y;
        x = std::max(x, y);
        y = sum - x;
        rightAnswer = x - y;
        break;
    case MULT:
        rightAnswer = x * y;
        break;
    case DIV:
        rightAnswer = x%y;
        break;
    default:
        break;
    }

    return (QString::number(x) + operDisplay[op] +
            QString::number(y) + "=");
}


int MathHandler::getNum(OPERTYPE op){

    int maxLim = getMaxLim();
    int x = rand();
    if (op == MULT || op == DIV){
        maxLim = getMaxLimStrict();
    }
    x = (x%maxLim)+1;
    return x;
}


QString MathHandler::getExpression()
{
    OPERTYPE op=getOperator();
    return buildExpression(op, getNum(op), getNum(op));
}

bool MathHandler::checkAnswer(QString answerText){
    try{
        int userAnswer= answerText.toInt();
        return userAnswer==rightAnswer;
    }
    catch(...){ return false;}
}

int MathHandler::getMaxLim(){
    int upperLim[]={50, 100, 200};
    return upperLim[diffLevel];
}

int MathHandler::getMaxLimStrict(){
    int upperLim[]={10, 20, 30};
    return upperLim[diffLevel];
}
