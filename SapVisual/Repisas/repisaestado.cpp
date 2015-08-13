#include "repisaestado.h"

RepisaEstado::RepisaEstado():Repisa()
{
     ActualizarMapa((ObjetoMaestro*)new Estado);
}

void RepisaEstado::ConsultarBusqueda()
{
    MostrarLabel();
    return;
}

void RepisaEstado::GrupoBotonesClick(QAbstractButton *buttonID)
{
    /*Cambia*/
    Dialogo=new FormEstado(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(((Estado*)MapaRepisa->value(buttonID->objectName())));
    ObjetosAbiertos.push_back(buttonID->objectName());
    buttonID->setEnabled(false);
    /**/

    Dialogo->show();
}

void RepisaEstado::NuevoClick()
{
    Dialogo=new FormEstado(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}

void RepisaEstado::BuscarClick()
{
    Busqueda=new BusquedaMaestra(this);

    QStringList campos;
    campos <<"Codigo" <<"Codigo Imagen"<< "Nombre";
    Busqueda->ComboCampos->addItems(campos);

    Busqueda->move(this->x()+this->width()-60,this->y()+90);
    Busqueda->show();

    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}

void RepisaEstado::ObtenerConsulta()
{
    QString ord;

  //  if(GrupoBoton->button(1)->isChecked())
    {
        ord="asc";
    }
  //  if(GrupoBoton->button(2)->isChecked())
    {
        ord="desc";
    }
    Ordenamiento=ord;
    OrderByCampo="codigo";
    Estado* ObjetoBusqueda=new Estado();

    switch (IndiceBusqueda)
    {
    case 0:
        ObjetoBusqueda->setCodigo(LineBuscar->text());
        OrderByCampo="codigo";
        break;
    case 1:
        ObjetoBusqueda->setCodigoImagen(LineBuscar->text());
        OrderByCampo="codigo_imagen";
        break;
    case 2:
        ObjetoBusqueda->setNombre(LineBuscar->text());
        OrderByCampo="nombre";
        break;
    default:
        break;
    }


    Bd->Fabrica->Conectar();


    QString Extra=" order by "+OrderByCampo+" "+ord+" LIMIT "+QString::number(RegistrosBusqueda)+" offset 0";
    QSqlQueryModel* Model= FabricaLocal->BuscarTabla(*ObjetoBusqueda,Extra,CAMPOS);
    Bd->Fabrica->Desconectar();


    Model->setHeaderData(0,Qt::Horizontal,"Codigo");
    Model->setHeaderData(1,Qt::Horizontal,"Nombre");
    Model->setHeaderData(2,Qt::Horizontal,"Codigo Imagen");
    Model->setHeaderData(3,Qt::Horizontal,"Ruta");


    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);


    emit my_signal(Model,CamposVisibles);
    ActualizarMapa((ObjetoMaestro*)ObjetoBusqueda);
}

void RepisaEstado::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Estado *i=(Estado*)(*it);
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getRutaImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre());
    GrupoBotones->addButton(pp);

    Botones.push_back(pp);
    //qDebug()<<i->getCodigo();

    pp->setParent(FondoRepisa);
    pp->setVisible(true);
    if(ObjetosAbiertos.contains(i->getCodigo()))
    {
        pp->setEnabled(false);
    }
}

void RepisaEstado::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearEstado();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->ContarConsulta(ObjetoConsulta);
    QString extra=" order by "+OrderByCampo+" "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}

