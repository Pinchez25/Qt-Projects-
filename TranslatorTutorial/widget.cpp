#include "widget.h"
#include "./ui_widget.h"
#include<QFontDialog>
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok){

    }else{

    }

}


void Widget::on_pushButton_2_clicked()
{
    QMessageBox::information(NULL, tr("Message"),tr("User %1 submitted a message with title %2. The mesage is %3").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->textEdit->toPlainText()));
}

