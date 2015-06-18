#include "formarticulotipo.h"
#include "ui_formarticulotipo.h"

FormArticuloTipo::FormArticuloTipo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormArticuloTipo)
{
    ui->setupUi(this);

    /*Dos Lineas Para el fondo Madera*/
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    Fab=Bd->Fabrica->CrearArticuloTipo();

    ui->guardar->setIcon(QIcon(BotonGuardar));
    ui->modificar->setIcon(QIcon(BotonModificar));
    ui->eliminar->setIcon(QIcon(BotonEliminar));

    Estado=INSERTAR;
    ui->modificar->setEnabled(false);
    ui->eliminar->setEnabled(false);
    ui->guardar->setEnabled(true);


}

void FormArticuloTipo::SetArticuloTipo(int boton, ArticuloTipo valor)
{
    idBoton=boton;
    ui->nombre->setText(valor.getNombre());
    ui->codigo->setText(valor.getCodigo());
    ui->imagen->setText(valor.getImagen());
    CodigoImagen=valor.getCodigo_Imagen();
    QPixmap pix;
    pix.load(RutaImagenes+valor.getImagen());
    ui->imagenlabel->setPixmap(pix.scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->guardar->setEnabled(false);
    ui->modificar->setEnabled(true);
    ui->eliminar->setEnabled(true);
    ui->nombre->setEnabled(false);
    ui->BotonArchivo->setEnabled(false);
}

FormArticuloTipo::~FormArticuloTipo()
{
    delete ui;
}

void FormArticuloTipo::on_BotonArchivo_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();

}

void FormArticuloTipo::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {

    this->close();
 //   emit(Activar(idBoton));
    this->destroy();
    }
}

void FormArticuloTipo::on_guardar_clicked()
{

    if(Estado==INSERTAR)
    {
    Guardar();
    emit ActualizarRepisa((ObjetoMaestro*)new ArticuloTipo());
    }
    if(Estado==MODIFICAR)
    {
    Modificar();
     emit ActualizarRepisa((ObjetoMaestro*)new ArticuloTipo());
    }

}

void FormArticuloTipo::on_eliminar_clicked()
{
    Eliminar();
}

void FormArticuloTipo::on_modificar_clicked()
{
    Estado=MODIFICAR;
    ui->modificar->setEnabled(false);
    ui->guardar->setEnabled(true);
    ui->eliminar->setEnabled(false);
    ui->nombre->setEnabled(true);
    ui->BotonArchivo->setEnabled(true);
}

void FormArticuloTipo::Ruta(QString Codigo, QString Cadena)
{
    QString fileName = Cadena;
    CodigoImagen=Codigo;
   if (!fileName.isEmpty())
   {
     QPixmap*  pix=new QPixmap(RutaImagenes+fileName);

       ui->imagenlabel->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
       ui->imagen->setText(fileName);
    }
}


bool FormArticuloTipo::Guardar()
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
            mensaje.SetMensaje("Tipo Articulo Insertado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
        else
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Error, Ya existe el Nombre",ADVERTENCIA);
            mensaje.exec();
            return false;
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

bool FormArticuloTipo::Modificar()
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
            mensaje.SetMensaje("Tipo Articulo Modificado",ADVERTENCIA);
            mensaje.exec();
            return true;
        }
        else
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Error, Ya existe el Nombre",ADVERTENCIA);
            mensaje.exec();
            return false;
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

bool FormArticuloTipo::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Articulo Tipo Eliminado",ADVERTENCIA);
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

bool FormArticuloTipo::ValidarCampos()
{

    if(ui->nombre->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->imagen->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Imagen Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    return true;
}

void FormArticuloTipo::AsignarCampos()
{
    Antiguo.setCodigo(ui->codigo->text());
    Objeto.setNombre(ui->nombre->text());
    Objeto.setCodigo_Imagen(CodigoImagen);
    qDebug()<<"PAse"+CodigoImagen;
}


void FormArticuloTipo::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
}