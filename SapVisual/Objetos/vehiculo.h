#ifndef VEHICULO_H
#define VEHICULO_H
#include "objetomaestro.h"

class Vehiculo: public ObjetoMaestro
{
private:
    QString Codigo;
    QString Placa;
    QString PlacaAntigua;
    QString FechaIngreso;
public:
    Vehiculo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getPlaca() const;
    void setPlaca(const QString &value);
    QString getPlacaAntigua() const;
    void setPlacaAntigua(const QString &value);
    QString getFechaIngreso() const;
    void setFechaIngreso(const QString &value);
};

#endif // VEHICULO_H
