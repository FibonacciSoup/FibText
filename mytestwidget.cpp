#include "mytestwidget.h"
#include "ui_mytestwidget.h"
#include <QFileDialog>
#include <QTextStream>
#include <QBrush>
#include <QTextCharFormat>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

const int maxn=1005;

int f[maxn][maxn];

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

void highlight_out(QTextEdit* te, QString* s){
    te->setPlainText("");
    QBrush b1(QColor(0,255,0));
    QBrush b2(QColor(255,255,255));
    QTextCharFormat f1, f2;
    f1.setBackground(b1);
    f2.setBackground(b2);
    int len=static_cast<int>(s->length());
    for(int i=0;i<len;++i){
        if(s->at(i).toLatin1()=='_') {
            te->setCurrentCharFormat(f1);
        }
        else {
            te->setCurrentCharFormat(f2);
        }
        QString tmp(s->at(i));
        te->insertPlainText(tmp);
    }
}

void my_compare(int x,int y,QString* s1,QString* s2,QString* ans1,QString* ans2,int f[][maxn]){
    if(x==0&&y==0)return;
    if(x==0){
        my_compare(x,y-1,s1,s2,ans1,ans2,f);
        ans2->append('_');
        return;
    }
    if(y==0){
        my_compare(x-1,y,s1,s2,ans1,ans2,f);
        ans1->append('_');
        return;
    }
    if(s1->at(x-1)==s2->at(y-1)){
        my_compare(x-1,y-1,s1,s2,ans1,ans2,f);
        ans1->append(s1->at(x-1));
        ans2->append(s2->at(y-1));
        return;
    }
    if(f[x-1][y]>f[x][y-1]){
        my_compare(x-1,y,s1,s2,ans1,ans2,f);
        ans1->append('_');
    }else{
        my_compare(x,y-1,s1,s2,ans1,ans2,f);
        ans2->append('_');
    }
}

void myTestWidget::on_pushButton_6_clicked()
{
    QString s1 = ui->textEdit_1->toPlainText();
    QString s2 = ui->textEdit_2->toPlainText();
    int len1=static_cast<int>(s1.length());
    int len2=static_cast<int>(s2.length());
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
            if(s1.at(i-1)==s2.at(j-1))f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=std::max(f[i-1][j-1],std::max(f[i-1][j],f[i][j-1]));
    QString ans1="",ans2="";
    my_compare(len1,len2,&s1,&s2,&ans1,&ans2,f);
    //ui->textEdit_1->setText(ans1);
    //ui->textEdit_2->setText(ans2);
    highlight_out(ui->textEdit_1,&ans1);
    highlight_out(ui->textEdit_2,&ans2);
}
