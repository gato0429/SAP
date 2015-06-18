#include "formmaestro.h"

FormMaestro::FormMaestro()
{
    Bd=DefBD::IniciarBD();

}

void FormMaestro::SetFondo()
{

    Form->setWindowFlags(Qt::Window
                         | Qt::FramelessWindowHint
                         | Qt::WindowMinimizeButtonHint
                         | Qt::WindowMaximizeButtonHint
                         | Qt::WindowCloseButtonHint);

        QPixmap bkgnd(FondoForm);
        bkgnd = bkgnd.scaled(Form->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        Form->setPalette(palette);



}
