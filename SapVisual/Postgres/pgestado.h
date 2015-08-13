#ifndef PGESTADO_H
#define PGESTADO_H


#include "../Fabricas/fabricaestado.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"
class PgEstado: public FabricaEstado
{
public:
    PgEstado();

    // FabricaEstado interface
public:
    bool Borrar(Estado valor);
    bool Insertar(Estado valor);
    bool Actualizar(Estado Antiguo, Estado Nuevo);
    Estado Buscar(Estado valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Estado valor, QString Extra, CONSULTA tipo);
    QMap<QString,QString>* BuscarClave();
};

#endif // PGESTADO_H
