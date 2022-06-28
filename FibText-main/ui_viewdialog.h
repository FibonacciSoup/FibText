/********************************************************************************
** Form generated from reading UI file 'viewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDIALOG_H
#define UI_VIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_viewDialog
{
public:
    QPushButton *pushButtonClose;
    QGroupBox *groupBoxColor;
    QPushButton *pushButtonColor;
    QLabel *labelColor;
    QPushButton *pushButtonApplyColor_1;
    QPushButton *pushButtonApplyColor_2;
    QGroupBox *groupBoxFont;
    QPushButton *pushButtonFont;
    QLabel *labelFont;
    QPushButton *pushButtonApplyFont_1;
    QPushButton *pushButtonDefault;

    void setupUi(QDialog *viewDialog)
    {
        if (viewDialog->objectName().isEmpty())
            viewDialog->setObjectName(QStringLiteral("viewDialog"));
        viewDialog->resize(470, 241);
        pushButtonClose = new QPushButton(viewDialog);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(260, 200, 93, 28));
        groupBoxColor = new QGroupBox(viewDialog);
        groupBoxColor->setObjectName(QStringLiteral("groupBoxColor"));
        groupBoxColor->setGeometry(QRect(10, 10, 451, 81));
        pushButtonColor = new QPushButton(groupBoxColor);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));
        pushButtonColor->setGeometry(QRect(10, 30, 111, 28));
        labelColor = new QLabel(groupBoxColor);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        labelColor->setGeometry(QRect(140, 33, 21, 21));
        labelColor->setFrameShape(QFrame::StyledPanel);
        pushButtonApplyColor_1 = new QPushButton(groupBoxColor);
        pushButtonApplyColor_1->setObjectName(QStringLiteral("pushButtonApplyColor_1"));
        pushButtonApplyColor_1->setGeometry(QRect(180, 30, 121, 28));
        pushButtonApplyColor_2 = new QPushButton(groupBoxColor);
        pushButtonApplyColor_2->setObjectName(QStringLiteral("pushButtonApplyColor_2"));
        pushButtonApplyColor_2->setGeometry(QRect(320, 30, 121, 28));
        groupBoxFont = new QGroupBox(viewDialog);
        groupBoxFont->setObjectName(QStringLiteral("groupBoxFont"));
        groupBoxFont->setGeometry(QRect(10, 110, 451, 81));
        pushButtonFont = new QPushButton(groupBoxFont);
        pushButtonFont->setObjectName(QStringLiteral("pushButtonFont"));
        pushButtonFont->setGeometry(QRect(20, 30, 95, 32));
        labelFont = new QLabel(groupBoxFont);
        labelFont->setObjectName(QStringLiteral("labelFont"));
        labelFont->setGeometry(QRect(130, 25, 151, 41));
        pushButtonApplyFont_1 = new QPushButton(groupBoxFont);
        pushButtonApplyFont_1->setObjectName(QStringLiteral("pushButtonApplyFont_1"));
        pushButtonApplyFont_1->setGeometry(QRect(320, 30, 121, 28));
        pushButtonDefault = new QPushButton(viewDialog);
        pushButtonDefault->setObjectName(QStringLiteral("pushButtonDefault"));
        pushButtonDefault->setGeometry(QRect(100, 200, 93, 28));
        groupBoxFont->raise();
        groupBoxColor->raise();
        pushButtonClose->raise();
        pushButtonDefault->raise();

        retranslateUi(viewDialog);

        QMetaObject::connectSlotsByName(viewDialog);
    } // setupUi

    void retranslateUi(QDialog *viewDialog)
    {
        viewDialog->setWindowTitle(QApplication::translate("viewDialog", "\350\260\203\346\225\264\346\230\276\347\244\272", 0));
        pushButtonClose->setText(QApplication::translate("viewDialog", "\345\205\263\351\227\255", 0));
        groupBoxColor->setTitle(QApplication::translate("viewDialog", "\350\260\203\346\225\264\346\226\207\345\255\227\351\242\234\350\211\262", 0));
        pushButtonColor->setText(QApplication::translate("viewDialog", "\351\200\211\346\213\251\351\242\234\350\211\262...", 0));
        labelColor->setText(QString());
        pushButtonApplyColor_1->setText(QApplication::translate("viewDialog", "\345\272\224\347\224\250\345\234\250\345\267\246\346\226\207\346\234\254\346\241\206", 0));
        pushButtonApplyColor_2->setText(QApplication::translate("viewDialog", "\345\272\224\347\224\250\345\234\250\345\217\263\346\226\207\346\234\254\346\241\206", 0));
        groupBoxFont->setTitle(QApplication::translate("viewDialog", "\350\260\203\346\225\264\345\255\227\344\275\223", 0));
        pushButtonFont->setText(QApplication::translate("viewDialog", "\351\200\211\346\213\251\345\255\227\344\275\223...", 0));
        labelFont->setText(QApplication::translate("viewDialog", "AaBbCcDd", 0));
        pushButtonApplyFont_1->setText(QApplication::translate("viewDialog", "\345\272\224\347\224\250", 0));
        pushButtonDefault->setText(QApplication::translate("viewDialog", "\350\256\276\344\270\272\351\273\230\350\256\244\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class viewDialog: public Ui_viewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDIALOG_H
