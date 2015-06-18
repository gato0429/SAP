#include "repisaarticuloalias.h"

RepisaArticuloAlias::RepisaArticuloAlias()
{
        ActualizarMapa((ObjetoMaestro*)new Articulo());
}


void RepisaArticuloAlias::GrupoBotonesClick(QAbstractButton *buttonID)
{
    // buttonID->setEnabled(false);
     int i=GrupoBotones->id(buttonID);
     /*Cambia*/
     Dialogo=new FormArticuloAlias(this);
     Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
     Dialogo->SetArticulo(*((Articulo*)MapaRepisa->value(buttonID->objectName())));
     /**/
     Dialogo->show();
}

void RepisaArticuloAlias::NuevoClick()
{
    Dialogo=new FormArticuloAlias(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}

void RepisaArticuloAlias::BuscarClick()
{
    /*
    Busqueda=new BusquedaArticulo(this);
    Busqueda->move(this->x()+this->width(),this->y());
    Busqueda->show();
    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
    */
}

void RepisaArticuloAlias::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Articulo *i=(Articulo*)(*it);
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getRutaImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre());
    GrupoBotones->addButton(pp);
    Botones.push_back(pp);
    pp->setVisible(true);

}

void RepisaArticuloAlias::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearArticulo();
    Bd->Fabrica->Conectar();

    RegistrosTabla=FabricaLocal->Contar();
    // qDebug()<<"elem:"+TotalElementos;

    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    qDebug()<<"aqui toy";

    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}
