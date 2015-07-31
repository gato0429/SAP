#include "formmoneda.h"
#include "ui_formmoneda.h"

FormMoneda::FormMoneda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormMoneda),FormMaestro()
{
    ui->setupUi(this);
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearMoneda();

    /*-----------------*/
    ui->ButtonGuardar->setIcon(QIcon(BotonGuardar));
    ui->ButtonModificar->setIcon(QIcon(BotonModificar));
    ui->ButtonEliminar->setIcon(QIcon(BotonEliminar));

    Estado=INSERTAR;
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);
    Habilitar();

}

FormMoneda::~FormMoneda()
{
    delete ui;
}

void FormMoneda::Ruta(QString Codigo, QString Cadena)
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


void FormMoneda::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Moneda());
        this->close();
        this->destroy();
    }
}


void FormMoneda::on_ButtonGuardar_clicked()
{
    if(Estado==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new Moneda());
    }
    if(Estado==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->ButtonGuardar->setEnabled(false);
        ui->ButtonModificar->setEnabled(true);
        ui->ButtonEliminar->setEnabled(true);
        ui->ButtonArchivoImagen->setEnabled(false);
     emit ActualizarRepisa((ObjetoMaestro*)new Moneda());
    }
}

void FormMoneda::on_ButtonModificar_clicked()
{
    Estado=MODIFICAR;
    /*--Habilitacion Botones-*/
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);
    ui->ButtonArchivoImagen->setEnabled(true);
    /*---Desabilitar Campos--*/
    Habilitar();
 }
void FormMoneda::on_ButtonRegresar_clicked()
{

    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}


void FormMoneda::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
    Objeto=*((Moneda*)(ObjetoTipo));
    Deshabilitar();

    ui->LineCodigo->setText(Objeto.getCodigo());
    ui->LineNombre->setText(Objeto.getNombre());
    ui->LineImagen->setText(Objeto.getRutaImagen());
    ui->LineSimbolo->setText(Objeto.getSimbolo());
    QPixmap*  pix=new QPixmap(RutaImagenes+Objeto.getRutaImagen());
    ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    /*-----Manipulacion de los Botones------*/
    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
    ui->ButtonArchivoImagen->setEnabled(false);
}

bool FormMoneda::Guardar()
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
            mensaje.SetMensaje("Moneda Insertada",ADVERTENCIA);
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

bool FormMoneda::Modificar()
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
            mensaje.SetMensaje("Moneda Modificada",ADVERTENCIA);
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

bool FormMoneda::Eliminar()
{ /*--------------*/
    AsignarCampos();
   /*---------------*/
   if(Bd->Fabrica->Conectar())
   {
       if( Fab->Borrar(Antiguo))
       {
           MensajeEmergente mensaje;
           mensaje.SetMensaje("Moneda Eliminada",ADVERTENCIA);
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

bool FormMoneda::ValidarCampos()
{
    if(ui->LineNombre->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineSimbolo->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Simbolo Vacio",ADVERTENCIA);
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

void FormMoneda::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setSimbolo(ui->LineSimbolo->text());
    Objeto.setCodigoImagen(CodigoImagen);
}

void FormMoneda::Habilitar()
{
    ui->LineNombre->setEnabled(true);
    ui->LineSimbolo->setEnabled(true);
}

void FormMoneda::Deshabilitar()
{
    ui->LineNombre->setEnabled(false);
    ui->LineSimbolo->setEnabled(false);
}

void FormMoneda::Limpiar()
{
    ui->LineCodigo->clear();
    ui->LineImagen->clear();
    ui->LineNombre->clear();
    CodigoImagen.clear();
}
void FormMoneda::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();

}
