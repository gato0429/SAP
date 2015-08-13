#ifndef FABRICAEMPLEADOCARGO_H
#define FABRICAEMPLEADOCARGO_H
#include "../Objetos/empleadocargo.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaEmpleadoCargo
{
public:
    FabricaEmpleadoCargo();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(EmpleadoCargo valor)=0;
    virtual     bool Insertar(EmpleadoCargo valor)=0;
    virtual     bool Actualizar(EmpleadoCargo Antiguo, EmpleadoCargo Nuevo)=0;
    virtual     EmpleadoCargo Buscar(EmpleadoCargo valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(EmpleadoCargo valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAEMPLEADOCARGO_H
