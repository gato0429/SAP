#ifndef SUCURSALES_H
#define SUCURSALES_H
#include "objetomaestro.h"

class Sucursales:public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString Direccion;
    QString Telefono;
    QString Ruc;
    QString CodigoImagen;
    QString RutaImagen;
public:
    Sucursales();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDireccion() const;
    void setDireccion(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getRuc() const;
    void setRuc(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // SUCURSALES_H
