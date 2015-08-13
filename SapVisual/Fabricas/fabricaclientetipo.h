#ifndef FABRICACLIENTETIPO_H
#define FABRICACLIENTETIPO_H
#include "../Objetos/clientetipo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaClienteTipo
{
public:
    FabricaClienteTipo();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(ClienteTipo valor)=0;
    virtual     bool Insertar(ClienteTipo valor)=0;
    virtual     bool Actualizar(ClienteTipo Antiguo, ClienteTipo Nuevo)=0;
    virtual     ClienteTipo Buscar(ClienteTipo valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(ClienteTipo valor,QString Extra,CONSULTA tipo)=0;
 virtual QMap<QString, ObjetoMaestro *> *BuscarClave()=0;
};

#endif // FABRICACLIENTETIPO_H
