#ifndef REPISAESTADO_H
#define REPISAESTADO_H

#include "repisa.h"
#include "../Fabricas/fabricaestado.h"
#include "../Formularios/formestado.h"

class RepisaEstado:public Repisa
{
private:
    FabricaEstado*       FabricaLocal;
    FormEstado*          Dialogo;
public:
    RepisaEstado();

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

#endif // REPISAESTADO_H
