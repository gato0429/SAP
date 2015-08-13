#ifndef PGSUCURSALES_H
#define PGSUCURSALES_H
#include "../Fabricas/fabricasucursales.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgSucursales : public FabricaSucursales
{
public:
    PgSucursales();

    // FabricaSucursales interface
public:
    bool Borrar(Sucursales valor);
    bool Insertar(Sucursales valor);
    bool Actualizar(Sucursales Antiguo, Sucursales Nuevo);
    Sucursales Buscar(Sucursales valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Sucursales valor, QString Extra, CONSULTA tipo);
};

#endif // PGSUCURSALES_H
