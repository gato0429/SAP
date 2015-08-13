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
    double  CantidadMin;
    QString    Unico;

    QString CodigoUnidad;
    QString NombreUnidad;
    QString SimboloUnidad;
    QString RutaImagenUnidad;

    QString CodigoMoneda;
    QString NombreMoneda;
    QString SimboloMoneda;
    QString RutaImagenMoneda;

    QString CodigoTipo;
    QString NombreTipo;
    QString RutaImagenTipo;

    QString CodigoModelo;
    QString NombreModelo;
    QString RutaImagenModelo;

    QString CodigoMarca;
    QString NombreMarca;
    QString RutaImagenMarca;

    double Precio;
    
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
    double getCantidadMin() const;
    void setCantidadMin(double value);
    QString getUnico() const;
    void setUnico(QString value);
    QString getCodigoModelo() const;
    void setCodigoModelo(const QString &value);
    QString getNombreModelo() const;
    void setNombreModelo(const QString &value);
    QString getRutaImagenModelo() const;
    void setRutaImagenModelo(const QString &value);
    QString getCodigoMarca() const;
    void setCodigoMarca(const QString &value);
    QString getNombreMarca() const;
    void setNombreMarca(const QString &value);
    QString getRutaImagenMarca() const;
    void setRutaImagenMarca(const QString &value);
    QString getCodigoMoneda() const;
    void setCodigoMoneda(const QString &value);
    QString getNombreMoneda() const;
    void setNombreMoneda(const QString &value);
    QString getSimboloMoneda() const;
    void setSimboloMoneda(const QString &value);
    QString getRutaImagenMoneda() const;
    void setRutaImagenMoneda(const QString &value);
    double getPrecio() const;
    void setPrecio(double value);
};

#endif // ARTICULO_H
