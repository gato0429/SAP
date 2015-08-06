#ifndef PGVEHICULOTIPO_H
#define PGVEHICULOTIPO_H

#include "../Fabricas/fabricavehiculotipo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgVehiculoTipo : public FabricaVehiculoTipo
{
public:
    PgVehiculoTipo();

    // FabricaVehiculoTipo interface
public:
    bool Borrar(VehiculoTipo valor);
    bool Insertar(VehiculoTipo valor);
    bool Actualizar(VehiculoTipo Antiguo, VehiculoTipo Nuevo);
    VehiculoTipo Buscar(VehiculoTipo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(VehiculoTipo valor, QString Extra, CONSULTA tipo);
};

#endif // PGVEHICULOTIPO_H
