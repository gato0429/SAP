#ifndef BUSQUEDAEMPLEADO_H
#define BUSQUEDAEMPLEADO_H
#include "busquedamaestra.h"
#include "../Fabricas/fabricaempleados.h"
class BusquedaEmpleado:public BusquedaMaestra
{
private:
    FabricaEmpleados* Fab;
public:
    BusquedaEmpleado(QWidget *parent = 0);

    // BusquedaMaestra interface
public:
    void ObtenerConsulta();
    void IniciarCampos();
    void CambiarCombo(int index);
};

#endif // BUSQUEDAEMPLEADO_H
