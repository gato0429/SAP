#ifndef REPISASUCURSALES_H
#define REPISASUCURSALES_H

#include "repisa.h"
//#include "../Formularios/formsucursales.h"
#include "../Fabricas/fabricasucursales.h"
class RepisaSucursales : public Repisa
{
private:
    FabricaSucursales*       FabricaLocal;
    //FormSucursales*          Dialogo;
public:
    RepisaSucursales();


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

#endif // REPISASUCURSALES_H
