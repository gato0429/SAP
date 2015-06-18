#include "busquedaarticulotipo.h"

BusquedaArticuloTipo::BusquedaArticuloTipo(QWidget *parent):BusquedaMaestra(parent)
{
    IniciarCampos();
}

void BusquedaArticuloTipo::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" << "Nombre";
    ComboCampos->addItems(campos);
}



