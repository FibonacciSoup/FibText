#ifndef MYTESTWIDGET_H
#define MYTESTWIDGET_H

#include <QWidget>

namespace Ui {
class myTestWidget;
}

class myTestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myTestWidget(QWidget *parent = 0);
    ~myTestWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::myTestWidget *ui;
};

#endif // MYTESTWIDGET_H
