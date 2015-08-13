#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T12:47:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SapVisual
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    principal.cpp \
    RepisasComplementos/repisacomplemento.cpp \
    Repisas/repisa.cpp \
    Repisas/repisaarticulo.cpp \
    Repisas/repisaarticuloalias.cpp \
    Repisas/repisaarticulotipo.cpp \
    Repisas/repisaempleados.cpp \
    Repisas/repisaimagenes.cpp \
    Repisas/repisaunidades.cpp \
    Postgres/pgarticulo.cpp \
    Postgres/pgarticuloalias.cpp \
    Postgres/pgarticulotipo.cpp \
    Postgres/pgcliente.cpp \
    Postgres/pgempleado.cpp \
    Postgres/pgimagen.cpp \
    Postgres/pgunidad.cpp \
    Postgres/postgres.cpp \
    Objetos/articulo.cpp \
    Objetos/articuloalias.cpp \
    Objetos/articulotipo.cpp \
    Objetos/basedatos.cpp \
    Objetos/cliente.cpp \
    Objetos/empleado.cpp \
    Objetos/imagen.cpp \
    Objetos/objetomaestro.cpp \
    Objetos/unidad.cpp \
    Formularios/formarticulo.cpp \
    Formularios/formarticuloalias.cpp \
    Formularios/formarticulotipo.cpp \
    Formularios/formempleado.cpp \
    Formularios/formimagenes.cpp \
    Formularios/formmaestro.cpp \
    Formularios/formunidad.cpp \
    Fabricas/fabricaarticuloalias.cpp \
    Fabricas/fabricaarticulos.cpp \
    Fabricas/fabricaarticulotipos.cpp \
    Fabricas/fabricabasedatos.cpp \
    Fabricas/fabricaclientes.cpp \
    Fabricas/fabricaempleados.cpp \
    Fabricas/fabricaimagenes.cpp \
    Fabricas/fabricaunidades.cpp \
    Extras/mensajeemergente.cpp \
    Extras/visorconsultas.cpp \
    Extras/visorimagenes.cpp \
    Busqueda/busquedaarticulo.cpp \
    Busqueda/busquedaarticulotipo.cpp \
    Busqueda/busquedaempleado.cpp \
    Busqueda/busquedamaestra.cpp \
    Busqueda/busquedaunidad.cpp \
    Objetos/marca.cpp \
    Fabricas/fabricamarca.cpp \
    Postgres/pgmarca.cpp \
    Objetos/moneda.cpp \
    Formularios/formmarca.cpp \
    Repisas/repisamarca.cpp \
    Objetos/modelo.cpp \
    Fabricas/fabricamodelo.cpp \
    Postgres/pgmodelo.cpp \
    Repisas/repisamodelo.cpp \
    Formularios/formmodelo.cpp \
    Fabricas/fabricamoneda.cpp \
    Postgres/pgmoneda.cpp \
    Formularios/formmoneda.cpp \
    Repisas/repisamoneda.cpp \
    Fabricas/fabricavehiculotipo.cpp \
    Postgres/pgvehiculotipo.cpp \
    Objetos/vehiculotipo.cpp \
    Formularios/formvehiculotipo.cpp \
    Repisas/repisavehiculotipo.cpp \
    Objetos/vehiculorubro.cpp \
    Fabricas/fabricavehiculorubro.cpp \
    Postgres/pgvehiculorubro.cpp \
    Formularios/formvehiculorubro.cpp \
    Repisas/repisavehiculorubro.cpp \
    Objetos/clientetipo.cpp \
    Fabricas/fabricaclientetipo.cpp \
    Postgres/pgclientetipo.cpp \
    Formularios/formclientetipo.cpp \
    Repisas/repisaclientetipo.cpp \
    Objetos/estado.cpp \
    Fabricas/fabricaestado.cpp \
    Postgres/pgestado.cpp \
    Formularios/formestado.cpp \
    Repisas/repisaestado.cpp \

    Repisas/repisacliente.cpp \
    Formularios/formcliente.cpp

    Objetos/vehiculo.cpp \
    Fabricas/fabricavehiculo.cpp \
    Postgres/pgvehiculo.cpp \
    Repisas/repisavehiculo.cpp \
    Objetos/operaciones.cpp \
    Fabricas/fabricaoperaciones.cpp \
    Postgres/pgoperaciones.cpp \
    Formularios/formoperaciones.cpp \
    Repisas/repisaoperaciones.cpp \
    Objetos/empleadoarea.cpp \
    Fabricas/fabricaempleadoarea.cpp \
    Postgres/pgempleadoarea.cpp \
    Formularios/formempleadoarea.cpp \
    Repisas/repisaempleadoarea.cpp \
    Objetos/empleadocargo.cpp \
    Fabricas/fabricaempleadocargo.cpp \
    Postgres/pgempleadocargo.cpp \
    Formularios/formempleadocargo.cpp \
    Repisas/repisaempleadocargo.cpp \
    Objetos/proveedor.cpp \
    Fabricas/fabricaproveedor.cpp \
    Postgres/pgproveedor.cpp \
    Repisas/repisaproveedor.cpp \
    Objetos/representante.cpp \
    Fabricas/fabricarepresentante.cpp \
    Postgres/pgrepresentante.cpp \
    Repisas/repisarepresentante.cpp \
    Objetos/accionista.cpp \
    Fabricas/fabricaaccionista.cpp \
    Postgres/pgaccionista.cpp \
    Repisas/repisaaccionista.cpp \
    Objetos/sucursales.cpp \
    Fabricas/fabricasucursales.cpp \
    Postgres/pgsucursales.cpp \
    Repisas/repisasucursales.cpp


HEADERS  += mainwindow.h \
    DefBD.h \
    Definiciones.h \
    Fabricas.h \
    Objetos.h \
    principal.h \
    RepisasComplementos/repisacomplemento.h \
    Repisas/repisa.h \
    Repisas/repisaarticulo.h \
    Repisas/repisaarticuloalias.h \
    Repisas/repisaarticulotipo.h \
    Repisas/repisaempleados.h \
    Repisas/repisaimagenes.h \
    Repisas/repisaunidades.h \
    Postgres/pgarticulo.h \
    Postgres/pgarticuloalias.h \
    Postgres/pgarticulotipo.h \
    Postgres/pgcliente.h \
    Postgres/pgempleado.h \
    Postgres/pgimagen.h \
    Postgres/pgunidad.h \
    Postgres/postgres.h \
    Objetos/articulo.h \
    Objetos/articuloalias.h \
    Objetos/articulotipo.h \
    Objetos/basedatos.h \
    Objetos/cliente.h \
    Objetos/empleado.h \
    Objetos/imagen.h \
    Objetos/objetomaestro.h \
    Objetos/unidad.h \
    Formularios/formarticulo.h \
    Formularios/formarticuloalias.h \
    Formularios/formarticulotipo.h \
    Formularios/formempleado.h \
    Formularios/formimagenes.h \
    Formularios/formmaestro.h \
    Formularios/formunidad.h \
    Fabricas/fabricaarticuloalias.h \
    Fabricas/fabricaarticulos.h \
    Fabricas/fabricaarticulotipos.h \
    Fabricas/fabricabasedatos.h \
    Fabricas/fabricaclientes.h \
    Fabricas/fabricaempleados.h \
    Fabricas/fabricaimagenes.h \
    Fabricas/fabricamaestra.h \
    Fabricas/fabricaunidades.h \
    Extras/mensajeemergente.h \
    Extras/visorconsultas.h \
    Extras/visorimagenes.h \
    Busqueda/busquedaarticulo.h \
    Busqueda/busquedaarticulotipo.h \
    Busqueda/busquedaempleado.h \
    Busqueda/busquedamaestra.h \
    Busqueda/busquedaunidad.h \
    Objetos/marca.h \
    Fabricas/fabricamarca.h \
    Postgres/pgmarca.h \
    Objetos/moneda.h \
    Formularios/formmarca.h \
    Repisas/repisamarca.h \
    Objetos/modelo.h \
    Fabricas/fabricamodelo.h \
    Postgres/pgmodelo.h \
    Repisas/repisamodelo.h \
    Formularios/formmodelo.h \
    Fabricas/fabricamoneda.h \
    Postgres/pgmoneda.h \
    Formularios/formmoneda.h \
    Repisas/repisamoneda.h \
    Fabricas/fabricavehiculotipo.h \
    Postgres/pgvehiculotipo.h \
    Objetos/vehiculotipo.h \
    Formularios/formvehiculotipo.h \
    Repisas/repisavehiculotipo.h \
    Objetos/vehiculorubro.h \
    Fabricas/fabricavehiculorubro.h \
    Postgres/pgvehiculorubro.h \
    Formularios/formvehiculorubro.h \
    Repisas/repisavehiculorubro.h \
    Objetos/clientetipo.h \
    Fabricas/fabricaclientetipo.h \
    Postgres/pgclientetipo.h \
    Formularios/formclientetipo.h \
    Repisas/repisaclientetipo.h \
    Objetos/estado.h \
    Fabricas/fabricaestado.h \
    Postgres/pgestado.h \
    Formularios/formestado.h \
    Repisas/repisaestado.h \

    Repisas/repisacliente.h \
    Formularios/formcliente.h

    Objetos/vehiculo.h \
    Fabricas/fabricavehiculo.h \
    Postgres/pgvehiculo.h \
    Repisas/repisavehiculo.h \
    Objetos/operaciones.h \
    Fabricas/fabricaoperaciones.h \
    Postgres/pgoperaciones.h \
    Formularios/formoperaciones.h \
    Repisas/repisaoperaciones.h \
    Objetos/empleadoarea.h \
    Fabricas/fabricaempleadoarea.h \
    Postgres/pgempleadoarea.h \
    Formularios/formempleadoarea.h \
    Repisas/repisaempleadoarea.h \
    Objetos/empleadocargo.h \
    Fabricas/fabricaempleadocargo.h \
    Postgres/pgempleadocargo.h \
    Formularios/formempleadocargo.h \
    Repisas/repisaempleadocargo.h \
    Objetos/proveedor.h \
    Fabricas/fabricaproveedor.h \
    Postgres/pgproveedor.h \
    Repisas/repisaproveedor.h \
    Objetos/representante.h \
    Fabricas/fabricarepresentante.h \
    Postgres/pgrepresentante.h \
    Repisas/repisarepresentante.h \
    Objetos/accionista.h \
    Fabricas/fabricaaccionista.h \
    Postgres/pgaccionista.h \
    Repisas/repisaaccionista.h \
    Objetos/sucursales.h \
    Fabricas/fabricasucursales.h \
    Postgres/pgsucursales.h \
    Repisas/repisasucursales.h


FORMS    += mainwindow.ui \
    principal.ui \
    Formularios/formarticulo.ui \
    Formularios/formarticuloalias.ui \
    Formularios/formarticulotipo.ui \
    Formularios/formempleado.ui \
    Formularios/formimagenes.ui \
    Formularios/formunidad.ui \
    Extras/mensajeemergente.ui \
    Extras/visorconsultas.ui \
    Extras/visorimagenes.ui \
    Busqueda/busquedamaestra.ui \
    Formularios/formmarca.ui \
    Formularios/formmodelo.ui \
    Formularios/formmoneda.ui \
    Formularios/formvehiculotipo.ui \
    Formularios/formvehiculorubro.ui \
    Formularios/formclientetipo.ui \
    Formularios/formestado.ui \

    Formularios/formcliente.ui

    Formularios/formoperaciones.ui \
    Formularios/formempleadoarea.ui \
    Formularios/formempleadocargo.ui

    Formularios/formoperaciones.ui \
    Formularios/formempleadoarea.ui \
    Formularios/formempleadocargo.ui

    Formularios/formoperaciones.ui \
    Formularios/formempleadoarea.ui \
    Formularios/formempleadocargo.ui

    Formularios/formoperaciones.ui \
    Formularios/formempleadoarea.ui \
    Formularios/formempleadocargo.ui

    Formularios/formoperaciones.ui \
    Formularios/formempleadoarea.ui \
    Formularios/formempleadocargo.ui

    Formularios/formoperaciones.ui \
    Formularios/formempleadoarea.ui \
    Formularios/formempleadocargo.ui


RESOURCES += \
    Recursos.qrc
