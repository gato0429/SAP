#include "formempleado.h"
#include "ui_formempleado.h"

FormEmpleado::FormEmpleado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormEmpleado),FormMaestro()
{
    ui->setupUi(this);
    /*Dos Lineas Para el fondo Madera*/
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));

    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearEmpleado();

    /*-----------------*/
    ui->BotonGuardar->setIcon(QIcon(BotonGuardar));
    ui->BotonModificar->setIcon(QIcon(BotonModificar));
    ui->BotonEliminar->setIcon(QIcon(BotonEliminar));

    Estado=INSERTAR;
    ui->BotonModificar->setEnabled(false);
    ui->BotonEliminar->setEnabled(false);
    ui->BotonGuardar->setEnabled(true);
    ui->DateIngreso->setDate(QDate::currentDate());
}

FormEmpleado::~FormEmpleado()
{
    delete ui;
}

void FormEmpleado::SetEmpleado(Empleado Externo)
{

    Objeto.setCodigo(Externo.getCodigo());
    ui->LineNombre->setEnabled(false);
    ui->LineCodigo_Interno->setEnabled(false);
    ui->LineDireccion->setEnabled(false);
    ui->LineMail->setEnabled(false);
    ui->LineDescuento->setEnabled(false);
    ui->ComboSexo->setEnabled(false);
    ui->DateIngreso->setEnabled(false);
    ui->LineDni->setEnabled(false);
    ui->LineTelefono->setEnabled(false);

    ui->LineCodigo->setText(Externo.getCodigo());
    ui->LineCodigo_Interno->setText(Externo.getCodigoInterno());
    ui->LineDescuento->setValue(Externo.getDescuento());
    ui->LineDireccion->setText(Externo.getDireccion());
    ui->LineDni->setText(Externo.getDni());
    ui->LineNombre->setText(Externo.getNombre());
    ui->LineMail->setText(Externo.getEmail());
    ui->LineTelefono->setText(Externo.getTelefono());
    ui->ComboSexo->setCurrentText(Externo.getSexo());
    ui->DateIngreso->setDate(Externo.getFechaIngreso());

    ui->BotonModificar->setEnabled(true);
    ui->BotonEliminar->setEnabled(true);
    ui->BotonGuardar->setEnabled(false);
}


bool FormEmpleado::Guardar()
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
            mensaje.SetMensaje("Empleado Insertado",ADVERTENCIA);
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


bool FormEmpleado::Modificar()
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
            mensaje.SetMensaje("Empleado Modificado",ADVERTENCIA);
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

bool FormEmpleado::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Empleado Eliminado",ADVERTENCIA);
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

bool FormEmpleado::ValidarCampos()
{
    if(ui->LineNombre->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineDni->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Dni Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->LineDescuento->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Descuento Vacio",ADVERTENCIA);
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

    return true;
}


void FormEmpleado::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());
    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setDni(ui->LineDni->text());
    Objeto.setSexo(ui->ComboSexo->currentText());
    Objeto.setEmail(ui->LineMail->text());
    Objeto.setDireccion(ui->LineDireccion->text());
    Objeto.setDescuento(ui->LineDescuento->text().toDouble());
    qDebug()<<"-->ASA"<<ui->LineDescuento->text().toDouble();
    Objeto.setFechaIngreso(ui->DateIngreso->date());
    Objeto.setTelefono(ui->LineTelefono->text());
    Objeto.setCodigoInterno(ui->LineCodigo_Interno->text());

}

void FormEmpleado::Habilitar()
{

}

void FormEmpleado::Deshabilitar()
{

}

void FormEmpleado::Limpiar()
{

}

void FormEmpleado::on_BotonGuardar_clicked()
{
    if(Estado==INSERTAR)
    {
    Guardar();
    emit ActualizarRepisa((ObjetoMaestro*)new Empleado());
    }
    if(Estado==MODIFICAR)
    {
    Modificar();
    qDebug()<<"ante de modificar gatunooooo";
     emit ActualizarRepisa((ObjetoMaestro*)new Empleado());
    }
}

void FormEmpleado::on_BotonModificar_clicked()
{
    Estado=MODIFICAR;
    ui->BotonModificar->setEnabled(false);
    ui->BotonGuardar->setEnabled(true);
    ui->BotonEliminar->setEnabled(false);
    ui->LineNombre->setEnabled(true);
    ui->LineDireccion->setEnabled(true);
    ui->LineMail->setEnabled(true);
    ui->LineDescuento->setEnabled(true);
    ui->ComboSexo->setEnabled(true);
    ui->DateIngreso->setEnabled(true);
    ui->LineTelefono->setEnabled(true);
    ui->LineCodigo_Interno->setEnabled(true);
    ui->LineDni->setEnabled(true);
}

void FormEmpleado::on_BotonEliminar_clicked()
{
  Eliminar();

}

void FormEmpleado::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
    }
}

void FormEmpleado::on_BotonEliminar_2_clicked()
{
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}


void FormEmpleado::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
}
