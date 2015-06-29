#include "formmodelo.h"
#include "ui_formmodelo.h"

FormModelo::FormModelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormModelo),FormMaestro()
{
    ui->setupUi(this);
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearModelo();

    /*-----------------*/
    ui->ButtonGuardar->setIcon(QIcon(BotonGuardar));
    ui->ButtonModificar->setIcon(QIcon(BotonModificar));
    ui->ButtonEliminar->setIcon(QIcon(BotonEliminar));

    Estado=INSERTAR;
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);

}

FormModelo::~FormModelo()
{
    delete ui;
}



void FormModelo::SetObjeto(ObjetoMaestro *ObjetoTipo)
{

    Objeto=*((Modelo*)(ObjetoTipo));
    //Objeto.setCodigo(Externo.getCodigo());
    ui->LineNombre->setEnabled(false);
    ui->LineImagen->setReadOnly(true);

    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);

}

bool FormModelo::Guardar()
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
            mensaje.SetMensaje("Modelo Insertado",ADVERTENCIA);
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


bool FormModelo::Modificar()
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
            mensaje.SetMensaje("Modelo Modificado",ADVERTENCIA);
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

bool FormModelo::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Modelo Eliminado",ADVERTENCIA);
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

bool FormModelo::ValidarCampos()
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

void FormModelo::AsignarCampos()
{

    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setCodigo(CodigoImagen);
}
void FormModelo::on_ButtonGuardar_clicked()
{

}

void FormModelo::on_ButtonModificar_clicked()
{

}

void FormModelo::on_ButtonEliminar_clicked()
{

}

void FormModelo::on_ButtonRegresar_clicked()
{

}

void FormModelo::on_ButtonArchivoImagen_clicked()
{

}
