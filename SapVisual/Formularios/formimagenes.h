#ifndef FORMIMAGENES_H
#define FORMIMAGENES_H

#include <QWidget>
#include "formmaestro.h"
#include "../Repisas/repisaimagenes.h"
namespace Ui {
class FormImagenes;
}
class RepisaImagenes;
class FormImagenes : public QDialog,FormMaestro
{
    Q_OBJECT

public:
    explicit FormImagenes(QWidget *parent = 0);
    ~FormImagenes();
signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    Ui::FormImagenes *ui;
    QString fileName;
    QMap<QString,int> ListaCarpetas;
    QTreeWidgetItem*  CarpetaActual;
    ESTADO Estado;

    RepisaImagenes* mRepisa;

    FabricaImagenes* Fab;
    Imagen          Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Imagen          Antiguo;

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

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_BotonImagen_clicked();

    void on_BotonCarpetaAgregar_4_clicked();


    void on_ButtonGuardar_clicked();

    void on_ButtonModificar_clicked();

    void on_ButtonEliminar_clicked();

    void on_ButtonRegresar_clicked();

private:
    QPoint oldPos;

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
};

#endif // FORMIMAGENES_H
