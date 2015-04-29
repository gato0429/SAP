#ifndef REPISAARTICULOALIAS_H
#define REPISAARTICULOALIAS_H
#include "repisa.h"
#include "../Formularios/formarticuloalias.h"
class RepisaArticuloAlias:public Repisa
{
private:
    FabricaArticulos*         FabricaLocal;
    FormArticuloAlias*       Dialogo;
  //  BusquedaMaestra*        Busqueda;
public:
    RepisaArticuloAlias();

    // Repisa interface
private slots:
    void GrupoBotonesClick(QAbstractButton *buttonID);

public slots:
    void NuevoClick();
    void BuscarClick();

public:
    void ObjetosIndependientes();
    void ActualizarConsulta();
};

#endif // REPISAARTICULOALIAS_H
