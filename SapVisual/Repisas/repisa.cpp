#include "repisa.h"
#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QPalette>


QMainWindow* Repisa::Formulario=0;

Repisa::Repisa()
{

    AnchoVisor=420;
    AltoVisor=275;
    InicioVisor=20;

    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
    cantidadMostrar=32;
    Ordenamiento="desc";
    OrderByCampo="codigo";
    IndiceBusqueda=0;
        RegistrosBusqueda=100;
Busqueda=NULL;
VisorConsulta=new VisorConsultas(this);
connect(this,SIGNAL(my_signal(QSqlQueryModel *,QList<bool>)),VisorConsulta,SLOT(Consulta(QSqlQueryModel *,QList<bool>)));

    TotalRepisa=16;
    Bd=DefBD::IniciarBD();
   Formulario=this;
   Formulario->setGeometry(100,100,420,577);

   Formulario->setWindowFlags(Qt::Window
                        | Qt::FramelessWindowHint
                        | Qt::WindowMinimizeButtonHint
                        | Qt::WindowMaximizeButtonHint
                        | Qt::WindowCloseButtonHint);

    QPixmap bkgnd(":/Imagenes/fondos/madera.png");
    bkgnd = bkgnd.scaled(Formulario->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPalette palette;
   palette.setBrush(QPalette::Background, bkgnd);
 //   Formulario->setPalette(palette);


    setAttribute(Qt::WA_TranslucentBackground);
   //   setStyleSheet("background:transparent;");


       DibujarRepisa();
       LLenarDetalles();

       Atras= new QPushButton(Formulario);
       Siguiente= new QPushButton(Formulario);
       Nuevo= new QPushButton(Formulario);
       Buscar= new QPushButton(Formulario);
       Cerrar= new QPushButton(Formulario);
       Dibujar();

        connect(Atras, SIGNAL(clicked()),Formulario, SLOT(AtrasClick()));
        connect(Siguiente, SIGNAL(clicked()),Formulario, SLOT(SiguienteClick()));
        connect(Nuevo, SIGNAL(clicked()),Formulario, SLOT(NuevoClick()));
        connect(Buscar, SIGNAL(clicked()),Formulario, SLOT(BuscarClick()));
        connect(Cerrar, SIGNAL(clicked()), Formulario, SLOT(CerrarClick()));
       Atras->setParent(FondoRepisa);
       Siguiente->setParent(FondoRepisa);
       Nuevo->setParent(FondoRepisa);
       Buscar->setParent(FondoRepisa);
       Cerrar->setParent(FondoRepisa);

}


void Repisa::LLenarDetalles()
{
    QFont serifFont("Cambria", 12, QFont::Cursive);
    serifFont.setStyle(QFont::StyleItalic);
    /*Titulo*/
    LabelTitulo=new QLabel(Formulario);
    LabelTitulo->setGeometry(123,90,135,20);
    LabelTitulo->setAlignment(Qt::AlignCenter);
    LabelTitulo->setFont(serifFont);
    LabelTitulo->setText("Sin Nombre");

    LabelTitulo->setParent(FondoRepisa);

    QString style="QDateEdit {"
            "border: 1px solid gray;"
            "border-radius: 10px;"
            "padding: 0 8px;"
           " background: transparent;"
           " }"
            "font: italic 12pt 'Cambria';";
           /* "QDateEdit::down-arrow {"
            "image: url(:/down-arrow.png);"
            "border: 1px solid #000000;"
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 0 #dedede, stop: 0.5 #434343,"
            "stop: 0.51 #000000, stop: 1 #656a6d);"
            "}";*/
    QString stylecombo="QComboBox"
    "{"
          " border: 1px solid gray;"
          "border-radius: 10px;"
          "padding: 0 8px;"
          "background: transparent;"
          "selection-background-color: darkgray;"
    "}"

   " QComboBox QListView"
    "{"

            "background: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));"
           " color: rgb(220, 220, 220);"
           " margin: 0 0 0 0;"
                       " border: 1px solid gray;"

                        "padding: 0 8px;"
                       "selection-background-color: darkgray;"
                      "background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));"
       "}"

";";

    /*Line Buscar*/
    LineBuscar=new QLineEdit(Formulario);
    LineBuscar->setGeometry(120,160,150,20);
    LineBuscar->setStyleSheet("    border: 1px solid gray;"
                              "border-radius: 10px;"
                              "padding: 0 8px;"
                              "background: transparent;"
                              "selection-background-color: darkgray;");
    LineBuscar->setFont(serifFont);
    LineBuscar->setParent(FondoRepisa);
    /*Combo*/

    ComboTipo=new QComboBox(Formulario);
    ComboTipo->setGeometry(120,160,150,20);
    ComboTipo->setStyleSheet(stylecombo);
    ComboTipo->setFont(serifFont);
   ComboTipo->setParent(FondoRepisa);
    /*Fechas*/


    FechaInicio=new QDateEdit(Formulario);
    FechaInicio->setCalendarPopup(true);
    FechaInicio->setGeometry(120,135,150,20);
    FechaInicio->setStyleSheet(style);
    FechaInicio->setFont(serifFont);
   FechaInicio->setParent(FondoRepisa);

    FechaFin=new QDateEdit(Formulario);
    FechaFin->setCalendarPopup(true);
    FechaFin->setGeometry(120,160,150,20);
    FechaFin->setStyleSheet(style);
    FechaFin->setFont(serifFont);
   FechaFin->setParent(FondoRepisa);

  MostrarLabel();
/*Vinculando Señales*/
  connect(ComboTipo, SIGNAL(currentIndexChanged (int)),Formulario, SLOT(on_ComboTipo_currentIndexChanged(int)));
  connect(FechaInicio, SIGNAL(dateChanged(const QDate&)),Formulario, SLOT(on_EditFecha_dateChanged(const QDate&)));
  connect(FechaFin, SIGNAL(dateChanged(const QDate&)),Formulario, SLOT(on_EditFechaFin_dateChanged(const QDate&)));
  connect(LineBuscar, SIGNAL(returnPressed()),Formulario, SLOT(on_LineBusqueda_returnPresed()));

}

void Repisa::DibujarRepisa()
{

    QPixmap* pix=new QPixmap(":/Imagenes/fondos/estante.png");
    FondoRepisa=new QLabel(Formulario);
    FondoRepisa->setGeometry(0,0,420,577);
    FondoRepisa->setPixmap(pix->scaled(371,561,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


   /*
    int y=0;

    QPixmap* pix=new QPixmap(":/Imagenes/fondos/muroder.png");

    QLabel* muroder=new QLabel(Formulario);
    muroder->setGeometry(340,-10,81,631);
    muroder->setPixmap(pix->scaled(81,631,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));



    QLabel* muroizq=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/muroizq.png");
    muroizq->setGeometry(0,-10,81,631);
    muroizq->setPixmap(pix->scaled(81,631,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


    QLabel* muroarriba=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/techo.png");
    muroarriba->setPixmap(pix->scaled(413,140,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    muroarriba->setGeometry(6,-56,413,140);

    QLabel* repisa1=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/repisa1.png");
    repisa1->setPixmap(pix->scaled(397,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    repisa1->setGeometry(11,47-y,397,81);



    QLabel* repisa2=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/repisa1.png");
    repisa2->setPixmap(pix->scaled(397,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    repisa2->setGeometry(11,151,397,81);

    QLabel* repisa3=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/repisa1.png");
    repisa3->setPixmap(pix->scaled(397,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    repisa3->setGeometry(11,255,397,81);

    QLabel* repisa4=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/repisa1.png");
    repisa4->setPixmap(pix->scaled(397,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    repisa4->setGeometry(11,359,397,81);

    QLabel* repisa5=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/repisa1.png");
    repisa5->setPixmap(pix->scaled(397,81,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    repisa5->setGeometry(11,463,397,81);

    QLabel* muroabajo=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/madera4.png");
    muroabajo->setPixmap(pix->scaled(521,58,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    muroabajo->setGeometry(0,521-y,521,58);


    QLabel* division1=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/division.png");
    division1->setPixmap(pix->scaled(71,146,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    division1->setGeometry(271,-15-y,71,146);

    QLabel* division2=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/division.png");
    division2->setPixmap(pix->scaled(71,146,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    division2->setGeometry(271,89-y,71,146);

    QLabel* division3=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/division.png");
    division3->setPixmap(pix->scaled(71,146,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    division3->setGeometry(271,193-y,71,146);

    QLabel* division4=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/division.png");
    division4->setPixmap(pix->scaled(71,146,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    division4->setGeometry(271,297-y,71,146);

    QLabel* division5=new QLabel(Formulario);
    pix=new QPixmap(":/Imagenes/fondos/division.png");
    division5->setPixmap(pix->scaled(71,146,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    division5->setGeometry(271,401-y,71,146);
*/
}

void Repisa::MostrarLabel()
{
      LineBuscar->setHidden(false);
      ComboTipo->setHidden(true);
      FechaFin->setHidden(true);
      FechaInicio->setHidden(true);
}

void Repisa::MostrarCombo()
{
    LineBuscar->setHidden(true);
    ComboTipo->setHidden(false);
    FechaFin->setHidden(true);
    FechaInicio->setHidden(true);
}

void Repisa::MostrarFecha()
{
    LineBuscar->setHidden(true);
    ComboTipo->setHidden(true);
    FechaFin->setHidden(false);
    FechaInicio->setHidden(false);
}

void Repisa::OcultarTodo()
{
    LineBuscar->setHidden(true);
    ComboTipo->setHidden(true);
    FechaFin->setHidden(true);
    FechaInicio->setHidden(true);
    ObtenerConsulta();
}

void Repisa::ActualizarRepisaLocal(ObjetoMaestro *Objeto, int limite, QString Ord)
{
    Ordenamiento=Ord;
    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
    ObjetoConsulta=Objeto;
    cantidadMostrar=limite;
    ActualizarConsulta();
    if(Mapa->size()<32)
    {
        RegistrosTabla=Mapa->size();
      //   qDebug()<<"register-->"<<RegistrosTabla;
    }
    else
    {
        RegistrosTabla=32;
    }
    if(Ordenamiento=="asc"||Ordenamiento=="ASC")
    {
        it=Mapa->begin();
    }
    else
    {
        it=Mapa->end();
        it--;
    }

    LlenarRepisa();
    ElementosContados=ElementosContados+elementos;
    TotalElementos=TotalElementos+elementos;
   // qDebug()<<"-->"<<TotalElementos;
}

void Repisa::LimpiarRepisa()
{
    for(int a=0; a<Botones.size(); a++)
    {

        GrupoBotones->removeButton(Botones[a]);
        delete Botones[a];
    }
    Botones.clear();
}



void Repisa::ActualizarRepisa(ObjetoMaestro *Objeto, int limite, QString Ord)
{

    Ordenamiento=Ord;
    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
    ObjetoConsulta=Objeto;
    cantidadMostrar=limite;
    ActualizarConsulta();
    if(Mapa->size()<32)
    {
        RegistrosTabla=Mapa->size();
        qDebug()<<"register-->"<<RegistrosTabla;
    }
    else
    {
        RegistrosTabla=32;
    }
    if(Ordenamiento=="asc"||Ordenamiento=="ASC")
    {
        it=Mapa->begin();
    }
    else
    {
        it=Mapa->end();
        it--;
    }

    LlenarRepisa();
    ElementosContados=ElementosContados+elementos;
    TotalElementos=TotalElementos+elementos;
   // qDebug()<<"-->"<<TotalElementos;

}

void Repisa::RecibirTipoConsulta(int index, bool detalle, int registros)
{
    IndiceBusqueda=index;
    DetalleBusqueda=detalle;
    RegistrosBusqueda=registros;
    Atras->setVisible(true);
    qDebug()<<"Entre a la consulta";

    if (detalle)
    {


        VisorConsulta->setGeometry(this->geometry().center().x()-InicioVisor/2-20,this->pos().y()+380,AnchoVisor,AltoVisor);
  //   VisorConsulta->move(0,this->height()/2); //siempre igual
        InicioVisor=VisorConsulta->geometry().width();
        AnchoVisor=VisorConsulta->geometry().width();
        AltoVisor=VisorConsulta->geometry().height();
     VisorConsulta->show();
    }
    else
    {
        InicioVisor=VisorConsulta->geometry().width();
        AnchoVisor=VisorConsulta->geometry().width();
        AltoVisor=VisorConsulta->geometry().height();
       VisorConsulta->close();
    }
    ConsultarBusqueda();
}

void Repisa::ActualizarTodo(ObjetoMaestro *Objeto)
{
    Ordenamiento="desc";
    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
    ObjetoConsulta=Objeto; //esto estaba comentado
    ActualizarConsulta();

    if(Ordenamiento=="asc"||Ordenamiento=="ASC")
    {
        it=Mapa->begin();
    }
    else
    {
        it=Mapa->end();
        it--;
    }

    LlenarRepisa();
    ElementosContados=ElementosContados+elementos;
    TotalElementos=TotalElementos+elementos;
    qDebug()<<"-->"<<TotalElementos;
}

void Repisa::ActivarRepisa()
{
    Nuevo->setEnabled(true);
    Buscar->setEnabled(true);
}

void Repisa::ActivarBoton(int id)
{
    GrupoBotones->button(id)->setEnabled(true);
}

void Repisa::ActivarBotonRepisa(QString codigo)
{
    //qDebug()<<"codigo recibido:"+codigo;
    if ( ObjetosAbiertos.contains(codigo)) {
        ObjetosAbiertos.removeOne(codigo);
        QList<QAbstractButton*> vb=GrupoBotones->buttons();
        for (int var = 0; var < vb.size(); ++var)
        {
            if(vb.at(var)->objectName()==codigo)
            {
                vb.at(var)->setEnabled(true);
                return;
            }

        }

    }
}

void Repisa::on_ComboTipo_currentIndexChanged(int index)
{
    ObtenerConsulta();
}

void Repisa::on_EditFecha_dateChanged(const QDate &date)
{
    ObtenerConsulta();
}

void Repisa::on_EditFechaFin_dateChanged(const QDate &date)
{
    ObtenerConsulta();
}

void Repisa::on_LineBusqueda_returnPresed()
{
    ObtenerConsulta();
}

void Repisa::AtrasClick()
{

      TotalElementos=TotalElementos-elementos;
      ElementosContados=ElementosContados-elementos;
    if(ElementosContados<=0)
    {
         qDebug()<<"retrocedi llege a 100";
//         ElementosContados=80;
         int t=TotalElementos;
         TotalElementos=TotalElementos-32;
        ActualizarConsulta();

        if(Ordenamiento=="asc"||Ordenamiento=="ASC")
        {
            it=Mapa->begin();
            it+=TotalRepisa;
        }
        else
        {
            it=Mapa->begin();
            it+=(TotalRepisa-1);
        }

        LlenarRepisa();
        ElementosContados=32;
        TotalElementos=t;
    }
    else
    {

        if(Ordenamiento=="asc"||Ordenamiento=="ASC")
        {
          it-=elementos+TotalRepisa;

        }
        else
        {

                     if(it==Mapa->begin()-1)
                     {
                          it=Mapa->begin();
                          it+=elementos+(TotalRepisa-1);
                     }
                     else
                     {
                         it+=elementos+TotalRepisa;
                     }

        }

    LlenarRepisa();
    }



if(TotalElementos<=TotalRepisa)
{
    Atras->setEnabled(false);
}
else
{
      Atras->setEnabled(true);
}
qDebug()<<"-->"<<TotalElementos;
}

void Repisa::SiguienteClick()
{

         qDebug()<<"antes de dar siguiente";
    if(ElementosContados>=cantidadMostrar)
    {
         qDebug()<<" avanzo llege a 100 casa";
         ElementosContados=0;
        ActualizarConsulta();
         qDebug()<<" pase llege a 100";
        if(Ordenamiento=="asc"||Ordenamiento=="ASC")
        {
            it=Mapa->begin();
        }
        else
        {
            it=Mapa->end();
            it--;
        }

        LlenarRepisa();
    }
    else
    {
         qDebug()<<"else del siguiente";
    LlenarRepisa();
    }

    ElementosContados=ElementosContados+elementos;
    TotalElementos=TotalElementos+elementos;

    if(TotalElementos>=RegistrosTabla)
    {
        Siguiente->setEnabled(false);
    }
    else
    {
         Siguiente->setEnabled(true);
    }

    if(TotalElementos<=TotalRepisa)
    {
        Atras->setEnabled(false);
    }
    else
    {
          Atras->setEnabled(true);
    }

qDebug()<<"-->"<<TotalElementos;
}



void Repisa::CerrarClick()
{

    VisorConsulta->close();
    delete VisorConsulta;
    if(Busqueda!=NULL)
    {
    Busqueda->close();
    delete Busqueda;
    }
    this->close();
    this->destroy();
}

void Repisa::Dibujar()
{

    Atras->setIcon(QIcon(":/Imagenes/iconos/izquierda.png"));
    Atras->setIconSize(QSize(50,50));
    Atras->setFlat(true);
    Atras->setGeometry(105,535,50,31);


    Siguiente->setIcon(QIcon(":/Imagenes/iconos/derecha.png"));
    Siguiente->setIconSize(QSize(50,50));
    Siguiente->setFlat(true);
    Siguiente->setGeometry(267,535,50,31);


    Nuevo->setIcon(QIcon(":/Imagenes/iconos/add.png"));
    Nuevo->setIconSize(QSize(60,60));
    Nuevo->setFlat(true);
    Nuevo->setGeometry(290,215,60,60);

    Buscar->setIcon(QIcon(":/Imagenes/iconos/buscar.png"));
    Buscar->setIconSize(QSize(60,60));
    Buscar->setFlat(true);
    Buscar->setGeometry(290,300,60,60);


    Cerrar->setIcon(QIcon(":/Imagenes/iconos/delete.png"));
    Cerrar->setIconSize(QSize(60,60));
    Cerrar->setFlat(true);
    Cerrar->setGeometry(290,455,60,60);
}

void Repisa::LlenarRepisa()
{


    LimpiarRepisa();
    fil=1;
    col=1;
    ix=40;
    iy=230;//48
    elementos=0;

    if(Ordenamiento=="asc"||Ordenamiento=="ASC")
    {
        ittemp=Mapa->end();
    }
    else
    {
        ittemp=Mapa->begin()-1;
    }

    while (it!=ittemp&&fil<=4) //cantidad de filas
    {

        if(col<=4)
        {

            ObjetosIndependientes();
            ix=ix+60;
            col++;
            if(Ordenamiento=="asc"||Ordenamiento=="ASC")
            {
            it++;
            }
            else
            {
             it--;
            }
            elementos++;

        }
        else
        {
            ix=40;
            col=1;
            iy=iy+82;//104
            fil++;
        }
   }



    if(TotalElementos<=TotalRepisa)
    {
        Atras->setEnabled(false);
    }
    else
    {
          Atras->setEnabled(true);
    }

    if(TotalElementos>=RegistrosTabla)
    {
        Siguiente->setEnabled(false);
    }
    else
    {
         Siguiente->setEnabled(true);
    }

    if(RegistrosTabla<=TotalRepisa)
    {
        Siguiente->setEnabled(false);
    }

}

void Repisa::ActualizarMapa(ObjetoMaestro *Objeto)
{
    Ordenamiento="desc";
    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
    cantidadMostrar=32;
    ObjetoConsulta=Objeto;

    ActualizarConsulta();


    if(Ordenamiento=="asc"||Ordenamiento=="ASC")
    {
        it=Mapa->begin();
    }
    else
    {
        it=Mapa->end();
        it--;
    }


    LlenarRepisa();
    ElementosContados=ElementosContados+elementos;
    TotalElementos=TotalElementos+elementos;
    qDebug()<<"-->"<<TotalElementos;
}




