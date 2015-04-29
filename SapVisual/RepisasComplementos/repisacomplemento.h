#ifndef REPISACOMPLEMENTO_H
#define REPISACOMPLEMENTO_H

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

class RepisaComplemento:public QMainWindow
{
    Q_OBJECT

protected:
      static  QMainWindow* Formulario;
public:
      void DibujarRepisa();
      void Dibujar();
    RepisaComplemento();
};

#endif // REPISACOMPLEMENTO_H
