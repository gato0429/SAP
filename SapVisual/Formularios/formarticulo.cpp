#include "formarticulo.h"
#include "ui_formarticulo.h"

FormArticulo::FormArticulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormArticulo),FormMaestro()
{
    ui->setupUi(this);
    /*Dos Lineas Para el fondo Madera*/
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));


    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearArticulo();
    LlenarListaTipos();
    LlenarListaUnidad();
    Estados=INSERTAR;
    /*-----------------*/
    ui->BotonBusquedaImagen->setEnabled(true);
    ui->BotonEliminar->setEnabled(false);
    ui->BotonModificar->setEnabled(false);
    ui->BotonGuardar->setEnabled(true);
    ui->ListaTipo->setEnabled(true);
    ui->BotonBusquedaImagen->setEnabled(true);
    /*-------*/
    ui->BotonEliminarAlias->setEnabled(false);
    ui->BotonModificarAlias->setEnabled(false);
    ui->BotonGuardarAlias->setEnabled(false);
    ui->LineNombreAlias->setEnabled(false);
    ui->ListaAlias->setEnabled(true);
    ESTADOALIAS=INSERTAR;
        FabAlias=Bd->Fabrica->CrearArticuloAlias();
}

void FormArticulo::SetArticulo(Articulo Externo)
{

    /*----*/
    ui->BotonBusquedaImagen->setEnabled(true);
    ui->BotonEliminar->setEnabled(false);
    ui->BotonModificar->setEnabled(true);
    ui->BotonGuardar->setEnabled(false);
    ui->BotonBusquedaImagen->setEnabled(false);

    ui->ListaTipo->setEnabled(false);
    ui->LineNombre->setEnabled(false);
    ui->LineNombreTipo->setEnabled(false);
    ui->ComboVigencia->setEnabled(false);
    ui->LineSimbolo->setEnabled(false);
    ui->LineNombreUnidad->setEnabled(false);
    ui->ListaUnidad->setEnabled(false);
    ui->LineCodigoExterno->setEnabled(false);
    ui->LineCodigoInterno->setEnabled(false);
     /*-----*/
    Estados=MODIFICAR;
    ui->LineCodigo->setText(Externo.getCodigo());
    ui->LineCodTipo->setText(Externo.getCodigoTipo());
    ui->LineCodUnidad->setText(Externo.getCodigoUnidad());
    ui->LineCodigoInterno->setText(Externo.getCodigoInterno());
    ui->LineCodigoExterno->setText(Externo.getCodigoExterno());
    CodigoImagen=Externo.getCodigoImagen();

    ui->LineNombre->setText(Externo.getNombre());
    ui->LineImagen->setText(Externo.getRutaImagen());

    ui->ComboVigencia->setCurrentText(Externo.getVigencia());

     ui->LineNombreTipo->setText(Externo.getNombreTipo());
    ui->LineNombreUnidad->setText(Externo.getNombreUnidad());
    ui->LineSimbolo->setText(Externo.getSimboloUnidad());

    QPixmap pix;
    pix.load(RutaImagenes+Externo.getRutaImagenTipo());
    ui->LabelTipoImagen->setPixmap(pix.scaled(153,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    pix.load(RutaImagenes+Externo.getRutaImagenUnidad());
    ui->LabelUnidadImagen->setPixmap(pix.scaled(153,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    pix.load(RutaImagenes+Externo.getRutaImagen());
    ui->LabelImagen->setPixmap(pix.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    pix.load(RutaImagenes+Externo.getRutaImagen());
    ui->LabelImagenAlias->setPixmap(pix.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    LlenarListaAlias(Externo.getCodigo());
    ui->LineNombreAlias->setEnabled(false);
}

FormArticulo::~FormArticulo()
{

    delete ui;
}

void FormArticulo::LlenarListaTipos()
{
    FabricaArticuloTipos* FabTip=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();
    MapaTipos=FabTip->BuscarMapa((ObjetoMaestro*)new ArticuloTipo(),"",TODO);
    Bd->Fabrica->Desconectar();
    for(it=MapaTipos->begin(); it!=MapaTipos->end(); it++)
    {
        ArticuloTipo* art=(ArticuloTipo*)(it.value());
        ui->ListaTipo->addItem( new QListWidgetItem(QIcon(RutaImagenes+art->getImagen()),art->getNombre()));
    }

    QSqlQueryModel* Model;
    Bd->Fabrica->Conectar();

  /*  Model=new QSqlQueryModel();
    Model->setQuery("SELECT distinct nombre FROM articulo_tipo ;");
    QCompleter* Completar=new QCompleter(Model,this);
    Completar->setCaseSensitivity(Qt::CaseInsensitive);
    Completar->setCompletionColumn(0);
    ui->LineNombreTipo->setCompleter(Completar);
*/
    Bd->Fabrica->Desconectar();
}

void FormArticulo::LlenarListaUnidad()
{
    FabricaUnidades* FabUni=Bd->Fabrica->CrearUnidad();

    Bd->Fabrica->Conectar();
    MapaUnidad=FabUni->BuscarMapa((ObjetoMaestro*)new Unidad(),"",TODO);
    Bd->Fabrica->Desconectar();

    for(it_uni=MapaUnidad->begin(); it_uni!=MapaUnidad->end(); it_uni++)
    {
        Unidad* uni=(Unidad*)(it_uni.value());
        ui->ListaUnidad->addItem( new QListWidgetItem(QIcon(RutaImagenes+uni->getRutaImagen()),uni->getNombre()));
    }

    QSqlQueryModel* Model=new QSqlQueryModel();

    Bd->Fabrica->Conectar();
/*
    Model->setQuery("SELECT distinct nombre FROM unidad ;");
    QCompleter* Completar=new QCompleter(Model,this);
    Completar->setCaseSensitivity(Qt::CaseInsensitive);
    Completar->setCompletionColumn(0);
    ui->LineNombreUnidad->setCompleter(Completar);
*/
    Bd->Fabrica->Desconectar();
}

void FormArticulo::LlenarListaAlias(QString CodigoArticulo)
{

    ui->ListaAlias->clearSelection();
    ui->ListaAlias->clearFocus();

  ui->ListaAlias->clear();
    qDebug()<<"PASE EL CLEAR";
    Bd->Fabrica->Conectar();
    ArticuloAlias* obj=new ArticuloAlias();
    obj->setCodigoArticulo(CodigoArticulo);

    MapaAlias=FabAlias->BuscarMapa((ObjetoMaestro*)obj,"",CAMPOS);
    Bd->Fabrica->Desconectar();

    for(it_ali=MapaAlias->begin(); it_ali!=MapaAlias->end(); it_ali++)
    {
        ArticuloAlias* ali=(ArticuloAlias*)(it_ali.value());
        ui->ListaAlias->addItem( new QListWidgetItem(ali->getNombre()));
    }

}

bool FormArticulo::Guardar()
{
    if(!ValidarCampos())
    {
        return false;
    }

    /*------------*/
    AsignarCampos();
    /*------------*/

    if(Bd->Fabrica->Conectar())
    {
        if(Fab->Insertar(Objeto))
        {

            MensajeEmergente mensaje;
            mensaje.SetMensaje("Articulo Insertado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }

     Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormArticulo::Modificar()
{
    if(!ValidarCampos())
    {
        return false;
    }
    /*------*/
    AsignarCampos();
    /*-------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Actualizar(Antiguo,Objeto))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Articulo Modificado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }

        Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormArticulo::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Articulo Eliminado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
      Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormArticulo::ValidarCampos()
{
    if(ui->LineCodUnidad->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Unidad Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineCodTipo->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Tipo de Articulo Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineNombre->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineImagen->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Imagen Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

void FormArticulo::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());


    Objeto.setCodigoTipo(ui->LineCodTipo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setRutaImagen(ui->LineImagen->text());
    Objeto.setCodigoImagen(CodigoImagen);
    Objeto.setCodigoUnidad(ui->LineCodUnidad->text());
    Objeto.setCodigoInterno(ui->LineCodigoInterno->text());
    Objeto.setCodigoExterno(ui->LineCodigoExterno->text());
    Objeto.setVigencia(ui->ComboVigencia->currentText());
}

void FormArticulo::Habilitar()
{

}

void FormArticulo::Deshabilitar()
{

}

void FormArticulo::Limpiar()
{

}





void FormArticulo::on_ListaTipo_currentRowChanged(int currentRow)
{
    it=MapaTipos->begin();
    it+=currentRow;
    ArticuloTipo* art=(ArticuloTipo*)(it.value());
    ui->LineCodTipo->setText(it.key());
    ui->LineNombreTipo->setText(art->getNombre());

    QPixmap pix;
    pix.load(RutaImagenes+art->getImagen());
    ui->LabelTipoImagen->setPixmap(pix.scaled(153,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->LabelTipoImagen->setScaledContents(true);
}

void FormArticulo::on_LineNombreTipo_returnPressed()
{
    FabricaArticuloTipos* FabTip=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();
    ArticuloTipo art;
    art.setNombre(ui->LineNombreTipo->text());
    art=FabTip->Buscar(art);
    Bd->Fabrica->Desconectar();
    if(!art.getCodigo().isNull())
    {
    ui->LineCodTipo->setText(art.getCodigo());
    QPixmap pix;
    pix.load(RutaImagenes+art.getImagen());
    ui->LabelTipoImagen->setPixmap(pix.scaled(153,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}

void FormArticulo::on_BotonGuardar_clicked()
{
    if(Estados==INSERTAR)
    {
        if(Guardar())
        {
        emit ActualizarRepisa((ObjetoMaestro*)new Articulo());
        }
    }
    if(Estados==MODIFICAR)
    {
        if(Modificar())
        {emit ActualizarRepisa((ObjetoMaestro*)new Articulo());
        }
    }
}

void FormArticulo::on_BotonBusquedaImagen_clicked()
{
    VisorImagenes* visor=new VisorImagenes(this);
    visor->exec();
}

void FormArticulo::Ruta(QString Codigo, QString Cadena)
{
    QString fileName = Cadena;
    CodigoImagen=Codigo;
   if (!fileName.isEmpty())
   {
     QPixmap*  pix=new QPixmap(RutaImagenes+fileName);

       ui->LabelImagen->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
       ui->LineImagen->setText(fileName);
    }
}

void FormArticulo::on_BotonModificar_clicked()
{
    Estados=MODIFICAR;

    /*----*/
    ui->BotonBusquedaImagen->setEnabled(true);
    ui->BotonEliminar->setEnabled(false);
    ui->BotonModificar->setEnabled(false);
    ui->BotonGuardar->setEnabled(true);
    ui->BotonBusquedaImagen->setEnabled(true);

    ui->ListaTipo->setEnabled(true);
    ui->LineNombre->setEnabled(true);
    ui->LineNombreTipo->setEnabled(true);

    ui->ComboVigencia->setEnabled(true);

    ui->LineSimbolo->setEnabled(true);
    ui->LineNombreUnidad->setEnabled(true);
    ui->ListaUnidad->setEnabled(true);
    ui->LineCodigoExterno->setEnabled(true);
    ui->LineCodigoInterno->setEnabled(true);

     /*-----*/
}

void FormArticulo::on_tabWidget_tabBarClicked(int index)
{
    if(index==4)
    {
        this->close();
        this->destroy();
    }
}

void FormArticulo::on_ListaUnidad_currentRowChanged(int currentRow)
{
    it_uni=MapaUnidad->begin();
    it_uni+=currentRow;
    Unidad* uni=(Unidad*)(it_uni.value());
    ui->LineCodUnidad->setText(it_uni.key());
    ui->LineNombreUnidad->setText(uni->getNombre());
    ui->LineSimbolo->setText(uni->getSimbolo());
    QPixmap pix;
    pix.load(RutaImagenes+uni->getRutaImagen());
    ui->LabelUnidadImagen->setPixmap(pix.scaled(153,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->LabelUnidadImagen->setScaledContents(true);
}

void FormArticulo::on_LineNombreUnidad_returnPressed()
{
    FabricaUnidades* FabUni=Bd->Fabrica->CrearUnidad();
    Bd->Fabrica->Conectar();
    Unidad uni;
    uni.setNombre(ui->LineNombreUnidad->text());
    uni=FabUni->Buscar(uni);
    Bd->Fabrica->Desconectar();
    if(!uni.getCodigo().isNull())
    {
    ui->LineCodUnidad->setText(uni.getCodigo());
    ui->LineSimbolo->setText(uni.getSimbolo());
    QPixmap pix;
    pix.load(RutaImagenes+uni.getRutaImagen());
    ui->LabelUnidadImagen->setPixmap(pix.scaled(153,128,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}

bool FormArticulo::ValidarCamposAlias()
{
    if(ui->LineNombreAlias->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

void FormArticulo::AsignarCamposAlias()
{
    AntiguoAlias.setCodigo(ui->LineCodigoAlias->text());
    ObjetoAlias.setNombre(ui->LineNombreAlias->text());
    ObjetoAlias.setCodigoArticulo(ui->LineCodigo->text());
}

bool FormArticulo::GuardarAlias()
{

    if(!ValidarCamposAlias())
    {
        return false;
    }

    /*------------*/
    AsignarCamposAlias();
    /*------------*/

    if(Bd->Fabrica->Conectar())
    {
        if(FabAlias->Insertar(ObjetoAlias))
        {

            MensajeEmergente mensaje;
            mensaje.SetMensaje("Alias Insertado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }

     Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormArticulo::ModificarAlias()
{
    if(!ValidarCamposAlias())
    {
        return false;
    }

    /*------------*/
    AsignarCamposAlias();
    /*------------*/

    if(Bd->Fabrica->Conectar())
    {
        if(FabAlias->Actualizar(AntiguoAlias,ObjetoAlias))
        {

            MensajeEmergente mensaje;
            mensaje.SetMensaje("Alias Modificado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }

     Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

bool FormArticulo::EliminarAlias()
{
    /*--------------*/
     AsignarCamposAlias();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( FabAlias->Borrar(AntiguoAlias))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Alias Eliminado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
      Bd->Fabrica->Desconectar();
    }
    else
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Error, No hay conexion con la Base de Datos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}


void FormArticulo::on_BotonGuardarAlias_clicked()
{
    if(ESTADOALIAS==INSERTAR)
    {
        if(GuardarAlias())
        {
        }
    }
    if(ESTADOALIAS==MODIFICAR)
    {
        if(ModificarAlias())
        {}
    }

    ui->BotonEliminarAlias->setEnabled(false);
    ui->BotonModificarAlias->setEnabled(false);
    ui->BotonNuevoAlias->setEnabled(true);
    ui->BotonGuardarAlias->setEnabled(false);
    LlenarListaAlias(ui->LineCodigo->text());
    ui->LineNombreAlias->clear();
    ui->LineCodigoAlias->clear();
    ui->ListaAlias->setEnabled(true);
}

void FormArticulo::on_BotonModificarAlias_clicked()
{
    ESTADOALIAS=MODIFICAR;
    ui->ListaAlias->setEnabled(false);
    ui->BotonEliminarAlias->setEnabled(false);
    ui->BotonModificarAlias->setEnabled(false);
    ui->BotonNuevoAlias->setEnabled(false);
    ui->BotonGuardarAlias->setEnabled(true);
    ui->LineNombreAlias->setEnabled(true);

}

void FormArticulo::on_BotonEliminarAlias_clicked()
{
     EliminarAlias();
    ui->BotonEliminarAlias->setEnabled(false);
    ui->BotonModificarAlias->setEnabled(true);
    ui->BotonNuevoAlias->setEnabled(true);
    ui->BotonGuardarAlias->setEnabled(false);
    ui->LineNombreAlias->setEnabled(false);

    LlenarListaAlias(ui->LineCodigo->text());
    ui->LineNombreAlias->clear();
    ui->LineCodigoAlias->clear();
    ui->ListaAlias->setEnabled(true);
}

void FormArticulo::on_BotonNuevoAlias_clicked()
{
    ESTADOALIAS=INSERTAR;
    ui->ListaAlias->setEnabled(false);
    ui->BotonEliminarAlias->setEnabled(false);
    ui->BotonModificarAlias->setEnabled(false);
    ui->BotonGuardarAlias->setEnabled(true);
    ui->BotonNuevoAlias->setEnabled(false);

    ui->LineNombreAlias->setEnabled(true);
    ui->LineNombreAlias->clear();
    ui->LineCodigoAlias->clear();
}

void FormArticulo::on_ListaAlias_currentRowChanged(int currentRow)
{
    if(currentRow!=-1)
    {
    it_ali=MapaAlias->begin();
    it_ali+=currentRow;
    ArticuloAlias* ali=(ArticuloAlias*)(it_ali.value());
    ui->LineCodigoAlias->setText(it_ali.key());
    ui->LineNombreAlias->setText(ali->getNombre());
    ui->BotonModificarAlias->setEnabled(true);
    ui->BotonEliminarAlias->setEnabled(true);
    }
}


void FormArticulo::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
}
