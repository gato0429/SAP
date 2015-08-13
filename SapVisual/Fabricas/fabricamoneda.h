#ifndef FABRICAMONEDA_H
#define FABRICAMONEDA_H

#include "../Objetos/moneda.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaMoneda
{
public:
    FabricaMoneda();
public:
    QList<ObjetoMaestro *> *MapaRepisaGlobal;
    virtual     bool Borrar(Moneda valor)=0;
    virtual     bool Insertar(Moneda valor)=0;
    virtual     bool Actualizar(Moneda Antiguo, Moneda Nuevo)=0;
    virtual     Moneda Buscar(Moneda valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Moneda valor,QString Extra,CONSULTA tipo)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarClave()=0;

};

#endif // FABRICAMONEDA_H
