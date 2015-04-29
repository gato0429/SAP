#ifndef FABRICAMAESTRA_H
#define FABRICAMAESTRA_H
#include "../Definiciones.h"
#include <QMap>
#include <QSqlQueryModel>
#include "../Objetos/objetomaestro.h"
template <class Tipo>
class FabricaMaestra
{
public:

    FabricaMaestra();

public:

virtual     bool Borrar(Tipo valor)=0;
virtual     bool Insertar(Tipo valor)=0;
virtual     bool Actualizar(Tipo Antiguo, Tipo Nuevo)=0;
virtual     Tipo Buscar(Tipo valor)=0;
     virtual    QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
     virtual int Contar()=0;
     virtual int ContarConsulta(ObjetoMaestro* valor)=0;
virtual     QSqlQueryModel* BuscarTabla(Tipo valor,QString Extra,CONSULTA tipo)=0;

};



#endif // FABRICAMAESTRA_H
