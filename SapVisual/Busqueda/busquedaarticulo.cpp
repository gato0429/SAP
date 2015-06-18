#include "busquedaarticulo.h"

BusquedaArticulo::BusquedaArticulo(QWidget *parent ):BusquedaMaestra(parent)
{
    IniciarCampos();
/*    Fab=BD->Fabrica->CrearArticulo();
    FabTip=BD->Fabrica->CrearArticuloTipo();
    FabUni=BD->Fabrica->CrearUnidad();

    BD->Fabrica->Conectar();
    MapaTipos=FabTip->BuscarMapa((ObjetoMaestro*)new ArticuloTipo()," order by nombre asc",TODO);
    MapaUnidad=FabUni->BuscarMapa((ObjetoMaestro*)new Unidad()," order by nombre asc",TODO);
    BD->Fabrica->Desconectar();

    ComboTipos->setInsertPolicy(QComboBox::InsertAlphabetically);*/
}


void BusquedaArticulo::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" <<"Codigo Interno"<<"Codigo Externo" <<"Nombre"<<"Tipo"<<"Unidad"<<"Vigencia";
    ComboCampos->addItems(campos);
}

