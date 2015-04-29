#include "pgimagen.h"

PgImagen::PgImagen()
{
}



bool PgImagen::Borrar(Imagen valor)
{

    QSqlQuery query;

    return  query.exec("DELETE FROM imagenes WHERE codigo='"+valor.getCodigo()+"'");
}

bool PgImagen::Insertar(Imagen valor)
{

    QSqlQuery query;
      query.prepare("INSERT INTO imagenes("
                        "carpeta, nombre,pixel)"
                "VALUES (?, ?, ?);");

     query.addBindValue(valor.getCarpeta());
     query.addBindValue(valor.getNombre());
     query.addBindValue(valor.getPixel());

      return query.exec();
}

bool PgImagen::Actualizar(Imagen Antiguo, Imagen Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE imagenes SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getCarpeta().isNull())
    {
        consulta=consulta+", carpeta='"+Nuevo.getCarpeta()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getPixel().isNull())
    {
        consulta=consulta+", pixel='"+Nuevo.getPixel()+"'";
    }
    /*-------------------------------------*/
    /*contar la cantidad de caracteres desde el inicio hasta set*/
    consulta.replace(c,2," ");
    consulta=consulta+" WHERE ";

    /*-------------------------------------*/


    if(!Antiguo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Antiguo.getCodigo()+"') AND ";
    }
    if(!Antiguo.getCarpeta().isNull())
    {
        consulta=consulta+", carpeta='"+Antiguo.getCarpeta()+"') AND ";
    }
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Antiguo.getNombre()+"') AND ";
    }
    if(!Antiguo.getPixel().isNull())
    {
        consulta=consulta+", pixel='"+Antiguo.getPixel()+"') AND ";
    }


    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;
    return query.exec(consulta);
}

Imagen PgImagen::Buscar(Imagen valor)
{
    QString consulta;

    consulta="SELECT codigo, carpeta, nombre, pixel"
            " FROM imagenes WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getCarpeta().isNull())
    {
        consulta=consulta+" carpeta like '%"+valor.getCarpeta()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getPixel().isNull())
    {
        consulta=consulta+" pixel like '%"+valor.getPixel()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5,";");

    qDebug()<<consulta;

    Imagen resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setCarpeta(query.value(1).toString());
          resp.setNombre(query.value(2).toString());
          resp.setPixel(query.value(3).toByteArray());
          flag=false;
      }


    return resp;
}

QMap<QString, ObjetoMaestro*> *PgImagen::BuscarMapa(Imagen valor, CONSULTA tipo)
{


    QString consulta;

    if(tipo==TODO)
    {
        consulta="SELECT codigo, carpeta, nombre, pixel"
                " FROM imagenes ";
    }
   else
    {
    consulta="SELECT codigo, carpeta, nombre, pixel"
            " FROM imagenes WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getCarpeta().isNull())
    {
        consulta=consulta+" carpeta like '%"+valor.getCarpeta()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getPixel().isNull())
    {
        consulta=consulta+" pixel like '%"+valor.getPixel()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5,";");
    }
    qDebug()<<consulta;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();



    QSqlQuery query(consulta);

      while (query.next() ) {
           Imagen* resp=new Imagen();
          resp->setCodigo(query.value(0).toString());
          resp->setCarpeta(query.value(1).toString());
          resp->setNombre(query.value(2).toString());
          resp->setPixel(query.value(3).toByteArray());
          salida->insert(resp->getCodigo(), (ObjetoMaestro*)resp);
      }


    return salida;
}

int PgImagen::Contar()
{

return 0;
}
