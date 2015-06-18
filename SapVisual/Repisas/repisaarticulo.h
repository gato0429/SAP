#ifndef REPISAARTICULO_H
#define REPISAARTICULO_H
#include "repisa.h"

#include "../Fabricas/fabricaarticulos.h"
#include "../Formularios/formarticulo.h"
#include "../Busqueda/busquedaarticulo.h"
class RepisaArticulo:public Repisa
{
private:
    FabricaArticulos*         FabricaLocal;
    FormArticulo*         Dialogo;
    BusquedaMaestra*        Busqueda;
public:
    RepisaArticulo();

    // Repisa interface
public:
    void ObjetosIndependientes();
    void ActualizarConsulta();
public slots:
    void GrupoBotonesClick(QAbstractButton* buttonID);
    void NuevoClick();
    void BuscarClick();

    // Repisa interface
private slots:
    void RecibirTipoConsulta(int index, bool detalle, int registros);

public:
    void ObtenerConsulta();
};

#endif // REPISAARTICULO_H
