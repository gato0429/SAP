#ifndef REPISAARTICULO_H
#define REPISAARTICULO_H
#include "repisa.h"

#include "../Fabricas/fabricaarticulos.h"
#include "../Formularios/formarticulo.h"
#include "../Busqueda/busquedaarticulo.h"
#include "../Fabricas/fabricamarca.h"
class RepisaArticulo:public Repisa
{
private:
    FabricaArticulos*         FabricaLocal;
    FormArticulo*         Dialogo;

public:
    RepisaArticulo();


public slots:
    void GrupoBotonesClick(QAbstractButton* buttonID);
    void NuevoClick();
    void BuscarClick();

public:
    void ObtenerConsulta();
    void ObjetosIndependientes();
    void ActualizarConsulta();
    // Repisa interface
protected:
    void ConsultarBusqueda();
};

#endif // REPISAARTICULO_H
