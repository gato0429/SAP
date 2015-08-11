#include "postgres.h"

Postgres::Postgres()
{
    mDriver = QSqlDatabase::addDatabase("QPSQL");
}

bool Postgres::Conectar()
{
    mDriver.setHostName(QString::fromStdString(HostName));
        mDriver.setDatabaseName(QString::fromStdString(DataBaseName));
        mDriver.setUserName(QString::fromStdString(UserName));
        mDriver.setPassword(QString::fromStdString(Password));
        mDriver.setPort(Port);

        mDriver.open();

        if(mDriver.isOpen())
        {
            Estado=true;
            return true;
        }
        Estado=false;

        return false;
}

bool Postgres::Desconectar()
{
    mDriver.close();
      if(!mDriver.isOpen())
      {
          Estado=false;
          return true;
      }
      Estado=true;
      return false;

}

bool Postgres::HayConexion()
{
    return Estado;
}

FabricaClientes *Postgres::CrearCliente()
{
    return new PgCliente();
}


FabricaArticuloTipos *Postgres::CrearArticuloTipo()
{
    return new PgArticuloTipo();
}


FabricaImagenes *Postgres::CrearImagen()
{
    return new PgImagen();
}

FabricaArticulos *Postgres::CrearArticulo()
{
    return new PgArticulo();
}

FabricaEmpleados *Postgres::CrearEmpleado()
{
    return new PgEmpleado();
}

FabricaUnidades *Postgres::CrearUnidad()
{
    return new PgUnidad();
}

FabricaArticuloAlias *Postgres::CrearArticuloAlias()
{
    return new PgArticuloAlias();
}


FabricaMarca *Postgres::CrearMarca()
{
    return new PgMarca();
}

FabricaModelo *Postgres::CrearModelo()
{
    return new PgModelo();
}
FabricaMoneda *Postgres::CrearMoneda()
{
    return new PgMoneda();
}
FabricaVehiculoTipo *Postgres::CrearVehiculoTipo()
{
    return new PgVehiculoTipo();
}

FabricaVehiculoRubro *Postgres::CrearVehiculoRubro()
{
    return new PgVehiculoRubro();
}

FabricaClienteTipo *Postgres::CrearClienteTipo()
{
    return new PgClienteTipo();
}

FabricaEstado *Postgres::CrearEstado()
{
    return new PgEstado();
}

FabricaVehiculo *Postgres::CrearVehiculo()
{
    return new PgVehiculo();
}

FabricaOperaciones *Postgres::CrearOperaciones()
{
    return new PgOperaciones();
}

FabricaEmpleadoArea *Postgres::CrearEmpleadoArea()
{
    return new PgEmpleadoArea();
}

FabricaEmpleadoCargo *Postgres::CrearEmpleadoCargo()
{
    return new PgEmpleadoCargo();
}
