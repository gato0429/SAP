#ifndef BUSQUEDAARTICULOTIPO_H
#define BUSQUEDAARTICULOTIPO_H
#include "busquedamaestra.h"
#include "../Fabricas/fabricaarticulotipos.h"
class BusquedaArticuloTipo:public BusquedaMaestra
{
private:

public:
    BusquedaArticuloTipo(QWidget *parent = 0);

    // BusquedaMaestra interface
public:

    void IniciarCampos();
};

#endif // BUSQUEDAARTICULOTIPO_H
