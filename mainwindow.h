#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(int tipo, QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionBase_de_datos_de_usuarios_triggered();
    void on_actionQuitar_triggered();
    void on_actionAcerca_de_triggered();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
