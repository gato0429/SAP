#include "clientetipo.h"


QString ClienteTipo::getCodigo() const
{
    return Codigo;
}

void ClienteTipo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString ClienteTipo::getNombre() const
{
    return Nombre;
}

void ClienteTipo::setNombre(const QString &value)
{
    Nombre = value;
}

QString ClienteTipo::getCodigoImagen() const
{
    return CodigoImagen;
}

void ClienteTipo::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString ClienteTipo::getRutaImagen() const
{
    return RutaImagen;
}

void ClienteTipo::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
ClienteTipo::ClienteTipo()
{

}

