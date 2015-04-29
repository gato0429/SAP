#include "fabricabasedatos.h"

FabricaBaseDatos* FabricaBaseDatos::Unico=0;

FabricaBaseDatos::FabricaBaseDatos(BASEDATOS tipo)
{
    switch (tipo) {
    case POSTGRES:
            Fabrica=new Postgres();
        break;
    case MONGO:

        break;
    default:
        break;
    }
}

FabricaBaseDatos *FabricaBaseDatos::IniciarFabrica(BASEDATOS tipo)
{
    if (!Unico)
    {
        Unico=new FabricaBaseDatos(tipo);
    }
    return Unico;
}


