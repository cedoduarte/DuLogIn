#include "dialog.h"
#include "ui_dialog.h"
#include "registraradmindialog.h"
#include "DuCrypt.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QCheckBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->contrasenyaLineEdit->setEchoMode(QLineEdit::Password);
    compruebaAdmin();
    ui->usuarioNormalRadioButton->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    DuCrypt k;
    k.setPassword(generaContrasenya());
    k.setSalt(generaContrasenya());
    QSqlQuery q;
    Usuario u(-1, ui->usuarioLineEdit->text(), ui->contrasenyaLineEdit->text());
    int cantidad;
    bool esUsuario;
    if (ui->usuarioNormalRadioButton->isChecked()) {
        q.exec(QString("SELECT count(*) FROM usuario WHERE nombre LIKE '%1' "
                       "AND contrasenya LIKE '%2'").arg(k.encrypt(u.nombre()))
               .arg(k.encrypt(u.contrasenya())));
        q.next();
        cantidad = q.value(0).toInt();
        if (cantidad == 0) {
            QMessageBox::warning(this, "Aviso",
                                 "Usuario o contraseña incorrectos");
            return;
        }
        esUsuario = true;
    } else {
        q.exec(QString("SELECT count(*) FROM administrador WHERE nombre "
                       "LIKE '%1' AND contrasenya LIKE '%2'")
               .arg(k.encrypt(u.nombre()))
               .arg(k.encrypt(u.contrasenya())));
        q.next();
        cantidad = q.value(0).toInt();
        if (cantidad == 0) {
            QMessageBox::warning(this, "Aviso",
                                 "Usuario o contraseña incorrectos");
            return;
        }
        esUsuario = false;
    }
    if (esUsuario) {
        mTipo = USUARIO;
    } else {
        mTipo = ADMINISTRADOR;
    }
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_registrarAdminPushButton_clicked()
{
    RegistrarAdminDialog d(this);
    auto adminCheckBox = d.getAdminCheckBox();
    adminCheckBox->setChecked(true);
    adminCheckBox->setEnabled(false);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    DuCrypt k;
    k.setPassword(generaContrasenya());
    k.setSalt(generaContrasenya());

    auto admin = d.getAdmin();
    QSqlQuery q;
    q.exec(QString("INSERT INTO administrador "
                   "(nombre, contrasenya) VALUES ('%1','%2')")
           .arg(k.encrypt(admin.nombre()))
           .arg(k.encrypt(admin.contrasenya())));
    compruebaAdmin();
}

void Dialog::compruebaAdmin()
{
    QSqlQuery q;
    q.exec("SELECT count(*) FROM administrador");
    q.next();
    const int cantidadAdmins = q.value(0).toInt();
    if (cantidadAdmins == 0) {
        ui->registrarAdminPushButton->setEnabled(true);
    } else {
        ui->registrarAdminPushButton->setEnabled(false);
    }
}

QString Dialog::generaContrasenya()
{
    QString contrasenya
            = "abcdefg1234567890°!#$%&/()=?¡¿;,.-}{[]+´";
    return contrasenya;
}
