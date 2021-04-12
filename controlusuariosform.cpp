#include "controlusuariosform.h"
#include "ui_controlusuariosform.h"
#include "DuCrypt.h"
#include "dialog.h"
#include "registraradmindialog.h"
#include <QSqlTableModel>
#include <QCheckBox>
#include <QSqlQuery>

ControlUsuariosForm::ControlUsuariosForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ControlUsuariosForm)
{
    ui->setupUi(this);
    mModelUsuario = new QSqlTableModel(this);
    mModelUsuario->setTable("usuario");
    mModelUsuario->select();
    mModelUsuario->setHeaderData(0, Qt::Horizontal, "ID Usuario");
    mModelUsuario->setHeaderData(1, Qt::Horizontal, "Nombre Usuario");
    mModelUsuario->setHeaderData(2, Qt::Horizontal, "Contraseña Usuario");
    ui->tableViewUsuario->setModel(mModelUsuario);
    mModelAdmin = new QSqlTableModel(this);
    mModelAdmin->setTable("administrador");
    mModelAdmin->select();
    mModelAdmin->setHeaderData(0, Qt::Horizontal, "ID Admin");
    mModelAdmin->setHeaderData(1, Qt::Horizontal, "Nombre Admin");
    mModelAdmin->setHeaderData(2, Qt::Horizontal, "Contraseña Admin");
    ui->tableViewAdmin->setModel(mModelAdmin);
}

ControlUsuariosForm::~ControlUsuariosForm()
{
    delete ui;
}

void ControlUsuariosForm::on_tableViewAdmin_clicked(const QModelIndex &index)
{
    DuCrypt k;
    k.setPassword(Dialog::generaContrasenya());
    k.setSalt(Dialog::generaContrasenya());
    auto valor = k.decrypt(index.data().toString());
    ui->valorLineEdit->setText(valor);
}

void ControlUsuariosForm::on_agregarPushButton_clicked()
{
    RegistrarAdminDialog d(this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    DuCrypt k;
    k.setPassword(Dialog::generaContrasenya());
    k.setSalt(Dialog::generaContrasenya());

    auto admin = d.getAdmin();
    QSqlQuery q;
    q.exec(QString("INSERT INTO %1 "
                   "(nombre, contrasenya) VALUES ('%2','%3')")
           .arg(d.getAdminCheckBox()->isChecked() ? "administrador" : "usuario")
           .arg(k.encrypt(admin.nombre()))
           .arg(k.encrypt(admin.contrasenya())));
    mModelAdmin->select();
    mModelUsuario->select();
}

void ControlUsuariosForm::on_tableViewUsuario_clicked(const QModelIndex &index)
{
    on_tableViewAdmin_clicked(index);
}
