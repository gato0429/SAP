#ifndef PGMARCA_H
#define PGMARCA_H

#include "../Fabricas/fabricamarca.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgMarca:public FabricaMarca
{
public:
    PgMarca();

    // FabricaMarca interface
public:
    bool Borrar(Marca valor);
    bool Insertar(Marca valor);
    bool Actualizar(Marca Antiguo, Marca Nuevo);
    Marca Buscar(Marca valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Marca);
    int Contar();
    int ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Marca valor, QString Extra, CONSULTA tipo);
};

#endif // PGMARCA_H