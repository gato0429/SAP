#ifndef PGARTICULO_H
#define PGARTICULO_H
#include "../Fabricas/fabricaarticulos.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <qdebug.h>
#include <QMap>

class PgArticulo:public FabricaArticulos
{
public:
    PgArticulo();

    // FabricaArticulos interface
public:
    bool Borrar(Articulo valor);
    bool Insertar(Articulo valor);
    bool Actualizar(Articulo Antiguo, Articulo Nuevo);
    Articulo Buscar(Articulo valor);
    QMap<QString, ObjetoMaestro *> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    int Contar();
    int ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Articulo valor, QString Extra, CONSULTA tipo);
    QSqlQueryModel *FuncionArticulos(Articulo valor, QString Extra);
};

#endif // PGARTICULO_H
