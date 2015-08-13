#ifndef FORMCLIENTE_H
#define FORMCLIENTE_H

#include <QDialog>
#include "../Formularios/formmaestro.h"
namespace Ui {
class FormCliente;
}

class FormCliente : public QDialog,FormMaestro
{
    Q_OBJECT
signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );

public:
    explicit FormCliente(QWidget *parent = 0);
    ~FormCliente();

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
    Ui::FormCliente *ui;
    Cliente                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Cliente                        Antiguo;
    FabricaClientes*               Fab;
    QString CodigoImagen;
    QMap<QString, ObjetoMaestro*>* MapaTipo;

    // FormMaestro interface
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);
    void CargarCombos();
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
};

#endif // FORMCLIENTE_H
