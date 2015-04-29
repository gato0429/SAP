#include "repisa.h"
#include <QBuffer>
#include <QDebug>
#include <QFile>


QMainWindow* Repisa::Formulario=0;

Repisa::Repisa()
{
    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
    cantidadMostrar=100;
    Ordenamiento="desc";

    Bd=DefBD::IniciarBD();
   Formulario=this;
   Formulario->setGeometry(100,100,420,577);

   Formulario->setWindowFlags(Qt::Window
                        | Qt::FramelessWindowHint
                        | Qt::WindowMinimizeButtonHint
                        | Qt::WindowMaximizeButtonHint
                        | Qt::WindowCloseButtonHint);

    QPixmap bkgnd(":/Imagenes/fondos/madera4.png");
    bkgnd = bkgnd.scaled(Formulario->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    Formulario->setPalette(palette);




       DibujarRepisa();
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

}
ObjetoMaestro* Repisa::ObjetoConsulta=0;

void Repisa::DibujarRepisa()
{
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
    if(Mapa->size()<100)
    {
        RegistrosTabla=Mapa->size();
      //   qDebug()<<"register-->"<<RegistrosTabla;
    }
    else
    {
        RegistrosTabla=100;
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

void Repisa::ActualizarTodo(ObjetoMaestro *Objeto)
{
    Ordenamiento="desc";
    elementos=0;
    TotalElementos=0;
    ElementosContados=0;
   // ObjetoConsulta=Objeto;
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

void Repisa::AtrasClick()
{

      TotalElementos=TotalElementos-elementos;
      ElementosContados=ElementosContados-elementos;
    if(ElementosContados<=0)
    {
         qDebug()<<"retrocedi llege a 100";
//         ElementosContados=80;
         int t=TotalElementos;
         TotalElementos=TotalElementos-100;
        ActualizarConsulta();

        if(Ordenamiento=="asc"||Ordenamiento=="ASC")
        {
            it=Mapa->begin();
            it+=20;
        }
        else
        {
            it=Mapa->begin();
            it+=19;
        }

        LlenarRepisa();
        ElementosContados=100;
        TotalElementos=t;
    }
    else
    {

        if(Ordenamiento=="asc"||Ordenamiento=="ASC")
        {
          it-=elementos+20;

        }
        else
        {

                     if(it==Mapa->begin()-1)
                     {
                          it=Mapa->begin();
                          it+=elementos+19;
                     }
                     else
                     {
                         it+=elementos+20;
                     }

        }

    LlenarRepisa();
    }



if(TotalElementos<=20)
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


    if(ElementosContados>=cantidadMostrar)
    {
         qDebug()<<" avanzo llege a 100";
         ElementosContados=0;
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
    }
    else
    {

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

    if(TotalElementos<=20)
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
    this->close();
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
    Nuevo->setGeometry(325,40,60,60);

    Buscar->setIcon(QIcon(":/Imagenes/iconos/buscar.png"));
    Buscar->setIconSize(QSize(60,60));
    Buscar->setFlat(true);
    Buscar->setGeometry(325,140,60,60);


    Cerrar->setIcon(QIcon(":/Imagenes/iconos/delete.png"));
    Cerrar->setIconSize(QSize(60,60));
    Cerrar->setFlat(true);
    Cerrar->setGeometry(325,245,60,60);
}

void Repisa::LlenarRepisa()
{


    LimpiarRepisa();
    fil=1;
    col=1;
    ix=40;
    iy=48;
    elementos=0;

    if(Ordenamiento=="asc"||Ordenamiento=="ASC")
    {
        ittemp=Mapa->end();
    }
    else
    {
        ittemp=Mapa->begin()-1;
    }

    while (it!=ittemp&&fil<=5)
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
            iy=iy+104;
            fil++;
        }
   }



    if(TotalElementos<=20)
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

    if(RegistrosTabla<=20)
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
    cantidadMostrar=100;
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




