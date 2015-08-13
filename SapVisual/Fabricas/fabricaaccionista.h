#ifndef FABRICAACCIONISTA_H
#define FABRICAACCIONISTA_H
#include "../Objetos/accionista.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Definiciones.h"
using namespace std;

class FabricaAccionista
{
public:
    FabricaAccionista();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    virtual     bool Borrar(Accionista valor)=0;
    virtual     bool Insertar(Accionista valor)=0;
    virtual     bool Actualizar(Accionista Antiguo, Accionista Nuevo)=0;
    virtual     Accionista Buscar(Accionista valor)=0;
    virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA Tipo)=0;
    virtual qint64 Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Accionista valor,QString Extra,CONSULTA tipo)=0;

};

#endif // FABRICAACCIONISTA_H
