#ifndef FORMARTICULOALIAS_H
#define FORMARTICULOALIAS_H

#include <QWidget>
#include <QDialog>
#include <QListWidgetItem>
#include "formmaestro.h"
#include "../Extras/visorimagenes.h"

namespace Ui {
class FormArticuloAlias;
}

class FormArticuloAlias : public QDialog,FormMaestro
{
    Q_OBJECT

private:
    ArticuloAlias                        Objeto;   //Cada Form trabaja con su objeto nuevo y antiguo
    ArticuloAlias                        Antiguo;
    FabricaArticuloAlias*               Fab;
public:
    explicit FormArticuloAlias(QWidget *parent = 0);
    ~FormArticuloAlias();
    void SetArticulo(Articulo Externo);
private:
    Ui::FormArticuloAlias *ui;

    // FormMaestro interface
protected:
    bool Guardar();
    bool Modificar();
    bool Eliminar();
    bool ValidarCampos();
    void AsignarCampos();
private slots:
    void on_eliminar_clicked();
    void on_modificar_clicked();
    void on_guardar_clicked();
};

#endif // FORMARTICULOALIAS_H
