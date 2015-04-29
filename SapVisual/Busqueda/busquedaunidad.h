#ifndef BUSQUEDAUNIDAD_H
#define BUSQUEDAUNIDAD_H
#include "busquedamaestra.h"
#include "../Fabricas/fabricaunidades.h"

class BusquedaUnidad:public BusquedaMaestra
{
private:
    FabricaUnidades* Fab;
public:
    BusquedaUnidad(QWidget *parent = 0);

    // BusquedaMaestra interface
public:
    void ObtenerConsulta();
    void IniciarCampos();
};

#endif // BUSQUEDAUNIDAD_H
