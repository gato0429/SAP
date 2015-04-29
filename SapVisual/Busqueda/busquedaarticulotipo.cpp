#include "busquedaarticulotipo.h"

BusquedaArticuloTipo::BusquedaArticuloTipo(QWidget *parent):BusquedaMaestra(parent)
{
    IniciarCampos();
    Fab=BD->Fabrica->CrearArticuloTipo();
}

void BusquedaArticuloTipo::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" << "Nombre";
    ComboCampos->addItems(campos);
}


void BusquedaArticuloTipo::ObtenerConsulta()
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

    ArticuloTipo ObjetoConsulta;

    switch (index)
    {
    case 1:
        ObjetoConsulta.setCodigo(LineNombre->text());
        break;
    case 2:
        ObjetoConsulta.setNombre(LineNombre->text());
        break;
    default:
        break;
    }


    BD->Fabrica->Conectar();

    QString Extra=" order by codigo "+ord+" LIMIT "+fin+" offset 0";
    QSqlQueryModel* Model= Fab->BuscarTabla(ObjetoConsulta,Extra,CAMPOS);
    BD->Fabrica->Desconectar();


    Model->setHeaderData(0,Qt::Horizontal,"Codigo");
    Model->setHeaderData(1,Qt::Horizontal,"Nombre");
    Model->setHeaderData(2,Qt::Horizontal,"CodigoImagen");
    Model->setHeaderData(3,Qt::Horizontal,"Ruta");

    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);

    emit my_signal(Model,CamposVisibles);
    emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta),fin.toInt(),ord);
    VisorConsulta->move(this->x(),this->y()+this->height());

}

