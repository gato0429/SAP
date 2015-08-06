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
        consulta=consulta+" ,codigo=:cod";
    }
    if(!Nuevo.getCarpeta().isNull())
    {
        consulta=consulta+" ,carpeta=:car";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+" ,nombre=:nom";
    }
    if(!Nuevo.getPixel().isNull())
    {
        consulta=consulta+" ,pixel=:pix";
    }

    /*-------------------------------------*/
    /*contar la cantidad de caracteres desde el inicio hasta set*/
    consulta.replace(c,2," ");
    consulta=consulta+" WHERE ";

    /*-------------------------------------*/


    if(!Antiguo.getCodigo().isNull())
    {
        consulta=consulta+"(codigo='"+Antiguo.getCodigo()+"') AND ";
    }
    if(!Antiguo.getCarpeta().isNull())
    {
        consulta=consulta+"(carpeta='"+Antiguo.getCarpeta()+"') AND ";
    }
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+"( nombre='"+Antiguo.getNombre()+"') AND ";
    }
    if(!Antiguo.getPixel().isNull())
    {
        consulta=consulta+"(pixel='"+Antiguo.getPixel()+"') AND ";
    }


    consulta.replace(consulta.size()-5,5," ");

    qDebug()<<consulta;
    query.prepare(consulta);
    query.bindValue(":cod",Nuevo.getCodigo());
    query.bindValue(":car",Nuevo.getCarpeta());
    query.bindValue(":nom",Nuevo.getNombre());
    query.bindValue(":pix",Nuevo.getPixel());


    bool flag=query.exec();

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return flag;
}

Imagen PgImagen::Buscar(Imagen valor)
{
    QString consulta;

    consulta="SELECT codigo, carpeta, nombre, pixel"
            " FROM imagenes WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getCarpeta().isNull())
    {
        consulta=consulta+" carpeta ilike '%"+valor.getCarpeta()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getPixel().isNull())
    {
        consulta=consulta+" pixel ilike '%"+valor.getPixel()+"%' AND ";
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

QMap<QString, ObjetoMaestro*> *PgImagen::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Imagen* val=(Imagen*)(valor);
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



    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getCarpeta().isNull())
    {
        consulta=consulta+" carpeta ilike '%"+val->getCarpeta()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getPixel().isNull())
    {
        consulta=consulta+" pixel ilike '%"+val->getPixel()+"%' AND ";
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
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);

      }


    return salida;
}

int PgImagen::Contar()
{

return 0;
}


QSqlQueryModel *PgImagen::BuscarTabla(Imagen valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

         if(tipo==TODO)
         {
             consulta="SELECT codigo, carpeta, nombre, pixel "
                     " FROM imagenes;";
         }
         else
         {
             consulta="SELECT codigo, carpeta, nombre, pixel "
                     " FROM imagenes where ";

         if(!valor.getCodigo().isNull())
         {
             consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
         }

         if(!valor.getCarpeta().isNull())
         {
             consulta=consulta+" carpeta ilike '%"+valor.getCarpeta()+"%' AND ";
         }
         if(!valor.getNombre().isNull())
         {
             consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
         }
         if(!valor.getPixel().isNull())
         {
             consulta=consulta+" pixel ilike '%"+valor.getPixel()+"%' AND ";
         }

         consulta.replace(consulta.size()-5,5," ");
         }
         consulta=consulta+Extra;

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery(consulta);

         qDebug()<<consulta;
         return model;

}

qint64 PgImagen::ContarConsulta(ObjetoMaestro *valor)
{
    Imagen* val=(Imagen*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM imagenes WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getCarpeta().isNull())
    {
        consulta=consulta+" carpeta ilike '%"+val->getCarpeta()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }

    if(!val->getPixel().isNull())
    {
        consulta=consulta+" pixel ilike '%"+val->getPixel()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");


        QSqlQuery query(consulta);
        qint64 num;
        while(query.next())
        {
          num=query.value(0).toLongLong();
          return num;
        }

    return num;

}
