#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
#include "objetomaestro.h"
using namespace std;

class Cliente:public ObjetoMaestro
{
protected:
    QString Codigo;
    QString Tipo;
    QString Nombre;
    QString Direccion;
    QString Pais;
    QString Contacto;
    QString Telefono;
    QString Email;
    QString Web;
    double  Descuento;
    QDate  Fecha;
    QString CodigoInterno;
    QString NumDoc;

public:
    Cliente();

    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getTipo() const;
    void setTipo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDireccion() const;
    void setDireccion(const QString &value);
    QString getPais() const;
    void setPais(const QString &value);
    QString getContacto() const;
    void setContacto(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getWeb() const;
    void setWeb(const QString &value);
    double getDescuento() const;
    void setDescuento(double value);
    QDate getFecha() const;
    void setFecha(const QDate &value);

    //Cliente & operator= (Cliente & valor);   //asignacion

    QString getCodigoInterno() const;
    void setCodigoInterno(const QString &value);
    QString getNumDoc() const;
    void setNumDoc(const QString &value);
};

#endif // CLIENTE_H
