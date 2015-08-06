#ifndef VEHICULORUBRO_H
#define VEHICULORUBRO_H
#include "objetomaestro.h"

class VehiculoRubro : public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString CodigoImagen;
    QString RutaImagen;
public:
    VehiculoRubro();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // VEHICULORUBRO_H
