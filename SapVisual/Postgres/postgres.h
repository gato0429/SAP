#ifndef POSTGRES_H
#define POSTGRES_H
#include "../Objetos/basedatos.h"
#include <QSqlDatabase>
#include "pgcliente.h"
#include "pgarticulotipo.h"
#include "pgimagen.h"
#include "pgarticulo.h"
#include "pgempleado.h"
#include "pgunidad.h"
#include "pgarticuloalias.h"
#include "pgmarca.h"
#include "pgmodelo.h"
#include "pgmoneda.h"
#include "pgvehiculotipo.h"
#include "pgvehiculorubro.h"
#include "pgclientetipo.h"
#include "pgestado.h"
#include "pgvehiculo.h"
#include "pgoperaciones.h"
#include "pgempleadoarea.h"
#include "pgempleadocargo.h"
#include "pgproveedor.h"
#include "pgrepresentante.h"
#include "pgaccionista.h"
#include "pgsucursales.h"
class Postgres:public BaseDatos
{
private:
    QSqlDatabase   mDriver;

public:

    Postgres();

    // BaseDatos interface
    bool Conectar();
    bool Desconectar();
    bool HayConexion();

    // BaseDatos interface
public:
    FabricaClientes      *CrearCliente();
    FabricaArticuloTipos *CrearArticuloTipo();   
    FabricaImagenes      *CrearImagen();
    FabricaArticulos     *CrearArticulo();
    FabricaEmpleados     *CrearEmpleado();
    FabricaUnidades      *CrearUnidad();
    FabricaArticuloAlias *CrearArticuloAlias();
    FabricaMarca         *CrearMarca();
    FabricaModelo        *CrearModelo();
    FabricaMoneda        *CrearMoneda();
    FabricaVehiculoTipo  *CrearVehiculoTipo();
    FabricaVehiculoRubro *CrearVehiculoRubro();
    FabricaClienteTipo   *CrearClienteTipo();
    FabricaEstado        *CrearEstado();
    FabricaVehiculo      *CrearVehiculo();
    FabricaOperaciones   *CrearOperaciones();
    FabricaEmpleadoArea  *CrearEmpleadoArea();
    FabricaEmpleadoCargo *CrearEmpleadoCargo();
    FabricaProveedor     *CrearProveedor();
    FabricaRepresentante *CrearRepresentante();
    FabricaAccionista    *CrearAccionista();
    FabricaSucursales    *CrearSucursales();

};


#endif // POSTGRES_H
