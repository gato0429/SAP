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
    explicit BusquedaMaestra(QWidget *parent = 0);
    virtual void ObtenerConsulta()=0;
    virtual void IniciarCampos()=0;
    virtual void CambiarCombo(int index);
    ~BusquedaMaestra();
signals:
    void my_signal(QSqlQueryModel*,QList<bool>);
    void SignalRepisa(ObjetoMaestro*,int,QString);
    void Activar();

private:
    Ui::BusquedaMaestra *ui;
protected:
    FabricaBaseDatos* BD;
    VisorConsultas* VisorConsulta;
    QCompleter*     Completar;
    CONSULTA        FlagConsulta;
    QComboBox*      ComboCampos;
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
    void on_BotonConsultar_2_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_LineNombre_2_returnPressed();



    void on_ComboCampos_currentIndexChanged(int index);

    void on_ComboTipo_currentIndexChanged(int index);

    void on_EditFecha_dateChanged(const QDate &date);

    void on_EditFechaFin_dateChanged(const QDate &date);

    void on_LineFin_2_valueChanged(int arg1);

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

#endif // BUSQUEDAMAESTRA_H
