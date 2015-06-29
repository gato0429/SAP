#ifndef REPISA_H
#define REPISA_H
#include <QSet>
#include <vector>
#include <QButtonGroup>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QtWidgets>
#include "../Objetos/objetomaestro.h"
#include <vector>
#include "../Fabricas/fabricabasedatos.h"
#include "../DefBD.h"
#include <QLineEdit>
#include "../Extras/visorconsultas.h"
#include "../Busqueda/busquedamaestra.h"
#include "../Formularios/formmaestro.h"
#include <iostream>
#include <QString>
#include <qlist.h>
using namespace std;
class Repisa:public QMainWindow
{
Q_OBJECT
protected:
    ObjetoMaestro*          ObjetoConsulta;
    BusquedaMaestra*        Busqueda;
    /*Titulo de la Repisa*/
    QLabel*         LabelTitulo;
     QLabel* FondoRepisa;
    /**/
    /*Busqueda*/
    QString CampoBusqueda;
    /*-------*/
    /*Campos de Busqueda*/
    VisorConsultas* VisorConsulta;
    QLineEdit*      LineBuscar;
    QDateEdit*      FechaInicio;
    QDateEdit*      FechaFin;
    QComboBox*      ComboTipo;
    int             IndiceBusqueda;
    bool            DetalleBusqueda;
    int             RegistrosBusqueda;
    QList<QString>  ObjetosAbiertos;
    QString         OrderByCampo;
    /*Tañmaño del visor*/
    double  AnchoVisor;
    double  InicioVisor;
    double  AltoVisor;
    /**/
  QPushButton*    Nuevo;
  QPushButton*    Buscar;
  static  QMainWindow* Formulario;
  QPushButton*    Atras;
  QPushButton*    Siguiente;
  QPushButton*    Cerrar;




  QMap<QString,ObjetoMaestro*>*   MapaRepisa;
//  QMap<QString,ObjetoMaestro*>::iterator it;

  //QMap<QString,ObjetoMaestro*>::reverse_iterator itf;

//  QMap<QString,ObjetoMaestro*>::iterator ittemp;

  QList<ObjetoMaestro*>* Mapa;
  QList<ObjetoMaestro*>::iterator it;
  QList<ObjetoMaestro*>::iterator ittemp;
  vector<QPushButton*>          Botones;
  QButtonGroup*                 GrupoBotones;
  FabricaBaseDatos*             Bd;

  QAbstractButton*                  BotonActual;
  int RegistrosTabla;
  int elementos;
  int TotalElementos;
  int ElementosContados;
  int fil;
  int col;
  int ix;
  int iy;
  int cantidadMostrar;
  QString Ordenamiento;

  void MostrarLabel();
  void MostrarCombo();
  void MostrarFecha();
  void OcultarTodo();
  void ActualizarRepisaLocal(ObjetoMaestro * Objeto, int limite,QString Ord);
  virtual void ConsultarBusqueda()=0;
private:

  int TotalRepisa;
  void LimpiarRepisa();
  void LLenarDetalles(); //Titulo y Busqueda

private slots:
   virtual void GrupoBotonesClick(QAbstractButton* buttonID)=0;
   virtual void ActualizarRepisa(ObjetoMaestro * Objeto, int limite,QString Ord);
    virtual void RecibirTipoConsulta(int index,bool detalle, int registros);

    void ActualizarTodo(ObjetoMaestro * Objeto);
    void ActivarRepisa();
    void ActivarBoton(int id);
    void ActivarBotonRepisa(QString codigo);

   void on_ComboTipo_currentIndexChanged(int index);
   void on_EditFecha_dateChanged(const QDate &date);
   void on_EditFechaFin_dateChanged(const QDate &date);
   void on_LineBusqueda_returnPresed();
public slots:

    virtual void AtrasClick();
    virtual void SiguienteClick();
    virtual void NuevoClick()=0;
    virtual void BuscarClick()=0;
    virtual void CerrarClick();
public:
   virtual void ObtenerConsulta()=0;

    Repisa();
    void DibujarRepisa();
    void Dibujar();
    virtual void LlenarRepisa();
    virtual void ObjetosIndependientes()=0;
    virtual void ActualizarMapa(ObjetoMaestro* Objeto);
    virtual void ActualizarConsulta()=0;
 signals:
      void my_signal(QSqlQueryModel*,QList<bool>);

protected:
    void mousePressEvent(QMouseEvent *evt)
    {
        oldPos = evt->globalPos();

    }

    void mouseMoveEvent(QMouseEvent *evt)
    {
        const QPoint delta = evt->globalPos() - oldPos;
        move(x()+delta.x(), y()+delta.y());
        oldPos = evt->globalPos();


        if(Busqueda!=NULL)
        {
            InicioVisor=VisorConsulta->geometry().width();
            AnchoVisor=VisorConsulta->geometry().width();
            AltoVisor=VisorConsulta->geometry().height();
            Busqueda->move(this->x()+this->width()-60,this->y()+90);
            VisorConsulta->setGeometry(this->geometry().center().x()-InicioVisor/2-20,this->pos().y()+380,AnchoVisor,AltoVisor);

        }
    }

private:
    QPoint oldPos;

    virtual void enterEvent(QEvent * event)
    {

        this->setFocus();
    }
};



#endif // REPISA_H
