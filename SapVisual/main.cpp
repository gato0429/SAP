
#include "principal.h"
#include <QApplication>
#include "Fabricas.h"
#include "Objetos.h"
#include "Repisas/repisaarticulotipo.h"
#include "Formularios/formarticulotipo.h"
#include "Repisas/repisaarticulo.h"
#include "Extras/visorimagenes.h"
#include "Repisas/repisaempleados.h"
#include "Repisas/repisaunidades.h"
#include "Repisas/repisaarticuloalias.h"
#include "Repisas/repisaimagenes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

   // RepisaImagenes* w=new RepisaImagenes();
   //RepisaArticulo* w=new RepisaArticulo();
   RepisaEmpleados* w=new RepisaEmpleados();

   w->show();



    return a.exec();
}
