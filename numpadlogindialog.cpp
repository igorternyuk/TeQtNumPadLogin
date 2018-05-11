#include "numpadlogindialog.hpp"
#include "ui_numpadlogindialog.h"

#define PASSWORD 12345

NumPadLoginDialog::NumPadLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NumPadLoginDialog)
{
    ui->setupUi(this);
    auto lcdPal = ui->lcdNumber->palette();
    lcdPal.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
    lcdPal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    ui->lcdNumber->setPalette(lcdPal);
}

NumPadLoginDialog::~NumPadLoginDialog()
{
    delete ui;
}

void NumPadLoginDialog::on_btnClear_clicked()
{
    ui->lcdNumber->display(0);
}

void NumPadLoginDialog::on_btnEnter_clicked()
{
    if(ui->lcdNumber->value() == PASSWORD)
    {
        accept();
        return;
    }
    reject();
}

void NumPadLoginDialog::onKeyClicked(const QString *text)
{

}

void NumPadLoginDialog::connectKeys()
{

}
