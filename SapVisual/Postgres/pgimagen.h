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
    QMap<QString, ObjetoMaestro*> *BuscarMapa(Imagen valor, CONSULTA tipo);
    int Contar();
};

#endif // PGIMAGEN_H
