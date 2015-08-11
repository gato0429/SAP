#ifndef BASEDATOS_H
#define BASEDATOS_H
#include <QtSql/QSql>
#include <string>

#include "../Fabricas/fabricaclientes.h"
#include "../Fabricas/fabricaarticulotipos.h"
#include "../Fabricas/fabricaimagenes.h"
#include "../Fabricas/fabricaarticulos.h"
#include "../Fabricas/fabricaempleados.h"
#include "../Fabricas/fabricaunidades.h"
#include "../Fabricas/fabricaarticuloalias.h"
#include "../Fabricas/fabricamarca.h"
#include "../Fabricas/fabricamodelo.h"
#include "../Fabricas/fabricamoneda.h"
#include "../Fabricas/fabricavehiculotipo.h"
#include "../Fabricas/fabricavehiculorubro.h"
#include "../Fabricas/fabricaclientetipo.h"
#include "../Fabricas/fabricaestado.h"
#include "../Fabricas/fabricavehiculo.h"
#include "../Fabricas/fabricaoperaciones.h"
#include "../Fabricas/fabricaempleadoarea.h"
#include "../Fabricas/fabricaempleadocargo.h"

using namespace std;

class BaseDatos
{
protected:
    string HostName;
    string DataBaseName;
    string UserName;
    string Password;
    int    Port;
    bool   Estado;
public:
    BaseDatos();

    /*Cada tipo de BD debe redefinir estas funciones a su forma*/
    virtual bool        Conectar()=0;
    virtual bool        Desconectar()=0;
    virtual bool        HayConexion()=0;
    /*--------------------------------*/

    /*Esto es para la BD*/

    string getHostName() const;
    void setHostName(const string &value);
    string getDataBaseName() const;
    void setDataBaseName(const string &value);
    string getUserName() const;
    void setUserName(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
    int getPort() const;
    void setPort(int value);
    bool getEstado() const;
    void setEstado(bool value);

    /*---------------------------------*/
    /*Aqui se crean todos los objetos a manejar como metodos virtuales para q en todas las
      fabricas aparescan*/

    virtual FabricaClientes       *CrearCliente()=0;
    virtual FabricaArticuloTipos  *CrearArticuloTipo()=0;
    virtual FabricaImagenes       *CrearImagen()=0;
    virtual FabricaArticulos      *CrearArticulo()=0;
    virtual FabricaEmpleados      *CrearEmpleado()=0;
    virtual FabricaUnidades       *CrearUnidad()=0;
    virtual FabricaArticuloAlias  *CrearArticuloAlias()=0;
    virtual FabricaMarca          *CrearMarca()=0;
    virtual FabricaModelo         *CrearModelo()=0;
    virtual FabricaMoneda         *CrearMoneda()=0;
    virtual FabricaVehiculoTipo   *CrearVehiculoTipo()=0;
    virtual FabricaVehiculoRubro  *CrearVehiculoRubro()=0;
    virtual FabricaClienteTipo    *CrearClienteTipo()=0;
    virtual FabricaEstado         *CrearEstado()=0;
    virtual FabricaVehiculo       *CrearVehiculo()=0;
    virtual FabricaOperaciones    *CrearOperaciones()=0;
    virtual FabricaEmpleadoArea   *CrearEmpleadoArea()=0;
    virtual FabricaEmpleadoCargo  *CrearEmpleadoCargo()=0;
};

#endif // BASEDATOS_H
