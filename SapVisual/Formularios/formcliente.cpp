#include "formcliente.h"
#include "ui_formcliente.h"

FormCliente::FormCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormCliente),FormMaestro()
{
    ui->setupUi(this);
    /*Dos Lineas Para el fondo Madera*/
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearCliente();

    /*-----------------*/
    ui->ButtonGuardar->setIcon(QIcon(BotonGuardar));
    ui->ButtonModificar->setIcon(QIcon(BotonModificar));
    ui->ButtonEliminar->setIcon(QIcon(BotonEliminar));

    Estados=INSERTAR;
    ui->ButtonModificar->setEnabled(false);
    ui->ButtonEliminar->setEnabled(false);
    ui->ButtonGuardar->setEnabled(true);
    Habilitar();
    CargarCombos();
     ui->DateIngreso->setDate(QDate::currentDate());
}

FormCliente::~FormCliente()
{
    delete ui;
}




void FormCliente::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
    Objeto=*((Cliente*)(ObjetoTipo));
    Deshabilitar();

    ui->LineCodigo->setText(Objeto.getCodigo());
    ui->LineCodigoInterno->setText(Objeto.getCodigoInterno());
    ui->LineNombre->setText(Objeto.getNombre());
    ui->LineImagen->setText(Objeto.getRutaImagen());
    ui->LineContacto->setText(Objeto.getContacto());
    ui->LineDireccion->setText(Objeto.getDireccion());
    ui->LineDocumento->setText(Objeto.getNumDoc());
    ui->LineEmail->setText(Objeto.getEmail());
    ui->LinePais->setText(Objeto.getPais());
    ui->DateIngreso->setDate(Objeto.getFecha());
    ui->LineTelefono->setText(Objeto.getTelefono());
    ui->LineWeb->setText(Objeto.getWeb());
    ui->SpinBoxDescuento->setValue(Objeto.getDescuento());
    ui->ComboClienteTipo->setCurrentText(Objeto.getNombreTipo());
    ui->ComboDocumento->setCurrentText(Objeto.getTipo());

    QPixmap*  pix=new QPixmap(RutaImagenes+Objeto.getRutaImagen());
    ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    /*-----Manipulacion de los Botones------*/
    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
    ui->ButtonArchivoImagen->setEnabled(false);

}

void FormCliente::CargarCombos()
{
    FabricaClienteTipo* FabTipo=Bd->Fabrica->CrearClienteTipo();
    Bd->Fabrica->Conectar();
    MapaTipo=FabTipo->BuscarClave();

    Bd->Fabrica->Desconectar();
    ui->ComboClienteTipo->addItem("");

    foreach (const QString &str, MapaTipo->keys())
   {
       ClienteTipo* obj=(ClienteTipo*)MapaTipo->value(str);
       ui->ComboClienteTipo->addItem(QIcon(RutaImagenes+obj->getRutaImagen()),obj->getNombre());

   }
}

bool FormCliente::Guardar()
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
            mensaje.SetMensaje("Cliente Insertado",ADVERTENCIA);
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

    return false;
}

bool FormCliente::Modificar()
{    if(!ValidarCampos())
    {
        return false;
    }
    AsignarCampos();

    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Actualizar(Antiguo,Objeto))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Cliente Modificada",ADVERTENCIA);
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

bool FormCliente::Eliminar()
{    /*--------------*/
    AsignarCampos();
   /*---------------*/
   if(Bd->Fabrica->Conectar())
   {
       if( Fab->Borrar(Antiguo))
       {
           MensajeEmergente mensaje;
           mensaje.SetMensaje("Cliente Eliminada",ADVERTENCIA);
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

bool FormCliente::ValidarCampos()
{

    if(ui->LineCodigoInterno->text().isEmpty())
    {
        ui->LineCodigoInterno->setText("0000");
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Codigo Interno vacio se asignara nulo",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboClienteTipo->currentIndex()==0)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Tipo Cliente Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboDocumento->currentIndex()==0)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Tipo Documento Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineDocumento->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Documento Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }

    if(ui->ComboDocumento->currentIndex()==1&&ui->LineDocumento->text().size()!=8)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("El Dni Debe ser de 8 Digitos",ADVERTENCIA);
        mensaje.exec();
        return false;
    }

    if(ui->ComboDocumento->currentIndex()==2&&ui->LineDocumento->text().size()!=11)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("El Ruc Debe ser de 11 Digitos",ADVERTENCIA);
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
    if(ui->LineDireccion->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Direccion Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LinePais->text().isEmpty())
    {
        ui->LinePais->setText("Peru");
         return false;
    }
    if(ui->LineContacto->text().isEmpty())
    {
        ui->LineContacto->setText("Vacio");
         return false;
    }
    if(ui->LineTelefono->text().isEmpty())
    {
        ui->LineTelefono->setText("Vacio");
         return false;
    }
    if(ui->LineEmail->text().isEmpty())
    {
        ui->LineEmail->setText("Vacio");
         return false;
    }
    if(ui->LineWeb->text().isEmpty())
    {
        ui->LineWeb->setText("Vacio");
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

void FormCliente::AsignarCampos()
{
    ClienteTipo* objTipo=(ClienteTipo*)MapaTipo->value(ui->ComboClienteTipo->currentText());



    Antiguo.setCodigo(ui->LineCodigo->text());

    Objeto.setCodigo(ui->ComboDocumento->currentText()[0]+ui->LineDocumento->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setCodigoInterno(ui->LineCodigoInterno->text());
    Objeto.setCodigoTipo(objTipo->getCodigo());
    Objeto.setContacto(ui->LineContacto->text());
    Objeto.setDescuento(ui->SpinBoxDescuento->value());
    Objeto.setDireccion(ui->LineDireccion->text());
    Objeto.setEmail(ui->LineEmail->text());
    Objeto.setFecha(ui->DateIngreso->date());
    Objeto.setNumDoc(ui->LineDocumento->text());
    Objeto.setPais(ui->LinePais->text());
    Objeto.setTelefono(ui->LineTelefono->text());
    Objeto.setWeb(ui->LineWeb->text());
    Objeto.setTipo(ui->ComboDocumento->currentText());
    Objeto.setCodigoImagen(CodigoImagen);

}

void FormCliente::Habilitar()
{

    ui->LineCodigoInterno->setEnabled(true);
    ui->LineNombre->setEnabled(true);
    ui->LineImagen->setEnabled(true);
    ui->LineContacto->setEnabled(true);
    ui->LineDireccion->setEnabled(true);
    ui->LineDocumento->setEnabled(true);
    ui->LineEmail->setEnabled(true);
    ui->LinePais->setEnabled(true);
    ui->DateIngreso->setEnabled(true);
    ui->LineTelefono->setEnabled(true);
    ui->LineWeb->setEnabled(true);
    ui->SpinBoxDescuento->setEnabled(true);
    ui->ComboClienteTipo->setEnabled(true);
    ui->ComboDocumento->setEnabled(true);
}

void FormCliente::Deshabilitar()
{
    ui->LineCodigoInterno->setEnabled(false);
    ui->LineNombre->setEnabled(false);
    ui->LineImagen->setEnabled(false);
    ui->LineContacto->setEnabled(false);
    ui->LineDireccion->setEnabled(false);
    ui->LineDocumento->setEnabled(false);
    ui->LineEmail->setEnabled(false);
    ui->LinePais->setEnabled(false);
    ui->DateIngreso->setEnabled(false);
    ui->LineTelefono->setEnabled(false);
    ui->LineWeb->setEnabled(false);
    ui->SpinBoxDescuento->setEnabled(false);
    ui->ComboClienteTipo->setEnabled(false);
    ui->ComboDocumento->setEnabled(false);

}

void FormCliente::Limpiar()
{
    ui->LineCodigo->clear();
    ui->LineCodigoInterno->clear();
    ui->LineNombre->clear();
    ui->LineImagen->clear();
    ui->LineContacto->clear();
    ui->LineDireccion->clear();
    ui->LineDocumento->clear();
    ui->LineEmail->clear();
    ui->LinePais->clear();
    ui->DateIngreso->setDate(QDate::currentDate());
    ui->LineTelefono->clear();
    ui->LineWeb->clear();
    ui->SpinBoxDescuento->clear();
    ui->ComboClienteTipo->setCurrentIndex(0);
    ui->ComboDocumento->setCurrentIndex(0);
    CodigoImagen.clear();
}

void FormCliente::Ruta(QString Codigo, QString Cadena)
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

void FormCliente::on_ButtonGuardar_clicked()
{
    if(Estados==INSERTAR)
    {
    if(Guardar())
    {
    Limpiar();
    }
    emit ActualizarRepisa((ObjetoMaestro*)new Cliente());
    }
    if(Estados==MODIFICAR)
    {
        if(Modificar())
        {
            Deshabilitar();
            /*Volver a su estado los botones*/
            ui->ButtonGuardar->setEnabled(false);
            ui->ButtonModificar->setEnabled(true);
            ui->ButtonEliminar->setEnabled(true);
         emit ActualizarRepisa((ObjetoMaestro*)new Cliente());
        }

    }
}
void FormCliente::on_ButtonModificar_clicked()
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

void FormCliente::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Cliente());
        this->close();
        this->destroy();
    }
}

void FormCliente::on_ButtonRegresar_clicked()
{
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}

void FormCliente::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* v=new VisorImagenes(this);
    v->exec();
}
