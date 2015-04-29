#include "imagen.h"


QString Imagen::getCarpeta() const
{
    return Carpeta;
}

void Imagen::setCarpeta(const QString &value)
{
    Carpeta = value;
}

QString Imagen::getNombre() const
{
    return Nombre;
}

void Imagen::setNombre(const QString &value)
{
    Nombre = value;
}

QString Imagen::getCodigo() const
{
    return Codigo;
}

void Imagen::setCodigo(const QString &value)
{
    Codigo = value;
}

QByteArray Imagen::getPixel() const
{
    return Pixel;
}

void Imagen::setPixel(const QByteArray &value)
{
    Pixel = value;
}
Imagen::Imagen()
{
}
