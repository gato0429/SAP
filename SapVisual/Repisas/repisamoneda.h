#ifndef REPISAMONEDA_H
#define REPISAMONEDA_H

#include "repisa.h"
#include "../Fabricas/fabricamoneda.h"
#include "../Formularios/formmoneda.h"

class RepisaMoneda :public Repisa
{
private:
    FabricaMoneda*       FabricaLocal;
    FormMoneda*          Dialogo;

public:
    RepisaMoneda();

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

#endif // REPISAMONEDA_H
