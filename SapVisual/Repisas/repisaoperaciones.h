#ifndef REPISAOPERACIONES_H
#define REPISAOPERACIONES_H

#include "repisa.h"
#include "../Fabricas/fabricaoperaciones.h"
#include "../Formularios/formoperaciones.h"


class RepisaOperaciones:public Repisa
{
private:
    FabricaOperaciones*       FabricaLocal;
    FormOperaciones*          Dialogo;
public:
    RepisaOperaciones();

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

#endif // REPISAOPERACIONES_H
