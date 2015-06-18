#include "moneda.h"


QString Moneda::getCodigo() const
{
    return Codigo;
}

void Moneda::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Moneda::getNombre() const
{
    return Nombre;
}

void Moneda::setNombre(const QString &value)
{
    Nombre = value;
}

QString Moneda::getSimbolo() const
{
    return Simbolo;
}

void Moneda::setSimbolo(const QString &value)
{
    Simbolo = value;
}

QString Moneda::getCodigoImagen() const
{
    return CodigoImagen;
}

void Moneda::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Moneda::getRutaImagen() const
{
    return RutaImagen;
}

void Moneda::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Moneda::Moneda()
{

}

