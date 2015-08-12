#ifndef PGPROVEEDOR_H
#define PGPROVEEDOR_H
#include "../Fabricas/fabricaproveedor.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgProveedor : public FabricaProveedor
{
public:
    PgProveedor();

    // FabricaProveedor interface
public:
    bool Borrar(Proveedor valor);
    bool Insertar(Proveedor valor);
    bool Actualizar(Proveedor Antiguo, Proveedor Nuevo);
    Proveedor Buscar(Proveedor valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Proveedor valor, QString Extra, CONSULTA tipo);
};

#endif // PGPROVEEDOR_H
