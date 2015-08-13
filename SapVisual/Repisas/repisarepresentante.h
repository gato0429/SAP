#ifndef REPISAREPRESENTANTE_H
#define REPISAREPRESENTANTE_H

#include "repisa.h"
#include "../Fabricas/fabricarepresentante.h"
//#include "../Formularios/formrepresentante.h"
class RepisaRepresentante:public Repisa
{
private:
    FabricaRepresentante*       FabricaLocal;
   // FormRepresentante*          Dialogo;

public:
    RepisaRepresentante();

    // Repisa interface
protected:
    void ConsultarBusqueda();

private slots:
    void GrupoBotonesClick(QAbstractButton *buttonID);

public slots:
    void NuevoClick();
    void BuscarClick();

public:
    void ObtenerConsulta();
    void ObjetosIndependientes();
    void ActualizarConsulta();
};

#endif // REPISAREPRESENTANTE_H
