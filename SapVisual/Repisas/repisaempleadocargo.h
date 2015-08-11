#ifndef REPISAEMPLEADOCARGO_H
#define REPISAEMPLEADOCARGO_H
#include "repisa.h"
#include "../Formularios/formempleadocargo.h"
#include "../Fabricas/fabricaempleadocargo.h"


class RepisaEmpleadoCargo : public Repisa
{
private:
    FabricaEmpleadoCargo*       FabricaLocal;
    FormEmpleadoCargo*          Dialogo;
public:
    RepisaEmpleadoCargo();

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

#endif // REPISAEMPLEADOCARGO_H
