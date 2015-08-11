#ifndef FORMOPERACIONES_H
#define FORMOPERACIONES_H

#include <QDialog>
#include <QWidget>
#include "formmaestro.h"
#include "../Fabricas/fabricaoperaciones.h"
namespace Ui {
class FormOperaciones;
}

class FormOperaciones : public QDialog,FormMaestro
{
    Q_OBJECT

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    Operaciones                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Operaciones                       Antiguo;
    FabricaOperaciones*                Fab;
        QString CodigoImagen;

public:
    explicit FormOperaciones(QWidget *parent = 0);
    ~FormOperaciones();

private:
    Ui::FormOperaciones *ui;

    // FormMaestro interface
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);

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

private slots:
    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Codigo,QString Cadena);
    /*-------------------------*/
    void on_ButtonGuardar_clicked();
    void on_ButtonModificar_clicked();
    void on_ButtonEliminar_clicked();
    void on_ButtonRegresar_clicked();
    void on_ButtonArchivoImagen_clicked();
};

#endif // FORMOPERACIONES_H
