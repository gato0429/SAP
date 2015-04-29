#include "repisaimagenes.h"

RepisaImagenes::RepisaImagenes()
{
     ActualizarMapa(new Imagen());
}
RepisaImagenes* RepisaImagenes::mUnico=0;

void RepisaImagenes::ActualizarMapa(ObjetoMaestro *Objeto)
{
    FabricaLocal=Bd->Fabrica->CrearImagen();
    Bd->Fabrica->Conectar();
    Mapa=FabricaLocal->BuscarMapa(*((Imagen*)Objeto),CAMPOS);
    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    it=Mapa->begin();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));
    SiguienteClick();
}

void RepisaImagenes::ObjetosIndependientes()
{
    QPushButton* pp=new QPushButton(this);
    Imagen *i=(Imagen*)(it.value());

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

RepisaImagenes *RepisaImagenes::Iniciar()
{
    if(mUnico==NULL)
    {
        mUnico=new RepisaImagenes();
    }

    return mUnico;
}

void RepisaImagenes::ActualizarConsulta()
{

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
