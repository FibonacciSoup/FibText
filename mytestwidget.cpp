#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <QFileDialog>
#include <QTextStream>
#include <QBrush>
#include <QTextCharFormat>
#include <QScrollBar>
#include <QTextCursor>
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QTextEdit>
#include <QColor>
#include <QTextDocument>
#include "mytestwidget.h"
#include "ui_mytestwidget.h"
#include "viewdialog.h"
#include "ui_viewdialog.h"

typedef long long LL;

const int maxn=2000;

static int tem,pU,enter_left[maxn],enter_right[maxn],f[maxn][maxn];
static std::vector<int>unmatched_pos_left,unmatched_pos_right,unmatched_row_left,unmatched_row_right,unmatched;

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

    //防止在编辑文本时高亮
    connect(ui->textEdit_1,SIGNAL(cursorPositionChanged()),this,SLOT(leftSetWhiteBrush()));
    connect(ui->textEdit_2,SIGNAL(cursorPositionChanged()),this,SLOT(rightSetWhiteBrush()));

    //set icon for cursor
    QCursor cursor,cursor1,cursor2;
    QPixmap dir(":/icon/arrow.png");
    QPixmap dir1(":/icon/cross.png");
    QPixmap dir2(":/icon/biarrow.png");
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
    ui->pushButtonViewDialog->setCursor(cursor);
    ui->pushButton_15->setCursor(cursor);
    ui->pushButton_16->setCursor(cursor);
    ui->pushButton_17->setCursor(cursor);
    ui->pushButton_18->setCursor(cursor);
    ui->pushButton_19->setCursor(cursor);
    ui->textEdit_1->viewport()->setCursor(cursor2);
    ui->textEdit_2->viewport()->setCursor(cursor2);
    this->setCursor(cursor1);

    m_pViewdialog = NULL;

    textStyleSheet_default = "color: rgb(0,0,0); font: Normal 9pt \"宋体\"; ";
    textStyleSheet_1 = "color: %1; font: %2; ";
    textStyleSheet_2 = "color: %1; font: %2; ";
    qssColor_1 = "rgb(0,0,0)";
    qssColor_2 = "rgb(0,0,0)";
    qssFont_1 = "Normal 9pt \"宋体\"";
    qssFont_2 = "Normal 9pt \"宋体\"";

    connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(clearList()));
    connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(clearList()));
    //clear listwidget when any of the textEditWidget is cleared

    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(changeMove()));

    connect(ui->textEdit_1,SIGNAL(textChanged()),this,SLOT(leftLCDclear()));
    connect(ui->textEdit_2,SIGNAL(textChanged()),this,SLOT(rightLCDclear()));

    //淡蓝色界面
    tabWidgetSS = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                  "stop:0 rgba(222, 240, 254, 255), stop:1 rgba(192, 222, 246, 255));"
                  "border: none; font: 16px \"黑体\"; color: rgb(20,50,80); ";
    topPushbuttonSS = "QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                      "stop:0 rgba(200, 230, 255, 255), stop:1 rgba(160, 200, 230, 255)); "
                      "border: 1px solid rgb(85, 155, 220); }"
                      "QPushButton:hover{background-color: rgb(225,235,255); }"
                      "QPushButton:pressed{background-color: rgb(150,190,220); }";
    textPushbuttonSS = "QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                      "stop:0 rgba(222, 240, 254, 255), stop:1 rgba(192, 222, 246, 255)); "
                      "border: 1px solid rgb(85, 155, 220); }"
                      "QPushButton:hover{background-color: rgb(225,235,255); }"
                      "QPushButton:pressed{background-color: rgb(150,190,220); }";

    ui->frame_top->setStyleSheet("background-color: rgb(222, 240, 254);");
    ui->frame_main->setStyleSheet("background-color: rgb(234, 247, 255);");
    ui->tabWidget->setStyleSheet(tabWidgetSS);
    ui->pushButton_6->setStyleSheet(topPushbuttonSS);
    ui->pushButton_7->setStyleSheet(topPushbuttonSS);
    ui->pushButton_5->setStyleSheet(topPushbuttonSS);
    ui->pushButton_19->setStyleSheet(topPushbuttonSS);
    ui->pushButton_8->setStyleSheet(topPushbuttonSS);
    ui->pushButton_9->setStyleSheet(topPushbuttonSS);
    ui->pushButton_10->setStyleSheet(topPushbuttonSS);
    ui->pushButton_11->setStyleSheet(topPushbuttonSS);
    ui->pushButtonViewDialog->setStyleSheet(topPushbuttonSS);
    ui->lineEdit->setStyleSheet("border: 1px solid rgb(85,155,220); background-color: rgb(255,255,255); "
                                "font: 15px \"宋体\"; color: rgb(0,0,0); ");
    ui->pushButton->setStyleSheet(textPushbuttonSS);
    ui->pushButton_2->setStyleSheet(textPushbuttonSS);
    ui->pushButton_3->setStyleSheet(textPushbuttonSS);
    ui->pushButton_4->setStyleSheet(textPushbuttonSS);
    ui->pushButton_15->setStyleSheet(textPushbuttonSS);
    ui->pushButton_16->setStyleSheet(textPushbuttonSS);
    ui->pushButton_17->setStyleSheet(textPushbuttonSS);
    ui->pushButton_18->setStyleSheet(textPushbuttonSS);

}

myTestWidget::~myTestWidget()
{
    delete ui;

    if (m_pViewdialog != NULL){
        delete m_pViewdialog;
        m_pViewdialog = NULL;
    }
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
    te->setCurrentCharFormat(f2);
}

void my_compare(int x,int y,QString* s1,QString* s2,QString* ans1,QString* ans2){
    if(x==0&&y==0)return;
    if(x==0){
        my_compare(x,y-1,s1,s2,ans1,ans2);
        ans2->append('_');
        unmatched_row_right.push_back(enter_right[y]);
        unmatched_pos_right.push_back(y);
        return;
    }
    if(y==0){
        my_compare(x-1,y,s1,s2,ans1,ans2);
        ans1->append('_');
        unmatched_row_left.push_back(enter_left[x]);
        unmatched_pos_left.push_back(x);
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
        unmatched_row_left.push_back(enter_left[x]);
        unmatched_pos_left.push_back(x);
    }else{
        my_compare(x,y-1,s1,s2,ans1,ans2);
        ans2->append('_');
        unmatched_row_right.push_back(enter_right[y]);
        unmatched_pos_right.push_back(y);
    }
}

void myTestWidget::on_pushButton_6_clicked()
{
    QString s1 = ui->textEdit_1->toPlainText();
    QString s2 = ui->textEdit_2->toPlainText();
    int len1=static_cast<int>(s1.length());
    int len2=static_cast<int>(s2.length());
    memset(f,0,sizeof(f));
    while(!unmatched_row_left.empty())unmatched_row_left.pop_back();
    while(!unmatched_row_right.empty())unmatched_row_right.pop_back();
    pU=0;
    while(!unmatched_pos_left.empty())unmatched_pos_left.pop_back();
    while(!unmatched_pos_right.empty())unmatched_pos_right.pop_back();
    while(!unmatched.empty())unmatched.pop_back();
    for(int i=1;i<=len1;i++) enter_left[i]=enter_left[i-1]+(s1.at(i-1)=='\n'||s1.at(i-1)=='\r');
    for(int i=1;i<=len2;i++) enter_right[i]=enter_right[i-1]+(s2.at(i-1)=='\n'||s2.at(i-1)=='\r');
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
    //highlight the unmatched words

    QTextCursor tc_left=ui->textEdit_1->textCursor();
    QTextCursor tc_right=ui->textEdit_2->textCursor();
    tc_left.movePosition(QTextCursor::Start);
    tc_right.movePosition(QTextCursor::Start);
    ui->textEdit_1->setTextCursor(tc_left);
    ui->textEdit_2->setTextCursor(tc_right);

    ui->listWidget->clear();
    unmatched.insert(unmatched.end(),unmatched_row_left.begin(),unmatched_row_left.end());
    unmatched.insert(unmatched.end(),unmatched_row_right.begin(),unmatched_row_right.end());
    std::sort(unmatched.begin(),unmatched.end());
    tem=std::unique(unmatched.begin(),unmatched.end())-unmatched.begin();
    for(int i=0;i<tem;i++){
        int itemCount = ui->listWidget->count();
            QListWidgetItem * item = new QListWidgetItem;
            item->setSizeHint(QSize(ui->listWidget->width(),20));
            item->setText(QString::fromStdString(std::to_string(unmatched[i]+1)).arg(itemCount));
//            item->setFlags(Qt::ItemIsEnabled);
//            item->setCheckState(Qt::Unchecked);
            ui->listWidget->addItem(item);
    }
    //show the row number of the unmatched words
}//文本比较

void myTestWidget::on_pushButton_10_clicked()
{
    QString s1 = ui->textEdit_1->toPlainText();
    int l1=static_cast<int>(s1.length());
    int count_1 = 0;
    for(int i = 0;i < l1;i++){
        if(s1.at(i) != ' ' && s1.at(i) != '\n') count_1++;
    }
    ui->lcdNumber_1->display(count_1);
}//左文本框字符数统计

void myTestWidget::on_pushButton_11_clicked()
{
    QString s2 = ui->textEdit_2->toPlainText();
    int l2=static_cast<int>(s2.length());
    int count_2 = 0;
    for(int i = 0;i < l2;i++){
        if(s2.at(i) != ' ' && s2.at(i) != '\n') count_2++;
    }
    ui->lcdNumber_2->display(count_2);
}//右文本框字符统计

int myTestWidget::isadigit(QChar a)
{
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) return 1;
    else return 0;
}//判断是否为字母或数字，用于判断单词数

void myTestWidget::on_pushButton_8_clicked()
{
    QString s1 = ui->textEdit_1->toPlainText();
    int len1=static_cast<int>(s1.length());
    int count_1 = 0;
    int flagk;
    for(flagk = 0;flagk < len1;flagk++){
        if(isadigit(s1.at(flagk)) == 1){
            count_1++;
            break;
        }
    }
    for(int i = flagk;i < len1 - 1;i++){
        if(isadigit(s1.at(i)) == 0 && isadigit(s1.at(i + 1)) == 1){
            if(isadigit(s1.at(i - 1)) == 1 && s1.at(i) == '-') continue;
            else count_1++;
        }
    }
    ui->lcdNumber_1->display(count_1);
}//左文本框单词数统计

void myTestWidget::on_pushButton_9_clicked()
{
    QString s2 = ui->textEdit_2->toPlainText();
    int len2=static_cast<int>(s2.length());
    int count_2 = 0;
    int flagk;
    for(flagk = 0;flagk < len2;flagk++){
        if(isadigit(s2.at(flagk)) == 1){
            count_2++;
            break;
        }
    }
    for(int i = flagk;i < len2 - 1;i++){
        if(isadigit(s2.at(i)) == 0 && isadigit(s2.at(i + 1)) == 1){
            if(isadigit(s2.at(i - 1)) == 1 && s2.at(i) == '-') continue;
            else count_2++;
        }
    }
    ui->lcdNumber_2->display(count_2);
}//右文本框单词数统计

void myTestWidget::leftLCDclear()
{
    ui->lcdNumber_1->display(0);
}

void myTestWidget::rightLCDclear()
{
    ui->lcdNumber_2->display(0);
}

void myTestWidget::on_pushButton_7_clicked(){
    QTextCursor tc_left=ui->textEdit_1->textCursor();
    QTextCursor tc_right=ui->textEdit_2->textCursor();
    if(pU==0){
        tc_left.movePosition(QTextCursor::Start);
        tc_right.movePosition(QTextCursor::Start);
    }
    int row_left=tc_left.blockNumber(),row_right=tc_right.blockNumber();
    int total_row_L = ui->textEdit_1->document()->lineCount();
    int total_row_R = ui->textEdit_2->document()->lineCount();
    if(pU>=tem)return;
    if(unmatched[pU]>total_row_L&&unmatched[pU]>total_row_R)return;
    if(unmatched[pU]<=total_row_R)tc_right.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, unmatched[pU]-row_right);
        else tc_right.movePosition(QTextCursor::End,QTextCursor::MoveAnchor);
    if(unmatched[pU]<=total_row_L)tc_left.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, unmatched[pU]-row_left);
        else tc_left.movePosition(QTextCursor::End,QTextCursor::MoveAnchor);
    if(pU+1<tem)++pU;
        else pU=0;
    ui->textEdit_1->setTextCursor(tc_left);
    ui->textEdit_2->setTextCursor(tc_right);
}//turn to the row of the next unmatched word

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

void myTestWidget::on_pushButton_17_clicked()
{
    QString text = ui->textEdit_1->toPlainText();
    ui->textEdit_1->setPlainText(text);
} //取消高亮

void myTestWidget::on_pushButton_18_clicked()
{
    QString text = ui->textEdit_2->toPlainText();
    ui->textEdit_2->setPlainText(text);
} //取消高亮

void myTestWidget::leftSetWhiteBrush()
{
    QBrush b(QColor(255,255,255));
    QTextCharFormat f;
    f.setBackground(b);
    ui->textEdit_1->setCurrentCharFormat(f);
}

void myTestWidget::rightSetWhiteBrush()
{
    QBrush b(QColor(255,255,255));
    QTextCharFormat f;
    f.setBackground(b);
    ui->textEdit_2->setCurrentCharFormat(f);
}

void myTestWidget::on_pushButtonViewDialog_clicked()
{
    if ( NULL == m_pViewdialog ){
        m_pViewdialog = new viewDialog(this);
    }
    m_pViewdialog->exec();

/*    if (m_pViewdialog->exec() == QDialog::Accepted){
        qDebug() << "QDialog::Accepted";
    }else{
        qDebug() << "QDialog::Closed";
    }*/
}

void myTestWidget::leftSetQSSColor(QColor c)
{
    qssColor_1 = "rgb(%1,%2,%3)";
    qssColor_1 = qssColor_1.arg(c.red()).arg(c.green()).arg(c.blue());
}

void myTestWidget::leftSetQSSFont(QFont f)
{
    qssFont_1 = "%1 %2pt \"%3\"";
    qssFont_1 = qssFont_1.arg(f.styleName()).arg(f.pointSize()).arg(f.family());
}

void myTestWidget::leftSetColor(QColor c)
{
    leftSetQSSColor(c);
    textStyleSheet_1 = "color: %1; font: %2; ";
    textStyleSheet_1 = textStyleSheet_1.arg(qssColor_1).arg(qssFont_1);
    ui->textEdit_1->setStyleSheet(textStyleSheet_1);
}

void myTestWidget::leftSetFont(QFont f)
{
    leftSetQSSFont(f);
    textStyleSheet_1 = "color: %1; font: %2; ";
    textStyleSheet_1 = textStyleSheet_1.arg(qssColor_1).arg(qssFont_1);
    ui->textEdit_1->setStyleSheet(textStyleSheet_1);
}

void myTestWidget::rightSetQSSColor(QColor c)
{
    qssColor_2 = "rgb(%1,%2,%3)";
    qssColor_2 = qssColor_2.arg(c.red()).arg(c.green()).arg(c.blue());
}

void myTestWidget::rightSetQSSFont(QFont f)
{
    qssFont_2 = "%1 %2pt \"%3\"";
    qssFont_2 = qssFont_2.arg(f.styleName()).arg(f.pointSize()).arg(f.family());
}

void myTestWidget::rightSetColor(QColor c)
{
    rightSetQSSColor(c);
    textStyleSheet_2 = "color: %1; font: %2; ";
    textStyleSheet_2 = textStyleSheet_2.arg(qssColor_2).arg(qssFont_2);
    ui->textEdit_2->setStyleSheet(textStyleSheet_2);
}

void myTestWidget::rightSetFont(QFont f)
{
    rightSetQSSFont(f);
    textStyleSheet_2 = "color: %1; font: %2; ";
    textStyleSheet_2 = textStyleSheet_2.arg(qssColor_2).arg(qssFont_2);
    ui->textEdit_2->setStyleSheet(textStyleSheet_2);
}

void myTestWidget::setDefaultFont()
{
    ui->textEdit_1->setStyleSheet(textStyleSheet_default);
    ui->textEdit_2->setStyleSheet(textStyleSheet_default);
    qssColor_1 = "rgb(0,0,0)";
    qssColor_2 = "rgb(0,0,0)";
    qssFont_1 = "Normal 9pt \"宋体\"";
    qssFont_2 = "Normal 9pt \"宋体\"";
}

void myTestWidget::clearList(){
    ui->listWidget->clear();
}

void myTestWidget::changeMove(){
    QListWidgetItem *item = ui->listWidget->currentItem();
    QString s = item->text();
    int x = s.toInt();
    moveToRow(x);
}

void myTestWidget::moveToRow(int x){
    pU=static_cast<int>(std::lower_bound(unmatched.begin(),unmatched.begin()+tem,x-1)-unmatched.begin());

    QTextCursor tc_left=ui->textEdit_1->textCursor();
    QTextCursor tc_right=ui->textEdit_2->textCursor();
    tc_left.movePosition(QTextCursor::Start);
    tc_right.movePosition(QTextCursor::Start);
    int row_left=tc_left.blockNumber(),row_right=tc_right.blockNumber();
    int total_row_L = ui->textEdit_1->document()->lineCount();
    int total_row_R = ui->textEdit_2->document()->lineCount();
    if(unmatched[pU]<=total_row_R)tc_right.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, unmatched[pU]-row_right);
        else tc_right.movePosition(QTextCursor::End,QTextCursor::MoveAnchor);
    if(unmatched[pU]<=total_row_L)tc_left.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, unmatched[pU]-row_left);
        else tc_left.movePosition(QTextCursor::End,QTextCursor::MoveAnchor);
    if(pU+1<tem)++pU;
        else pU=0;
    ui->textEdit_1->setTextCursor(tc_left);
    ui->textEdit_2->setTextCursor(tc_right);
}
