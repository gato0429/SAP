#ifndef REPISAEMPLEADOAREA_H
#define REPISAEMPLEADOAREA_H
#include "repisa.h"
#include "../Formularios/formempleadoarea.h"
#include "../Fabricas/fabricaempleadoarea.h"

class RepisaEmpleadoArea : public Repisa
{
private:
    FabricaEmpleadoArea*       FabricaLocal;
    FormEmpleadoArea*          Dialogo;
public:
    RepisaEmpleadoArea();

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

#endif // REPISAEMPLEADOAREA_H
