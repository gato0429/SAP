#ifndef FORMEMPLEADO_H
#define FORMEMPLEADO_H

#include <QWidget>
#include <QDialog>
#include <QListWidgetItem>
#include "formmaestro.h"
namespace Ui {
class FormEmpleado;
}

class FormEmpleado : public QDialog, FormMaestro
{
    Q_OBJECT

public:
    explicit FormEmpleado(QWidget *parent = 0);
    ~FormEmpleado();
    void SetEmpleado(Empleado Externo);

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    Ui::FormEmpleado *ui;
    Empleado                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Empleado                        Antiguo;
    FabricaEmpleados*               Fab;
    // FormMaestro interface
protected:
    bool Guardar();
    bool Modificar();
    bool Eliminar();
    bool ValidarCampos();
       void AsignarCampos();
       void Habilitar();
       void Deshabilitar();
       void Limpiar();
    /*Movimiento del Form*/
protected:
    void mousePressEvent(QMouseEvent *evt)
    {
        oldPos = evt->globalPos();
    }

    void mouseMoveEvent(QMouseEvent *evt)
    {
        const QPoint delta = evt->globalPos() - oldPos;
        Form->move(Form->x()+delta.x(), Form->y()+delta.y());
        oldPos = evt->globalPos();
    }

protected:
    QPoint oldPos;

    // FormMaestro interface

private slots:
    void on_BotonGuardar_clicked();
    void on_BotonModificar_clicked();
    void on_BotonEliminar_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_BotonEliminar_2_clicked();

    // FormMaestro interface
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);
};

#endif // FORMEMPLEADO_H
