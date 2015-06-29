#include "repisamodelo.h"

RepisaModelo::RepisaModelo()
{
    ActualizarMapa((ObjetoMaestro*)new Modelo);
}



void RepisaModelo::ConsultarBusqueda()
{
}

void RepisaModelo::GrupoBotonesClick(QAbstractButton *buttonID)
{
    /*Cambia*/
    Dialogo=new FormModelo(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(((Marca*)MapaRepisa->value(buttonID->objectName())));
    ObjetosAbiertos.push_back(buttonID->objectName());
    buttonID->setEnabled(false);
    /**/
    Dialogo->show();
}


void RepisaModelo::NuevoClick()
{
    Dialogo=new FormModelo(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}
void RepisaModelo::BuscarClick()
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

void RepisaModelo::ObtenerConsulta()
{
}

void RepisaModelo::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Modelo *i=(Modelo*)(*it);
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getRutaImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre());
    GrupoBotones->addButton(pp);

    Botones.push_back(pp);
    //qDebug()<<i->getCodigo();
    pp->setVisible(true);
    if(ObjetosAbiertos.contains(i->getCodigo()))
    {
        pp->setEnabled(false);
    }

}

void RepisaModelo::ActualizarConsulta()
{

    FabricaLocal=Bd->Fabrica->CrearModelo();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->ContarConsulta(ObjetoConsulta);
    QString extra=" order by "+OrderByCampo+" "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}
