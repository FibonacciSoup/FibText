#ifndef MYTESTWIDGET_H
#define MYTESTWIDGET_H

#include <QWidget>
#include "viewdialog.h"
#include "ui_viewdialog.h"

namespace Ui {
class myTestWidget;
}

class viewDialog;

class myTestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myTestWidget(QWidget *parent = 0);
    ~myTestWidget();
    void leftSetQSSColor(QColor c);
    void leftSetQSSFont(QFont f);
    void leftSetColor(QColor c);
    void leftSetFont(QFont f);
    void rightSetQSSColor(QColor c);
    void rightSetQSSFont(QFont f);
    void rightSetColor(QColor c);
    void rightSetFont(QFont f);
    void setDefaultFont();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void leftVerticalScroll();

    void rightVerticalScroll();

    void leftHorizontalScroll();

    void rightHorizontalScroll();

    void leftShowLineNum();

    void rightShowLineNum();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void leftSetWhiteBrush();

    void rightSetWhiteBrush();

    void on_pushButtonViewDialog_clicked();

    void clearList();

    void moveToRow(int);

    void changeMove();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    int isadigit(QChar a);

    void leftLCDclear();

    void rightLCDclear();

    void on_pushButton_5_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::myTestWidget *ui;
    viewDialog *m_pViewdialog;
    QString textStyleSheet_default;
    QString textStyleSheet_1;
    QString textStyleSheet_2;
    QString qssColor_1;
    QString qssColor_2;
    QString qssFont_1;
    QString qssFont_2;
    QString tabWidgetSS;
    QString topPushbuttonSS;
    QString textPushbuttonSS;
};

#endif // MYTESTWIDGET_H
