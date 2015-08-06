
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"
<<<<<<< HEAD
#include "Repisas/repisaimagenes.h"
=======
#include "Repisas/repisavehiculotipo.h"
#include "Repisas/repisaimagenes.h"
#include "Repisas/repisavehiculorubro.h"
#include "Repisas/repisaclientetipo.h"
#include "Repisas/repisaestado.h"
>>>>>>> origin/panochon
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
<<<<<<< HEAD
   RepisaMoneda* w=new RepisaMoneda();
  // RepisaImagenes* w=new RepisaImagenes();
=======
 //  RepisaVehiculoRubro* w=new RepisaVehiculoRubro();
 // RepisaImagenes* w=new RepisaImagenes();
//    RepisaMoneda* w=new RepisaMoneda();
    // RepisaClienteTipo* w=new RepisaClienteTipo();
       RepisaEstado* w=new RepisaEstado();
>>>>>>> origin/panochon
    w->show();



    return a.exec();
}
