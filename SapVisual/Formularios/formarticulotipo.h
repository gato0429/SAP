#ifndef FORMARTICULOTIPO_H
#define FORMARTICULOTIPO_H

#include <QWidget>
#include <QDialog>
#include <QListWidgetItem>
#include "formmaestro.h"
#include "../Extras/visorimagenes.h"
namespace Ui {
class FormArticuloTipo;
}


class FormArticuloTipo : public QDialog,FormMaestro
{
    Q_OBJECT

public:
    explicit FormArticuloTipo(QWidget *parent = 0);
    void     SetArticuloTipo(int boton,ArticuloTipo valor);
    ~FormArticuloTipo();

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private slots:
    void on_BotonArchivo_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_guardar_clicked();

    void on_eliminar_clicked();

    void on_modificar_clicked();

    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Codigo,QString Cadena);
    /*-------------------------*/

private:
    Ui::FormArticuloTipo *ui;
    ESTADO Estado;

    QString CodigoImagen;
    ArticuloTipo  Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    ArticuloTipo  Antiguo;
    int idBoton;
    FabricaArticuloTipos*               Fab;
protected:
    void mousePressEvent(QMouseEvent *evt)
    {
        oldPos = evt->globalPos();
    }

    void mouseMoveEvent(QMouseEvent *evt)
    {
        const QPoint delta = evt->globalPos() - oldPos;
        move(x()+delta.x(), y()+delta.y());
        oldPos = evt->globalPos();
    }

private:
    QPoint oldPos;



    // FormMaestro interface
protected:
    bool Guardar();
    bool Modificar();
    bool Eliminar();
    bool ValidarCampos();
    void AsignarCampos();

    // FormMaestro interface
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);
};



#endif // FORMARTICULOTIPO_H
