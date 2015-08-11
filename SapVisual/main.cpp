
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"
#include "Repisas/repisavehiculotipo.h"
#include "Repisas/repisaimagenes.h"
#include "Repisas/repisavehiculorubro.h"
#include "Repisas/repisaclientetipo.h"
#include "Repisas/repisaestado.h"
#include "Repisas/repisaoperaciones.h"
#include "Repisas/repisaempleadoarea.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
 //  RepisaVehiculoRubro* w=new RepisaVehiculoRubro();
 // RepisaImagenes* w=new RepisaImagenes();
//    RepisaMoneda* w=new RepisaMoneda();
    // RepisaClienteTipo* w=new RepisaClienteTipo();
       //RepisaEstado* w=new RepisaEstado();
   // RepisaOperaciones* w=new RepisaOperaciones();
    RepisaEmpleadoArea* w=new RepisaEmpleadoArea();
    w->show();



    return a.exec();
}
