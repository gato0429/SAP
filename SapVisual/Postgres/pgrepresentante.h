#ifndef PGREPRESENTANTE_H
#define PGREPRESENTANTE_H
#include "../Fabricas/fabricarepresentante.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgRepresentante : public FabricaRepresentante
{
public:
    PgRepresentante();

    // FabricaRepresentante interface
public:
    bool Borrar(Representante valor);
    bool Insertar(Representante valor);
    bool Actualizar(Representante Antiguo, Representante Nuevo);
    Representante Buscar(Representante valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Representante valor, QString Extra, CONSULTA tipo);
};

#endif // PGREPRESENTANTE_H
