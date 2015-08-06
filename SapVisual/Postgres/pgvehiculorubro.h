#ifndef PGVEHICULORUBRO_H
#define PGVEHICULORUBRO_H

#include "../Fabricas/fabricavehiculorubro.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"
class PgVehiculoRubro : public FabricaVehiculoRubro
{
public:
    PgVehiculoRubro();

    // FabricaVehiculoRubro interface
public:
    bool Borrar(VehiculoRubro valor);
    bool Insertar(VehiculoRubro valor);
    bool Actualizar(VehiculoRubro Antiguo, VehiculoRubro Nuevo);
    VehiculoRubro Buscar(VehiculoRubro valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(VehiculoRubro valor, QString Extra, CONSULTA tipo);
};

#endif // PGVEHICULORUBRO_H
