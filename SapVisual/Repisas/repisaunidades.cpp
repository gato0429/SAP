#include "repisaunidades.h"

RepisaUnidades::RepisaUnidades()
{
    ActualizarMapa((ObjetoMaestro*)new Unidad());

}


void RepisaUnidades::GrupoBotonesClick(QAbstractButton *buttonID)
{
    Dialogo=new FormUnidad(this);
    Dialogo->move(this->x()+this->width(),this->y()); //siempre igual
    Dialogo->SetObjeto(*((Unidad*)MapaRepisa->value(buttonID->objectName())));
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
    Unidad *i=(Unidad*)(*it);
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

    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);

    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

}


void RepisaUnidades::RecibirTipoConsulta(int index, bool detalle, int registros)
{
}

void RepisaUnidades::ObtenerConsulta()
{
    /*QString fin=LineFin->text();
    QString ord;
    int index=ComboCampos->currentIndex();


    if(GrupoBoton->button(1)->isChecked())
    {
        ord="asc";
    }
    if(GrupoBoton->button(2)->isChecked())
    {
        ord="desc";
    }

    Unidad ObjetoConsulta;

    switch (index)
    {
    case 1:
        ObjetoConsulta.setCodigo(LineNombre->text());
        break;
    case 2:
        ObjetoConsulta.setNombre(LineNombre->text());
        break;
    case 3:
        ObjetoConsulta.setSimbolo(LineNombre->text());
        break;
    default:
        break;
    }


    BD->Fabrica->Conectar();

    QString Extra=" order by codigo "+ord+" LIMIT "+fin+" offset 0";
    QSqlQueryModel* Model= Fab->BuscarTabla(ObjetoConsulta,Extra,CAMPOS);
    BD->Fabrica->Desconectar();


    Model->setHeaderData(0,Qt::Horizontal,"Codigo");
    Model->setHeaderData(1,Qt::Horizontal,"Nombre");
    Model->setHeaderData(2,Qt::Horizontal,"Simbolo");
    Model->setHeaderData(3,Qt::Horizontal,"Codigo Imagen");
    Model->setHeaderData(4,Qt::Horizontal,"Ruta");

    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);*/

    /*
        emit my_signal(Model,CamposVisibles);

        emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta),fin.toInt(),ord);
        VisorConsulta->move(this->x(),this->y()+this->height());
    */
}
