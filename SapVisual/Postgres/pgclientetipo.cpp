#include "pgclientetipo.h"

PgClienteTipo::PgClienteTipo()
{

}

bool PgClienteTipo::Borrar(ClienteTipo valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM cliente_tipo WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgClienteTipo::Insertar(ClienteTipo valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO cliente_tipo(nombre, codigo_imagen, tipo)"
            " VALUES (?, ?, ?);");

      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getCodigoImagen());
      query.addBindValue(valor.getTipo());

      bool flag=query.exec();
      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;
}

bool PgClienteTipo::Actualizar(ClienteTipo Antiguo, ClienteTipo Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE cliente_tipo SET ";

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
    if(!Nuevo.getTipo().isNull())
    {
        consulta=consulta+", tipo='"+Nuevo.getTipo()+"'";
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

    if(!Antiguo.getTipo().isNull())
    {
        consulta=consulta+", tipo='"+Antiguo.getTipo()+"'";
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

ClienteTipo PgClienteTipo::Buscar(ClienteTipo valor)
{
    QString consulta;

        consulta="SELECT codigo, nombre, codigo_imagen, ruta_img, tipo "
                "FROM vista_detalle_cliente_tipo WHERE ";


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

    if(!valor.getTipo().isNull())
    {
        consulta=consulta+" tipo ilike '%"+valor.getTipo()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    ClienteTipo* resp=new ClienteTipo();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoImagen(query.value(2).toString());
          resp->setRutaImagen(query.value(3).toString());
          resp->setTipo(query.value(4).toString());
          flag=false;
      }

       return *resp;
}

QMap<QString, ObjetoMaestro *> *PgClienteTipo::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    ClienteTipo* val=(ClienteTipo*)(valor);
    QString consulta;

    if(tipo==TODO)
    {
        consulta="SELECT codigo, nombre, codigo_imagen, ruta_img, tipo  "
                "FROM vista_detalle_cliente_tipo";

    }
    else
    {
        consulta="SELECT codigo, nombre, codigo_imagen, ruta_img, tipo  "
                "FROM vista_detalle_cliente_tipo WHERE ";

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
    if(!val->getTipo().isNull())
    {
        consulta=consulta+" tipo ilike '%"+val->getTipo()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;
    qDebug()<<consulta;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
          ClienteTipo* resp=new ClienteTipo();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoImagen(query.value(2).toString());
          resp->setRutaImagen(query.value(3).toString());
          resp->setTipo(query.value(4).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgClienteTipo::Contar()
{
    QString consulta="SELECT count(*) FROM cliente_tipo";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgClienteTipo::ContarConsulta(ObjetoMaestro *valor)
{
    ClienteTipo* val=(ClienteTipo*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_cliente_tipo WHERE ";

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
    if(!val->getTipo().isNull())
    {
        consulta=consulta+" tipo ilike '%"+val->getTipo()+"%' AND ";
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

QSqlQueryModel *PgClienteTipo::BuscarTabla(ClienteTipo valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

     if(tipo==TODO)
     {
         consulta="SELECT codigo, nombre, codigo_imagen, ruta_img, tipo "
                 "FROM vista_detalle_cliente_tipo";
     }
     else
     {
         consulta="SELECT codigo, nombre, codigo_imagen, ruta_img, tipo "
                       "FROM vista_detalle_cliente_tipo where";

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
     if(!valor.getTipo().isNull())
     {
         consulta=consulta+" tipo ilike '%"+valor.getTipo()+"%' AND ";
     }

     consulta.replace(consulta.size()-5,5," ");
     }
     consulta=consulta+Extra;

     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery(consulta);

     qDebug()<<consulta;

     return model;
}

QMap<QString, ObjetoMaestro *> *PgClienteTipo::BuscarClave()
{
    QString consulta;

    consulta="SELECT codigo, nombre, codigo_imagen, ruta_img, tipo "
            "FROM vista_detalle_cliente_tipo order by nombre asc";



        QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
        QSqlQuery query(consulta);

          while (query.next() ) {

              ClienteTipo* resp=new ClienteTipo();
              resp->setCodigo(query.value(0).toString());
              resp->setNombre(query.value(1).toString());
              resp->setCodigoImagen(query.value(2).toString());
              resp->setRutaImagen(query.value(3).toString());
              resp->setTipo(query.value(4).toString());


              salida->insert(query.value(1).toString(),(ObjetoMaestro*)resp);
          }




        return salida;
}

