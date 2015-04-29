#include "basedatos.h"


string BaseDatos::getHostName() const
{
    return HostName;
}

void BaseDatos::setHostName(const string &value)
{
    HostName = value;
}

string BaseDatos::getDataBaseName() const
{
    return DataBaseName;
}

void BaseDatos::setDataBaseName(const string &value)
{
    DataBaseName = value;
}

string BaseDatos::getUserName() const
{
    return UserName;
}

void BaseDatos::setUserName(const string &value)
{
    UserName = value;
}

string BaseDatos::getPassword() const
{
    return Password;
}

void BaseDatos::setPassword(const string &value)
{
    Password = value;
}

int BaseDatos::getPort() const
{
    return Port;
}

void BaseDatos::setPort(int value)
{
    Port = value;
}

bool BaseDatos::getEstado() const
{
    return Estado;
}

void BaseDatos::setEstado(bool value)
{
    Estado = value;
}
BaseDatos::BaseDatos()
{
}
