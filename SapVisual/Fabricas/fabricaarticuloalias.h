#ifndef FABRICAArticuloAliasALIAS_H
#define FABRICAArticuloAliasALIAS_H
#include "../Objetos/ArticuloAlias.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"

using namespace std;

class FabricaArticuloAlias
{
public:
    FabricaArticuloAlias();

    virtual bool Borrar(ArticuloAlias valor)=0;
    virtual bool Insertar(ArticuloAlias valor)=0;
    virtual bool Actualizar(ArticuloAlias Antiguo, ArticuloAlias Nuevo)=0;
    virtual ArticuloAlias Buscar(ArticuloAlias valor)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual int Contar()=0;
    virtual int ContarConsulta(ObjetoMaestro* valor)=0;
    virtual QSqlQueryModel* BuscarTabla(ArticuloAlias valor,QString Extra,CONSULTA tipo)=0;


};

#endif // FABRICAArticuloAliasALIAS_H
