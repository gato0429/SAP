#ifndef ARTICULO_H
#define ARTICULO_H
#include "objetomaestro.h"
class Articulo:public ObjetoMaestro
{
private:
    QString Codigo;
    QString CodigoInterno;
    QString CodigoExterno;

    QString Nombre;
    QString CodigoImagen;
    QString RutaImagen;
    QString Vigencia;

    QString CodigoUnidad;
    QString NombreUnidad;
    QString SimboloUnidad;
    QString RutaImagenUnidad;

    QString CodigoTipo;
    QString NombreTipo;
    QString RutaImagenTipo;

public:
    Articulo();

    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
    QString getCodigoUnidad() const;
    void setCodigoUnidad(const QString &value);

    QString getRutaImagenUnidad() const;
    void setRutaImagenUnidad(const QString &value);
    QString getVigencia() const;
    void setVigencia(const QString &value);
    QString getCodigoTipo() const;
    void setCodigoTipo(const QString &value);
    QString getNombreTipo() const;
    void setNombreTipo(const QString &value);
    QString getRutaImagenTipo() const;
    void setRutaImagenTipo(const QString &value);
    QString getNombreUnidad() const;
    void setNombreUnidad(const QString &value);
    QString getSimboloUnidad() const;
    void setSimboloUnidad(const QString &value);
    QString getCodigoInterno() const;
    void setCodigoInterno(const QString &value);
    QString getCodigoExterno() const;
    void setCodigoExterno(const QString &value);
};

#endif // ARTICULO_H
