#ifndef REPISAMARCA_H
#define REPISAMARCA_H

#include "repisa.h"
#include "../Fabricas/fabricamarca.h"
#include "../Formularios/formmarca.h"
class RepisaMarca:public Repisa
{
private:
    FabricaMarca*       FabricaLocal;
    FormMarca*          Dialogo;
public:
    RepisaMarca();

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

#endif // REPISAMARCA_H
