#include "cliente.h"




QString Cliente::getCodigo() const
{
    return Codigo;
}

void Cliente::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Cliente::getTipo() const
{
    return Tipo;
}

void Cliente::setTipo(const QString &value)
{
    Tipo = value;
}

QString Cliente::getNombre() const
{
    return Nombre;
}

void Cliente::setNombre(const QString &value)
{
    Nombre = value;
}

QString Cliente::getDireccion() const
{
    return Direccion;
}

void Cliente::setDireccion(const QString &value)
{
    Direccion = value;
}

QString Cliente::getPais() const
{
    return Pais;
}

void Cliente::setPais(const QString &value)
{
    Pais = value;
}

QString Cliente::getContacto() const
{
    return Contacto;
}

void Cliente::setContacto(const QString &value)
{
    Contacto = value;
}

QString Cliente::getTelefono() const
{
    return Telefono;
}

void Cliente::setTelefono(const QString &value)
{
    Telefono = value;
}

QString Cliente::getEmail() const
{
    return Email;
}

void Cliente::setEmail(const QString &value)
{
    Email = value;
}

QString Cliente::getWeb() const
{
    return Web;
}

void Cliente::setWeb(const QString &value)
{
    Web = value;
}

double Cliente::getDescuento() const
{
    return Descuento;
}

void Cliente::setDescuento(double value)
{
    Descuento = value;
}

QDate Cliente::getFecha() const
{
    return Fecha;
}

void Cliente::setFecha(const QDate &value)
{
    Fecha = value;
}
/*
Cliente &Cliente::operator=(Cliente &valor)
{
    this->Codigo=valor.Codigo;
    this->Tipo=valor.Tipo;
    this->Nombre=valor.Nombre;
    this->Direccion=valor.Direccion;
    this->Pais=valor.Pais;
    this->Contacto=valor.Contacto;
    this->Telefono=valor.Telefono;
    this->Email=valor.Email;
    this->Web=valor.Web;
    this->Descuento=valor.Descuento;
    this->Fecha=valor.Fecha;
    return (*this);
}*/


QString Cliente::getCodigoInterno() const
{
    return CodigoInterno;
}

void Cliente::setCodigoInterno(const QString &value)
{
    CodigoInterno = value;
}

QString Cliente::getNumDoc() const
{
    return NumDoc;
}

void Cliente::setNumDoc(const QString &value)
{
    NumDoc = value;
}

QString Cliente::getCodigoTipo() const
{
    return CodigoTipo;
}

void Cliente::setCodigoTipo(const QString &value)
{
    CodigoTipo = value;
}

QString Cliente::getNombreTipo() const
{
    return NombreTipo;
}

void Cliente::setNombreTipo(const QString &value)
{
    NombreTipo = value;
}

QString Cliente::getRutaImagenTipo() const
{
    return RutaImagenTipo;
}

void Cliente::setRutaImagenTipo(const QString &value)
{
    RutaImagenTipo = value;
}

QString Cliente::getCodigoImagen() const
{
    return CodigoImagen;
}

void Cliente::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Cliente::getRutaImagen() const
{
    return RutaImagen;
}

void Cliente::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}

QDate Cliente::getFechaFin() const
{
    return FechaFin;
}

void Cliente::setFechaFin(const QDate &value)
{
    FechaFin = value;
}
Cliente::Cliente()
{

    Descuento=-1;
    Fecha.setDate(1,1,1);
}
