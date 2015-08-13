#include "representante.h"


QString Representante::getCodigo() const
{
    return Codigo;
}

void Representante::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Representante::getNombre() const
{
    return Nombre;
}

void Representante::setNombre(const QString &value)
{
    Nombre = value;
}

QString Representante::getDni() const
{
    return Dni;
}

void Representante::setDni(const QString &value)
{
    Dni = value;
}

QString Representante::getTelefono() const
{
    return Telefono;
}

void Representante::setTelefono(const QString &value)
{
    Telefono = value;
}

QString Representante::getCorreo() const
{
    return Correo;
}

void Representante::setCorreo(const QString &value)
{
    Correo = value;
}

QString Representante::getCodigoCliente() const
{
    return CodigoCliente;
}

void Representante::setCodigoCliente(const QString &value)
{
    CodigoCliente = value;
}

QString Representante::getNombreCliente() const
{
    return NombreCliente;
}

void Representante::setNombreCliente(const QString &value)
{
    NombreCliente = value;
}

QString Representante::getCodigoImagen() const
{
    return CodigoImagen;
}

void Representante::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Representante::getRutaImagen() const
{
    return RutaImagen;
}

void Representante::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
Representante::Representante()
{

}

