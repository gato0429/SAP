#include "repisaarticulo.h"

RepisaArticulo::RepisaArticulo():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new Articulo());
    LabelTitulo->setText("Articulos");


    //Ordenamiento="asc";
}


void RepisaArticulo::ObjetosIndependientes()
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

void RepisaArticulo::ActualizarConsulta()
{


    FabricaLocal=Bd->Fabrica->CrearArticulo();
    Bd->Fabrica->Conectar();
    RegistrosTabla=FabricaLocal->Contar();
    QString extra=" order by codigo "+Ordenamiento+" LIMIT "+ QString::number(cantidadMostrar) +" offset "+QString::number(TotalElementos);
    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    Mapa=FabricaLocal->MapaRepisaGlobal;
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
  //   Dialogo->SetArticulo(*((Articulo*)MapaRepisa->value(buttonID->objectName())));
     Dialogo->SetObjeto(((Articulo*)MapaRepisa->value(buttonID->objectName())));

     ObjetosAbiertos.push_back(buttonID->objectName());
     buttonID->setEnabled(false);

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
    Busqueda=new BusquedaMaestra(this);

    QStringList campos;
    campos <<"Codigo"<<"Codigo Interno"<<"Codigo Externo" <<"Nombre"<<"Cantidad Minima"<<"Grupo"<<"Vigencia"<< "Familia"<<"Unidad"<<"Modelo"<<"Marca"<<"Moneda"<<"Precio";
    Busqueda->ComboCampos->addItems(campos);

    Busqueda->move(this->x()+this->width()-60,this->y()+90);
    Busqueda->show();

    Nuevo->setEnabled(false);
    Buscar->setEnabled(false);
}



void RepisaArticulo::ObtenerConsulta()
{

    QString ord;

   // if(GrupoBoton->button(1)->isChecked())
    {
        ord="asc";
    }
 //   if(GrupoBoton->button(2)->isChecked())
    {
        ord="desc";
    }

    Ordenamiento=ord;
    OrderByCampo="codigo";
     Articulo* ObjetoBusqueda=new Articulo();


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
        ObjetoBusqueda->setCodigoExterno(LineBuscar->text());
        OrderByCampo="codigo_externo";
        break;
    case 3:
        ObjetoBusqueda->setNombre(LineBuscar->text());
        OrderByCampo="nombre";
        break;
    case 4:
        ObjetoBusqueda->setCantidadMin(LineBuscar->text().toDouble());
        OrderByCampo="cantidad_min";
        break;
    case 5:
        ObjetoBusqueda->setUnico(ComboTipo->currentText());
        OrderByCampo="unico";
        break;
    case 6:
        ObjetoBusqueda->setVigencia(ComboTipo->currentText());
        OrderByCampo="vigencia";
        break;
    case 7:
        ObjetoBusqueda->setNombreTipo(ComboTipo->currentText());
        OrderByCampo="nombre_tipo";
        break;
    case 8:
        ObjetoBusqueda->setNombreUnidad(ComboTipo->currentText());
        OrderByCampo="nombre_unidad";
        break;
    case 9:
        ObjetoBusqueda->setNombreModelo(ComboTipo->currentText());
        OrderByCampo="nombre_modelo";
        break;
    case 10:
        ObjetoBusqueda->setNombreMarca(ComboTipo->currentText());
        OrderByCampo="nombre_marca";
        break;
    case 11:
        ObjetoBusqueda->setNombreMoneda(ComboTipo->currentText());
        OrderByCampo="nombre_moneda";
        break;
    case 12:
        ObjetoBusqueda->setPrecio(LineBuscar->text().toDouble());
        OrderByCampo="precio";
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
    Model->setHeaderData(2,Qt::Horizontal,"Codigo Externo");

    Model->setHeaderData(3,Qt::Horizontal,"Nombre");
    Model->setHeaderData(4,Qt::Horizontal,"Cant. Min.");
    Model->setHeaderData(5,Qt::Horizontal,"Unico");

    Model->setHeaderData(6,Qt::Horizontal,"Codigo Imagen");
    Model->setHeaderData(7,Qt::Horizontal,"Ruta Imagen");
    Model->setHeaderData(8,Qt::Horizontal,"Vigencia");

    Model->setHeaderData(9,Qt::Horizontal,"Codigo Unidad");
    Model->setHeaderData(10,Qt::Horizontal,"Unidad");
    Model->setHeaderData(11,Qt::Horizontal,"Uni.");
    Model->setHeaderData(12,Qt::Horizontal,"Ruta Unidad");

    Model->setHeaderData(13,Qt::Horizontal,"Codigo Tipo");
    Model->setHeaderData(14,Qt::Horizontal,"Tipo");
    Model->setHeaderData(15,Qt::Horizontal,"Ruta Tipo");

    Model->setHeaderData(16,Qt::Horizontal,"Codigo Modelo");
    Model->setHeaderData(17,Qt::Horizontal,"Modelo");
    Model->setHeaderData(18,Qt::Horizontal,"Ruta Modelo");

    Model->setHeaderData(19,Qt::Horizontal,"Codigo Marca");
    Model->setHeaderData(20,Qt::Horizontal,"Marca");
    Model->setHeaderData(21,Qt::Horizontal,"Ruta Marca");

    Model->setHeaderData(22,Qt::Horizontal,"Codigo Moneda");
    Model->setHeaderData(23,Qt::Horizontal,"Moneda");
    Model->setHeaderData(24,Qt::Horizontal,"Simb.");
    Model->setHeaderData(25,Qt::Horizontal,"Ruta Moneda");
    Model->setHeaderData(26,Qt::Horizontal,"Precio");
    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);

    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);

    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(false);

    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);


    emit my_signal(Model,CamposVisibles);
    ActualizarMapa((ObjetoMaestro*)ObjetoBusqueda);

}


void RepisaArticulo::ConsultarBusqueda()
{
    QMap<QString, ObjetoMaestro*>* MapaCombo;

    if(IndiceBusqueda==5)
    {
        MostrarCombo();
        ComboTipo->clear();
        ComboTipo->addItem("General");
        ComboTipo->addItem("Unico");
        return;
   }
    if(IndiceBusqueda==6)
    {
        MostrarCombo();
        ComboTipo->clear();
        ComboTipo->addItem("Vigente");
        ComboTipo->addItem("Inactivo");
        return;
   }

    if(IndiceBusqueda==7)
    {
        MostrarCombo();
        FabricaArticuloTipos * Fab=Bd->Fabrica->CrearArticuloTipo();
        Bd->Fabrica->Conectar();
        MapaCombo=Fab->BuscarMapa((ObjetoMaestro*)new ArticuloTipo()," order by nombre asc ",TODO);
        Bd->Fabrica->Desconectar();
        ComboTipo->clear();

        foreach (const QString &str, MapaCombo->keys())
        {
           ArticuloTipo* m=(ArticuloTipo*)MapaCombo->value(str);
           ComboTipo->addItem(QIcon(RutaImagenes+m->getImagen()),m->getNombre());
        }

        return;
    }
    if(IndiceBusqueda==8)
    {
        MostrarCombo();
        FabricaUnidades * Fab=Bd->Fabrica->CrearUnidad();
        Bd->Fabrica->Conectar();
        MapaCombo=Fab->BuscarMapa((ObjetoMaestro*)new Unidad()," order by nombre asc ",TODO);
        Bd->Fabrica->Desconectar();
        ComboTipo->clear();

        foreach (const QString &str, MapaCombo->keys())
        {
           Unidad* m=(Unidad*)MapaCombo->value(str);
           ComboTipo->addItem(QIcon(RutaImagenes+m->getRutaImagen()),m->getNombre());
        }

        return;
    }
    if(IndiceBusqueda==9)
    {
        MostrarCombo();
        FabricaModelo * Fab=Bd->Fabrica->CrearModelo();
        Bd->Fabrica->Conectar();
        MapaCombo=Fab->BuscarClave();
        Bd->Fabrica->Desconectar();
        ComboTipo->clear();

        foreach (const QString &str, MapaCombo->keys())
        {
           Modelo* m=(Modelo*)MapaCombo->value(str);
           ComboTipo->addItem(QIcon(RutaImagenes+m->getRutaImagen()),m->getNombre());
        }

        return;
    }
    if(IndiceBusqueda==10)
    {
        MostrarCombo();
        FabricaMarca * Fab=Bd->Fabrica->CrearMarca();
        Bd->Fabrica->Conectar();
        MapaCombo=Fab->BuscarMapa((ObjetoMaestro*)new Marca()," order by nombre asc ",TODO);
        Bd->Fabrica->Desconectar();
        ComboTipo->clear();

        foreach (const QString &str, MapaCombo->keys())
        {
           Marca* m=(Marca*)MapaCombo->value(str);
           ComboTipo->addItem(QIcon(RutaImagenes+m->getRutaImagen()),m->getNombre());
        }

        return;
    }
    if(IndiceBusqueda==11)
    {
        MostrarCombo();
        FabricaMoneda * Fab=Bd->Fabrica->CrearMoneda();
        Bd->Fabrica->Conectar();
        MapaCombo=Fab->BuscarMapa((ObjetoMaestro*)new Moneda()," order by nombre asc ",TODO);
        Bd->Fabrica->Desconectar();
        ComboTipo->clear();

        foreach (const QString &str, MapaCombo->keys())
        {
           Moneda* m=(Moneda*)MapaCombo->value(str);
           ComboTipo->addItem(QIcon(RutaImagenes+m->getRutaImagen()),m->getNombre());
        }

        return;
    }
    MostrarLabel();


    return;
}
