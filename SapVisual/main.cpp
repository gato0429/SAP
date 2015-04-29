
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DefBD::IniciarBD();

    RepisaUnidades* w=new RepisaUnidades();
    w->show();



    return a.exec();
}
