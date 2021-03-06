#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

#define BTN_SIZE 100

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);
signals:
    void keyWasPressed(const QString&);
};

#endif // BUTTON_H
