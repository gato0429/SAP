#include "formarticulo.h"
#include "ui_formarticulo.h"

FormArticulo::FormArticulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormArticulo),FormMaestro()
{
    ui->setupUi(this);
    /*Dos Lineas Para el fondo Madera*/
    Form=this;
    Parent=parent;
    connect(this,SIGNAL(ActivarBoton(QString)),parent,SLOT(ActivarBotonRepisa(QString)));
    connect(this,SIGNAL(ActualizarRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarTodo(ObjetoMaestro*)));


    SetFondo();
    /*------------------------------*/
    Fab=Bd->Fabrica->CrearArticulo();

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
    }



FormArticulo::~FormArticulo()
{

    delete ui;
}



bool FormArticulo::Guardar()
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
            mensaje.SetMensaje("Articulo Insertado",ADVERTENCIA);
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

bool FormArticulo::Modificar()
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
            mensaje.SetMensaje("Articulo Modificado",ADVERTENCIA);
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

bool FormArticulo::Eliminar()
{
    /*--------------*/
     AsignarCampos();
    /*---------------*/
    if(Bd->Fabrica->Conectar())
    {
        if( Fab->Borrar(Antiguo))
        {
            MensajeEmergente mensaje;
            mensaje.SetMensaje("Articulo Eliminado",ADVERTENCIA);
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

bool FormArticulo::ValidarCampos()
{
    if(ui->LineNombre->text().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Nombre Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboTipo->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Familia Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }

    if(ui->ComboModelo->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Modelo Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboMarca->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Marca Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }

    if(ui->ComboUnidad->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Unidad Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboMoneda->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Moneda Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboUnico->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Grupo Vacio",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->ComboVigencia->currentText().isEmpty())
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Vigencia Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->SpinCantidadMin->value()==0)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Cantidad Vacia",ADVERTENCIA);
        mensaje.exec();
        return false;
    }
    if(ui->SpinPrecio->value()==0)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje("Precio Vacio",ADVERTENCIA);
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

void FormArticulo::AsignarCampos()
{
    Antiguo.setCodigo(ui->LineCodigo->text());

    Unidad* objUnidad=(Unidad*)MapaUnidad->value(ui->ComboUnidad->currentText());
    Objeto.setCodigoUnidad(objUnidad->getCodigo());
    Modelo* objModelo=(Modelo*)MapaModelo->value(ui->ComboModelo->currentText());
    Objeto.setCodigoModelo(objModelo->getCodigo());
    Marca* objMarca=(Marca*)MapaMarca->value(ui->ComboMarca->currentText());
    Objeto.setCodigoMarca(objMarca->getCodigo());
    Moneda* objMoneda=(Moneda*)MapaMoneda->value(ui->ComboMoneda->currentText());
    Objeto.setCodigoMoneda(objMoneda->getCodigo());
    ArticuloTipo* objTipo=(ArticuloTipo*)MapaTipo->value(ui->ComboTipo->currentText());
    Objeto.setCodigoTipo(objTipo->getCodigo());

    Objeto.setNombre(ui->LineNombre->text());
    Objeto.setVigencia(ui->ComboVigencia->currentText());
    Objeto.setUnico(ui->ComboUnico->currentText());
    Objeto.setCantidadMin(ui->SpinCantidadMin->value());
    Objeto.setCodigoImagen(CodigoImagen);
    Objeto.setCodigoInterno(ui->LineCodigoInterno->text());
    Objeto.setCodigoExterno(ui->LineCodigoExterno->text());
    Objeto.setPrecio(ui->SpinPrecio->value());

}

void FormArticulo::Habilitar()
{
 ui->LineCodigoExterno->setEnabled(true);
 ui->LineCodigoInterno->setEnabled(true);

 ui->LineNombre->setEnabled(true);
 ui->ComboMarca->setEnabled(true);
 ui->ComboModelo->setEnabled(true);
 ui->ComboMoneda->setEnabled(true);
 ui->ComboTipo->setEnabled(true);
 ui->ComboUnico->setEnabled(true);
 ui->ComboUnidad->setEnabled(true);
 ui->ComboVigencia->setEnabled(true);
 ui->SpinCantidadMin->setEnabled(true);
 ui->SpinPrecio->setEnabled(true);
}

void FormArticulo::Deshabilitar()
{
    ui->LineCodigoExterno->setEnabled(false);
    ui->LineCodigoInterno->setEnabled(false);

    ui->LineNombre->setEnabled(false);
    ui->ComboMarca->setEnabled(false);
    ui->ComboModelo->setEnabled(false);
    ui->ComboMoneda->setEnabled(false);
    ui->ComboTipo->setEnabled(false);
    ui->ComboUnico->setEnabled(false);
    ui->ComboUnidad->setEnabled(false);
    ui->ComboVigencia->setEnabled(false);
    ui->SpinCantidadMin->setEnabled(false);
    ui->SpinPrecio->setEnabled(false);
}

void FormArticulo::Limpiar()
{
    ui->LineCodigo->clear();
    ui->LineImagen->clear();
    ui->LineNombre->clear();
    ui->LineCodigoExterno->setText("0000");
    ui->LineCodigoInterno->setText("0000");
    ui->ComboMarca->setCurrentIndex(0);
    ui->ComboModelo->setCurrentIndex(0);
    ui->ComboMoneda->setCurrentIndex(0);
    ui->ComboTipo->setCurrentIndex(0);
    ui->ComboUnico->setCurrentIndex(0);
    ui->ComboUnidad->setCurrentIndex(0);
    ui->ComboVigencia->setCurrentIndex(0);
    ui->SpinCantidadMin->setValue(0);
    ui->SpinPrecio->setValue(0);
    CodigoImagen.clear();
}







void FormArticulo::Ruta(QString Codigo, QString Cadena)
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

void FormArticulo::CargarCombos()
{
    FabricaArticuloTipos* FabTipo=Bd->Fabrica->CrearArticuloTipo();
    FabricaModelo* FabModelo=Bd->Fabrica->CrearModelo();
    FabricaMarca* FabMarca=Bd->Fabrica->CrearMarca();
    FabricaMoneda* FabMoneda=Bd->Fabrica->CrearMoneda();
    FabricaUnidades* FabUnidad=Bd->Fabrica->CrearUnidad();

    Bd->Fabrica->Conectar();
    MapaTipo=FabTipo->BuscarClave();
    MapaModelo=FabModelo->BuscarClave();
    MapaMarca=FabMarca->BuscarClave();
    MapaUnidad=FabUnidad->BuscarClave();
    MapaMoneda=FabMoneda->BuscarClave();

    Bd->Fabrica->Desconectar();
     ui->ComboTipo->addItem("");
     ui->ComboModelo->addItem("");
     ui->ComboMarca->addItem("");
     ui->ComboUnidad->addItem("");
     ui->ComboMoneda->addItem("");

     foreach (const QString &str, MapaTipo->keys())
    {
        ArticuloTipo* obj=(ArticuloTipo*)MapaTipo->value(str);
        ui->ComboTipo->addItem(QIcon(RutaImagenes+obj->getImagen()),obj->getNombre());

    }
    foreach (const QString &str, MapaModelo->keys())
    {
        Modelo* obj=(Modelo*)MapaModelo->value(str);
        ui->ComboModelo->addItem(QIcon(RutaImagenes+obj->getRutaImagen()),obj->getNombre());
    }
    foreach (const QString &str, MapaMarca->keys())
    {
        Marca* obj=(Marca*)MapaMarca->value(str);
        ui->ComboMarca->addItem(QIcon(RutaImagenes+obj->getRutaImagen()),obj->getNombre());

    }
    foreach (const QString &str, MapaUnidad->keys())
    {qDebug() << str;
        Unidad* obj=(Unidad*)MapaUnidad->value(str);
        ui->ComboUnidad->addItem(QIcon(RutaImagenes+obj->getRutaImagen()),obj->getNombre());

    }
    foreach (const QString &str, MapaMoneda->keys())
    {
        Moneda* obj=(Moneda*)MapaMoneda->value(str);
        ui->ComboMoneda->addItem(QIcon(RutaImagenes+obj->getRutaImagen()),obj->getNombre());

    }
}


void FormArticulo::SetObjeto(ObjetoMaestro *ObjetoTipo)
{
    Objeto=*((Articulo*)(ObjetoTipo));
    Deshabilitar();

    Antiguo.setCodigo(Objeto.getCodigo());
    ui->LineCodigo->setText(Objeto.getCodigo());
    ui->LineCodigoExterno->setText(Objeto.getCodigoExterno());
    ui->LineCodigoInterno->setText(Objeto.getCodigoInterno());
    ui->LineNombre->setText(Objeto.getNombre());
    ui->LineImagen->setText(Objeto.getRutaImagen());
    ui->SpinCantidadMin->setValue(Objeto.getCantidadMin());

    ui->ComboMarca->setCurrentText(Objeto.getNombreMarca());
    ui->ComboModelo->setCurrentText(Objeto.getNombreModelo());
    ui->ComboMoneda->setCurrentText(Objeto.getNombreMoneda());
    ui->ComboTipo->setCurrentText(Objeto.getNombreTipo());
    ui->ComboUnico->setCurrentText(Objeto.getUnico());
    ui->ComboUnidad->setCurrentText(Objeto.getNombreUnidad());
    ui->ComboVigencia->setCurrentText(Objeto.getVigencia());
    ui->SpinPrecio->setValue(Objeto.getPrecio());
    QPixmap*  pix=new QPixmap(RutaImagenes+Objeto.getRutaImagen());
    ui->LabelImage->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    /*-----Manipulacion de los Botones------*/
    ui->ButtonModificar->setEnabled(true);
    ui->ButtonEliminar->setEnabled(true);
    ui->ButtonGuardar->setEnabled(false);
    ui->ButtonArchivoImagen->setEnabled(false);
}

void FormArticulo::on_ButtonGuardar_clicked()
{
    if(Estados==INSERTAR)
    {
    if(Guardar())
    Limpiar();
    emit ActualizarRepisa((ObjetoMaestro*)new Articulo());
    }
    if(Estados==MODIFICAR)
    {
    if(Modificar())
        Deshabilitar();
        /*Volver a su estado los botones*/
        ui->ButtonGuardar->setEnabled(false);
        ui->ButtonModificar->setEnabled(true);
        ui->ButtonEliminar->setEnabled(true);
     emit ActualizarRepisa((ObjetoMaestro*)new Articulo());
    }
}

void FormArticulo::on_ButtonModificar_clicked()
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

void FormArticulo::on_ButtonEliminar_clicked()
{
    if(Eliminar())
    {
    emit(ActivarBoton(Objeto.getCodigo()));
    emit ActualizarRepisa((ObjetoMaestro*)new Articulo());
        this->close();
        this->destroy();
    }
}

void FormArticulo::on_ButtonRegresar_clicked()
{
    emit(ActivarBoton(Objeto.getCodigo()));
    this->close();
    this->destroy();
}

void FormArticulo::on_ButtonArchivoImagen_clicked()
{
    VisorImagenes* visor=new VisorImagenes(this);
    visor->exec();
}

void FormArticulo::on_ComboTipo_currentTextChanged(const QString &arg1)
{
    if (!arg1.isEmpty()) {
        ArticuloTipo* obj=(ArticuloTipo*)MapaTipo->value(arg1);
        QPixmap*  pix=new QPixmap(RutaImagenes+obj->getImagen());
        ui->label_imagen_familia->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    }
    else
    {
        ui->label_imagen_familia->setText("Familia");
    }

}



void FormArticulo::on_ComboModelo_currentTextChanged(const QString &arg1)
{ if (!arg1.isEmpty()) {
    Modelo* obj=(Modelo*)MapaModelo->value(arg1);
    QPixmap*  pix=new QPixmap(RutaImagenes+obj->getRutaImagen());
    ui->label_imagen_modelo->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
    else
    {
        ui->label_imagen_modelo->setText("Modelo");
    }
}

void FormArticulo::on_ComboMarca_currentTextChanged(const QString &arg1)
{ if (!arg1.isEmpty()) {
    Marca* obj=(Marca*)MapaMarca->value(arg1);
    QPixmap*  pix=new QPixmap(RutaImagenes+obj->getRutaImagen());
    ui->label_imagen_marca->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
    else
    {
        ui->label_imagen_marca->setText("Marca");
    }
}

void FormArticulo::on_ComboMoneda_currentTextChanged(const QString &arg1)
{ if (!arg1.isEmpty()) {
    Moneda* obj=(Moneda*)MapaMoneda->value(arg1);
    QPixmap*  pix=new QPixmap(RutaImagenes+obj->getRutaImagen());
    ui->label_imagen_moneda->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
    else
    {
        ui->label_imagen_moneda->setText("Moneda");
    }
}

void FormArticulo::on_ComboUnidad_currentTextChanged(const QString &arg1)
{ if (!arg1.isEmpty()) {
    Unidad* obj=(Unidad*)MapaUnidad->value(arg1);
    QPixmap*  pix=new QPixmap(RutaImagenes+obj->getRutaImagen());
    ui->label_imagen_unidad->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
    else
    {
        ui->label_imagen_unidad->setText("Unidad");
    }
}
