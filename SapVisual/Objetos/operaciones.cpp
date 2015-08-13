#include "operaciones.h"


QString Operaciones::getCodigo() const
{
    return Codigo;
}

void Operaciones::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Operaciones::getNombre() const
{
    return Nombre;
}

void Operaciones::setNombre(const QString &value)
{
    Nombre = value;
}

QString Operaciones::getDescripcion() const
{
    return Descripcion;
}

void Operaciones::setDescripcion(const QString &value)
{
    Descripcion = value;
}

QString Operaciones::getCodigoImagen() const
{
    return CodigoImagen;
}

void Operaciones::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Operaciones::getRutaImagen() const
{
    return RutaImagen;
}

void Operaciones::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Operaciones::Operaciones()
{

}

