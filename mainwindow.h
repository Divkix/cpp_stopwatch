//
// Created by Divanshu Chauhan on 3/19/23.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTimer();
    void on_startStopButton_clicked();
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime startTime;
    bool running;
};

#endif // MAINWINDOW_H
