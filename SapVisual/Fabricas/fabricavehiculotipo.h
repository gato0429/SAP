#ifndef FABRICAVEHICULOTIPO_H
#define FABRICAVEHICULOTIPO_H

#include "../Objetos/vehiculotipo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaVehiculoTipo
{
public:
    FabricaVehiculoTipo();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(VehiculoTipo valor)=0;
    virtual     bool Insertar(VehiculoTipo valor)=0;
    virtual     bool Actualizar(VehiculoTipo Antiguo, VehiculoTipo Nuevo)=0;
    virtual     VehiculoTipo Buscar(VehiculoTipo valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(VehiculoTipo valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAVEHICULOTIPO_H
