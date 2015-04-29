#ifndef ARTICULOTIPO_H
#define ARTICULOTIPO_H

#include "objetomaestro.h"

class ArticuloTipo:public ObjetoMaestro
{
protected:
    QString Codigo;
    QString Nombre;
    QString Codigo_Imagen;
    QString Imagen;
public:
    ArticuloTipo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getImagen() const;
    void setImagen(const QString &value);
    QString getCodigo_Imagen() const;
    void setCodigo_Imagen(const QString &value);
};

#endif // ARTICULOTIPO_H
