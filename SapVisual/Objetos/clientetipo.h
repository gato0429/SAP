#ifndef CLIENTETIPO_H
#define CLIENTETIPO_H
#include "objetomaestro.h"

class ClienteTipo: public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString CodigoImagen;
    QString RutaImagen;
    QString Tipo;

public:
    ClienteTipo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
    QString getTipo() const;
    void setTipo(const QString &value);
};

#endif // CLIENTETIPO_H
