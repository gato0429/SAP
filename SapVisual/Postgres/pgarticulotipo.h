#ifndef PGARTICULOTIPO_H
#define PGARTICULOTIPO_H
#include "../Fabricas/fabricaarticulotipos.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <qdebug.h>
#include <QMap>

class PgArticuloTipo:public FabricaArticuloTipos
{
public:
    PgArticuloTipo();

    // FabricaArticuloTipos interface
public:
    bool Borrar(ArticuloTipo valor);
    bool Insertar(ArticuloTipo valor);
    bool Actualizar(ArticuloTipo Antiguo, ArticuloTipo Nuevo);
    ArticuloTipo Buscar(ArticuloTipo valor);
    QMap<QString, ObjetoMaestro*> *BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo);
    int Contar();
    int ContarConsulta(ObjetoMaestro* valor);
    QSqlQueryModel *BuscarTabla(ArticuloTipo valor, QString Extra, CONSULTA tipo);

};

#endif // PGARTICULOTIPO_H
