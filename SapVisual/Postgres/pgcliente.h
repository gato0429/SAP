#ifndef PGCLIENTE_H
#define PGCLIENTE_H
#include "../Fabricas/fabricaclientes.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>


class PgCliente:public FabricaClientes
{
public:
    PgCliente();


    // FabricaClientes interface
public:
    bool Borrar(Cliente valor);
    bool Insertar(Cliente valor);
    bool Actualizar(Cliente Antiguo, Cliente Nuevo);
    Cliente Buscar(Cliente valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    int Contar();
    int ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Cliente valor, QString Extra, CONSULTA tipo);

};

#endif // PGCLIENTE_H
