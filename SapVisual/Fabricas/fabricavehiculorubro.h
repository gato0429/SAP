#ifndef FABRICAVEHICULORUBRO_H
#define FABRICAVEHICULORUBRO_H

#include "../Objetos/vehiculorubro.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaVehiculoRubro
{
public:
    FabricaVehiculoRubro();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(VehiculoRubro valor)=0;
    virtual     bool Insertar(VehiculoRubro valor)=0;
    virtual     bool Actualizar(VehiculoRubro Antiguo, VehiculoRubro Nuevo)=0;
    virtual     VehiculoRubro Buscar(VehiculoRubro valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(VehiculoRubro valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAVEHICULORUBRO_H
