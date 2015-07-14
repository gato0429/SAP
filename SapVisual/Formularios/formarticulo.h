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
    void SetArticulo(Articulo Externo);
    ~FormArticulo();
signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    QString CodigoImagen;
    Ui::FormArticulo *ui;
    void LlenarListaTipos();
    void LlenarListaUnidad();


    QMap<QString, ObjetoMaestro*>* MapaTipos;
    QMap<QString, ObjetoMaestro*>::iterator it;

    QMap<QString, ObjetoMaestro*>* MapaUnidad;
    QMap<QString, ObjetoMaestro*>::iterator it_uni;

    QMap<QString, ObjetoMaestro*>* MapaAlias;
    QMap<QString, ObjetoMaestro*>::iterator it_ali;

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
    /*--Esto cambiara en otra version-*/
    FabricaArticuloAlias*               FabAlias;
    bool ValidarCamposAlias();
    void AsignarCamposAlias();
    bool GuardarAlias();
    bool ModificarAlias();
    bool EliminarAlias();
    ArticuloAlias           ObjetoAlias;
    ArticuloAlias           AntiguoAlias;
    ESTADO ESTADOALIAS;
        void LlenarListaAlias(QString CodigoArticulo);
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
    void on_ListaTipo_currentRowChanged(int currentRow);
    void on_LineNombreTipo_returnPressed();
    void on_BotonGuardar_clicked();
    void on_BotonBusquedaImagen_clicked();
    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Codigo, QString Cadena);
    /*-------------------------*/

    void on_BotonModificar_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_ListaUnidad_currentRowChanged(int currentRow);
    void on_LineNombreUnidad_returnPressed();
    void on_BotonGuardarAlias_clicked();
    void on_BotonModificarAlias_clicked();
    void on_BotonEliminarAlias_clicked();
    void on_BotonNuevoAlias_clicked();
    void on_ListaAlias_currentRowChanged(int currentRow);

    // FormMaestro interface
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);
};

#endif // FORMARTICULO_H
