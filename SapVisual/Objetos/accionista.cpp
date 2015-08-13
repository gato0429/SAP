#include "accionista.h"


QString Accionista::getCodigo() const
{
    return Codigo;
}

void Accionista::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Accionista::getNombre() const
{
    return Nombre;
}

void Accionista::setNombre(const QString &value)
{
    Nombre = value;
}

QString Accionista::getDni() const
{
    return Dni;
}

void Accionista::setDni(const QString &value)
{
    Dni = value;
}

QString Accionista::getTelefono() const
{
    return Telefono;
}

void Accionista::setTelefono(const QString &value)
{
    Telefono = value;
}

QString Accionista::getDireccion() const
{
    return Direccion;
}

void Accionista::setDireccion(const QString &value)
{
    Direccion = value;
}

QString Accionista::getCodigoCliente() const
{
    return CodigoCliente;
}

void Accionista::setCodigoCliente(const QString &value)
{
    CodigoCliente = value;
}

QString Accionista::getNombreCliente() const
{
    return NombreCliente;
}

void Accionista::setNombreCliente(const QString &value)
{
    NombreCliente = value;
}

QString Accionista::getRutaImagen() const
{
    return RutaImagen;
}

void Accionista::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Accionista::Accionista()
{

}

