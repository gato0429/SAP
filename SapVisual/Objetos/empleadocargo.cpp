#include "empleadocargo.h"


QString EmpleadoCargo::getCodigo() const
{
    return Codigo;
}

void EmpleadoCargo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString EmpleadoCargo::getNombre() const
{
    return Nombre;
}

void EmpleadoCargo::setNombre(const QString &value)
{
    Nombre = value;
}

QString EmpleadoCargo::getCodigoImagen() const
{
    return CodigoImagen;
}

void EmpleadoCargo::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString EmpleadoCargo::getRutaImagen() const
{
    return RutaImagen;
}

void EmpleadoCargo::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
EmpleadoCargo::EmpleadoCargo()
{

}

