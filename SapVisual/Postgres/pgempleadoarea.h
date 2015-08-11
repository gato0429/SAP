#ifndef PGEMPLEADOAREA_H
#define PGEMPLEADOAREA_H
#include "../Fabricas/fabricaempleadoarea.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"


class PgEmpleadoArea : public FabricaEmpleadoArea
{
public:
    PgEmpleadoArea();

    // FabricaEmpleadoArea interface
public:
    bool Borrar(EmpleadoArea valor);
    bool Insertar(EmpleadoArea valor);
    bool Actualizar(EmpleadoArea Antiguo, EmpleadoArea Nuevo);
    EmpleadoArea Buscar(EmpleadoArea valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(EmpleadoArea valor, QString Extra, CONSULTA tipo);
};

#endif // PGEMPLEADOAREA_H
