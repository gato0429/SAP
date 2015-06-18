#include "formarticuloalias.h"
#include "ui_formarticuloalias.h"

FormArticuloAlias::FormArticuloAlias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormArticuloAlias)
{
    ui->setupUi(this);

    /*Dos Lineas Para el fondo Madera*/
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearArticuloAlias();
    Estado=INSERTAR;
    /*-----------------*/
    ui->eliminar->setEnabled(false);
    ui->modificar->setEnabled(false);
    ui->guardar->setEnabled(true);

}

FormArticuloAlias::~FormArticuloAlias()
{
    delete ui;
}

void FormArticuloAlias::SetArticulo(Articulo Externo)
{

}


bool FormArticuloAlias::Guardar()
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
            mensaje.SetMensaje("Nuevo Alias Insertado",ADVERTENCIA);
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

bool FormArticuloAlias::Modificar()
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

bool FormArticuloAlias::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Unidad Eliminada",ADVERTENCIA);
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

bool FormArticuloAlias::ValidarCampos()
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

void FormArticuloAlias::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigoAlias->text());
    Objeto.setNombre(ui->LineNombreAlias->text());
    Objeto.setCodigoArticulo(ui->LineCodigoArticulo->text());

}
void FormArticuloAlias::on_eliminar_clicked()
{
    Eliminar();
}

void FormArticuloAlias::on_modificar_clicked()
{
    Estado=MODIFICAR;
    ui->modificar->setEnabled(false);
    ui->guardar->setEnabled(true);
    ui->eliminar->setEnabled(false);

    ui->LineNombreAlias->setEnabled(true);

}

void FormArticuloAlias::on_guardar_clicked()
{
    Guardar();
}


void FormArticuloAlias::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
}