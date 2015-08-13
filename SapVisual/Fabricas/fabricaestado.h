#ifndef FABRICAESTADO_H
#define FABRICAESTADO_H

#include "../Objetos/estado.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;
class FabricaEstado
{
public:
    FabricaEstado();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Estado valor)=0;
    virtual     bool Insertar(Estado valor)=0;
    virtual     bool Actualizar(Estado Antiguo, Estado Nuevo)=0;
    virtual     Estado Buscar(Estado valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Estado valor,QString Extra,CONSULTA tipo)=0;
    virtual QMap<QString,QString>* BuscarClave()=0;

};

#endif // FABRICAESTADO_H
