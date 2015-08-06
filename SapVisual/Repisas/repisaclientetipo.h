#ifndef REPISACLIENTETIPO_H
#define REPISACLIENTETIPO_H

#include "repisa.h"
#include "../Fabricas/fabricaclientetipo.h"
#include "../Formularios/formclientetipo.h"
class RepisaClienteTipo:public Repisa
{
private:
    FabricaClienteTipo*       FabricaLocal;
    FormClienteTipo*          Dialogo;
public:
    RepisaClienteTipo();

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

#endif // REPISACLIENTETIPO_H
