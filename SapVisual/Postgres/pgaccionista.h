#ifndef PGACCIONISTA_H
#define PGACCIONISTA_H
#include "../Fabricas/fabricaaccionista.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>
#include <QDebug>
#include "../Extras/mensajeemergente.h"

class PgAccionista : public FabricaAccionista
{
public:
    PgAccionista();

    // FabricaAccionista interface
public:
    bool Borrar(Accionista valor);
    bool Insertar(Accionista valor);
    bool Actualizar(Accionista Antiguo, Accionista Nuevo);
    Accionista Buscar(Accionista valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo);
    qint64 Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Accionista valor, QString Extra, CONSULTA tipo);
};

#endif // PGACCIONISTA_H
