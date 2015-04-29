#include "repisaarticulotipo.h"

RepisaArticuloTipo::RepisaArticuloTipo():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new ArticuloTipo());

}


void RepisaArticuloTipo::NuevoClick()
{
    Dialogo=new FormArticuloTipo(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}


void RepisaArticuloTipo::BuscarClick()
{
    Busqueda=new BusquedaArticuloTipo(this);
    Busqueda->move(this->x()+this->width(),this->y());
    Busqueda->show();
    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);

}
void RepisaArticuloTipo::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();

    RegistrosTabla=FabricaLocal->Contar();
    // qDebug()<<"elem:"+TotalElementos;

    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    qDebug()<<"aqui toy";

    Mapa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);

    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));
}


void RepisaArticuloTipo::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    ArticuloTipo *i=(ArticuloTipo*)(it.value());
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre());
    GrupoBotones->addButton(pp);
    Botones.push_back(pp);
    pp->setVisible(true);

}



void RepisaArticuloTipo::GrupoBotonesClick(QAbstractButton* buttonID)
{
   // buttonID->setEnabled(false);
    int i=GrupoBotones->id(buttonID);
    /*Cambia*/
    Dialogo=new FormArticuloTipo(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetArticuloTipo(i,*((ArticuloTipo*)Mapa->value(buttonID->objectName())));
    /**/
    Dialogo->show();
}
