#ifndef BUSQUEDAARTICULO_H
#define BUSQUEDAARTICULO_H
#include "busquedamaestra.h"
#include "../Fabricas/fabricaarticulos.h"
#include "../Fabricas/fabricaarticulotipos.h"

class BusquedaArticulo:public BusquedaMaestra
{
private:

    FabricaArticuloTipos* FabTip;
    FabricaUnidades* FabUni;

    QMap<QString,ObjetoMaestro*>* MapaTipos;
    QMap<QString,ObjetoMaestro*>::iterator itp;

    QMap<QString,ObjetoMaestro*>* MapaUnidad;
    QMap<QString,ObjetoMaestro*>::iterator itu;

    QStringList lista;

    QCompleter*        CompleterTipos;

public:
    BusquedaArticulo(QWidget *parent = 0);

    // BusquedaMaestra interface
public:
    void IniciarCampos();

};

#endif // BUSQUEDAARTICULO_H
