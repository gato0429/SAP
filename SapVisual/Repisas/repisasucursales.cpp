#include "repisasucursales.h"

RepisaSucursales::RepisaSucursales(): Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new Sucursales);
}

void RepisaSucursales::ConsultarBusqueda()
{
    MostrarLabel();
    return;
}

void RepisaSucursales::GrupoBotonesClick(QAbstractButton *buttonID)
{
    /*Cambia*/
    /*Dialogo=new FormSucursales(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(((Sucursales*)MapaRepisa->value(buttonID->objectName())));
    ObjetosAbiertos.push_back(buttonID->objectName());
    buttonID->setEnabled(false);

    Dialogo->show();
    */
}

void RepisaSucursales::NuevoClick()
{
   /* Dialogo=new FormSucursal(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
    */
}

void RepisaSucursales::BuscarClick()
{
    Busqueda=new BusquedaMaestra(this);

    QStringList campos;
    campos <<"Codigo" << "Nombre"<< "Direccion"<< "Telefono"<< "Ruc"<< "Codigo Imagen";
    Busqueda->ComboCampos->addItems(campos);

    Busqueda->move(this->x()+this->width()-60,this->y()+90);
    Busqueda->show();

    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}

void RepisaSucursales::ObtenerConsulta()
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
    Sucursales* ObjetoBusqueda=new Sucursales();

    switch (IndiceBusqueda)
    {
    case 0:
        ObjetoBusqueda->setCodigo(LineBuscar->text());
        OrderByCampo="codigo";
        break;
    case 1:
        ObjetoBusqueda->setNombre(LineBuscar->text());
        OrderByCampo="nombre";
        break;
    case 2:
        ObjetoBusqueda->setDireccion(LineBuscar->text());
        OrderByCampo="direccion";
        break;
    case 3:
        ObjetoBusqueda->setTelefono(LineBuscar->text());
        OrderByCampo="telefono";
        break;
    case 4:
        ObjetoBusqueda->setRuc(LineBuscar->text());
        OrderByCampo="ruc";
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

void RepisaSucursales::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Sucursales *i=(Sucursales*)(*it);
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

void RepisaSucursales::ActualizarConsulta()
{

    FabricaLocal=Bd->Fabrica->CrearSucursales();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->ContarConsulta(ObjetoConsulta);
    QString extra=" order by "+OrderByCampo+" "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}

