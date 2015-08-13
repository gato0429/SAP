#ifndef PGOPERACIONES_H
#define PGOPERACIONES_H

#include "../Fabricas/fabricaoperaciones.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgOperaciones: public FabricaOperaciones
{
public:
    PgOperaciones();

    // FabricaOperaciones interface
public:
    bool Borrar(Operaciones valor);
    bool Insertar(Operaciones valor);
    bool Actualizar(Operaciones Antiguo, Operaciones Nuevo);
    Operaciones Buscar(Operaciones valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Operaciones valor, QString Extra, CONSULTA tipo);
};

#endif // PGOPERACIONES_H
