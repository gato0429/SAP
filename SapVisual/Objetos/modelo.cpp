#include "modelo.h"



QString Modelo::getCodigo() const
{
    return Codigo;
}

void Modelo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Modelo::getNombre() const
{
    return Nombre;
}

void Modelo::setNombre(const QString &value)
{
    Nombre = value;
}

QString Modelo::getCodigoImagen() const
{
    return CodigoImagen;
}

void Modelo::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Modelo::getRutaImagen() const
{
    return RutaImagen;
}

void Modelo::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Modelo::Modelo()
{

}

