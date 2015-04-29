#include "articulotipo.h"


QString ArticuloTipo::getCodigo() const
{
    return Codigo;
}

void ArticuloTipo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString ArticuloTipo::getNombre() const
{
    return Nombre;
}

void ArticuloTipo::setNombre(const QString &value)
{
    Nombre = value;
}

QString ArticuloTipo::getImagen() const
{
    return Imagen;
}

void ArticuloTipo::setImagen(const QString &value)
{
    Imagen = value;
}



QString ArticuloTipo::getCodigo_Imagen() const
{
    return Codigo_Imagen;
}

void ArticuloTipo::setCodigo_Imagen(const QString &value)
{
    Codigo_Imagen = value;
}
ArticuloTipo::ArticuloTipo()
{
    this->addPixmap(QPixmap(":/Imagenes/iconos/cat.png"));
}
