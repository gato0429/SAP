#include "repisaarticulo.h"

RepisaArticulo::RepisaArticulo():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new Articulo());
    //Ordenamiento="asc";
}


void RepisaArticulo::ObjetosIndependientes()
{

    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Articulo *i=(Articulo*)(it.value());
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getRutaImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre()+"\n"+"Tipo: "+i->getNombreTipo());
    GrupoBotones->addButton(pp);
    Botones.push_back(pp);
    pp->setVisible(true);

}

void RepisaArticulo::ActualizarConsulta()
{


    FabricaLocal=Bd->Fabrica->CrearArticulo();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->Contar();
    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    Mapa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));
}


void RepisaArticulo::GrupoBotonesClick(QAbstractButton* buttonID)
{
    // buttonID->setEnabled(false);
     int i=GrupoBotones->id(buttonID);
     /*Cambia*/
     Dialogo=new FormArticulo(this);
     Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
     Dialogo->SetArticulo(*((Articulo*)Mapa->value(buttonID->objectName())));
     /**/
     Dialogo->show();
}


void RepisaArticulo::NuevoClick()
{
    Dialogo=new FormArticulo(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}

void RepisaArticulo::BuscarClick()
{
    Busqueda=new BusquedaArticulo(this);
    Busqueda->move(this->x()+this->width(),this->y());
    Busqueda->show();
    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}
