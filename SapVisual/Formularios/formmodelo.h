#ifndef FORMMODELO_H
#define FORMMODELO_H

#include <QWidget>
#include "formmaestro.h"
#include "../Fabricas/fabricamodelo.h"

namespace Ui {
class FormModelo;
}

class FormModelo :  public QDialog,FormMaestro
{
    Q_OBJECT

signals:
    void ActivarBoton(QString);
    void ActualizarRepisa(ObjetoMaestro* );
private:
    Modelo                       Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    Modelo                        Antiguo;
    FabricaModelo*                Fab;
        QString CodigoImagen;

public:
    explicit FormModelo(QWidget *parent = 0);
    ~FormModelo();

private slots:
    void on_ButtonGuardar_clicked();

    void on_ButtonModificar_clicked();

    void on_ButtonEliminar_clicked();

    void on_ButtonRegresar_clicked();

    void on_ButtonArchivoImagen_clicked();

private:
    Ui::FormModelo *ui;

    // FormMaestro interface
public:
    void SetObjeto(ObjetoMaestro *ObjetoTipo);

protected:
    bool Guardar();
    bool Modificar();
    bool Eliminar();
    bool ValidarCampos();
    void AsignarCampos();
};

#endif // FORMMODELO_H
