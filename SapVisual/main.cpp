
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Repisas/repisaimagenes.h"
=======
=======
>>>>>>> origin/panochon
#include "Repisas/repisavehiculotipo.h"
#include "Repisas/repisaimagenes.h"
#include "Repisas/repisavehiculorubro.h"
#include "Repisas/repisaclientetipo.h"
#include "Repisas/repisaestado.h"
<<<<<<< HEAD
>>>>>>> origin/panochon
=======
>>>>>>> origin/panochon
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
<<<<<<< HEAD
<<<<<<< HEAD
   RepisaMoneda* w=new RepisaMoneda();
  // RepisaImagenes* w=new RepisaImagenes();
=======
=======
>>>>>>> origin/panochon
 //  RepisaVehiculoRubro* w=new RepisaVehiculoRubro();
 // RepisaImagenes* w=new RepisaImagenes();
//    RepisaMoneda* w=new RepisaMoneda();
    // RepisaClienteTipo* w=new RepisaClienteTipo();
       RepisaEstado* w=new RepisaEstado();
<<<<<<< HEAD
>>>>>>> origin/panochon
=======
>>>>>>> origin/panochon
    w->show();



    return a.exec();
}
