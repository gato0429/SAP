#ifndef PGCLIENTETIPO_H
#define PGCLIENTETIPO_H

#include "../Fabricas/fabricaclientetipo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgClienteTipo: public FabricaClienteTipo
{
public:
    PgClienteTipo();

    // FabricaClienteTipo interface
public:
    bool Borrar(ClienteTipo valor);
    bool Insertar(ClienteTipo valor);
    bool Actualizar(ClienteTipo Antiguo, ClienteTipo Nuevo);
    ClienteTipo Buscar(ClienteTipo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(ClienteTipo valor, QString Extra, CONSULTA tipo);
    QMap<QString, ObjetoMaestro *> *BuscarClave();
};

#endif // PGCLIENTETIPO_H
