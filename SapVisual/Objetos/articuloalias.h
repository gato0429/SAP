#ifndef ARTICULOALIAS_H
#define ARTICULOALIAS_H
#include "objetomaestro.h"

class ArticuloAlias:public ObjetoMaestro
{    
private:
    QString Codigo;
    QString Nombre;
    /*---*/
    QString CodigoArticulo;
    QString NombreArticulo;
    QString RutaArticulo;
public:
    ArticuloAlias();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigoArticulo() const;
    void setCodigoArticulo(const QString &value);
    QString getNombreArticulo() const;
    void setNombreArticulo(const QString &value);
    QString getRutaArticulo() const;
    void setRutaArticulo(const QString &value);
};

#endif // ARTICULOALIAS_H
