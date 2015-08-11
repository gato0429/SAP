#ifndef FABRICAEMPLEADOAREA_H
#define FABRICAEMPLEADOAREA_H
#include "../Objetos/empleadoarea.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaEmpleadoArea
{
public:
    FabricaEmpleadoArea();
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(EmpleadoArea valor)=0;
    virtual     bool Insertar(EmpleadoArea valor)=0;
    virtual     bool Actualizar(EmpleadoArea Antiguo, EmpleadoArea Nuevo)=0;
    virtual     EmpleadoArea Buscar(EmpleadoArea valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(EmpleadoArea valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAEMPLEADOAREA_H
