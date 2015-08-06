
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"
#include "Repisas/repisaimagenes.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
   RepisaMoneda* w=new RepisaMoneda();
  // RepisaImagenes* w=new RepisaImagenes();
    w->show();



    return a.exec();
}
