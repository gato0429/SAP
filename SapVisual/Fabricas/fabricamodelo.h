#ifndef FABRICAMODELO_H
#define FABRICAMODELO_H
#include "../Objetos/modelo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaModelo
{
public:
    FabricaModelo();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Modelo valor)=0;
    virtual     bool Insertar(Modelo valor)=0;
    virtual     bool Actualizar(Modelo Antiguo, Modelo Nuevo)=0;
    virtual     Modelo Buscar(Modelo valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Modelo valor,QString Extra,CONSULTA tipo)=0;
    virtual QMap<QString,ObjetoMaestro *>* BuscarClave()=0;

};

#endif // FABRICAMODELO_H
