#include "repisaunidades.h"

RepisaUnidades::RepisaUnidades()
{
    ActualizarMapa((ObjetoMaestro*)new Unidad());

}


void RepisaUnidades::GrupoBotonesClick(QAbstractButton *buttonID)
{
    Dialogo=new FormUnidad(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(*((Unidad*)Mapa->value(buttonID->objectName())));
    /**/
    Dialogo->show();
}

void RepisaUnidades::NuevoClick()
{
    Dialogo=new FormUnidad(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();

}

void RepisaUnidades::BuscarClick()
{
    Busqueda=new BusquedaUnidad(this);
    Busqueda->move(this->x()+this->width(),this->y());
    Busqueda->show();
    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}

void RepisaUnidades::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Unidad *i=(Unidad*)(it.value());
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

void RepisaUnidades::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearUnidad();
    Bd->Fabrica->Conectar();

    RegistrosTabla=FabricaLocal->Contar();
    // qDebug()<<"elem:"+TotalElementos;

    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    qDebug()<<"aqui toy as";

    Mapa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);

    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}
