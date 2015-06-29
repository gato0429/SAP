#ifndef REPISAMODELO_H
#define REPISAMODELO_H

#include "repisa.h"
#include "../Formularios/formmodelo.h"
#include "../Fabricas/fabricamodelo.h"
class RepisaModelo : public Repisa
{
private:
    FabricaModelo*       FabricaLocal;
    FormModelo*          Dialogo;
public:
    RepisaModelo();

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

#endif // REPISAMODELO_H
