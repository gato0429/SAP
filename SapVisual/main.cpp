
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamodelo.h"
#include "Repisas/repisamoneda.h"
#include "Repisas/repisamarca.h"
#include "Repisas/repisavehiculotipo.h"
#include "Repisas/repisaimagenes.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
   RepisaVehiculoTipo* w=new RepisaVehiculoTipo();
 // RepisaImagenes* w=new RepisaImagenes();
//    RepisaMoneda* w=new RepisaMoneda();
    w->show();



    return a.exec();
}
