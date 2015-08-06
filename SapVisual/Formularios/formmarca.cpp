#include "formmarca.h"
#include "ui_formmarca.h"

FormMarca::FormMarca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormMarca),FormMaestro()
{
    ui->setupUi(this);
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearMarca();

    /*-----------------*/
    ui->ButtonGuardar->setIcon(QIcon(BotonGuardar));
    ui->ButtonModificar->setIcon(QIcon(BotonModificar));
    ui->ButtonEliminar->setIcon(QIcon(BotonEliminar));

    Estados=INSERTAR;
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);
    Habilitar();
}

FormMarca::~FormMarca()
{
    delete ui;
}


bool FormMarca::Guardar()
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
            mensaje.SetMensaje("Marca Insertada",ADVERTENCIA);
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

bool FormMarca::Modificar()
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
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Marca Modificada",ADVERTENCIA);
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

bool FormMarca::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Marca Eliminada",ADVERTENCIA);
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

bool FormMarca::ValidarCampos()
{
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

void FormMarca::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setCodigoImagen(CodigoImagen);
}

void FormMarca::Habilitar()
{
    ui->LineNombre->setEnabled(true);
}

void FormMarca::Deshabilitar()
{
    ui->LineNombre->setEnabled(false);
}

void FormMarca::Limpiar()
{
    ui->LineCodigo->clear();
    ui->LineImagen->clear();
    ui->LineNombre->clear();
    CodigoImagen.clear();
}

void FormMarca::SetObjeto(ObjetoMaestro *ObjetoTipo)
{

    Objeto=*((Marca*)(ObjetoTipo));
    Deshabilitar();

    ui->LineCodigo->setText(Objeto.getCodigo());
    ui->LineNombre->setText(Objeto.getNombre());
    ui->LineImagen->setText(Objeto.getRutaImagen());

    QPixmap*  pix=new QPixmap(RutaImagenes+Objeto.getRutaImagen());
    ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    /*-----Manipulacion de los Botones------*/
    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
    ui->ButtonArchivoImagen->setEnabled(false);
}

void FormMarca::Ruta(QString Codigo, QString Cadena)
{
    QString fileName = Cadena;
    CodigoImagen=Codigo;
   if (!fileName.isEmpty())
   {
     QPixmap*  pix=new QPixmap(RutaImagenes+fileName);

       ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
       ui->LineImagen->setText(fileName);
    }
}

void FormMarca::on_ButtonGuardar_clicked()
{
    if(Estados==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new Marca());
    }
    if(Estados==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->ButtonGuardar->setEnabled(false);
        ui->ButtonModificar->setEnabled(true);
        ui->ButtonEliminar->setEnabled(true);
     emit ActualizarRepisa((ObjetoMaestro*)new Marca());
    }
}

void FormMarca::on_ButtonModificar_clicked()
{
   Estados=MODIFICAR;
   /*--Habilitacion Botones-*/
   ui->ButtonModificar->setEnabled(false);
   ui->ButtonEliminar->setEnabled(false);
   ui->ButtonGuardar->setEnabled(true);
   ui->ButtonArchivoImagen->setEnabled(true);
   /*---Desabilitar Campos--*/
   Habilitar();
}
void FormMarca::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Marca());
        this->close();
        this->destroy();
    }
}

void FormMarca::on_ButtonRegresar_clicked()
{

    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();

}

void FormMarca::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}
