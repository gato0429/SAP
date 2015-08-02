#include "pgvehiculorubro.h"

PgVehiculoRubro::PgVehiculoRubro()
{

}

bool PgVehiculoRubro::Borrar(VehiculoRubro valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM vehiculo_rubro WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgVehiculoRubro::Insertar(VehiculoRubro valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO vehiculo_rubro(nombre, codigo_imagen)"
            " VALUES (?, ?);");

      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getCodigoImagen());

      bool flag=query.exec();
      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;

}

bool PgVehiculoRubro::Actualizar(VehiculoRubro Antiguo, VehiculoRubro Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE vehiculo_rubro SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }

    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getCodigoImagen().isNull())
    {
        consulta=consulta+", codigo_imagen='"+Nuevo.getCodigoImagen()+"'";
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

    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+"(nombre='"+Antiguo.getNombre()+"') AND ";
    }
    if(!Antiguo.getCodigoImagen().isNull())
    {
        consulta=consulta+"(codigo_imagen='"+Antiguo.getCodigoImagen()+"') AND ";
    }

    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;

    bool flag=query.exec(consulta);

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return flag;

}

VehiculoRubro PgVehiculoRubro::Buscar(VehiculoRubro valor)
{

    QString consulta;

        consulta="SELECT codigo, nombre, codigo_imagen, ruta_img "
                "FROM vista_detalle_vehiculo_rubro WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen ilike '%"+valor.getCodigoImagen()+"%' AND ";
    }
    if(!valor.getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img ilike '%"+valor.getRutaImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    VehiculoRubro* resp=new VehiculoRubro();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoImagen(query.value(2).toString());
          resp->setRutaImagen(query.value(3).toString());
          flag=false;
      }

       return *resp;
}

QMap<QString, ObjetoMaestro *> *PgVehiculoRubro::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    VehiculoRubro* val=(VehiculoRubro*)(valor);
    QString consulta;

    if(tipo==TODO)
    {
        consulta="SELECT codigo, nombre, codigo_imagen, ruta_img "
                "FROM vista_detalle_vehiculo_rubro";

    }
    else
    {
        consulta="SELECT codigo, nombre, codigo_imagen, ruta_img "
                "FROM vista_detalle_vehiculo_rubro WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen ilike '%"+val->getCodigoImagen()+"%' AND ";
    }
    if(!val->getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img ilike '%"+val->getRutaImagen()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;
    qDebug()<<consulta;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
          VehiculoRubro* resp=new VehiculoRubro();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoImagen(query.value(2).toString());
          resp->setRutaImagen(query.value(3).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgVehiculoRubro::Contar()
{
    QString consulta="SELECT count(*) FROM vehiculo_rubro";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgVehiculoRubro::ContarConsulta(ObjetoMaestro *valor)
{
    VehiculoRubro* val=(VehiculoRubro*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_vehiculo_rubro WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen ilike '%"+val->getCodigoImagen()+"%' AND ";
    }
    if(!val->getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img ilike '%"+val->getRutaImagen()+"%' AND ";
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

QSqlQueryModel *PgVehiculoRubro::BuscarTabla(VehiculoRubro valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

     if(tipo==TODO)
     {
         consulta="SELECT codigo, nombre, codigo_imagen, ruta_img "
                 "FROM vista_detalle_vehiculo_rubro";
     }
     else
     {
         consulta="SELECT codigo, nombre, codigo_imagen, ruta_img "
                       "FROM vista_detalle_vehiculo_rubro where";

     if(!valor.getCodigo().isNull())
     {
         consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
     }

     if(!valor.getNombre().isNull())
     {
         consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
     }
     if(!valor.getCodigoImagen().isNull())
     {
         consulta=consulta+" codigo_imagen ilike '%"+valor.getCodigoImagen()+"%' AND ";
     }
     if(!valor.getRutaImagen().isNull())
     {
         consulta=consulta+" ruta_img like '%"+valor.getRutaImagen()+"%' AND ";
     }

     consulta.replace(consulta.size()-5,5," ");
     }
     consulta=consulta+Extra;

     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery(consulta);

     qDebug()<<consulta;

     return model;
}

