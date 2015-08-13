#ifndef FABRICACLIENTES_H
#define FABRICACLIENTES_H
#include "../Objetos/cliente.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaClientes
{
public:
    FabricaClientes();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;

    virtual bool Borrar(Cliente valor)=0;
    virtual bool Insertar(Cliente valor)=0;
    virtual bool Actualizar(Cliente Antiguo, Cliente Nuevo)=0;
    virtual Cliente Buscar(Cliente valor)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual int Contar()=0;
    virtual int ContarConsulta(ObjetoMaestro* valor)=0;
    virtual QSqlQueryModel* BuscarTabla(Cliente valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICACLIENTES_H
