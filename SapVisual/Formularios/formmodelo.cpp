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


    ui->LineNombre->setEnabled(false);


    ui->LineCodigo->setText(Objeto.getCodigo());
    ui->LineNombre->setText(Objeto.getNombre());
    ui->LineImagen->setText(Objeto.getRutaImagen());

    QPixmap*  pix=new QPixmap(RutaImagenes+Objeto.getRutaImagen());
    ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
    ui->ButtonArchivoImagen->setEnabled(false);
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
    Objeto.setCodigoImagen(CodigoImagen);
}
void FormModelo::Ruta(QString Codigo, QString Cadena)
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

void FormModelo::on_ButtonGuardar_clicked()
{
    if(Estado==INSERTAR)
    {
    if(Guardar())
    emit ActualizarRepisa((ObjetoMaestro*)new Modelo());
    }
    if(Estado==MODIFICAR)
    {
    if(Modificar())
     emit ActualizarRepisa((ObjetoMaestro*)new Modelo());
    }

}

void FormModelo::on_ButtonModificar_clicked()
{
    Estado=MODIFICAR;
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);
    ui->ButtonArchivoImagen->setEnabled(true);
    ui->LineNombre->setEnabled(true);
 }



void FormModelo::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Modelo());
        this->close();
        this->destroy();
    }
}

void FormModelo::on_ButtonRegresar_clicked()
{

    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}

void FormModelo::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}
