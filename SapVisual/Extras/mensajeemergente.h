#ifndef MENSAJEEMERGENTE_H
#define MENSAJEEMERGENTE_H

#include <QDialog>
#include <QWidget>
#include <QtGui>
#include <QString>
#include "../Definiciones.h"

enum TIPOMENSAJE
{
    ADVERTENCIA,
    PROBLEMA,
};

namespace Ui {
class MensajeEmergente;
}

class MensajeEmergente : public QDialog
{
    Q_OBJECT

public:
    explicit MensajeEmergente(QWidget *parent = 0);
    void SetMensaje(QString Mensaje, TIPOMENSAJE tipo);
    ~MensajeEmergente();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MensajeEmergente *ui;
    /*Para la movilidad del formulario*/
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
   /*---------------------------------------------*/
};

#endif // MENSAJEEMERGENTE_H
