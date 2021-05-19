#include <QFont>
#include <QStyle>
#include <QWidget>

#include "widgets.h"

BasicStyle::BasicStyle(){
   font=QFont("Comic Sans MS", 14, QFont::Bold, false);
}

int BasicStyle::getWidth(){
    return width;
}

int BasicStyle::getHeight(){
    return height;
}

QFont BasicStyle::getFont(){
    return font;
}

BasicButton::BasicButton(QString text, QWidget *parent):QPushButton(text, parent){
    setFont(getFont());
    setFixedSize(getWidth(), getHeight());
    setStyleSheet("background-color: #FFFFFF; border-radius: 4px;");
}

AttentionButton::AttentionButton(QString text, QWidget *parent): BasicButton(text, parent){
    setStyleSheet("background-color: #F66758; border-radius: 4px;");
    setFixedSize(getWidth(), getHeight());
}

int AttentionButton::getWidth(){
    return 200;
}

OperatorButton::OperatorButton(QString operatorSign, QWidget *parent): BasicButton(operatorSign, parent){
    setStyleSheet("background-color: #FBE583; border-radius: 4px;"); // border-width: 1px; border-style: solid; border-color: #041A7C;");
    setFixedSize(getWidth(), getHeight());
}

void OperatorButton::mousePressEvent(QMouseEvent* event){
    emit clicked_(text());
    QPushButton::mousePressEvent(event);
}

int OperatorButton::getWidth(){
    return 80;
}

BasicLabel::BasicLabel(QString text, QWidget *parent):QLabel(text, parent){
    setFont(getFont());
    setStyleSheet("background-color: #FFFFFF; border-radius: 4px;");
    setFixedSize(getWidth(), getHeight());
    setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
}

BasicLabel::BasicLabel(QString text, Qt::Alignment alignOption, QWidget *parent):BasicLabel(text, parent){
    setAlignment(alignOption | Qt::AlignVCenter);
}

BasicLabel::BasicLabel(QString text, QString colorOption, QWidget *parent):BasicLabel(text, parent){
    setStyleSheet("background-color: "+colorOption+"; border-radius: 4px;");
}


BasicTextEdit::BasicTextEdit(QWidget *parent): QLineEdit(parent){
    setFont(getFont());
    setStyleSheet("background-color: #FFFFFF; border-radius: 4px;");
    setFixedSize(getWidth(), getHeight());
    setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}
