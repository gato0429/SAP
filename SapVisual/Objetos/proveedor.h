#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include "objetomaestro.h"

class Proveedor : public ObjetoMaestro
{
private:
    QString Codigo;
    QString Nombre;
    QString CodigoImagen;
    QString RutaImagen;
    QString Tipo;
    QString Direccion;
    QString Telefono;
    QString Email;
    QString Web;
    // esta me ocasiono muchos problemas
    //QString Estado;
    QString FechaIngreso;
    QString Documento;
public:
    Proveedor();
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
    QString getDireccion() const;
    void setDireccion(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getWeb() const;
    void setWeb(const QString &value);
    QString getFechaIngreso() const;
    void setFechaIngreso(const QString &value);
    QString getDocumento() const;
    void setDocumento(const QString &value);
   // QString getEstado() const;
   // void setEstado(const QString &value);
};

#endif // PROVEEDOR_H
