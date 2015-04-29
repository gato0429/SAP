#ifndef PGARTICULOALIAS_H
#define PGARTICULOALIAS_H

#include "../Fabricas/fabricaarticuloalias.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <qdebug.h>
#include <QMap>

class PgArticuloAlias:public FabricaArticuloAlias
{
public:
    PgArticuloAlias();

    // FabricaArticuloAliasAlias interface
public:
    bool Borrar(ArticuloAlias valor);
    bool Insertar(ArticuloAlias valor);
    bool Actualizar(ArticuloAlias Antiguo, ArticuloAlias Nuevo);
    ArticuloAlias Buscar(ArticuloAlias valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    int Contar();
    int ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(ArticuloAlias valor, QString Extra, CONSULTA tipo);
};

#endif // PGARTICULOALIAS_H
