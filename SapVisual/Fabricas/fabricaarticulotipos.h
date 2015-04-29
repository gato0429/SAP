#ifndef FABRICAARTICULOTIPOS_H
#define FABRICAARTICULOTIPOS_H
#include "../Objetos/articulotipo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaArticuloTipos
{
public:
    FabricaArticuloTipos();
    virtual bool Borrar(ArticuloTipo valor)=0;
    virtual bool Insertar(ArticuloTipo valor)=0;
    virtual bool Actualizar(ArticuloTipo Antiguo, ArticuloTipo Nuevo)=0;
    virtual ArticuloTipo Buscar(ArticuloTipo valor)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual int Contar()=0;
    virtual int ContarConsulta(ObjetoMaestro* valor)=0;
    virtual QSqlQueryModel* BuscarTabla(ArticuloTipo valor,QString Extra,CONSULTA tipo)=0;
   // virtual
};

#endif // FABRICAARTICULOTIPOS_H
