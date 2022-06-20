#include "mytestwidget.h"
#include "ui_mytestwidget.h"
#include <QFileDialog>
#include <QTextStream>
#include <QBrush>
#include <QTextCharFormat>
#include <QScrollBar>
#include <QTextCursor>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <QApplication>
#include <QDebug>

typedef long long LL;

const int maxn=2000;

static int f[maxn][maxn];

myTestWidget::myTestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myTestWidget)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height()); //固定窗口大小
    ui->label->setText("第 1 行, 第 1 列");
    ui->label_2->setText("第 1 行, 第 1 列");
    ui->tabWidget->setTabText(0,"比较");
    ui->tabWidget->setTabText(1,"查找");
    ui->tabWidget->setTabText(2,"统计");
    ui->tabWidget->setTabText(3,"显示");

    //左右文本框同步滚动
    QScrollBar* QSB_left=ui->textEdit_1->verticalScrollBar();
    QScrollBar* QSB_right=ui->textEdit_2->verticalScrollBar();
    connect(QSB_left,SIGNAL(valueChanged(int)),this,SLOT(leftVerticalScroll()));
    connect(QSB_right,SIGNAL(valueChanged(int)),this,SLOT(rightVerticalScroll()));
    QScrollBar* QSB_left_h=ui->textEdit_1->horizontalScrollBar();
    QScrollBar* QSB_right_h=ui->textEdit_2->horizontalScrollBar();
    connect(QSB_left_h,SIGNAL(valueChanged(int)),this,SLOT(leftHorizontalScroll()));
    connect(QSB_right_h,SIGNAL(valueChanged(int)),this,SLOT(rightHorizontalScroll()));

    //显示行列号
    connect(ui->textEdit_1,SIGNAL(cursorPositionChanged()),this,SLOT(leftShowLineNum()));
    connect(ui->textEdit_2,SIGNAL(cursorPositionChanged()),this,SLOT(rightShowLineNum()));

    //set icon for cursor
    QCursor cursor,cursor1,cursor2;
    QString s = QCoreApplication::applicationDirPath();
    LL p = s.indexOf("build",0);
    QPixmap dir(s.left(p)+"/files/FibText-main/app-gda6cc8040_640.png");
    QPixmap dir1(s.left(p)+"/files/FibText-main/app-g1ea771702_640.png");
    QPixmap dir2(s.left(p)+"/files/FibText-main/app-g4ecdf12e9_640.png");
    QSize size(30,30);
    QPixmap scalemap = dir.scaled(size, Qt::KeepAspectRatio);
    QPixmap scalemap1 = dir1.scaled(size, Qt::KeepAspectRatio);
    QPixmap scalemap2 = dir2.scaled(size, Qt::KeepAspectRatio);
    cursor = QCursor(scalemap,25,0);
    cursor1 = QCursor(scalemap1);
    cursor2 = QCursor(scalemap2);
    ui->pushButton->setCursor(cursor);
    ui->pushButton_2->setCursor(cursor);
    ui->pushButton_3->setCursor(cursor);
    ui->pushButton_4->setCursor(cursor);
    ui->pushButton_5->setCursor(cursor);
    ui->pushButton_6->setCursor(cursor);
    ui->pushButton_7->setCursor(cursor);
    ui->pushButton_8->setCursor(cursor);
    ui->pushButton_9->setCursor(cursor);
    ui->pushButton_10->setCursor(cursor);
    ui->pushButton_11->setCursor(cursor);
    ui->pushButton_12->setCursor(cursor);
    ui->pushButton_13->setCursor(cursor);
    ui->pushButton_14->setCursor(cursor);
    ui->pushButton_15->setCursor(cursor);
    ui->pushButton_16->setCursor(cursor);
    ui->textEdit_1->viewport()->setCursor(cursor2);
    ui->textEdit_2->viewport()->setCursor(cursor2);
    this->setCursor(cursor1);
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

void highlight_out(QTextEdit* te, QString* s, QString* s1){
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
        QString tmp(s1->at(i));
        te->insertPlainText(tmp);
    }
}

void my_compare(int x,int y,QString* s1,QString* s2,QString* ans1,QString* ans2){
    if(x==0&&y==0)return;
    if(x==0){
        my_compare(x,y-1,s1,s2,ans1,ans2);
        ans2->append('_');
        return;
    }
    if(y==0){
        my_compare(x-1,y,s1,s2,ans1,ans2);
        ans1->append('_');
        return;
    }
    if(s1->at(x-1)==s2->at(y-1)){
        my_compare(x-1,y-1,s1,s2,ans1,ans2);
        ans1->append(s1->at(x-1));
        ans2->append(s2->at(y-1));
        return;
    }
    if(f[x-1][y]>f[x][y-1]){
        my_compare(x-1,y,s1,s2,ans1,ans2);
        ans1->append('_');
    }else{
        my_compare(x,y-1,s1,s2,ans1,ans2);
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
    my_compare(len1,len2,&s1,&s2,&ans1,&ans2);
    //ui->textEdit_1->setText(ans1);
    //ui->textEdit_2->setText(ans2);
    highlight_out(ui->textEdit_1,&ans1,&s1);
    highlight_out(ui->textEdit_2,&ans2,&s2);
}//文本比较

void myTestWidget::leftVerticalScroll()
{
    QScrollBar* QSB_left=ui->textEdit_1->verticalScrollBar();
    QScrollBar* QSB_right=ui->textEdit_2->verticalScrollBar();
    QSB_right->setValue(QSB_left->value());
}

void myTestWidget::rightVerticalScroll()
{
    QScrollBar* QSB_left=ui->textEdit_1->verticalScrollBar();
    QScrollBar* QSB_right=ui->textEdit_2->verticalScrollBar();
    QSB_left->setValue(QSB_right->value());
}

void myTestWidget::leftHorizontalScroll()
{
    QScrollBar* QSB_left_h=ui->textEdit_1->horizontalScrollBar();
    QScrollBar* QSB_right_h=ui->textEdit_2->horizontalScrollBar();
    QSB_right_h->setValue(QSB_left_h->value());
}

void myTestWidget::rightHorizontalScroll()
{
    QScrollBar* QSB_left_h=ui->textEdit_1->horizontalScrollBar();
    QScrollBar* QSB_right_h=ui->textEdit_2->horizontalScrollBar();
    QSB_left_h->setValue(QSB_right_h->value());
}

void myTestWidget::leftShowLineNum()
{
    QTextCursor tc=ui->textEdit_1->textCursor();
    int lineNum=tc.blockNumber()+1;
    int columnNum=tc.columnNumber()+1;
    QString s="第 ";
    s=s+QString::number(lineNum)+" 行, 第 "+QString::number(columnNum)+" 列";
    ui->label->setText(s);
}

void myTestWidget::rightShowLineNum()
{
    QTextCursor tc=ui->textEdit_2->textCursor();
    int lineNum=tc.blockNumber()+1;
    int columnNum=tc.columnNumber()+1;
    QString s="第 ";
    s=s+QString::number(lineNum)+" 行, 第 "+QString::number(columnNum)+" 列";
    ui->label_2->setText(s);
}
