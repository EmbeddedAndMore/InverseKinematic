#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QVector>
#include "segment.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVector<Segment*> segments;

private:
    Ui::MainWindow *ui;
    int timerId;
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void showEvent( QShowEvent* event );
    void timerEvent(QTimerEvent *event);
};
#endif // MAINWINDOW_H
