/********************************************************************************
** Form generated from reading UI file 'mytestwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTESTWIDGET_H
#define UI_MYTESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myTestWidget
{
public:
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLCDNumber *lcdNumber_1;
    QLCDNumber *lcdNumber_2;
    QTextEdit *textEdit_1;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QLabel *label;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QWidget *tab_2;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_19;
    QWidget *tab_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_11;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tab_4;
    QPushButton *pushButtonViewDialog;
    QListWidget *listWidget;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;

    void setupUi(QWidget *myTestWidget)
    {
        if (myTestWidget->objectName().isEmpty())
            myTestWidget->setObjectName(QStringLiteral("myTestWidget"));
        myTestWidget->resize(1080, 730);
        textEdit_2 = new QTextEdit(myTestWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(580, 140, 471, 531));
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit_2->setLineWrapMode(QTextEdit::NoWrap);
        pushButton = new QPushButton(myTestWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 100, 71, 31));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/open/open2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton_2 = new QPushButton(myTestWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 100, 71, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/save/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_3 = new QPushButton(myTestWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(580, 100, 71, 31));
        pushButton_3->setIcon(icon);
        pushButton_4 = new QPushButton(myTestWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(650, 100, 71, 31));
        pushButton_4->setIcon(icon1);
        lcdNumber_1 = new QLCDNumber(myTestWidget);
        lcdNumber_1->setObjectName(QStringLiteral("lcdNumber_1"));
        lcdNumber_1->setGeometry(QRect(470, 670, 91, 31));
        lcdNumber_1->setLineWidth(1);
        lcdNumber_1->setDigitCount(6);
        lcdNumber_1->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_1->setProperty("value", QVariant(0));
        lcdNumber_1->setProperty("intValue", QVariant(0));
        lcdNumber_2 = new QLCDNumber(myTestWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(960, 670, 91, 31));
        lcdNumber_2->setDigitCount(6);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2->setProperty("intValue", QVariant(0));
        textEdit_1 = new QTextEdit(myTestWidget);
        textEdit_1->setObjectName(QStringLiteral("textEdit_1"));
        textEdit_1->setGeometry(QRect(90, 140, 471, 531));
        textEdit_1->setFrameShape(QFrame::StyledPanel);
        textEdit_1->setFrameShadow(QFrame::Sunken);
        textEdit_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit_1->setLineWrapMode(QTextEdit::NoWrap);
        pushButton_15 = new QPushButton(myTestWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(230, 100, 71, 31));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/clear/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon2);
        pushButton_16 = new QPushButton(myTestWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(720, 100, 71, 31));
        pushButton_16->setIcon(icon2);
        label = new QLabel(myTestWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 680, 171, 16));
        label_2 = new QLabel(myTestWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(580, 680, 181, 16));
        tabWidget = new QTabWidget(myTestWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 1021, 81));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 10, 131, 31));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(160, 10, 131, 31));
        pushButton_13 = new QPushButton(tab);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(310, 10, 131, 31));
        pushButton_14 = new QPushButton(tab);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(460, 10, 131, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(790, 10, 101, 31));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 771, 31));
        pushButton_19 = new QPushButton(tab_2);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(900, 10, 101, 31));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(60, 10, 101, 31));
        pushButton_10 = new QPushButton(tab_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(180, 10, 101, 31));
        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(550, 10, 101, 31));
        pushButton_11 = new QPushButton(tab_3);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(670, 10, 101, 31));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(16, 17, 31, 16));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(510, 16, 31, 16));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pushButtonViewDialog = new QPushButton(tab_4);
        pushButtonViewDialog->setObjectName(QStringLiteral("pushButtonViewDialog"));
        pushButtonViewDialog->setGeometry(QRect(10, 10, 131, 31));
        tabWidget->addTab(tab_4, QString());
        listWidget = new QListWidget(myTestWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 140, 71, 531));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_17 = new QPushButton(myTestWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(300, 100, 101, 31));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/letter/A.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon3);
        pushButton_18 = new QPushButton(myTestWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(790, 100, 101, 31));
        pushButton_18->setIcon(icon3);
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        lcdNumber_1->raise();
        lcdNumber_2->raise();
        textEdit_1->raise();
        pushButton_15->raise();
        pushButton_16->raise();
        label->raise();
        label_2->raise();
        tabWidget->raise();
        listWidget->raise();
        pushButton_17->raise();
        pushButton_18->raise();
        textEdit_2->raise();

        retranslateUi(myTestWidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(myTestWidget);
    } // setupUi

    void retranslateUi(QWidget *myTestWidget)
    {
        myTestWidget->setWindowTitle(QApplication::translate("myTestWidget", "\346\226\207\346\234\254\345\244\204\347\220\206\345\231\250", 0));
        pushButton->setText(QApplication::translate("myTestWidget", "\346\211\223\345\274\200", 0));
        pushButton_2->setText(QApplication::translate("myTestWidget", "\344\277\235\345\255\230", 0));
        pushButton_3->setText(QApplication::translate("myTestWidget", "\346\211\223\345\274\200", 0));
        pushButton_4->setText(QApplication::translate("myTestWidget", "\344\277\235\345\255\230", 0));
        pushButton_15->setText(QApplication::translate("myTestWidget", "\346\270\205\351\231\244", 0));
        pushButton_16->setText(QApplication::translate("myTestWidget", "\346\270\205\351\231\244", 0));
        label->setText(QApplication::translate("myTestWidget", "\347\254\254 1 \350\241\214, \347\254\254 1 \345\210\227", 0));
        label_2->setText(QApplication::translate("myTestWidget", "\347\254\254 1 \350\241\214, \347\254\254 1 \345\210\227", 0));
        pushButton_6->setText(QApplication::translate("myTestWidget", "\346\257\224\350\276\203", 0));
        pushButton_7->setText(QApplication::translate("myTestWidget", "\350\275\254\345\210\260\344\270\213\344\270\200\345\244\204\344\270\215\345\220\214", 0));
        pushButton_13->setText(QApplication::translate("myTestWidget", "\350\275\254\345\210\260", 0));
        pushButton_14->setText(QApplication::translate("myTestWidget", "\350\276\223\345\207\272...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("myTestWidget", "Tab 1", 0));
        pushButton_5->setText(QApplication::translate("myTestWidget", "\345\234\250\345\267\246\350\276\271\346\237\245\346\211\276", 0));
        pushButton_19->setText(QApplication::translate("myTestWidget", "\345\234\250\345\217\263\350\276\271\346\237\245\346\211\276", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("myTestWidget", "Tab 2", 0));
        pushButton_8->setText(QApplication::translate("myTestWidget", "\345\215\225\350\257\215\346\225\260\347\273\237\350\256\241", 0));
        pushButton_10->setText(QApplication::translate("myTestWidget", "\345\255\227\347\254\246\346\225\260\347\273\237\350\256\241", 0));
        pushButton_9->setText(QApplication::translate("myTestWidget", "\345\215\225\350\257\215\346\225\260\347\273\237\350\256\241", 0));
        pushButton_11->setText(QApplication::translate("myTestWidget", "\345\255\227\347\254\246\346\225\260\347\273\237\350\256\241", 0));
        label_3->setText(QApplication::translate("myTestWidget", "\345\267\246\350\276\271", 0));
        label_4->setText(QApplication::translate("myTestWidget", "\345\217\263\350\276\271", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("myTestWidget", "Tab 3", 0));
        pushButtonViewDialog->setText(QApplication::translate("myTestWidget", "\350\260\203\346\225\264\346\230\276\347\244\272...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("myTestWidget", "Tab 4", 0));
        pushButton_17->setText(QApplication::translate("myTestWidget", "\345\217\226\346\266\210\351\253\230\344\272\256", 0));
        pushButton_18->setText(QApplication::translate("myTestWidget", "\345\217\226\346\266\210\351\253\230\344\272\256", 0));
    } // retranslateUi

};

namespace Ui {
    class myTestWidget: public Ui_myTestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTESTWIDGET_H
