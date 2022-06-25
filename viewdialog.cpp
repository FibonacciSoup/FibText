#include <QColor>
#include <QColorDialog>
#include <QString>
#include <QDialog>
#include <QFont>
#include <QFontDialog>
#include "viewdialog.h"
#include "ui_viewdialog.h"
#include "mytestwidget.h"
#include "ui_mytestwidget.h"

static QColor g_textColor;
static QFont g_textFont;

viewDialog::viewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewDialog)
{
    ui->setupUi(this);
    ui->labelColor->setStyleSheet("background-color: rgb(0,0,0); ");
    myParent = (myTestWidget*)parent;

    g_textColor.setRgb(0,0,0);
    g_textFont = ui->labelFont->font();

    //禁用帮助按钮和关闭按钮
    this->setWindowFlags(this->windowFlags()&(~Qt::WindowCloseButtonHint)&(~Qt::WindowContextHelpButtonHint));
}

viewDialog::~viewDialog()
{
    delete ui;
}

void viewDialog::on_pushButtonClose_clicked()
{
    this->accept();
}

void viewDialog::on_pushButtonColor_clicked()
{
    QColorDialog myColorDialog(Qt::black, this);
    if(myColorDialog.exec() == QDialog::Accepted){
        g_textColor = myColorDialog.currentColor();
        QString colorString = QString("rgb(%1,%2,%3)").arg(g_textColor.red()).arg(g_textColor.green()).arg(g_textColor.blue());
        ui->labelColor->setStyleSheet("background-color: "+colorString+"; ");
    }
}

void viewDialog::on_pushButtonApplyColor_1_clicked()
{
    myParent->leftSetColor(g_textColor);
}

void viewDialog::on_pushButtonApplyColor_2_clicked()
{
    myParent->rightSetColor(g_textColor);
}

void viewDialog::on_pushButtonFont_clicked()
{
    bool ok;
    g_textFont = QFontDialog::getFont(&ok, this);
    if(ok) {
        QString fontString = QString("%1 %2pt \"%3\"").arg(g_textFont.styleName()).arg(g_textFont.pointSize()).arg(g_textFont.family());
        ui->labelFont->setStyleSheet("font: "+fontString+"; ");
    }
}

void viewDialog::on_pushButtonApplyFont_1_clicked()
{
    myParent->leftSetFont(g_textFont);
    myParent->rightSetFont(g_textFont);
}

void viewDialog::on_pushButtonDefault_clicked()
{
    ui->labelColor->setStyleSheet("background-color: rgb(0,0,0); ");
    ui->labelFont->setStyleSheet("font: Normal 9pt \"宋体\"; ");
    myParent->setDefaultFont();
    g_textColor.setRgb(0,0,0);
    g_textFont = ui->labelFont->font();
}
