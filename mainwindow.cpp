#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGlobal.h>
#include <QTime>

int MainWindow::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void MainWindow::check()
{
    if (!finish){
        if (current_numb == random_numb){
            QString n("");
            n.setNum(current_numb);
            QString s = QString("Победа! \nЗагадано число: ") + n;
            ui->label->setText(s);
            finish = true;
        }
        else{
            ui->label->setText("Поробуй еще...");
        }
        ui->label_3->setNum(++try_count);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    current_numb = 0;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    random_numb = randInt(1,9);

    try_count=0;

    finish = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    current_numb = 1;
    check();
}

void MainWindow::on_pushButton_2_clicked()
{
    current_numb = 2;
    check();
}

void MainWindow::on_pushButton_3_clicked()
{
    current_numb = 3;
    check();
}

void MainWindow::on_pushButton_4_clicked()
{
    current_numb = 4;
    check();
}

void MainWindow::on_pushButton_5_clicked()
{
    current_numb = 5;
    check();
}

void MainWindow::on_pushButton_6_clicked()
{
    current_numb = 6;
    check();
}

void MainWindow::on_pushButton_7_clicked()
{
    current_numb = 7;
    check();
}

void MainWindow::on_pushButton_8_clicked()
{
    current_numb = 8;
    check();
}

void MainWindow::on_pushButton_9_clicked()
{
    current_numb = 9;
    check();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->label->setText("...Ожидание");

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    random_numb = randInt(1,9);

    current_numb = 0;

    try_count = 0;

    ui->label_3->setNum(try_count);

     finish = false;
}
