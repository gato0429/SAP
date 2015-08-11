#include "empleadoarea.h"


QString EmpleadoArea::getCodigo() const
{
    return Codigo;
}

void EmpleadoArea::setCodigo(const QString &value)
{
    Codigo = value;
}

QString EmpleadoArea::getNombre() const
{
    return Nombre;
}

void EmpleadoArea::setNombre(const QString &value)
{
    Nombre = value;
}

QString EmpleadoArea::getCodigoImagen() const
{
    return CodigoImagen;
}

void EmpleadoArea::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString EmpleadoArea::getRutaImagen() const
{
    return RutaImagen;
}

void EmpleadoArea::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
EmpleadoArea::EmpleadoArea()
{

}

