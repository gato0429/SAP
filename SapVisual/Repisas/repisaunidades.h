#ifndef REPISAUNIDADES_H
#define REPISAUNIDADES_H

#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaunidades.h"
#include "../Formularios/formunidad.h"
#include "../Busqueda/busquedaunidad.h"

class RepisaUnidades:public Repisa
{

private:
    FabricaUnidades*         FabricaLocal;
    FormUnidad*       Dialogo;
    BusquedaMaestra*        Busqueda;

public:
    RepisaUnidades();

    // Repisa interface
public slots:

    void GrupoBotonesClick(QAbstractButton *buttonID);
    void NuevoClick();
    void BuscarClick();

public:
    void ObjetosIndependientes();
    void ActualizarConsulta();

    // Repisa interface
private slots:
    void RecibirTipoConsulta(int index, bool detalle, int registros);

public:
    void ObtenerConsulta();
};

#endif // REPISAUNIDADES_H
