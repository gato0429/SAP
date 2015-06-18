
#include "principal.h"
#include <QApplication>

#include "Repisas/repisamarca.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   //RepisaEmpleados* w=new RepisaEmpleados();
   RepisaMarca* w=new RepisaMarca();
   w->show();



    return a.exec();
}
