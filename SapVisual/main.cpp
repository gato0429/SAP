
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"

#include "Repisas/repisaimagenes.h"

#include "Repisas/repisavehiculotipo.h"
#include "Repisas/repisaimagenes.h"
#include "Repisas/repisavehiculorubro.h"
#include "Repisas/repisaclientetipo.h"
#include "Repisas/repisaestado.h"
<<<<<<< HEAD
#include "Repisas/repisaarticulo.h"
#include "Repisas/repisacliente.h"
=======
#include "Repisas/repisaoperaciones.h"
#include "Repisas/repisaempleadoarea.h"
#include "Repisas/repisaempleadocargo.h"
>>>>>>> origin/panochon
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();

 //  RepisaMoneda* w=new RepisaMoneda();
  // RepisaImagenes* w=new RepisaImagenes();

 //  RepisaVehiculoRubro* w=new RepisaVehiculoRubro();
 //RepisaImagenes* w=new RepisaImagenes();
//    RepisaMoneda* w=new RepisaMoneda();
<<<<<<< HEAD
  //  RepisaClienteTipo* w=new RepisaClienteTipo();
    //   RepisaEstado* w=new RepisaEstado();
    RepisaCliente* w=new RepisaCliente();
=======
    // RepisaClienteTipo* w=new RepisaClienteTipo();
       //RepisaEstado* w=new RepisaEstado();
   // RepisaOperaciones* w=new RepisaOperaciones();
   // RepisaEmpleadoArea* w=new RepisaEmpleadoArea();
    RepisaEmpleadoCargo* w=new RepisaEmpleadoCargo();
>>>>>>> origin/panochon
    w->show();



    return a.exec();
}
