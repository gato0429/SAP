#include "articuloalias.h"


QString ArticuloAlias::getCodigo() const
{
    return Codigo;
}

void ArticuloAlias::setCodigo(const QString &value)
{
    Codigo = value;
}

QString ArticuloAlias::getNombre() const
{
    return Nombre;
}

void ArticuloAlias::setNombre(const QString &value)
{
    Nombre = value;
}

QString ArticuloAlias::getCodigoArticulo() const
{
    return CodigoArticulo;
}

void ArticuloAlias::setCodigoArticulo(const QString &value)
{
    CodigoArticulo = value;
}

QString ArticuloAlias::getNombreArticulo() const
{
    return NombreArticulo;
}

void ArticuloAlias::setNombreArticulo(const QString &value)
{
    NombreArticulo = value;
}

QString ArticuloAlias::getRutaArticulo() const
{
    return RutaArticulo;
}

void ArticuloAlias::setRutaArticulo(const QString &value)
{
    RutaArticulo = value;
}
ArticuloAlias::ArticuloAlias()
{
}
