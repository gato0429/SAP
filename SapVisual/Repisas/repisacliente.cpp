#include "repisacliente.h"

RepisaCliente::RepisaCliente():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new Cliente());
    LabelTitulo->setText("Clientes");

}



void RepisaCliente::ConsultarBusqueda()
{
    if (IndiceBusqueda==2)
    {

        MostrarCombo();
        FabricaClienteTipo * Fab=Bd->Fabrica->CrearClienteTipo();
        Bd->Fabrica->Conectar();
        MapaCombo=Fab->BuscarMapa((ObjetoMaestro*)new ClienteTipo()," ",TODO);
        Bd->Fabrica->Desconectar();
        ComboTipo->clear();

        foreach (const QString &str, MapaCombo->keys())
        {
           ClienteTipo* m=(ClienteTipo*)MapaCombo->value(str);
           ComboTipo->addItem(QIcon(RutaImagenes+m->getRutaImagen()),m->getNombre());
        }

        return;
    }
    if (IndiceBusqueda==3)
    {
        MostrarCombo();
        ComboTipo->clear();
        ComboTipo->addItem("Dni");
        ComboTipo->addItem("Ruc");

        return;

    }

    if (IndiceBusqueda==13)
    {
        MostrarFecha();

        return;

    }
    MostrarLabel();
    return;
}

void RepisaCliente::GrupoBotonesClick(QAbstractButton *buttonID)
{
    // buttonID->setEnabled(false);
     int i=GrupoBotones->id(buttonID);
     /*Cambia*/
     Dialogo=new FormCliente(this);
     Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
  //   Dialogo->SetArticulo(*((Articulo*)MapaRepisa->value(buttonID->objectName())));
     Dialogo->SetObjeto(((Cliente*)MapaRepisa->value(buttonID->objectName())));

     ObjetosAbiertos.push_back(buttonID->objectName());
     buttonID->setEnabled(false);

     /**/
     Dialogo->show();
}

void RepisaCliente::NuevoClick()
{
    Dialogo=new FormCliente(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();
}

void RepisaCliente::BuscarClick()
{
    Busqueda=new BusquedaMaestra(this);

    QStringList campos;
    campos <<"Codigo"<<"Codigo Interno"<<"Tipo"<<"Documento"<<"Nro Doc"<<"Nombre"<<"Direccion"<<"Pais"<<"Contacto"<< "Telefono"<<"Email"<<"Web"<<"Descuento"<<"Fecha";
    Busqueda->ComboCampos->addItems(campos);

    Busqueda->move(this->x()+this->width()-60,this->y()+90);
    Busqueda->show();

    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}

void RepisaCliente::ObtenerConsulta()
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
    Cliente* ObjetoBusqueda=new Cliente();

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
        ObjetoBusqueda->setNombreTipo(ComboTipo->currentText());
        OrderByCampo="nombre_tipo";
        break;
    case 3:
        ObjetoBusqueda->setTipo(ComboTipo->currentText());
        OrderByCampo="tipo";
        break;
    case 4:
        ObjetoBusqueda->setNumDoc(LineBuscar->text());
        OrderByCampo="num_doc";
        break;
    case 5:
        ObjetoBusqueda->setNombre(LineBuscar->text());
        OrderByCampo="nombre";
        break;
    case 6:
        ObjetoBusqueda->setDireccion(LineBuscar->text());
        OrderByCampo="direccion";
        break;
    case 7:
        ObjetoBusqueda->setPais(LineBuscar->text());
        OrderByCampo="pais";
        break;
    case 8:
        ObjetoBusqueda->setContacto(LineBuscar->text());
        OrderByCampo="direccion";
        break;
    case 9:
        ObjetoBusqueda->setTelefono(LineBuscar->text());
        OrderByCampo="telefono";
        break;
    case 10:
        ObjetoBusqueda->setEmail(LineBuscar->text());
        OrderByCampo="email";
        break;
    case 11:
        ObjetoBusqueda->setWeb(LineBuscar->text());
        OrderByCampo="web";
        break;
    case 12:
        ObjetoBusqueda->setDescuento(LineBuscar->text().toDouble());
        OrderByCampo="descuento";
        break;
    case 13:
        ObjetoBusqueda->setFecha(FechaInicio->date());
        ObjetoBusqueda->setFechaFin(FechaFin->date());
        OrderByCampo="fecha";
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
    Model->setHeaderData(2,Qt::Horizontal,"Documento");
    Model->setHeaderData(3,Qt::Horizontal,"Nro");
    Model->setHeaderData(4,Qt::Horizontal,"Tipo");
    Model->setHeaderData(5,Qt::Horizontal,"Nombre");
    Model->setHeaderData(6,Qt::Horizontal,"Direccion");
    Model->setHeaderData(7,Qt::Horizontal,"Pais");
    Model->setHeaderData(8,Qt::Horizontal,"Contacto");
    Model->setHeaderData(9,Qt::Horizontal,"Telefono");
    Model->setHeaderData(10,Qt::Horizontal,"Email");
    Model->setHeaderData(11,Qt::Horizontal,"Web");
    Model->setHeaderData(12,Qt::Horizontal,"Descuento");
    Model->setHeaderData(13,Qt::Horizontal,"Fecha Registro");

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
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);

    emit my_signal(Model,CamposVisibles);
    ActualizarMapa((ObjetoMaestro*)ObjetoBusqueda);

}

void RepisaCliente::ObjetosIndependientes()
{

    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    Cliente *i=(Cliente*)(*it);
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getRutaImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre()+"\n"+"Tipo: "+i->getNombreTipo());
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

void RepisaCliente::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearCliente();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->Contar();
    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
    Bd->Fabrica->Desconectar();

    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}
