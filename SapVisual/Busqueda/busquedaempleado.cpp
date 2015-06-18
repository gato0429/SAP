#include "busquedaempleado.h"

BusquedaEmpleado::BusquedaEmpleado(QWidget *parent):BusquedaMaestra(parent)
{
   // IniciarCampos();
qDebug()<<"Pase la intersasas";

}


void BusquedaEmpleado::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" <<"Codigo Interno"<< "Nombre"<<"Direccion"<<"Email"<<"Descuento"<<"Fecha"<<"Sexo"<<"Dni"<<"Telefono";
    ComboCampos->addItems(campos);
}
