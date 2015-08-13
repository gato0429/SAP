#ifndef REPISACLIENTE_H
#define REPISACLIENTE_H

#include "repisa.h"

#include "../Fabricas/fabricaclientes.h"
#include "../Formularios/formcliente.h"
class RepisaCliente:public Repisa
{
private:
    FabricaClientes*     FabricaLocal;
    FormCliente*         Dialogo;
public:
    RepisaCliente();

    QMap<QString, ObjetoMaestro*>* MapaCombo;

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

#endif // REPISACLIENTE_H
