#include "vehiculo.h"


QString Vehiculo::getCodigo() const
{
    return Codigo;
}

void Vehiculo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Vehiculo::getPlaca() const
{
    return Placa;
}

void Vehiculo::setPlaca(const QString &value)
{
    Placa = value;
}

QString Vehiculo::getPlacaAntigua() const
{
    return PlacaAntigua;
}

void Vehiculo::setPlacaAntigua(const QString &value)
{
    PlacaAntigua = value;
}

QString Vehiculo::getFechaIngreso() const
{
    return FechaIngreso;
}

void Vehiculo::setFechaIngreso(const QString &value)
{
    FechaIngreso = value;
}
Vehiculo::Vehiculo()
{

}

