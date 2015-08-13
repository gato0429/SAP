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

    QString CodigoTipo;
    QString NombreTipo;
    QString RutaImagenTipo;

    QString CodigoImagen;
    QString RutaImagen;
    /*Comodin Fecha*/
    QDate   FechaFin;
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
    QString getCodigoTipo() const;
    void setCodigoTipo(const QString &value);
    QString getNombreTipo() const;
    void setNombreTipo(const QString &value);
    QString getRutaImagenTipo() const;
    void setRutaImagenTipo(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
    QDate getFechaFin() const;
    void setFechaFin(const QDate &value);
};

#endif // CLIENTE_H
