#ifndef FABRICASUCURSALES_H
#define FABRICASUCURSALES_H
#include "../Objetos/sucursales.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;
class FabricaSucursales
{
public:
    FabricaSucursales();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Sucursales valor)=0;
    virtual     bool Insertar(Sucursales valor)=0;
    virtual     bool Actualizar(Sucursales Antiguo, Sucursales Nuevo)=0;
    virtual     Sucursales Buscar(Sucursales valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Sucursales valor,QString Extra,CONSULTA tipo)=0;


};

#endif // FABRICASUCURSALES_H
