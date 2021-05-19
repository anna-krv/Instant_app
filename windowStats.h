#ifndef WINDOWSTATS_H
#define WINDOWSTATS_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>

class WindowStats: public QWidget{
public:
    WindowStats(QString color, int width=320, int height=275,
                int ax=620, int ay=263, QWidget *parent=nullptr);
    ~WindowStats();
    void updateText(QString text);
private:
    QLabel* label;
    QPushButton* button;
};

#endif // WINDOWSTATS_H
