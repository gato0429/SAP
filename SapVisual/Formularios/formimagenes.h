#ifndef FORMIMAGENES_H
#define FORMIMAGENES_H

#include <QWidget>
#include "../Repisas/repisaimagenes.h"
namespace Ui {
class FormImagenes;
}
class RepisaImagenes;
class FormImagenes : public QWidget
{
    Q_OBJECT

public:
    explicit FormImagenes(QWidget *parent = 0);
    ~FormImagenes();

private:
    Ui::FormImagenes *ui;
    QString fileName;
    QMap<QString,int> ListaCarpetas;
    QTreeWidgetItem*  CarpetaActual;
    ESTADO Estado;
    RepisaImagenes* mRepisa;
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

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_BotonImagen_clicked();

    void on_BotonAgregarImagen_clicked();

    void on_BotonCarpetaBorrar_4_clicked();

    void on_BotonCarpetaAgregar_4_clicked();

    void on_VisorArbol_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    QPoint oldPos;
};

#endif // FORMIMAGENES_H
