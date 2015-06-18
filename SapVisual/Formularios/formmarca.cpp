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

    Estado=INSERTAR;
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);

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
    Objeto.setCodigo(CodigoImagen);
}

void FormMarca::SetObjeto(ObjetoMaestro *ObjetoTipo)
{

    Objeto=*((Marca*)(ObjetoTipo));
    //Objeto.setCodigo(Externo.getCodigo());
    ui->LineNombre->setEnabled(false);
    ui->LineImagen->setReadOnly(true);

    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
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
    if(Estado==INSERTAR)
    {
    Guardar();
    emit ActualizarRepisa((ObjetoMaestro*)new Marca());
    }
    if(Estado==MODIFICAR)
    {
    Modificar();
     emit ActualizarRepisa((ObjetoMaestro*)new Marca());
    }
}

void FormMarca::on_ButtonModificar_clicked()
{

}

void FormMarca::on_ButtonEliminar_clicked()
{

}

void FormMarca::on_ButtonRegresar_clicked()
{

}

void FormMarca::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}
