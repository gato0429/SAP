#include "empleado.h"


QString Empleado::getCodigo() const
{
    return Codigo;
}

void Empleado::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Empleado::getNombre() const
{
    return Nombre;
}

void Empleado::setNombre(const QString &value)
{
    Nombre = value;
}

QString Empleado::getDireccion() const
{
    return Direccion;
}

void Empleado::setDireccion(const QString &value)
{
    Direccion = value;
}

QString Empleado::getEmail() const
{
    return Email;
}

void Empleado::setEmail(const QString &value)
{
    Email = value;
}

double Empleado::getDescuento() const
{
    return Descuento;
}

void Empleado::setDescuento(double value)
{
    Descuento = value;
}

QDate Empleado::getFechaIngreso() const
{
    return FechaIngreso;
}

void Empleado::setFechaIngreso(const QDate &value)
{
    FechaIngreso = value;
}

QString Empleado::getDni() const
{
    return Dni;
}

void Empleado::setDni(const QString &value)
{
    Dni = value;
}

QString Empleado::getTelefono() const
{
    return Telefono;
}

void Empleado::setTelefono(const QString &value)
{
    Telefono = value;
}

QString Empleado::getSexo() const
{
    return Sexo;
}

void Empleado::setSexo(const QString &value)
{
    Sexo = value;
}

QString Empleado::getCodigoInterno() const
{
    return CodigoInterno;
}

void Empleado::setCodigoInterno(const QString &value)
{
    CodigoInterno = value;
}

QDate Empleado::getFechaFin() const
{
    return FechaFin;
}

void Empleado::setFechaFin(const QDate &value)
{
    FechaFin = value;
}
Empleado::Empleado()
{
    Descuento=-1;
    FechaIngreso.setDate(1,1,1);
    FechaFin.currentDate();
    QPixmap pix;
    pix.load(RutaImagenes+"Navidad/Regalo.png");

    addPixmap(pix);
}
