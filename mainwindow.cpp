#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pB_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pB_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    double all_numbers;
    all_numbers = (ui->lE_ekran->text()+button->text()).toDouble();
    new_label = QString::number(all_numbers);

    ui->lE_ekran->setText(new_label);
}

void MainWindow::on_pB_plmin_clicked()
{
    count_first = ui->lE_ekran->text().toDouble();
    ui->lE_ekran->clear();
    count_first = 0-count_first;
    ui->lE_ekran->setText(QString::number(count_first));
}

void MainWindow::on_pB_division_clicked()
{
    count_first = ui->lE_ekran->text().toDouble();
    ui->lE_ekran->clear();
    multi_count = 1;

}

void MainWindow::on_pB_multi_clicked()
{
    count_first = ui->lE_ekran->text().toDouble();
    ui->lE_ekran->clear();
    multi_count = 2;

}

void MainWindow::on_pB_minus_clicked()
{
    count_first = ui->lE_ekran->text().toDouble();
    ui->lE_ekran->clear();
    multi_count = 3;

}

void MainWindow::on_pB_plus_clicked()
{
    count_first = ui->lE_ekran->text().toDouble();
    ui->lE_ekran->clear();
    multi_count = 4;

}

void MainWindow::on_pB_equals_clicked()
{
    double result_equals;
    if(procent == false)
    {
        switch (multi_count) {
        case 1:
            result_equals = count_first/count_second;
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 2:
            result_equals = count_first*count_second;
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 3:
            result_equals = count_first-count_second;
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 4:
            result_equals = count_first+count_second;
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 0:
            ui->lE_ekran->setText(QString::number(count_second));
            break;
        }
    }
    else
    {
        switch (multi_count) {
        case 1:
            result_equals = count_first/(count_second*count_procent);
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 2:
            result_equals = count_first*(count_second*count_procent);
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 3:
            result_equals = count_first-(count_second*count_procent);
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 4:
            result_equals = count_first+(count_second*count_procent);
            ui->lE_ekran->setText(QString::number(result_equals));
            break;
        case 0:
            ui->lE_ekran->setText(QString::number(count_second));
            break;
        }
    }
    quals = true;
}

void MainWindow::on_pB_procent_clicked()
{
    count_procent = count_first/100;
    count_second = ui->lE_ekran->text().toDouble();
    QString text = ui->lE_ekran->text();
    ui->lE_ekran->setText(text +ui->pB_procent->text());
    procent = true;
}





void MainWindow::on_pB_clear_clicked()
{
    ui->lE_ekran->clear();
    count_first = 0;
    count_second = 0;
    count_procent = 0;
    multi_count = 0;
}
