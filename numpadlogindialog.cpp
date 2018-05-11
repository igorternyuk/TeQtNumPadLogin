#include "numpadlogindialog.hpp"
#include "button.hpp"
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QGridLayout>
//#include <QDebug>

#define MARGIN 5
#define LCD_HEIGHT 100
#define PASSWORD 12345

NumPadLoginDialog::NumPadLoginDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setFixedSize(BTN_SIZE * 3 + 8 * MARGIN,
                       (BTN_SIZE + MARGIN) * 4 + MARGIN + LCD_HEIGHT + 8 * MARGIN);
    mDisplay = new QLCDNumber(10, this);
    mDisplay->setFixedSize((BTN_SIZE  + MARGIN) * 3 - MARGIN / 2, LCD_HEIGHT);
    mDisplay->setAutoFillBackground(true);
    mDisplay->setSegmentStyle(QLCDNumber::Flat);
    auto lcdPal = mDisplay->palette();
    lcdPal.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
    lcdPal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    mDisplay->setPalette(lcdPal);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *grid = new QGridLayout(this);
    for(int y = 0; y < 4; ++y)
    {
        for(int x = 0; x < 3; ++x)
        {
            if(x == 0 && y == 3)
            {
                auto btnClear = new QPushButton(this);
                btnClear->setText("CLEAR");
                btnClear->setFixedSize(BTN_SIZE, BTN_SIZE);
                btnClear->setFont(QFont("Arial", 18));
                connect(btnClear, &QPushButton::clicked, this,
                        &NumPadLoginDialog::on_btnClear_clicked);
                grid->addWidget(btnClear, 3, 0);
            }
            else if(x == 2 && y == 3)
            {
                auto btnEnter = new QPushButton(this);
                btnEnter->setText("ENTER");
                btnEnter->setFixedSize(BTN_SIZE, BTN_SIZE);
                btnEnter->setFont(QFont("Arial", 18));
                connect(btnEnter, &QPushButton::clicked, this,
                        &NumPadLoginDialog::on_btnEnter_clicked);
                grid->addWidget(btnEnter, 3, 2);
            }
            else
            {
                auto numBtn = new Button(this);
                auto text = (x == 1 && y == 3)
                        ? "0"
                        : QString::number(7 - 3 * y + x);
                numBtn->setText(text);
                numBtn->setFont(QFont("Arial", 36));
                connect(numBtn, &Button::keyWasPressed, this,
                        &NumPadLoginDialog::onKeyClicked);
                grid->addWidget(numBtn, y, x);
            }
        }
    }
    mainLayout->addWidget(mDisplay);
    mainLayout->addLayout(grid);
    this->setLayout(mainLayout);
}

void NumPadLoginDialog::on_btnClear_clicked()
{
    mDisplay->display(0);
}

void NumPadLoginDialog::on_btnEnter_clicked()
{
    if(checkCode())
        accept();
    else
        reject();
}

void NumPadLoginDialog::onKeyClicked(const QString &keyText)
{
    auto currText = QString::number(mDisplay->value());
    currText += keyText;
    mDisplay->display(currText);
}

bool NumPadLoginDialog::checkCode()
{
    if(mDisplay->value() == PASSWORD)
    {
        return true;
    }
    QFile file("codes.txt");
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while(!in.atEnd()) {
            QString line = in.readLine();
            int val = line.toInt();
            if(mDisplay->value() == val)
            {
                return true;
            }
        }
        file.close();
    }
    return false;
}
