#ifndef FORMCLIENTETIPO_H
#define FORMCLIENTETIPO_H

#include <QDialog>
#include <QWidget>
#include "formmaestro.h"
#include "../Fabricas/fabricaclientetipo.h"

namespace Ui {
class FormClienteTipo;
}

class FormClienteTipo : public QDialog,FormMaestro
{
    Q_OBJECT

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );

public:
    explicit FormClienteTipo(QWidget *parent = 0);
    ~FormClienteTipo();
private:
    ClienteTipo                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    ClienteTipo                        Antiguo;
    FabricaClienteTipo*                Fab;
        QString CodigoImagen;

private:
    Ui::FormClienteTipo *ui;

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
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);
private slots:
    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Codigo,QString Cadena);
    /*-------------------------*/
    void on_ButtonGuardar_clicked();
    void on_ButtonModificar_clicked();
    void on_ButtonEliminar_clicked();
    void on_ButtonRegresar_clicked();
    void on_ButtonArchivoImagen_clicked();
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

};

#endif // FORMCLIENTETIPO_H
