#ifndef FORMMARCA_H
#define FORMMARCA_H

#include <QWidget>
#include "formmaestro.h"
#include "../Fabricas/fabricamarca.h"
namespace Ui {
class FormMarca;
}

class FormMarca : public QDialog,FormMaestro
{
    Q_OBJECT

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    Marca                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Marca                        Antiguo;
    FabricaMarca*                Fab;
        QString CodigoImagen;
public:

    explicit FormMarca(QWidget *parent = 0);
    ~FormMarca();

private:
    Ui::FormMarca *ui;

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

#endif // FORMMARCA_H
