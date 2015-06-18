#include "repisaimagenes.h"

RepisaImagenes::RepisaImagenes()
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
    pp->setVisible(true);
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

    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}

void RepisaImagenes::NuevoClick()
{
    Dialogo=new FormImagenes(this);
    Dialogo->show();
}

void RepisaImagenes::BuscarClick()
{

}

void RepisaImagenes::GrupoBotonesClick(QAbstractButton *buttonID)
{
  //  Dialogo=new FormImagenes(this);

    //Dialogo->SetArticuloTipo(*((Imagen*)Mapa->value(buttonID->objectName())));
    //Dialogo->show();
}
