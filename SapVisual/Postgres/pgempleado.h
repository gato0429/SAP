#ifndef PGEMPLEADO_H
#define PGEMPLEADO_H
#include "../Fabricas/fabricaempleados.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <qdebug.h>
#include <QMap>
#include <QList>
class PgEmpleado:public FabricaEmpleados
{
public:
    PgEmpleado();

    // FabricaEmpleados interface
public:
    bool Borrar(Empleado valor);
    bool Insertar(Empleado valor);
    bool Actualizar(Empleado Antiguo, Empleado Nuevo);
    Empleado Buscar(Empleado valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    qint64 Contar() ;
    qint64 ContarConsulta(ObjetoMaestro *valor) ;
    QSqlQueryModel *BuscarTabla(Empleado valor, QString Extra, CONSULTA tipo);
};

#endif // PGEMPLEADO_H
