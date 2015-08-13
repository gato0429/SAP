#ifndef REPISAACCIONISTA_H
#define REPISAACCIONISTA_H

#include "repisa.h"
#include "../Fabricas/fabricaaccionista.h"
//#include "../Formularios/formaccionista.h"
class RepisaAccionista : public Repisa
{
private:
    FabricaAccionista*       FabricaLocal;
   // FormAccionista*          Dialogo;
public:
    RepisaAccionista();

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

#endif // REPISAACCIONISTA_H
