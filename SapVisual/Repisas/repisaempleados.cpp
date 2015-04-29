#include "repisaempleados.h"

RepisaEmpleados::RepisaEmpleados()
{
    ActualizarMapa((ObjetoMaestro*)new Empleado);
}


void RepisaEmpleados::GrupoBotonesClick(QAbstractButton *buttonID)
{

    // buttonID->setEnabled(false);
     /*Cambia*/
     Dialogo=new FormEmpleado(this);
     Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
     Dialogo->SetEmpleado(*((Empleado*)Mapa->value(buttonID->objectName())));
     /**/
     Dialogo->show();
}

void RepisaEmpleados::NuevoClick()
{
    Dialogo=new FormEmpleado(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();

}

void RepisaEmpleados::BuscarClick()
{

    Busqueda=new BusquedaEmpleado(this);
    Busqueda->move(this->x()+this->width(),this->y());
    Busqueda->show();
    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}

void RepisaEmpleados::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Empleado *i=(Empleado*)(it.value());
    pp->setObjectName(i->getCodigo());
    pp->setIcon(*i);
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre());
    GrupoBotones->addButton(pp);
    Botones.push_back(pp);
    qDebug()<<i->getCodigo();
    pp->setVisible(true);
}

void RepisaEmpleados::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearEmpleado();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->Contar();
    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    Mapa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));
}
