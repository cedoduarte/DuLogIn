#ifndef CONTROLUSUARIOSFORM_H
#define CONTROLUSUARIOSFORM_H

#include <QWidget>

namespace Ui
{
class ControlUsuariosForm;
}

class QSqlTableModel;

class ControlUsuariosForm : public QWidget
{
    Q_OBJECT
public:
    explicit ControlUsuariosForm(QWidget *parent = nullptr);
    ~ControlUsuariosForm();
private slots:
    void on_tableViewAdmin_clicked(const QModelIndex &index);
    void on_agregarPushButton_clicked();
    void on_tableViewUsuario_clicked(const QModelIndex &index);
private:
    Ui::ControlUsuariosForm *ui;
    QSqlTableModel *mModelUsuario;
    QSqlTableModel *mModelAdmin;
};

#endif // CONTROLUSUARIOSFORM_H
