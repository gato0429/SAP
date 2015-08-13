#ifndef PGMODELO_H
#define PGMODELO_H
#include "../Fabricas/fabricamodelo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgModelo : public FabricaModelo
{
public:
    PgModelo();

    // FabricaModelo interface
public:
    bool Borrar(Modelo valor);
    bool Insertar(Modelo valor);
    bool Actualizar(Modelo Antiguo, Modelo Nuevo);
    Modelo Buscar(Modelo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Modelo valor, QString Extra, CONSULTA tipo);
    QMap<QString,ObjetoMaestro *>* BuscarClave();
};

#endif // PGMODELO_H
