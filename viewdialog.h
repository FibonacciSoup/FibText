#ifndef VIEWDIALOG_H
#define VIEWDIALOG_H

#include <QDialog>
#include "mytestwidget.h"
#include "ui_mytestwidget.h"

namespace Ui {
class viewDialog;
}

class myTestWidget;

class viewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit viewDialog(QWidget *parent = 0);
    ~viewDialog();

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonColor_clicked();

    void on_pushButtonApplyColor_1_clicked();

    void on_pushButtonApplyColor_2_clicked();

    void on_pushButtonFont_clicked();

    void on_pushButtonApplyFont_1_clicked();

    void on_pushButtonDefault_clicked();

private:
    Ui::viewDialog *ui;
    myTestWidget *myParent;
};

#endif // VIEWDIALOG_H
