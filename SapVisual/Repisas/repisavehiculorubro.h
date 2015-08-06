#ifndef REPISAVEHICULORUBRO_H
#define REPISAVEHICULORUBRO_H

#include "repisa.h"
#include "../Fabricas/fabricavehiculorubro.h"
#include "../Formularios/formvehiculorubro.h"
class RepisaVehiculoRubro:public Repisa
{
private:
    FabricaVehiculoRubro*       FabricaLocal;
    FormVehiculoRubro*          Dialogo;
public:
    RepisaVehiculoRubro();


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

#endif // REPISAVEHICULORUBRO_H
