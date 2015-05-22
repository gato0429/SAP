#ifndef FABRICAUNIDADES_H
#define FABRICAUNIDADES_H

#include "../Objetos/unidad.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;


class FabricaUnidades
{
public:
    FabricaUnidades();
public:

    virtual     bool Borrar(Unidad valor)=0;
    virtual     bool Insertar(Unidad valor)=0;
    virtual     bool Actualizar(Unidad Antiguo, Unidad Nuevo)=0;
    virtual     Unidad Buscar(Unidad valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Unidad)=0;
    virtual int Contar()=0;
    virtual int ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Unidad valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAUNIDADES_H
