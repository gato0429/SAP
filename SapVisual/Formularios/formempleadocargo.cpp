#include "formempleadocargo.h"
#include "ui_formempleadocargo.h"

FormEmpleadoCargo::FormEmpleadoCargo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormEmpleadoCargo),FormMaestro()
{
    ui->setupUi(this);
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearEmpleadoCargo();

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

FormEmpleadoCargo::~FormEmpleadoCargo()
{
    delete ui;
}

void FormEmpleadoCargo::Ruta(QString Codigo, QString Cadena)
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

void FormEmpleadoCargo::on_ButtonGuardar_clicked()
{
    if(Estados==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new EmpleadoCargo());
    }
    if(Estados==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->ButtonGuardar->setEnabled(false);
        ui->ButtonModificar->setEnabled(true);
        ui->ButtonEliminar->setEnabled(true);
     emit ActualizarRepisa((ObjetoMaestro*)new EmpleadoCargo());
    }

}

void FormEmpleadoCargo::on_ButtonModificar_clicked()
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

void FormEmpleadoCargo::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new EmpleadoCargo());
        this->close();
        this->destroy();
    }
}

void FormEmpleadoCargo::on_ButtonRegresar_clicked()
{
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}

void FormEmpleadoCargo::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}

void FormEmpleadoCargo::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
    Objeto=*((EmpleadoCargo*)(ObjetoTipo));
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

bool FormEmpleadoCargo::Guardar()
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
            mensaje.SetMensaje("Empleado_cargo Insertado",ADVERTENCIA);
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

bool FormEmpleadoCargo::Modificar()
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
            mensaje.SetMensaje("Empleado_cargo Modificado",ADVERTENCIA);
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

bool FormEmpleadoCargo::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Empleado_cargo Eliminado",ADVERTENCIA);
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

bool FormEmpleadoCargo::ValidarCampos()
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

void FormEmpleadoCargo::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setCodigoImagen(CodigoImagen);

}

void FormEmpleadoCargo::Habilitar()
{
    ui->LineNombre->setEnabled(true);
}

void FormEmpleadoCargo::Deshabilitar()
{
     ui->LineNombre->setEnabled(false);
}

void FormEmpleadoCargo::Limpiar()
{
    ui->LineCodigo->clear();
    ui->LineImagen->clear();
    ui->LineNombre->clear();
    CodigoImagen.clear();
}
