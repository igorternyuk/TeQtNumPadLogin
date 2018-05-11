#ifndef NUMPADLOGINDIALOG_HPP
#define NUMPADLOGINDIALOG_HPP

#include <QDialog>

namespace Ui
{
    class NumPadLoginDialog;
}

class NumPadLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumPadLoginDialog(QWidget *parent = nullptr);
    ~NumPadLoginDialog();

private slots:
    void on_btnClear_clicked();
    void on_btnEnter_clicked();
    void onKeyClicked(const QString* text);
private:
    void connectKeys();
    Ui::NumPadLoginDialog *ui;
};

#endif // NUMPADLOGINDIALOG_HPP
