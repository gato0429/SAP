#ifndef FABRICAEMPLEADOS_H
#define FABRICAEMPLEADOS_H
#include "../Objetos/empleado.h"
#include "../Definiciones.h"
#include <QMap>
#include <QSqlQueryModel>
class FabricaEmpleados
{
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    FabricaEmpleados();
    virtual bool Borrar(Empleado valor)=0;
    virtual bool Insertar(Empleado valor)=0;
    virtual bool Actualizar(Empleado Antiguo, Empleado Nuevo)=0;
    virtual Empleado Buscar(Empleado valor)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual QSqlQueryModel* BuscarTabla(Empleado valor,QString Extra,CONSULTA tipo)=0;
};

#endif // FABRICAEMPLEADOS_H
