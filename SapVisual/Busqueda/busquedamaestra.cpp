#include "busquedamaestra.h"
#include "ui_busquedamaestra.h"

BusquedaMaestra::BusquedaMaestra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusquedaMaestra)
{
    ui->setupUi(this);

    /*conexion con el visor*/

 //   connect(this,SIGNAL(SignalRepisa(ObjetoMaestro*,int,QString)),parent,SLOT(ActualizarRepisa(ObjetoMaestro *,int,QString)));
    connect(this,SIGNAL(Activar()),parent,SLOT(ActivarRepisa()));
    connect(this,SIGNAL(SignalBusquedaTipo(int,bool,int)),parent,SLOT(RecibirTipoConsulta(int,bool,int)));
    /**/

    /*Fondo Madera*/
    this->setWindowFlags(Qt::Window
                         | Qt::FramelessWindowHint
                         | Qt::WindowMinimizeButtonHint
                         | Qt::WindowMaximizeButtonHint
                         | Qt::WindowCloseButtonHint);

     QPixmap bkgnd(FondoForm);

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    /*------------------------------------------------*/

        /*Conexion con la BD y Fabrica*/

           //     ui->ComboCampos->addItem("Todo");
               // ComboCampos=new QComboBox(this);
                ComboCampos=this->ui->ComboCamposLabel;
               // ComboCampos->addItem("Todo");
                //ui->LineFin_2->setValidator(new QIntValidator(LineFin));
        /*-----------------------------*/


        /*Autocompletar
        QSqlQueryModel* Model;
        BD->Fabrica->Conectar();


        Model=new QSqlQueryModel();
        Model->setQuery("SELECT distinct codigo FROM articulo_tipo ;");
        Completar=new QCompleter(Model,this);
        Completar->setCaseSensitivity(Qt::CaseInsensitive);
        Completar->setCompletionColumn(0);
        ui->LineNombre->setCompleter(Completar);

        BD->Fabrica->Desconectar();
        */
}

void BusquedaMaestra::CambiarCombo(int index)
{

}


BusquedaMaestra::~BusquedaMaestra()
{
    delete ui;
}

void BusquedaMaestra::VisibleLine()
{
    LineNombre->setVisible(true);
    LineNombre->clear();


}

void BusquedaMaestra::VisibleFecha()
{

    ComboTipos->setVisible(false);

    LineNombre->setVisible(false);
}

void BusquedaMaestra::VisibleCombo()
{


}




void BusquedaMaestra::on_LineFin_2_valueChanged(int arg1)
{
  emit(SignalBusquedaTipo(ui->ComboCamposLabel->currentIndex(),ui->checkBoxDetalle->isChecked(),ui->LineFin_2->value()));
    if (!ui->checkBoxDetalle->isChecked())
    {
        this->close();
      this->destroy();
        emit (Activar());
    }
}

void BusquedaMaestra::on_checkBoxDetalle_stateChanged(int arg1)
{
    emit(SignalBusquedaTipo(ui->ComboCamposLabel->currentIndex(),ui->checkBoxDetalle->isChecked(),ui->LineFin_2->value()));
    if (!ui->checkBoxDetalle->isChecked())
    {
        this->close();
      this->destroy();
        emit (Activar());
    }
}

void BusquedaMaestra::on_ComboCamposLabel_currentIndexChanged(int index)
{
    emit(SignalBusquedaTipo(index,ui->checkBoxDetalle->isChecked(),ui->LineFin_2->value()));

    if (!ui->checkBoxDetalle->isChecked())
    {
        this->close();
      this->destroy();
        emit (Activar());
    }

}
