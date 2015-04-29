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
using namespace std;
class Repisa:public QMainWindow
{
Q_OBJECT
protected:
  QPushButton*    Nuevo;
  QPushButton*    Buscar;
  static  QMainWindow* Formulario;
  QPushButton*    Atras;
  QPushButton*    Siguiente;
  QPushButton*    Cerrar;

  QMap<QString,ObjetoMaestro*>*   Mapa;
  QMap<QString,ObjetoMaestro*>::iterator it;
  //QMap<QString,ObjetoMaestro*>::reverse_iterator itf;

  QMap<QString,ObjetoMaestro*>::iterator ittemp;

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
private:
    void LimpiarRepisa();


private slots:
   virtual void GrupoBotonesClick(QAbstractButton* buttonID)=0;
   virtual void ActualizarRepisa(ObjetoMaestro * Objeto, int limite,QString Ord);
   void ActualizarTodo(ObjetoMaestro * Objeto);
    void ActivarRepisa();
   void ActivarBoton(int id);

public slots:

    virtual void AtrasClick();
    virtual void SiguienteClick();
    virtual void NuevoClick()=0;
    virtual void BuscarClick()=0;
    virtual void CerrarClick();
public:
static ObjetoMaestro* ObjetoConsulta;
    Repisa();
    void DibujarRepisa();
    void Dibujar();
    virtual void LlenarRepisa();
    virtual void ObjetosIndependientes()=0;
    virtual void ActualizarMapa(ObjetoMaestro* Objeto);
    virtual void ActualizarConsulta()=0;


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
    }

private:
    QPoint oldPos;
};



#endif // REPISA_H
