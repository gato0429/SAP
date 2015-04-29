#ifndef FORMMAESTRO_H
#define FORMMAESTRO_H

#include <QWidget>
#include <QtWidgets>
#include "../Definiciones.h"
#include "../DefBD.h"
#include "../Extras/mensajeemergente.h"
#include "../Extras/visorimagenes.h"
class FormMaestro
{

public:

    FormMaestro();

protected:
     QWidget*          Form;
     QWidget*          Parent;
     FabricaBaseDatos* Bd;
     ESTADO Estado;
     void SetFondo();
     virtual bool Guardar()=0;
     virtual bool Modificar()=0;
     virtual bool Eliminar()=0;
     virtual bool ValidarCampos()=0;
     virtual void AsignarCampos()=0;
};

#endif // FORMMAESTRO_H
