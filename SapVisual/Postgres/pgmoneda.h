#ifndef PGMONEDA_H
#define PGMONEDA_H

#include "../Fabricas/fabricamoneda.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgMoneda:public FabricaMoneda
{
public:
    PgMoneda();

    // FabricaMoneda interface
public:
    bool Borrar(Moneda valor);
    bool Insertar(Moneda valor);
    bool Actualizar(Moneda Antiguo, Moneda Nuevo);
    Moneda Buscar(Moneda valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Moneda valor, QString Extra, CONSULTA tipo);
};

#endif // PGMONEDA_H
