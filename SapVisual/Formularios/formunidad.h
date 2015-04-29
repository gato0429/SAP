#ifndef FORMUNIDAD_H
#define FORMUNIDAD_H

#include <QDialog>
#include "formmaestro.h"
namespace Ui {
class FormUnidad;
}

class FormUnidad : public QDialog,FormMaestro
{
    Q_OBJECT

public:
    explicit FormUnidad(QWidget *parent = 0);
    void SetObjeto(Unidad valor);
    ~FormUnidad();

    /*-------------------------*/

signals:
    void ActualizarRepisa(ObjetoMaestro* );

private:
    Ui::FormUnidad *ui;

    ESTADO Estado;

    QString CodigoImagen;
    Unidad  Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Unidad  Antiguo;
    FabricaUnidades*               Fab;



protected:
    bool Guardar();
    bool Modificar();
    bool Eliminar();
    bool ValidarCampos();
    void AsignarCampos();
private slots:
    void on_guardar_clicked();
    void on_modificar_clicked();
    void on_eliminar_clicked();
    void on_tabWidget_tabBarClicked(int index);

    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Codigo,QString Cadena);
    void on_BotonArchivo_clicked();

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

#endif // FORMUNIDAD_H
