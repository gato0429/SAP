#include "articulo.h"



QString Articulo::getCodigo() const
{
    return Codigo;
}

void Articulo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Articulo::getNombre() const
{
    return Nombre;
}

void Articulo::setNombre(const QString &value)
{
    Nombre = value;
}

QString Articulo::getCodigoImagen() const
{
    return CodigoImagen;
}

void Articulo::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString Articulo::getRutaImagen() const
{
    return RutaImagen;
}

void Articulo::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}

QString Articulo::getCodigoUnidad() const
{
    return CodigoUnidad;
}

void Articulo::setCodigoUnidad(const QString &value)
{
    CodigoUnidad = value;
}



QString Articulo::getRutaImagenUnidad() const
{
    return RutaImagenUnidad;
}

void Articulo::setRutaImagenUnidad(const QString &value)
{
    RutaImagenUnidad = value;
}

QString Articulo::getVigencia() const
{
    return Vigencia;
}

void Articulo::setVigencia(const QString &value)
{
    Vigencia = value;
}

QString Articulo::getCodigoTipo() const
{
    return CodigoTipo;
}

void Articulo::setCodigoTipo(const QString &value)
{
    CodigoTipo = value;
}

QString Articulo::getNombreTipo() const
{
    return NombreTipo;
}

void Articulo::setNombreTipo(const QString &value)
{
    NombreTipo = value;
}

QString Articulo::getRutaImagenTipo() const
{
    return RutaImagenTipo;
}

void Articulo::setRutaImagenTipo(const QString &value)
{
    RutaImagenTipo = value;
}

QString Articulo::getNombreUnidad() const
{
    return NombreUnidad;
}

void Articulo::setNombreUnidad(const QString &value)
{
    NombreUnidad = value;
}

QString Articulo::getSimboloUnidad() const
{
    return SimboloUnidad;
}

void Articulo::setSimboloUnidad(const QString &value)
{
    SimboloUnidad = value;
}

QString Articulo::getCodigoInterno() const
{
    return CodigoInterno;
}

void Articulo::setCodigoInterno(const QString &value)
{
    CodigoInterno = value;
}

QString Articulo::getCodigoExterno() const
{
    return CodigoExterno;
}

void Articulo::setCodigoExterno(const QString &value)
{
    CodigoExterno = value;
}

double Articulo::getCantidadMin() const
{
    return CantidadMin;
}

void Articulo::setCantidadMin(double value)
{
    CantidadMin = value;
}

QString Articulo::getUnico() const
{
    return Unico;
}

void Articulo::setUnico(QString value)
{
    Unico = value;
}

QString Articulo::getCodigoModelo() const
{
    return CodigoModelo;
}

void Articulo::setCodigoModelo(const QString &value)
{
    CodigoModelo = value;
}

QString Articulo::getNombreModelo() const
{
    return NombreModelo;
}

void Articulo::setNombreModelo(const QString &value)
{
    NombreModelo = value;
}

QString Articulo::getRutaImagenModelo() const
{
    return RutaImagenModelo;
}

void Articulo::setRutaImagenModelo(const QString &value)
{
    RutaImagenModelo = value;
}

QString Articulo::getCodigoMarca() const
{
    return CodigoMarca;
}

void Articulo::setCodigoMarca(const QString &value)
{
    CodigoMarca = value;
}

QString Articulo::getNombreMarca() const
{
    return NombreMarca;
}

void Articulo::setNombreMarca(const QString &value)
{
    NombreMarca = value;
}

QString Articulo::getRutaImagenMarca() const
{
    return RutaImagenMarca;
}

void Articulo::setRutaImagenMarca(const QString &value)
{
    RutaImagenMarca = value;
}

QString Articulo::getCodigoMoneda() const
{
    return CodigoMoneda;
}

void Articulo::setCodigoMoneda(const QString &value)
{
    CodigoMoneda = value;
}

QString Articulo::getNombreMoneda() const
{
    return NombreMoneda;
}

void Articulo::setNombreMoneda(const QString &value)
{
    NombreMoneda = value;
}

QString Articulo::getSimboloMoneda() const
{
    return SimboloMoneda;
}

void Articulo::setSimboloMoneda(const QString &value)
{
    SimboloMoneda = value;
}

QString Articulo::getRutaImagenMoneda() const
{
    return RutaImagenMoneda;
}

void Articulo::setRutaImagenMoneda(const QString &value)
{
    RutaImagenMoneda = value;
}

double Articulo::getPrecio() const
{
    return Precio;
}

void Articulo::setPrecio(double value)
{
    Precio = value;
}
Articulo::Articulo()
{
    CantidadMin=-1;
    Precio=-1;
}
