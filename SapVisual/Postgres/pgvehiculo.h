#ifndef PGVEHICULO_H
#define PGVEHICULO_H

#include "../Fabricas/fabricavehiculo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgVehiculo:public FabricaVehiculo
{
public:
    PgVehiculo();

    // FabricaVehiculo interface
public:
    bool Borrar(Vehiculo valor);
    bool Insertar(Vehiculo valor);
    bool Actualizar(Vehiculo Antiguo, Vehiculo Nuevo);
    Vehiculo Buscar(Vehiculo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Vehiculo valor, QString Extra, CONSULTA tipo);
};

#endif // PGVEHICULO_H
