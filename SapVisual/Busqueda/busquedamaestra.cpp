#include "busquedamaestra.h"
#include "ui_busquedamaestra.h"

BusquedaMaestra::BusquedaMaestra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusquedaMaestra)
{
    ui->setupUi(this);

    /*conexion con el visor*/
    VisorConsulta=new VisorConsultas(this);
    connect(this,SIGNAL(my_signal(QSqlQueryModel *,QList<bool>)),VisorConsulta,SLOT(Consulta(QSqlQueryModel *,QList<bool>)));
    connect(this,SIGNAL(SignalRepisa(ObjetoMaestro*,int,QString)),parent,SLOT(ActualizarRepisa(ObjetoMaestro *,int,QString)));
    connect(this,SIGNAL(Activar()),parent,SLOT(ActivarRepisa()));
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
                BD=DefBD::IniciarBD();
                ui->ComboCampos->addItem("Todo");
                ComboCampos=ui->ComboCampos;
                ComboTipos=ui->ComboTipo;
                LineNombre=ui->LineNombre_2;
                LineFin=ui->LineFin_2;
                FechaEdit=ui->EditFecha;
                FechaEditFin=ui->EditFechaFin;
                ui->EditFecha->setHidden(true);
                ui->LineNombre_2->setHidden(false);
                ui->ComboTipo->setHidden(true);

                ui->labelDesde->setVisible(false);
                ui->labelHasta->setVisible(false);
                FechaEdit->setVisible(false);
                FechaEditFin->setVisible(false);

                GrupoBoton=new QButtonGroup(this);
                GrupoBoton->addButton(ui->ButAsc,1);
                GrupoBoton->addButton(ui->ButDesc,2);

                //ui->LineFin_2->setValidator(new QIntValidator(LineFin));
        /*-----------------------------*/
        VisorConsulta->show();
        VisorConsulta->setGeometry(parent->x()+parent->width(),parent->y()+this->height(),300,300);


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
    ui->EditFecha->setHidden(true);
    ui->ComboTipo->setHidden(true);
    ui->LineNombre_2->setHidden(false);
}


BusquedaMaestra::~BusquedaMaestra()
{
    delete ui;
}

void BusquedaMaestra::VisibleLine()
{
    LineNombre->setVisible(true);
    LineNombre->clear();

    ui->labelDesde->setVisible(false);
    ui->labelHasta->setVisible(false);
    FechaEdit->setVisible(false);
    FechaEditFin->setVisible(false);

    ComboTipos->setVisible(false);
}

void BusquedaMaestra::VisibleFecha()
{
    ui->labelDesde->setVisible(true);
    ui->labelHasta->setVisible(true);
    FechaEdit->setVisible(true);
    FechaEditFin->setVisible(true);
    FechaEdit->setDate(QDate::currentDate());
    FechaEditFin->setDate(QDate::currentDate());

    ComboTipos->setVisible(false);

    LineNombre->setVisible(false);
}

void BusquedaMaestra::VisibleCombo()
{
    ComboTipos->setVisible(true);
    ComboTipos->clear();

    ui->labelDesde->setVisible(false);
    ui->labelHasta->setVisible(false);
    FechaEdit->setVisible(false);
    FechaEditFin->setVisible(false);

    LineNombre->setVisible(false);

}

void BusquedaMaestra::on_BotonConsultar_2_clicked()
{
    ObtenerConsulta();
    /*

    ArticuloTipo ObjetoConsulta;
    if(ui->CheckNombre->isChecked())
    {
        ObjetoConsulta.setNombre(ui->LineNombre->text());
        //FlagConsulta=CAMPOS;
    }

    BD->Fabrica->Conectar();
    QString ini=ui->LineInicio->text();
    QString fin=ui->LineFin->text();
    QString Extra=" order by codigo desc LIMIT "+fin+" offset "+ini;
    QSqlQueryModel* Model= Fab->BuscarTabla(ObjetoConsulta,Extra,CAMPOS);
    BD->Fabrica->Desconectar();

    emit my_signal(Model);
    emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta),fin.toInt());
    VisorConsulta->move(this->x(),this->y()+this->height());

    */
}



void BusquedaMaestra::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {
        VisorConsulta->close();

        emit Activar();
        this->close();
        this->destroy();
    }
}

void BusquedaMaestra::on_LineNombre_2_returnPressed()
{
    ObtenerConsulta();
}


void BusquedaMaestra::on_ComboCampos_currentIndexChanged(int index)
{
    CambiarCombo(index);
}

void BusquedaMaestra::on_ComboTipo_currentIndexChanged(int index)
{
    ObtenerConsulta();
}

void BusquedaMaestra::on_EditFecha_dateChanged(const QDate &date)
{
    ObtenerConsulta();
}

void BusquedaMaestra::on_EditFechaFin_dateChanged(const QDate &date)
{
       ObtenerConsulta();
}

void BusquedaMaestra::on_LineFin_2_valueChanged(int arg1)
{
    ObtenerConsulta();
}
