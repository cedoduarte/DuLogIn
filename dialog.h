#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    enum Tipo
    {
        USUARIO, ADMINISTRADOR
    };

    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getTipo() const { return mTipo; }
    static QString generaContrasenya();
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_registrarAdminPushButton_clicked();
private:
    void compruebaAdmin();

    Ui::Dialog *ui;
    int mTipo;
};

#endif // DIALOG_H
