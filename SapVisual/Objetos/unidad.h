#ifndef UNIDAD_H
#define UNIDAD_H
#include "objetomaestro.h"
class Unidad:public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString Simbolo;
    QString CodigoImagen;
    /*---------------------*/
    QString RutaImagen;
public:
    Unidad();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getSimbolo() const;
    void setSimbolo(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // UNIDAD_H
