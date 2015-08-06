#ifndef VEHICULOTIPO_H
#define VEHICULOTIPO_H
#include "objetomaestro.h"

class VehiculoTipo : public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString CodigoImagen;
    QString RutaImagen;
public:
    VehiculoTipo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // VEHICULOTIPO_H
