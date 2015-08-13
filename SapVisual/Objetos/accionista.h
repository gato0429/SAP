#ifndef ACCIONISTA_H
#define ACCIONISTA_H
#include "objetomaestro.h"

class Accionista :public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString Dni;
    QString Telefono;
    QString Direccion;
    QString CodigoCliente;
    QString NombreCliente;
    QString RutaImagen;
public:
    Accionista();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDni() const;
    void setDni(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getDireccion() const;
    void setDireccion(const QString &value);
    QString getCodigoCliente() const;
    void setCodigoCliente(const QString &value);
    QString getNombreCliente() const;
    void setNombreCliente(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // ACCIONISTA_H
