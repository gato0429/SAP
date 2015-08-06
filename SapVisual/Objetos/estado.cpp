#include "estado.h"


QString Estado::getCodigo() const
{
    return Codigo;
}

void Estado::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Estado::getNombre() const
{
    return Nombre;
}

void Estado::setNombre(const QString &value)
{
    Nombre = value;
}

QString Estado::getCodigoImagen() const
{
    return CodigoImagen;
}

void Estado::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Estado::getRutaImagen() const
{
    return RutaImagen;
}

void Estado::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Estado::Estado()
{

}

