#ifndef FORMESTADO_H
#define FORMESTADO_H
#include <QWidget>
#include "formmaestro.h"
#include "../Fabricas/fabricaestado.h"
#include <QDialog>

namespace Ui {
class FormEstado;
}

class FormEstado : public QDialog,FormMaestro
{
    Q_OBJECT

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    Estado                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Estado                        Antiguo;
    FabricaEstado*                Fab;
    QString CodigoImagen;
public:
    explicit FormEstado(QWidget *parent = 0);
    ~FormEstado();

private:
    Ui::FormEstado *ui;

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

#endif // FORMESTADO_H
