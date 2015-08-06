#ifndef FABRICAIMAGENES_H
#define FABRICAIMAGENES_H
#include <QSqlQueryModel>
#include "../Objetos/imagen.h"
#include <QMap>
#include "../Definiciones.h"
class FabricaImagenes
{
public:
    QList<ObjetoMaestro*>* MapaRepisaGlobal;
    FabricaImagenes();
    virtual bool Borrar(Imagen valor)=0;
    virtual bool Insertar(Imagen valor)=0;
    virtual bool Actualizar(Imagen Antiguo, Imagen Nuevo)=0;
    virtual Imagen Buscar(Imagen valor)=0;
    virtual QMap<QString,ObjetoMaestro*>* BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)=0;
    virtual int Contar()=0;
    virtual qint64 ContarConsulta(ObjetoMaestro* valor)=0;
    virtual     QSqlQueryModel* BuscarTabla(Imagen valor,QString Extra,CONSULTA tipo)=0;
};

#endif // FABRICAIMAGENES_H
