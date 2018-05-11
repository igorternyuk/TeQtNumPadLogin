#ifndef NUMPADLOGINDIALOG_HPP
#define NUMPADLOGINDIALOG_HPP

#include <QDialog>
#include <QLCDNumber>

class Button;
class NumPadLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumPadLoginDialog(QWidget *parent = nullptr);

private slots:
    void on_btnClear_clicked();
    void on_btnEnter_clicked();
    void onKeyClicked(const QString &text);
private:
    bool checkCode();
    QLCDNumber *mDisplay;
    QList<Button*> mNumButtons;
};

#endif // NUMPADLOGINDIALOG_HPP
