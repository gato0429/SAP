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

     QPixmap bkgnd(FondoBusqueda);

        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd);

        this->setPalette(palette);
        setAttribute(Qt::WA_TranslucentBackground);


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
/*
               QPixmap* pix=new QPixmap(FondoBusqueda);
               QLabel* muroder=new QLabel(this);
               muroder->setGeometry(0,0,this->size().width(),this->size().height());
                muroder->setPixmap(pix->scaled(245,115,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
                this->ui->ComboCamposLabel->setParent(muroder);
                this->ui->ComboCamposLabel->setGeometry(this->ui->ComboCamposLabel->geometry());
       this->ui->checkBoxDetalle->setParent(muroder);
                this->ui->checkBoxDetalle->setGeometry(1,31,134,23);
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
