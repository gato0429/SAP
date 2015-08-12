#ifndef FABRICAPROVEEDOR_H
#define FABRICAPROVEEDOR_H
#include "../Objetos/proveedor.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaProveedor
{
public:
    FabricaProveedor();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Proveedor valor)=0;
    virtual     bool Insertar(Proveedor valor)=0;
    virtual     bool Actualizar(Proveedor Antiguo, Proveedor Nuevo)=0;
    virtual     Proveedor Buscar(Proveedor valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Proveedor valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAPROVEEDOR_H
