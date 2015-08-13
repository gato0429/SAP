#include "repisaoperaciones.h"

RepisaOperaciones::RepisaOperaciones()
{
    ActualizarMapa((ObjetoMaestro*)new Operaciones);
}

void RepisaOperaciones::ConsultarBusqueda()
{
    MostrarLabel();
    return;
}

void RepisaOperaciones::GrupoBotonesClick(QAbstractButton *buttonID)
{
    /*Cambia*/
    Dialogo=new FormOperaciones(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(((Operaciones*)MapaRepisa->value(buttonID->objectName())));
    ObjetosAbiertos.push_back(buttonID->objectName());
    buttonID->setEnabled(false);
    /**/
    Dialogo->show();
}

void RepisaOperaciones::NuevoClick()
{
    Dialogo=new FormOperaciones(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}

void RepisaOperaciones::BuscarClick()
{
    Busqueda=new BusquedaMaestra(this);

       QStringList campos;
       campos <<"Codigo" <<"Descripcion"<<"Codigo Imagen"<< "Nombre";
       Busqueda->ComboCampos->addItems(campos);

       Busqueda->move(this->x()+this->width()-60,this->y()+90);
       Busqueda->show();

       Nuevo->setEnabled(false);
       Buscar->setEnabled(false);
}

void RepisaOperaciones::ObtenerConsulta()
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
    Operaciones* ObjetoBusqueda=new Operaciones();

    switch (IndiceBusqueda)
    {
    case 0:
        ObjetoBusqueda->setCodigo(LineBuscar->text());
        OrderByCampo="codigo";
        break;
    case 1:
        ObjetoBusqueda->setDescripcion(LineBuscar->text());
        OrderByCampo="simbolo";
        break;
    case 2:
        ObjetoBusqueda->setCodigoImagen(LineBuscar->text());
        OrderByCampo="codigo_imagen";
        break;
    case 3:
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
    Model->setHeaderData(2,Qt::Horizontal,"Simbolo");
    Model->setHeaderData(3,Qt::Horizontal,"Codigo Imagen");
    Model->setHeaderData(4,Qt::Horizontal,"Ruta");


    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);


    emit my_signal(Model,CamposVisibles);
    ActualizarMapa((ObjetoMaestro*)ObjetoBusqueda);

}

void RepisaOperaciones::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Operaciones *i=(Operaciones*)(*it);
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

void RepisaOperaciones::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearOperaciones();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->ContarConsulta(ObjetoConsulta);
    QString extra=" order by "+OrderByCampo+" "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}

