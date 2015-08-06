#ifndef FORMVEHICULOTIPO_H
#define FORMVEHICULOTIPO_H

#include <QDialog>
#include <QWidget>
#include "formmaestro.h"
#include "../Fabricas/fabricavehiculotipo.h"
namespace Ui {
class FormVehiculoTipo;
}

class FormVehiculoTipo : public QDialog,FormMaestro
{
    Q_OBJECT
signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    VehiculoTipo                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    VehiculoTipo                        Antiguo;
    FabricaVehiculoTipo*                Fab;
        QString CodigoImagen;
public:
    explicit FormVehiculoTipo(QWidget *parent = 0);
    ~FormVehiculoTipo();

private slots:
        /*Agregar esto para cada ves que se desee llamar una imagen*/
        void Ruta(QString Codigo,QString Cadena);
        /*-------------------------*/
    void on_ButtonGuardar_clicked();

    void on_ButtonModificar_clicked();

    void on_ButtonEliminar_clicked();

    void on_ButtonRegresar_clicked();

    void on_ButtonArchivoImagen_clicked();

private:
    Ui::FormVehiculoTipo *ui;

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

#endif // FORMVEHICULOTIPO_H
