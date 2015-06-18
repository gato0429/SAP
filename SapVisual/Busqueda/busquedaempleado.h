#ifndef BUSQUEDAEMPLEADO_H
#define BUSQUEDAEMPLEADO_H
#include "busquedamaestra.h"
#include "../Fabricas/fabricaempleados.h"
class BusquedaEmpleado:public BusquedaMaestra
{
private:

public:
    BusquedaEmpleado(QWidget *parent = 0);

    // BusquedaMaestra interface
public:

    void IniciarCampos();

};

#endif // BUSQUEDAEMPLEADO_H
