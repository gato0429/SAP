#ifndef REPRESENTANTE_H
#define REPRESENTANTE_H
#include "objetomaestro.h"

class Representante :public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString Dni;
    QString Telefono;
    QString Correo;
    QString CodigoCliente;
    QString NombreCliente;
    QString CodigoImagen;
    QString RutaImagen;
public:
    Representante();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDni() const;
    void setDni(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getCorreo() const;
    void setCorreo(const QString &value);
    QString getCodigoCliente() const;
    void setCodigoCliente(const QString &value);
    QString getNombreCliente() const;
    void setNombreCliente(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // REPRESENTANTE_H
