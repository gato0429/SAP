#include "marca.h"


QString Marca::getCodigo() const
{
    return Codigo;
}

void Marca::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Marca::getNombre() const
{
    return Nombre;
}

void Marca::setNombre(const QString &value)
{
    Nombre = value;
}

QString Marca::getCodigoImagen() const
{
    return CodigoImagen;
}

void Marca::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Marca::getRutaImagen() const
{
    return RutaImagen;
}

void Marca::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Marca::Marca()
{

}

