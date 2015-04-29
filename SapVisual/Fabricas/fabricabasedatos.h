#ifndef FABRICABASEDATOS_H
#define FABRICABASEDATOS_H
#include "../Objetos/basedatos.h"
#include "../Postgres/postgres.h"
//#include "../Definiciones.h"


struct Definiciones;
class FabricaBaseDatos
{

private:
    static FabricaBaseDatos    *Unico;
    FabricaBaseDatos(BASEDATOS tipo);

public:
    static FabricaBaseDatos    *IniciarFabrica(BASEDATOS tipo);
    BaseDatos     *Fabrica;


};

#endif // FABRICABASEDATOS_H
