#include "busquedaarticulo.h"

BusquedaArticulo::BusquedaArticulo(QWidget *parent ):BusquedaMaestra(parent)
{
    IniciarCampos();
    Fab=BD->Fabrica->CrearArticulo();
    FabTip=BD->Fabrica->CrearArticuloTipo();
    FabUni=BD->Fabrica->CrearUnidad();

    BD->Fabrica->Conectar();
    MapaTipos=FabTip->BuscarMapa((ObjetoMaestro*)new ArticuloTipo()," order by nombre asc",TODO);
    MapaUnidad=FabUni->BuscarMapa((ObjetoMaestro*)new Unidad()," order by nombre asc",TODO);
    BD->Fabrica->Desconectar();

    ComboTipos->setInsertPolicy(QComboBox::InsertAlphabetically);
}


void BusquedaArticulo::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" <<"Codigo Interno"<<"Codigo Externo" <<"Nombre"<<"Tipo"<<"Unidad"<<"Vigencia";
    ComboCampos->addItems(campos);
}

void BusquedaArticulo::ObtenerConsulta()
{
    QString fin=LineFin->text();
    QString ord;
    int index=ComboCampos->currentIndex();


    if(GrupoBoton->button(1)->isChecked())
    {
        ord="asc";
    }
    if(GrupoBoton->button(2)->isChecked())
    {
        ord="desc";
    }

    Articulo ObjetoConsulta;
    QString Tipo;
    switch (index)
    {
    case 1:
        ObjetoConsulta.setCodigo(LineNombre->text());
        break;
    case 2:
        ObjetoConsulta.setCodigoInterno(LineNombre->text());
        break;
    case 3:
        ObjetoConsulta.setCodigoExterno(LineNombre->text());
        break;
    case 4:
        ObjetoConsulta.setNombre(LineNombre->text());
        break;
    case 5:
        ObjetoConsulta.setNombreTipo(ComboTipos->currentText());
        break;
    case 6:
        ObjetoConsulta.setNombreUnidad(ComboTipos->currentText());
        break;
    case 7:
        ObjetoConsulta.setVigencia(ComboTipos->currentText());
        break;
    default:
        break;
    }

    BD->Fabrica->Conectar();
    QString Extra=" order by codigo "+ord+" LIMIT "+fin+" offset 0";
    QSqlQueryModel* Model= Fab->BuscarTabla(ObjetoConsulta,Extra,CAMPOS);
    BD->Fabrica->Desconectar();

    Model->setHeaderData(0,Qt::Horizontal,"Codigo");
    Model->setHeaderData(1,Qt::Horizontal,"Codigo Interno");
    Model->setHeaderData(2,Qt::Horizontal,"Codigo Externo");
    Model->setHeaderData(3,Qt::Horizontal,"Nombre");
    Model->setHeaderData(4,Qt::Horizontal,"Codigo Imagen");
    Model->setHeaderData(5,Qt::Horizontal,"Ruta Imagen");
    Model->setHeaderData(6,Qt::Horizontal,"Vigencia");
    Model->setHeaderData(7,Qt::Horizontal,"Codigo Unidad");
    Model->setHeaderData(8,Qt::Horizontal,"Nombre Unidad");
    Model->setHeaderData(9,Qt::Horizontal,"Unidad");
    Model->setHeaderData(10,Qt::Horizontal,"Ruta Unidad");
    Model->setHeaderData(11,Qt::Horizontal,"Codigo Tipo");
    Model->setHeaderData(12,Qt::Horizontal,"Tipo");
    Model->setHeaderData(13,Qt::Horizontal,"Ruta Tipo");


    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);

    emit my_signal(Model,CamposVisibles);
    emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta),fin.toInt(),ord);
    VisorConsulta->move(this->x(),this->y()+this->height());

}


void BusquedaArticulo::CambiarCombo(int index)
{
    if(index==5)
    {
        ComboTipos->clear();
        LineNombre->setHidden(true);
        ComboTipos->setHidden(false);
        ComboTipos->setEditable(true);

        for(itp=MapaTipos->begin(); itp!=MapaTipos->end(); itp++)
        {
            ArticuloTipo* T=(ArticuloTipo*)itp.value();
            ComboTipos->addItem(QIcon(RutaImagenes+T->getImagen()),T->getNombre());
        }

        return;
    }

    if(index==6)
    {
        ComboTipos->clear();
        LineNombre->setHidden(true);
        ComboTipos->setHidden(false);
        ComboTipos->setEditable(false);

        for(itu=MapaUnidad->begin(); itu!=MapaUnidad->end(); itu++)
        {
            Unidad* T=(Unidad*)itu.value();
            ComboTipos->addItem(QIcon(RutaImagenes+T->getRutaImagen()),T->getNombre());
        }

        return;

    }



    if(index==7)
    {
        ComboTipos->clear();
        LineNombre->setHidden(true);
        ComboTipos->setHidden(false);
        ComboTipos->setEditable(false);
        ComboTipos->addItem("vigente");
        ComboTipos->addItem("caducado");
        return;
    }

    LineNombre->clear();
    LineNombre->setHidden(false);
    ComboTipos->setHidden(true);
    return;

}
