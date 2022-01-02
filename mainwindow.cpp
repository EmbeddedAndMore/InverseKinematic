#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtMath>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , segments({})
{
    ui->setupUi(this);
    timerId = startTimer(20);
}

MainWindow::~MainWindow()
{
    killTimer(timerId);
    for (auto p : segments)
        delete p;
    segments.clear();
    delete ui;
}

void MainWindow::showEvent( QShowEvent* event ) {
    QWidget::showEvent( event );
    //your code here
    segments.push_back(new Segment(this->width()/2, this->height()/2, 45, 50));
    for (int i = 1; i < 10; i++)
    {
        segments.push_back(new Segment(segments[i-1]->end.x(), segments[i-1]->end.y(), 0, 50));
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPoint p = this->mapFromGlobal(QCursor::pos());

    for (int i = segments.size()-1; i >=0 ; i--)
    {
        if (i == segments.size()-1)
        {
            segments[i]->follow(p.x(), p.y());
            segments[i]->update();
        }else{
            segments[i]->follow(segments[i+1]->start.x(), segments[i+1]->start.y());
            segments[i]->update();
        }
    }

    segments[0]->start = QVector2D(this->width()/2, this->height());
    segments[0]->update();

    for (int i = 1 ; i < segments.size(); i++)
    {
        segments[i]->start = segments[i-1]->end;
        segments[i]->update();
    }

    for (auto  seg: segments)
    {
        seg->show(&painter);
    }

}
void MainWindow::timerEvent(QTimerEvent *event)
{
    std::cout << "Update..."<< std::endl;
    update();
}
