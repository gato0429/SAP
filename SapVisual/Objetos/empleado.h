#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "objetomaestro.h"

class Empleado:public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString Direccion;
    QString Email;
    double   Descuento;
    QDate   FechaIngreso;
    QString Sexo;
    QString Dni;
    QString Telefono;
    QString CodigoInterno;

    /*Comodin Fecha*/
    QDate   FechaFin;

public:
    Empleado();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDireccion() const;
    void setDireccion(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    double getDescuento() const;
    void setDescuento(double value);
    QDate getFechaIngreso() const;
    void setFechaIngreso(const QDate &value);
    QString getDni() const;
    void setDni(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getSexo() const;
    void setSexo(const QString &value);
    QString getCodigoInterno() const;
    void setCodigoInterno(const QString &value);
    QDate getFechaFin() const;
    void setFechaFin(const QDate &value);
};

#endif // EMPLEADO_H
