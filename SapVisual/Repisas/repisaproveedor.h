#ifndef REPISAPROVEEDOR_H
#define REPISAPROVEEDOR_H

#include "repisa.h"
#include "../Fabricas/fabricaproveedor.h"
//#include "../Formularios/formproveedor.h"
class RepisaProveedor:public Repisa
{
private:
    FabricaProveedor*       FabricaLocal;
   // FormProveedor*          Dialogo;
public:
    RepisaProveedor();

    // Repisa interface
protected:
    void ConsultarBusqueda();

private slots:
    void GrupoBotonesClick(QAbstractButton *buttonID);

public slots:
    void NuevoClick();
    void BuscarClick();

public:
    void ObtenerConsulta();
    void ObjetosIndependientes();
    void ActualizarConsulta();
};

#endif // REPISAPROVEEDOR_H
