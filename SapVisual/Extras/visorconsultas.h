#ifndef VISORCONSULTAS_H
#define VISORCONSULTAS_H

#include <QSqlQueryModel>
#include <QWidget>
#include <QtGui>
#include "../Definiciones.h"
namespace Ui {
class VisorConsultas;
}

class VisorConsultas : public QWidget
{
    Q_OBJECT

public:
    explicit VisorConsultas(QWidget *parent = 0);
    ~VisorConsultas();

private slots:

    void Consulta(QSqlQueryModel * Modelo,QList<bool> CamposVisibles);


private:
    Ui::VisorConsultas *ui;

    /*Para la movilidad del formulario*/
/*   protected:
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
       QPoint oldPos;*/
   /*---------------------------------------------*/
};

#endif // VISORCONSULTAS_H
