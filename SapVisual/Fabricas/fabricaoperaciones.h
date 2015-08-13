#ifndef FABRICAOPERACIONES_H
#define FABRICAOPERACIONES_H

#include "../Objetos/operaciones.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;
class FabricaOperaciones
{
public:
    FabricaOperaciones();
public:
    QList<ObjetoMaestro *> *MapaRepisaGlobal;
    virtual     bool Borrar(Operaciones valor)=0;
    virtual     bool Insertar(Operaciones valor)=0;
    virtual     bool Actualizar(Operaciones Antiguo, Operaciones Nuevo)=0;
    virtual     Operaciones Buscar(Operaciones valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Operaciones valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAOPERACIONES_H
