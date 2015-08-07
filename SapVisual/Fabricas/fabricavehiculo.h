#ifndef FABRICAVEHICULO_H
#define FABRICAVEHICULO_H

#include "../Objetos/vehiculo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaVehiculo
{
public:
    FabricaVehiculo();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Vehiculo valor)=0;
    virtual     bool Insertar(Vehiculo valor)=0;
    virtual     bool Actualizar(Vehiculo Antiguo, Vehiculo Nuevo)=0;
    virtual     Vehiculo Buscar(Vehiculo valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Vehiculo valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAVEHICULO_H
