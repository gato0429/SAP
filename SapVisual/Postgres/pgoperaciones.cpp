#include "pgoperaciones.h"

PgOperaciones::PgOperaciones()
{

}

bool PgOperaciones::Borrar(Operaciones valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM operaciones WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgOperaciones::Insertar(Operaciones valor)
{
    QSqlQuery query;
        query.prepare("INSERT INTO operaciones(nombre,descripcion, codigo_imagen)"
              " VALUES (?,?, ?);");

        query.addBindValue(valor.getNombre());
        query.addBindValue(valor.getDescripcion());
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

bool PgOperaciones::Actualizar(Operaciones Antiguo, Operaciones Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE operaciones SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }

    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getDescripcion().isNull())
    {
        consulta=consulta+", descripcion='"+Nuevo.getDescripcion()+"'";
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
    if(!Antiguo.getDescripcion().isNull())
    {
        consulta=consulta+"(descripcion='"+Antiguo.getDescripcion()+"') AND ";
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

Operaciones PgOperaciones::Buscar(Operaciones valor)
{
    QString consulta;

        consulta="SELECT codigo, descripcion, nombre, codigo_imagen, ruta_img "
                "FROM vista_detalle_moneda WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getDescripcion().isNull())
    {
        consulta=consulta+" descripcion ilike '%"+valor.getDescripcion()+"%' AND ";
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
    Operaciones* resp=new Operaciones();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setDescripcion(query.value(2).toString());
          resp->setCodigoImagen(query.value(3).toString());
          resp->setRutaImagen(query.value(4).toString());
          flag=false;
      }

       return *resp;

}

QMap<QString, ObjetoMaestro *> *PgOperaciones::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Operaciones* val=(Operaciones*)(valor);
    QString consulta;

    if(Tipo==TODO)
    {
        consulta="SELECT codigo, nombre,descripcion, codigo_imagen, ruta_img "
                "FROM vista_detalle_operaciones";

    }
    else
    {
        consulta="SELECT codigo, nombre,descripcion, codigo_imagen, ruta_img "
                "FROM vista_detalle_operaciones WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDescripcion().isNull())
    {
        consulta=consulta+" descripcion ilike '%"+val->getDescripcion()+"%' AND ";
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
          Operaciones* resp=new Operaciones();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setDescripcion(query.value(2).toString());
          resp->setCodigoImagen(query.value(3).toString());
          resp->setRutaImagen(query.value(4).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgOperaciones::Contar()
{
    QString consulta="SELECT count(*) FROM operaciones";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgOperaciones::ContarConsulta(ObjetoMaestro *valor)
{
    Operaciones* val=(Operaciones*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_operaciones WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDescripcion().isNull())
    {
        consulta=consulta+" descripcion ilike '%"+val->getDescripcion()+"%' AND ";
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

QSqlQueryModel *PgOperaciones::BuscarTabla(Operaciones valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

     if(tipo==TODO)
     {
         consulta="SELECT codigo, nombre,descripcion, codigo_imagen, ruta_img "
                 "FROM vista_detalle_moneda";
     }
     else
     {
         consulta="SELECT codigo, nombre,descripcion,  codigo_imagen, ruta_img "
                       "FROM vista_detalle_moneda where";

     if(!valor.getCodigo().isNull())
     {
         consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
     }

     if(!valor.getNombre().isNull())
     {
         consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
     }
     if(!valor.getDescripcion().isNull())
     {
         consulta=consulta+" descripcion ilike '%"+valor.getDescripcion()+"%' AND ";
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

