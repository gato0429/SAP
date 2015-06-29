#ifndef BUSQUEDAMAESTRA_H
#define BUSQUEDAMAESTRA_H


#include <QWidget>
#include <QtGui>
#include <QCompleter>
#include <QComboBox>
#include <QLineEdit>
#include <QButtonGroup>
#include <QRadioButton>
#include <QAbstractButton>
#include <QDateEdit>
#include "../Definiciones.h"
#include "../Fabricas/fabricabasedatos.h"
#include "../Extras/visorconsultas.h"
#include "../DefBD.h"
#include <QSpinBox>
namespace Ui {
class BusquedaMaestra;
}

class BusquedaMaestra : public QWidget
{
    Q_OBJECT
public:
        QComboBox*      ComboCampos;
    explicit BusquedaMaestra(QWidget *parent = 0);

    virtual void CambiarCombo(int index);
    ~BusquedaMaestra();
signals:
   // void my_signal(QSqlQueryModel*,QList<bool>);
    void SignalRepisa(ObjetoMaestro*,int,QString);
    void SignalBusquedaTipo(int index,bool detalle, int registro); // Por que campo buscara en la repisa
    void Activar();

private:
    Ui::BusquedaMaestra *ui;
protected:
    FabricaBaseDatos* BD;
    VisorConsultas* VisorConsulta;
    QCompleter*     Completar;
    CONSULTA        FlagConsulta;

    QComboBox*      ComboTipos;
    QLineEdit*      LineNombre;
    QSpinBox*      LineFin;
    QButtonGroup*   GrupoBoton;
    QDateEdit*      FechaEdit;
    QDateEdit*      FechaEditFin;

    void VisibleLine();
    void VisibleFecha();
    void VisibleCombo();


private slots:



    void on_LineFin_2_valueChanged(int arg1);

    void on_checkBoxDetalle_stateChanged(int arg1);

    void on_ComboCamposLabel_currentIndexChanged(int index);

protected:
/*
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

#endif // BUSQUEDAMAESTRA_H
