#ifndef WIDGETS_H
#define WIDGETS_H

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>

struct BasicStyle{
public:
    BasicStyle();
    int getWidth();
    int getHeight();
protected:
    QFont getFont();

private:
    QFont font;
    static const int width=100, height=40;
};


class BasicLabel: public QLabel, public BasicStyle{

public:
    BasicLabel(QString text, QWidget* parent=nullptr);
    BasicLabel(QString text, QString color, QWidget* parent=nullptr);
    BasicLabel(QString text, Qt::Alignment alignOption, QWidget* parent=nullptr);
};


class BasicButton:public QPushButton, public BasicStyle{
public:
    BasicButton(QString text, QWidget *parent=nullptr);
};


class AttentionButton: public BasicButton{
public:
    AttentionButton(QString text, QWidget * parent=nullptr);
    int getWidth();
};


class OperatorButton: public BasicButton{
    Q_OBJECT

public:
signals:
    void clicked_(QString text);
public:
    OperatorButton(QString operatorSign="Random", QWidget *parent=nullptr);
    int getWidth();
protected:
    void mousePressEvent(QMouseEvent *event);
};


class BasicTextEdit: public QLineEdit, public BasicStyle{
public:
    BasicTextEdit(QWidget *parent = nullptr);
};


#endif // WIDGETS_H
