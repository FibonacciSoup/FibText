#include "mytestwidget.h"
#include "ui_mytestwidget.h"
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <cstring>

myTestWidget::myTestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTestWidget)
{
    ui->setupUi(this);
}

myTestWidget::~myTestWidget()
{
    delete ui;
}

void myTestWidget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件..."), QDir::currentPath(), tr("文本文件(*.txt)"));
    if(fileName!=""){
        QFile inFile(fileName);
        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        ui->textEdit_1->setPlainText(inFile.readAll());
        inFile.close();
    }
}//左文本框导入

void myTestWidget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("输入要保存的文件名..."), QDir::currentPath(), tr("文本文件(*.txt)"));
    if(fileName!=""){
        QFile outFile(fileName);
        outFile.open(QIODevice::WriteOnly|QIODevice::Text);
        QString text = ui->textEdit_1->toPlainText();
        QTextStream out(&outFile);
        out<<text;
        outFile.close();
    }
}//左文本框导出

void myTestWidget::on_pushButton_15_clicked()
{
    ui->textEdit_1->setPlainText("");
}//左文本框清除

void myTestWidget::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件..."), QDir::currentPath(), tr("文本文件(*.txt)"));
    if(fileName!=""){
        QFile inFile(fileName);
        inFile.open(QIODevice::ReadOnly|QIODevice::Text);
        ui->textEdit_2->setPlainText(inFile.readAll());
        inFile.close();
    }
}//右文本框导入

void myTestWidget::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("输入要保存的文件名..."), QDir::currentPath(), tr("文本文件(*.txt)"));
    if(fileName!=""){
        QFile outFile(fileName);
        outFile.open(QIODevice::WriteOnly|QIODevice::Text);
        QString text = ui->textEdit_2->toPlainText();
        QTextStream out(&outFile);
        out<<text;
        outFile.close();
    }
}//右文本框导出

void myTestWidget::on_pushButton_16_clicked()
{
    ui->textEdit_2->setPlainText("");
}//右文本框清除
