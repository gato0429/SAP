#ifndef REPISAIMAGENES_H
#define REPISAIMAGENES_H
#include "repisa.h"
#include "../Fabricas/fabricaimagenes.h"
#include "../Formularios/formimagenes.h"
class FormImagenes;
class RepisaImagenes:public Repisa
{
private:
    FabricaImagenes*    FabricaLocal;
    FormImagenes*   Dialogo;

public:
    RepisaImagenes();
  //  void ActualizarMapa(ObjetoMaestro* Objeto);
    void ObjetosIndependientes();
    void ActualizarConsulta();
public slots:
    void NuevoClick();
    void BuscarClick();
    void GrupoBotonesClick(QAbstractButton *buttonID);
};

#endif // REPISAIMAGENES_H
