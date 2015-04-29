#ifndef REPISAARTICULOTIPO_H
#define REPISAARTICULOTIPO_H

#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaarticulotipos.h"
#include "../Formularios/formarticulotipo.h"
#include "../Busqueda/busquedaarticulotipo.h"

class RepisaArticuloTipo:public Repisa
{
private:
  FabricaArticuloTipos*         FabricaLocal;
  FormArticuloTipo*       Dialogo;
  BusquedaMaestra*        Busqueda;

public:
    RepisaArticuloTipo();
    void ActualizarConsulta();
    void ObjetosIndependientes();
public slots:
    void NuevoClick();
    void BuscarClick();
    void GrupoBotonesClick(QAbstractButton *buttonID);
};

#endif // REPISAARTICULOTIPO_H
