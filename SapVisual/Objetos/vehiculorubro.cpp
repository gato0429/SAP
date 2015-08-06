#include "vehiculorubro.h"


QString VehiculoRubro::getCodigo() const
{
    return Codigo;
}

void VehiculoRubro::setCodigo(const QString &value)
{
    Codigo = value;
}

QString VehiculoRubro::getNombre() const
{
    return Nombre;
}

void VehiculoRubro::setNombre(const QString &value)
{
    Nombre = value;
}

QString VehiculoRubro::getCodigoImagen() const
{
    return CodigoImagen;
}

void VehiculoRubro::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString VehiculoRubro::getRutaImagen() const
{
    return RutaImagen;
}

void VehiculoRubro::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
VehiculoRubro::VehiculoRubro()
{

}

