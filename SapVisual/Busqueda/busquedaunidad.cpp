#include "busquedaunidad.h"

BusquedaUnidad::BusquedaUnidad(QWidget *parent):BusquedaMaestra(parent)
{
    IniciarCampos();
}



void BusquedaUnidad::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" << "Nombre"<<"Simbolo";
    ComboCampos->addItems(campos);


}
