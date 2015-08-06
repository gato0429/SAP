#ifndef PGIMAGEN_H
#define PGIMAGEN_H
#include "../Fabricas/fabricaimagenes.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>

class PgImagen:public FabricaImagenes
{
public:
    PgImagen();


    // FabricaImagenes interface
public:
    bool Borrar(Imagen valor);
    bool Insertar(Imagen valor);
    bool Actualizar(Imagen Antiguo, Imagen Nuevo);
    Imagen Buscar(Imagen valor);
    QMap<QString, ObjetoMaestro*> *BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo);
    int Contar();
    qint64 ContarConsulta(ObjetoMaestro *valor);
    QSqlQueryModel *BuscarTabla(Imagen valor, QString Extra, CONSULTA tipo);

};

#endif // PGIMAGEN_H
