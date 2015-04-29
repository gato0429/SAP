#include "unidad.h"


QString Unidad::getCodigo() const
{
    return Codigo;
}

void Unidad::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Unidad::getNombre() const
{
    return Nombre;
}

void Unidad::setNombre(const QString &value)
{
    Nombre = value;
}

QString Unidad::getSimbolo() const
{
    return Simbolo;
}

void Unidad::setSimbolo(const QString &value)
{
    Simbolo = value;
}

QString Unidad::getCodigoImagen() const
{
    return CodigoImagen;
}

void Unidad::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Unidad::getRutaImagen() const
{
    return RutaImagen;
}

void Unidad::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Unidad::Unidad()
{
}
