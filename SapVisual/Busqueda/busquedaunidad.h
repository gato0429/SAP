#ifndef BUSQUEDAUNIDAD_H
#define BUSQUEDAUNIDAD_H
#include "busquedamaestra.h"
#include "../Fabricas/fabricaunidades.h"

class BusquedaUnidad:public BusquedaMaestra
{

public:
    BusquedaUnidad(QWidget *parent = 0);

    // BusquedaMaestra interface
public:

    void IniciarCampos();
};

#endif // BUSQUEDAUNIDAD_H
