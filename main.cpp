#include "numpadlogindialog.hpp"
#include "mainwindow.hpp"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    NumPadLoginDialog dialog;
    if(dialog.exec() == NumPadLoginDialog::Rejected)
    {
        QMessageBox::critical(&dialog, "Error", "Incorrect code");
        return 0;
    }
    MainWindow window;
    window.show();
    return a.exec();
}
