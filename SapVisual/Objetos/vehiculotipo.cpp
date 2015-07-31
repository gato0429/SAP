#include "vehiculotipo.h"


QString VehiculoTipo::getCodigo() const
{
    return Codigo;
}

void VehiculoTipo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString VehiculoTipo::getNombre() const
{
    return Nombre;
}

void VehiculoTipo::setNombre(const QString &value)
{
    Nombre = value;
}

QString VehiculoTipo::getCodigoImagen() const
{
    return CodigoImagen;
}

void VehiculoTipo::setCodigoImagen(const QString &value)
{
    CodigoImagen = value;
}

QString VehiculoTipo::getRutaImagen() const
{
    return RutaImagen;
}

void VehiculoTipo::setRutaImagen(const QString &value)
{
    RutaImagen = value;
}
VehiculoTipo::VehiculoTipo()
{

}

