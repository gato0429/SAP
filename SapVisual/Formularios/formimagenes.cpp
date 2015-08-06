#include "formimagenes.h"
#include "ui_formimagenes.h"

FormImagenes::FormImagenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormImagenes),FormMaestro()
{

    ui->setupUi(this);
    Form=this;
    Parent=parent;

        connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
        connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

        SetFondo();
        /*------------------------------*/
        Fab=Bd->Fabrica->CrearImagen();

        /*-----------------*/
        ui->ButtonGuardar->setIcon(QIcon(BotonGuardar));
        ui->ButtonModificar->setIcon(QIcon(BotonModificar));
        ui->ButtonEliminar->setIcon(QIcon(BotonEliminar));

        Estado=INSERTAR;
        ui->ButtonModificar->setEnabled(false);
        ui->ButtonEliminar->setEnabled(false);
        ui->ButtonGuardar->setEnabled(true);
        Habilitar();


     /*--------------------------*/

        Bd->Fabrica->Conectar();
        QMap<QString,ObjetoMaestro*>* mapa=Fab->BuscarMapa((ObjetoMaestro*)new Imagen(),"",TODO);

        QMap<QString,ObjetoMaestro*>::iterator it;

        for(it=mapa->begin(); it!=mapa->end(); it++)
        {
           Imagen* i=(Imagen*)(it.value());
           QString Carpeta= i->getCarpeta();
           if (ui->ComboCarpeta->findText(Carpeta)==-1)
           {
            ui->ComboCarpeta->addItem(Carpeta);
           }
        }
        Bd->Fabrica->Desconectar();

         ui->LineNombre->setInputMask("AAAAAAAAAAAAAAAA");
}

FormImagenes::~FormImagenes()
{
    delete ui;
}

void FormImagenes::on_tabWidget_tabBarClicked(int index)
{

}

void FormImagenes::on_BotonImagen_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Abrir Imagen"),RutaImagenes,tr("Archivo Imagen (*.png)"));

    if (!fileName.isEmpty())
    {
      QPixmap*  pix=new QPixmap(fileName);

        ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        //ui->imagen->setText(fileName);

     }
}





void FormImagenes::on_BotonCarpetaAgregar_4_clicked()
{
    if(!ui->LineCarpetaNueva_4->text().isEmpty())
    {
        if (ui->ComboCarpeta->findText(ui->LineCarpetaNueva_4->text())==-1)
        {
            ui->ComboCarpeta->addItem(ui->LineCarpetaNueva_4->text());
            ui->LineCarpetaNueva_4->clear();
        }

    }


}

void FormImagenes::SetObjeto(ObjetoMaestro *ObjetoTipo)
{

    Objeto=*((Imagen*)(ObjetoTipo));
    Deshabilitar();

    QString t=Objeto.getNombre().remove(Objeto.getNombre().size()-4,4);
    ui->LineCodigo->setText(Objeto.getCodigo());
    ui->ComboCarpeta->setCurrentText(Objeto.getCarpeta());
    ui->LineNombre->setText(t);
    fileName=RutaImagenes+Objeto.getCarpeta()+"/"+Objeto.getNombre();

    QPixmap*  pix=new QPixmap(RutaImagenes+Objeto.getCarpeta()+"/"+Objeto.getNombre());
    ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    /*-----Manipulacion de los Botones------*/
    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
   // ui->ButtonArchivoImagen->setEnabled(false);
}

bool FormImagenes::Guardar()
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
            DefBD::GuardarImagen(Objeto.getCarpeta()+"/"+Objeto.getNombre());
            MensajeEmergente mensaje;

            mensaje.SetMensaje("Imagen Insertada",ADVERTENCIA);
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

bool FormImagenes::Modificar()
{
    if(!ValidarCampos())
    {
        return false;
    }
    AsignarCampos();

    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Actualizar(Antiguo,Objeto))
        {
            DefBD::GuardarImagen(Objeto.getCarpeta()+"/"+Objeto.getNombre());
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Imagen Modificada",ADVERTENCIA);
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

bool FormImagenes::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Imagen Eliminada",ADVERTENCIA);
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

bool FormImagenes::ValidarCampos()
{

    if( fileName.isEmpty())
     {
      MensajeEmergente mensaje;
      mensaje.SetMensaje("Imagen Vacia",ADVERTENCIA);
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
    if(ui->ComboCarpeta->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Carpeta Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }

    return true;
}

void FormImagenes::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text()+".png");
    Objeto.setCarpeta(ui->ComboCarpeta->currentText());
    qDebug()<<"casasdasd:"<<fileName;
    Objeto.setPixel(Definiciones::toQByteArray(fileName));
    //Objeto.setCodigoImagen(CodigoImagen);
}

void FormImagenes::Habilitar()
{
        ui->LineNombre->setEnabled(true);
        ui->ComboCarpeta->setEnabled(true);
        ui->LineCarpetaNueva_4->setEnabled(true);

}

void FormImagenes::Deshabilitar()
{
        ui->LineNombre->setEnabled(false);
        ui->ComboCarpeta->setEnabled(false);
        ui->LineCarpetaNueva_4->setEnabled(false);
}

void FormImagenes::Limpiar()
{
    ui->LineCodigo->clear();
    //ui->LineImagen->clear();
    ui->LineNombre->clear();
    //ui->LineCarpeta->clear();
  //  CodigoImagen.clear();
}
void FormImagenes::on_ButtonGuardar_clicked()
{
    if(Estado==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new Imagen());
    }
    if(Estado==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->ButtonGuardar->setEnabled(false);
        ui->ButtonModificar->setEnabled(true);
        ui->ButtonEliminar->setEnabled(true);
     emit ActualizarRepisa((ObjetoMaestro*)new Imagen());
    }
}

void FormImagenes::on_ButtonModificar_clicked()
{
    Estado=MODIFICAR;
    /*--Habilitacion Botones-*/
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);
   // ui->ButtonArchivoImagen->setEnabled(true);
    /*---Desabilitar Campos--*/
    Habilitar();
}

void FormImagenes::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Imagen());
        this->close();
        this->destroy();
    }
}

void FormImagenes::on_ButtonRegresar_clicked()
{
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}
