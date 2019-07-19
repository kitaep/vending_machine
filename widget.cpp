#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int n)
{
    money += n;
    if (money <= 0) {
        ui->pbReturn->setEnabled(false);
    }
    else {
        ui->pbReturn->setEnabled(true);
    }
    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    }
    else {
        ui->pbCoffee->setEnabled(true);
    }
    if (money < 150) {
        ui->pbTea->setEnabled(false);
    }
    else {
        ui->pbTea->setEnabled(true);
    }
    if (money < 200) {
        ui->pbGongcha->setEnabled(false);
    }
    else {
        ui->pbGongcha->setEnabled(true);
    }
    ui->lcdNumber->display(QString::number(money));
}

void Widget::on_pb10_clicked()
{
    change_money(10);
}

void Widget::on_pb50_clicked()
{
    change_money(50);
}

void Widget::on_pb100_clicked()
{
    change_money(100);
}

void Widget::on_pb500_clicked()
{
    change_money(500);
}

void Widget::on_pbCoffee_clicked()
{
    change_money(-100);
}

void Widget::on_pbTea_clicked()
{
    change_money(-150);
}


void Widget::on_pbGongcha_clicked()
{
    change_money(-200);
}

void Widget::on_pbReturn_clicked()
{
    int mon500 = 0, mon100 = 0, mon50 = 0, mon10 = 0;
    while(money>=500) {money=money-500; mon500++;}
    while(money>=100) {money=money-100; mon100++;}
    while(money>=50) {money=money-50; mon50++;}
    while(money>=10) {money=money-10; mon10++;}
    QMessageBox::information(nullptr, "Return Money", QString("500: %1\n 100: %2\n 50: %3\n 10: %4\n").arg(mon500).arg(mon100).arg(mon50).arg(mon10));
    QWidget::close();
}
