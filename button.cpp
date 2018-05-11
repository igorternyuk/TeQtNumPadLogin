#include "button.hpp"
#define BTN_SIZE 100
#define POWDER_BLUE "#b0e0e6"

Button::Button(QWidget *parent)
    :QPushButton(parent)
{
    this->setFixedSize(BTN_SIZE, BTN_SIZE);
    connect(this, &Button::clicked, [&](){
        emit keyWasPressed(this->text());
    });
    auto pal = this->palette();
    pal.setColor(QPalette::Button, QColor(POWDER_BLUE));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}
