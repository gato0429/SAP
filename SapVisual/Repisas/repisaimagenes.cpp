#include "repisaimagenes.h"

RepisaImagenes::RepisaImagenes():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new Imagen());
}


void RepisaImagenes::ObjetosIndependientes()
{
    QPushButton* pp=new QPushButton(this);
    Imagen *i=(Imagen*)(*it);

    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getCarpeta()+"/"+i->getNombre()));
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

void RepisaImagenes::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearImagen();
    Bd->Fabrica->Conectar();

    RegistrosTabla=FabricaLocal->Contar();
    // qDebug()<<"elem:"+TotalElementos;

    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    qDebug()<<"aqui toy as";

    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}

void RepisaImagenes::NuevoClick()
{
    Dialogo=new FormImagenes(this);
     Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->show();
}

void RepisaImagenes::BuscarClick()
{
    Busqueda=new BusquedaMaestra(this);

    QStringList campos;
    campos <<"Codigo" <<"Carpeta"<< "Nombre";
    Busqueda->ComboCampos->addItems(campos);

    Busqueda->move(this->x()+this->width()-60,this->y()+90);
    Busqueda->show();

    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}

void RepisaImagenes::GrupoBotonesClick(QAbstractButton *buttonID)
{
    Dialogo=new FormImagenes(this);
 Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(((Imagen*)MapaRepisa->value(buttonID->objectName())));

    ObjetosAbiertos.push_back(buttonID->objectName());
    buttonID->setEnabled(false);
Dialogo->show();
}


void RepisaImagenes::ConsultarBusqueda()
{
    MostrarLabel();
    return;
}

void RepisaImagenes::ObtenerConsulta()
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
    Imagen* ObjetoBusqueda=new Imagen();

    switch (IndiceBusqueda)
    {
    case 0:
        ObjetoBusqueda->setCodigo(LineBuscar->text());
        OrderByCampo="codigo";
        break;
    case 1:
        ObjetoBusqueda->setCarpeta(LineBuscar->text());
        OrderByCampo="carpeta";
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
    Model->setHeaderData(1,Qt::Horizontal,"Carpeta");
    Model->setHeaderData(2,Qt::Horizontal,"Nombre");
    Model->setHeaderData(3,Qt::Horizontal,"Pixel");


    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);


    emit my_signal(Model,CamposVisibles);
    ActualizarMapa((ObjetoMaestro*)ObjetoBusqueda);

}
