//
// Created by Divanshu Chauhan on 3/19/23.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    running = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTimer()
{
    QTime currentTime = QTime::currentTime();
    int elapsedTime = startTime.msecsTo(currentTime);
    QTime displayTime = QTime::fromMSecsSinceStartOfDay(elapsedTime);
    ui->timeLabel->setText(displayTime.toString("hh:mm:ss.zzz"));
}

void MainWindow::on_startStopButton_clicked()
{
    if (running) {
        timer->stop();
        ui->startStopButton->setText("Start");
    } else {
        startTime = QTime::currentTime().addMSecs(-ui->timeLabel->text().left(12).toDouble());
        timer->start(1);
        ui->startStopButton->setText("Stop");
    }
    running = !running;
}

void MainWindow::on_resetButton_clicked()
{
    if (running) {
        on_startStopButton_clicked();
    }
    ui->timeLabel->setText("00:00:00.000");
}
