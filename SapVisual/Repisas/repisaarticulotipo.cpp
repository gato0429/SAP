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

    MapaRepisa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);

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
    ArticuloTipo *i=(ArticuloTipo*)(*it);
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
    Dialogo->SetArticuloTipo(i,*((ArticuloTipo*)MapaRepisa->value(buttonID->objectName())));
    /**/
    Dialogo->show();
}


void RepisaArticuloTipo::RecibirTipoConsulta(int index, bool detalle, int registros)
{
}

void RepisaArticuloTipo::ObtenerConsulta()
{
/*
    QString fin=LineFin->text();
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

    ArticuloTipo ObjetoConsulta;

    switch (index)
    {
    case 1:
        ObjetoConsulta.setCodigo(LineNombre->text());
        break;
    case 2:
        ObjetoConsulta.setNombre(LineNombre->text());
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
    Model->setHeaderData(2,Qt::Horizontal,"CodigoImagen");
    Model->setHeaderData(3,Qt::Horizontal,"Ruta");

    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(false);
    CamposVisibles.push_back(true);*/

/*    emit my_signal(Model,CamposVisibles);
    emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta),fin.toInt(),ord);
    VisorConsulta->move(this->x(),this->y()+this->height());
*/
}
