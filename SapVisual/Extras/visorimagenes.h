#ifndef VISORIMAGENES_H
#define VISORIMAGENES_H


#include "../Fabricas.h"
#include "../DefBD.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTreeWidget>
#include <QDialog>
#include <QMainWindow>
#include <QtGui>
namespace Ui {
class VisorImagenes;
}

class VisorImagenes : public QDialog
{
    Q_OBJECT

public:
    explicit VisorImagenes(QWidget *parent = 0);
    ~VisorImagenes();

signals:
    void my_signal(QString,QString);
private slots:


    void on_VisorArbol_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_ButonSeleccion_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    QString fileName;
    Ui::VisorImagenes *ui;
    QMap<QString,int> ListaCarpetas;
    QTreeWidgetItem*  CarpetaActual;

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

#endif // VISORIMAGENES_H
