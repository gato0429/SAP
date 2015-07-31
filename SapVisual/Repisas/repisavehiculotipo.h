#ifndef REPISAVEHICULOTIPO_H
#define REPISAVEHICULOTIPO_H

#include "repisa.h"
#include "../Fabricas/fabricavehiculotipo.h"
#include "../Formularios/formvehiculotipo.h"
class RepisaVehiculoTipo:public Repisa
{
private:
    FabricaVehiculoTipo*       FabricaLocal;
    FormVehiculoTipo*          Dialogo;
public:
    RepisaVehiculoTipo();
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

#endif // REPISAVEHICULOTIPO_H
