#ifndef FORMARTICULO_H
#define FORMARTICULO_H

#include <QWidget>
#include <QDialog>
#include <QListWidgetItem>
#include "formmaestro.h"
#include "../Extras/visorimagenes.h"
namespace Ui {
class FormArticulo;
}

class FormArticulo : public QDialog, FormMaestro
{
    Q_OBJECT

public:
    explicit FormArticulo(QWidget *parent = 0);
    ~FormArticulo();
signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    QString CodigoImagen;
    Ui::FormArticulo *ui;

    QMap<QString, ObjetoMaestro*>* MapaTipo;
    QMap<QString, ObjetoMaestro*>* MapaMarca;
    QMap<QString, ObjetoMaestro*>* MapaModelo;
    QMap<QString, ObjetoMaestro*>* MapaUnidad;
    QMap<QString, ObjetoMaestro*>* MapaMoneda;

    Articulo                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Articulo                        Antiguo;
    FabricaArticulos*               Fab;
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
private slots:

    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Codigo, QString Cadena);
    void CargarCombos();
    /*-------------------------*/


    // FormMaestro interface
    void on_ButtonGuardar_clicked();

    void on_ButtonModificar_clicked();

    void on_ButtonEliminar_clicked();

    void on_ButtonRegresar_clicked();

    void on_ButtonArchivoImagen_clicked();

    void on_ComboTipo_currentTextChanged(const QString &arg1);


    void on_ComboModelo_currentTextChanged(const QString &arg1);

    void on_ComboMarca_currentTextChanged(const QString &arg1);

    void on_ComboMoneda_currentTextChanged(const QString &arg1);

    void on_ComboUnidad_currentTextChanged(const QString &arg1);

public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);
};

#endif // FORMARTICULO_H
