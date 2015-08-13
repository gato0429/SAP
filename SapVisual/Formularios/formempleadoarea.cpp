#include "formempleadoarea.h"
#include "ui_formempleadoarea.h"

FormEmpleadoArea::FormEmpleadoArea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormEmpleadoArea),FormMaestro()
{
    ui->setupUi(this);
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearEmpleadoArea();

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

FormEmpleadoArea::~FormEmpleadoArea()
{
    delete ui;
}

void FormEmpleadoArea::Ruta(QString Codigo, QString Cadena)
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

void FormEmpleadoArea::on_ButtonGuardar_clicked()
{
    if(Estados==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new EmpleadoArea());
    }
    if(Estados==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->ButtonGuardar->setEnabled(false);
        ui->ButtonModificar->setEnabled(true);
        ui->ButtonEliminar->setEnabled(true);
     emit ActualizarRepisa((ObjetoMaestro*)new EmpleadoArea());
    }

}

void FormEmpleadoArea::on_ButtonModificar_clicked()
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

void FormEmpleadoArea::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new EmpleadoArea());
        this->close();
        this->destroy();
    }
}

void FormEmpleadoArea::on_ButtonRegresar_clicked()
{
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}

void FormEmpleadoArea::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}

void FormEmpleadoArea::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
    Objeto=*((EmpleadoArea*)(ObjetoTipo));
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

bool FormEmpleadoArea::Guardar()
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
            mensaje.SetMensaje("Empleado_area Insertado",ADVERTENCIA);
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

bool FormEmpleadoArea::Modificar()
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
            mensaje.SetMensaje("Empleado_area Modificado",ADVERTENCIA);
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

bool FormEmpleadoArea::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Empleado_area Eliminado",ADVERTENCIA);
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

bool FormEmpleadoArea::ValidarCampos()
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

void FormEmpleadoArea::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setCodigoImagen(CodigoImagen);

}

void FormEmpleadoArea::Habilitar()
{
    ui->LineNombre->setEnabled(true);
}

void FormEmpleadoArea::Deshabilitar()
{
     ui->LineNombre->setEnabled(false);
}

void FormEmpleadoArea::Limpiar()
{
    ui->LineCodigo->clear();
    ui->LineImagen->clear();
    ui->LineNombre->clear();
    CodigoImagen.clear();
}
