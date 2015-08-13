#ifndef EMPLEADOCARGO_H
#define EMPLEADOCARGO_H
#include "objetomaestro.h"

class EmpleadoCargo :public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString CodigoImagen;
    QString RutaImagen;
public:
    EmpleadoCargo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // EMPLEADOCARGO_H
