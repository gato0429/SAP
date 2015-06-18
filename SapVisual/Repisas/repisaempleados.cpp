#include "repisaempleados.h"

RepisaEmpleados::RepisaEmpleados():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new Empleado);
}


void RepisaEmpleados::GrupoBotonesClick(QAbstractButton *buttonID)
{

    // buttonID->setEnabled(false);
     /*Cambia*/
     Dialogo=new FormEmpleado(this);
     Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
     Dialogo->SetEmpleado(*((Empleado*)MapaRepisa->value(buttonID->objectName())));
     ObjetosAbiertos.push_back(buttonID->objectName());
     buttonID->setEnabled(false);
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

    Busqueda=new BusquedaMaestra(this);

    QStringList campos;
    campos <<"Codigo" <<"Codigo Interno"<< "Nombre"<<"Direccion"<<"Email"<<"Descuento"<<"Fecha"<<"Sexo"<<"Dni"<<"Telefono";
    Busqueda->ComboCampos->addItems(campos);

    Busqueda->move(this->x()+this->width()-60,this->y()+90);
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
    Empleado *i=(Empleado*)(*it);
    pp->setObjectName(i->getCodigo());
    pp->setIcon(*i);
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

void RepisaEmpleados::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearEmpleado();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->ContarConsulta(ObjetoConsulta);
    QString extra=" order by "+OrderByCampo+" "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));
}




void RepisaEmpleados::ObtenerConsulta()
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
    Empleado* ObjetoBusqueda=new Empleado();

    switch (IndiceBusqueda)
    {

    case 0:
        ObjetoBusqueda->setCodigo(LineBuscar->text());
        OrderByCampo="codigo";
        break;
    case 1:
        ObjetoBusqueda->setCodigoInterno(LineBuscar->text());
        OrderByCampo="codigo_interno";
        break;
    case 2:
        ObjetoBusqueda->setNombre(LineBuscar->text());
        OrderByCampo="nombre";
        break;
    case 3:
        ObjetoBusqueda->setDireccion(LineBuscar->text());
        OrderByCampo="direccion";
        break;
    case 4:
        ObjetoBusqueda->setEmail(LineBuscar->text());
        OrderByCampo="email";
        break;
    case 5:
        ObjetoBusqueda->setDescuento(LineBuscar->text().toDouble());
        break;
    case 6:
        OrderByCampo="fecha";
        ObjetoBusqueda->setFechaIngreso(FechaInicio->date());
        ObjetoBusqueda->setFechaFin(FechaFin->date());

        break;
    case 7:
        OrderByCampo="sexo";
        ObjetoBusqueda->setSexo(ComboTipo->currentText());
        break;
    case 8:
        OrderByCampo="dni";
        ObjetoBusqueda->setDni(LineBuscar->text());
        break;
    case 9:
        OrderByCampo="telefono";
        ObjetoBusqueda->setTelefono(LineBuscar->text());
        break;
    default:
        break;
    }


    Bd->Fabrica->Conectar();


    QString Extra=" order by "+OrderByCampo+" "+ord+" LIMIT "+QString::number(RegistrosBusqueda)+" offset 0";
    QSqlQueryModel* Model= FabricaLocal->BuscarTabla(*ObjetoBusqueda,Extra,CAMPOS);
    Bd->Fabrica->Desconectar();


    Model->setHeaderData(0,Qt::Horizontal,"Codigo");
    Model->setHeaderData(1,Qt::Horizontal,"Codigo Interno");
    Model->setHeaderData(2,Qt::Horizontal,"Dni");
    Model->setHeaderData(3,Qt::Horizontal,"Sexo");
    Model->setHeaderData(4,Qt::Horizontal,"Nombre");
    Model->setHeaderData(5,Qt::Horizontal,"Direccion");
    Model->setHeaderData(6,Qt::Horizontal,"Email");
    Model->setHeaderData(7,Qt::Horizontal,"Descuento");
    Model->setHeaderData(8,Qt::Horizontal,"Fecha");
    Model->setHeaderData(9,Qt::Horizontal,"Telefono");

    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);


    emit my_signal(Model,CamposVisibles);
//    ActualizarRepisaLocal((ObjetoMaestro*)(&ObjetoBusqueda),RegistrosBusqueda,ord);
    ActualizarMapa((ObjetoMaestro*)ObjetoBusqueda);

}


void RepisaEmpleados::ConsultarBusqueda()
{


    if(IndiceBusqueda==7)
    {
        MostrarCombo();
        ComboTipo->clear();
        ComboTipo->addItem("Masculino");
        ComboTipo->addItem("Femenino");
        return;
   }

    if(IndiceBusqueda==6)
    {
        MostrarFecha();
        return;
    }

    MostrarLabel();


    return;
qDebug()<<"Tipo en seleccion"<<IndiceBusqueda;

}
