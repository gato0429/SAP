#ifndef PGUNIDAD_H
#define PGUNIDAD_H

#include "../Fabricas/fabricaunidades.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgUnidad:public FabricaUnidades
{
public:
    PgUnidad();

    // FabricaUnidades interface
public:
    bool Borrar(Unidad valor);
    bool Insertar(Unidad valor);
    bool Actualizar(Unidad Antiguo, Unidad Nuevo);
    Unidad Buscar(Unidad valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    int Contar();
    int ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Unidad valor, QString Extra, CONSULTA tipo);
    QMap<QString, ObjetoMaestro*> *BuscarClave();
};

#endif // PGUNIDAD_H
