#ifndef FABRICAREPRESENTANTE_H
#define FABRICAREPRESENTANTE_H
#include "../Objetos/representante.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaRepresentante
{
public:
    FabricaRepresentante();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Representante valor)=0;
    virtual     bool Insertar(Representante valor)=0;
    virtual     bool Actualizar(Representante Antiguo, Representante Nuevo)=0;
    virtual     Representante Buscar(Representante valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Representante valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAREPRESENTANTE_H
