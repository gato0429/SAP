#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "objetomaestro.h"

class Operaciones:public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString Descripcion;
    QString CodigoImagen;
    QString RutaImagen;
public:
    Operaciones();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDescripcion() const;
    void setDescripcion(const QString &value);
    QString getCodigoImagen() const;
    void setCodigoImagen(const QString &value);
    QString getRutaImagen() const;
    void setRutaImagen(const QString &value);
};

#endif // OPERACIONES_H
