#include <QApplication>
#include "widgets.h"
#include "windowStats.h"


WindowStats::WindowStats(QString color, int width, int height,
                         int ax, int ay, QWidget *parent):QWidget(parent){
    setFixedSize(width, height);
    move(ax, ay);
    setStyleSheet("background-color:"+color+" ;");
    int h_pad = 60, v_pad=25;
    label = new BasicLabel("", this);
    button = new AttentionButton("Bye-bye!", this);

    label->move(h_pad, v_pad);
    label->setFixedSize(width-2*h_pad, height-3*v_pad-button->height());

    button->move((width-button->width())/2, height-v_pad-button->height());
    connect(button, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
}

void WindowStats::updateText(QString text){
    label->setText(text);
}

WindowStats::~WindowStats(){
    delete label;
    delete button;
}
