#ifndef DEFBD_H
#define DEFBD_H
#include "Fabricas/fabricabasedatos.h"

struct DefBD
{

static FabricaBaseDatos* IniciarBD()
    {
     FabricaBaseDatos* mybd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
          mybd->Fabrica->setDataBaseName("Core2015");
          mybd->Fabrica->setHostName("192.168.1.40");
          mybd->Fabrica->setPort(5432);
          mybd->Fabrica->setUserName("postgres");
          mybd->Fabrica->setPassword("root");

          return mybd;
    }


static void GuardarImagen(QString CarpetaImagen)
{

    /*carpeta/gato.png*/
    int Sep=CarpetaImagen.indexOf("/");
       QString CarpetaLocal=CarpetaImagen.mid(0,Sep);
       QString Ruta=CarpetaImagen.mid(Sep+1);

       /*Verifica si hay la carpeta, si no la crea*/
       QDir dir(RutaImagenes+CarpetaLocal);
       if (!dir.exists())
       {
           dir.mkpath(RutaImagenes+CarpetaLocal);
       }
       /*Verifica si existe el archivo o la imagen, si no existe la baja*/
       QFile file_for_reading(RutaImagenes+Ruta);
       if(!file_for_reading.exists())
       {
           qDebug()<<"Entre a la imagen";
           Imagen i;
           i.setCarpeta(CarpetaLocal);
           i.setNombre(Ruta);
           FabricaImagenes* img=IniciarBD()->Fabrica->CrearImagen();
           Imagen d=img->Buscar(i);
           qDebug()<<"Entre a la imagen pixel";
           QPixmap pixmap=Definiciones::toQpixmap(d.getPixel());
           qDebug()<<"Entre a la imagen png";

           pixmap.save(RutaImagenes+CarpetaLocal+"/"+Ruta,"png");

       }
}

static QIcon   toQicon(QString ruta)
{
        QPixmap p;
        if(!p.load(RutaImagenes+ruta))
        {
            GuardarImagen(ruta);
        }
       // p.loadFromData(ruta,"PNG");
        QIcon ic;
        ic.addPixmap(p);
        return ic;
}

static QPixmap  toQpixmap(QString ruta)
{
    QPixmap p;
    if(!p.load(RutaImagenes+ruta))
    {
        GuardarImagen(ruta);
    }
    return p;
}

};
#endif // DEFBD_H
