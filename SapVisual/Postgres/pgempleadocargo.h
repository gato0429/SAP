#ifndef PGEMPLEADOCARGO_H
#define PGEMPLEADOCARGO_H
#include "../Fabricas/fabricaempleadocargo.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgEmpleadoCargo : public FabricaEmpleadoCargo
{
public:
    PgEmpleadoCargo();

    // FabricaEmpleadoCargo interface
public:
    bool Borrar(EmpleadoCargo valor);
    bool Insertar(EmpleadoCargo valor);
    bool Actualizar(EmpleadoCargo Antiguo, EmpleadoCargo Nuevo);
    EmpleadoCargo Buscar(EmpleadoCargo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(EmpleadoCargo valor, QString Extra, CONSULTA tipo);
};

#endif // PGEMPLEADOCARGO_H
