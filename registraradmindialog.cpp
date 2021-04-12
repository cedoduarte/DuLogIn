#include "registraradmindialog.h"
#include "ui_registraradmindialog.h"
#include <QMessageBox>

RegistrarAdminDialog::RegistrarAdminDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegistrarAdminDialog)
    , mAdmin(-1, "", "")
{
    ui->setupUi(this);
    ui->contrasenyaLineEdit->setEchoMode(QLineEdit::Password);
    ui->repiteContrasenyaLineEdit->setEchoMode(QLineEdit::Password);
}

RegistrarAdminDialog::~RegistrarAdminDialog()
{
    delete ui;
}

QCheckBox *RegistrarAdminDialog::getAdminCheckBox() const
{
    return ui->adminCheckBox;
}

void RegistrarAdminDialog::on_buttonBox_accepted()
{
    mAdmin.setId(1);
    mAdmin.setNombre(ui->usuarioLineEdit->text());
    mAdmin.setContrasenya(ui->contrasenyaLineEdit->text());
    if (mAdmin.contrasenya() != ui->repiteContrasenyaLineEdit->text()) {
        QMessageBox::critical(this, "Error",
                "Las contraseñas deben ser iguales");
        return;
    }
    accept();
}

void RegistrarAdminDialog::on_buttonBox_rejected()
{
    reject();
}
