#ifndef REPISAEMPLEADOS_H
#define REPISAEMPLEADOS_H
#include "repisa.h"
#include "../Busqueda/busquedaempleado.h"
#include "../Fabricas/fabricaempleados.h"
#include "../Formularios/formempleado.h"
#include <QDebug>
class RepisaEmpleados:public Repisa
{

private:
    FabricaEmpleados*         FabricaLocal;
    FormEmpleado*             Dialogo;

public:
    RepisaEmpleados();

    // Repisa interface
private slots:
    void GrupoBotonesClick(QAbstractButton *buttonID);
public slots:
    void NuevoClick();
    void BuscarClick();

public:
    void ObjetosIndependientes();
    void ActualizarConsulta();
    void ObtenerConsulta();
    void ConsultarBusqueda();
};

#endif // REPISAEMPLEADOS_H
