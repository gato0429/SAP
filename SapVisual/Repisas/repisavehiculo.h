#ifndef REPISAVEHICULO_H
#define REPISAVEHICULO_H

#include "repisa.h"
#include "../Fabricas/fabricavehiculo.h"
//#include "../Formularios/formvehiculo.h"
class RepisaVehiculo:public Repisa
{
private:
    FabricaVehiculo*       FabricaLocal;
   // Formvehiculo*          Dialogo;
public:
    RepisaVehiculo();

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

#endif // REPISAVEHICULO_H
