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
public:
     virtual void SetObjeto(ObjetoMaestro* ObjetoTipo)=0;
protected:
     QWidget*          Form;
     QWidget*          Parent;
     FabricaBaseDatos* Bd;
     ESTADO Estados;
     void SetFondo();
     virtual bool Guardar()=0;
     virtual bool Modificar()=0;
     virtual bool Eliminar()=0;
     virtual bool ValidarCampos()=0;
     virtual void AsignarCampos()=0;
     virtual void Habilitar()=0;
     virtual void Deshabilitar()=0;
     virtual void Limpiar()=0;
};

#endif // FORMMAESTRO_H
