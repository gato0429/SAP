#ifndef FABRICAARTICULOS_H
#define FABRICAARTICULOS_H
#include "../Objetos/articulo.h"
#include "../Definiciones.h"
#include <QMap>
#include <QSqlQueryModel>

class FabricaArticulos
{
public:
    FabricaArticulos();
    QList<ObjetoMaestro*>* MapaRepisaGlobal;

    virtual bool Borrar(Articulo valor)=0;
    virtual bool Insertar(Articulo valor)=0;
    virtual bool Actualizar(Articulo Antiguo, Articulo Nuevo)=0;
    virtual Articulo Buscar(Articulo valor)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro* valor,QString Extra, CONSULTA tipo)=0;
    virtual int Contar()=0;
    virtual int ContarConsulta(ObjetoMaestro* valor)=0;
    virtual QSqlQueryModel* BuscarTabla(Articulo valor,QString Extra,CONSULTA tipo)=0;


    virtual QSqlQueryModel *FuncionArticulos(Articulo valor, QString Extra)=0;





    // FabricaMaestra interface
public:

};

#endif // FABRICAARTICULOS_H
