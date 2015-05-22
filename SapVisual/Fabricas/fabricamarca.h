#ifndef FABRICAMARCA_H
#define FABRICAMARCA_H

#include "../Objetos/marca.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaMarca
{
public:
    FabricaMarca();
public:
    virtual     bool Borrar(Marca valor)=0;
    virtual     bool Insertar(Marca valor)=0;
    virtual     bool Actualizar(Marca Antiguo, Marca Nuevo)=0;
    virtual     Marca Buscar(Marca valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Marca)=0;
    virtual int Contar()=0;
    virtual int ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Marca valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAMARCA_H
