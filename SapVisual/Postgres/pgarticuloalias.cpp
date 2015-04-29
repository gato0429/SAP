#include "pgarticuloalias.h"

PgArticuloAlias::PgArticuloAlias()
{
}


bool PgArticuloAlias::Borrar(ArticuloAlias valor)
{

    QSqlQuery query;
    bool flag=query.exec("DELETE FROM articulos_alias WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgArticuloAlias::Insertar(ArticuloAlias valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO articulos_alias( "
                    " nombre, codigo_articulo) "
           " VALUES ( ?, ?);");


      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getCodigoArticulo());
      bool flag= query.exec();

      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;
}

bool PgArticuloAlias::Actualizar(ArticuloAlias Antiguo, ArticuloAlias Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE articulos_alias SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getCodigoArticulo().isNull())
    {
        consulta=consulta+", codigo_articulo='"+Nuevo.getCodigoArticulo()+"'";
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
    if(!Antiguo.getCodigoArticulo().isNull())
    {
        consulta=consulta+"(codigo_articulo='"+Antiguo.getCodigoArticulo()+"') AND ";
    }

    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;
    bool flag= query.exec(consulta);

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;

}

ArticuloAlias PgArticuloAlias::Buscar(ArticuloAlias valor)
{
    QString consulta;

    consulta="SELECT codigo, nombre, codigo_articulo, nombre_articulo, ruta_img_articulo "
            "FROM vista_detalle_articulo_alias WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getCodigoArticulo().isNull())
    {
        consulta=consulta+" codigo_articulo like '%"+valor.getCodigoArticulo()+"%' AND ";
    }
    if(!valor.getNombreArticulo().isNull())
    {
        consulta=consulta+" nombre_articulo like '%"+valor.getNombreArticulo()+"%' AND ";
    }
    if(!valor.getRutaArticulo().isNull())
    {
        consulta=consulta+" ruta_img_articulo like '%"+valor.getRutaArticulo()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");

    qDebug()<<consulta;

    ArticuloAlias resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setNombre(query.value(1).toString());
          resp.setCodigoArticulo(query.value(2).toString());
          resp.setNombreArticulo(query.value(3).toString());
          resp.setRutaArticulo(query.value(4).toString());

         flag=false;
      }


    return resp;
}

QMap<QString, ObjetoMaestro *> *PgArticuloAlias::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    ArticuloAlias* val=(ArticuloAlias*)(valor);
   qDebug()<<val->getCodigo();
    QString consulta;

    if(tipo==TODO)
    {
        consulta="SELECT codigo, nombre, codigo_articulo, nombre_articulo, ruta_img_articulo "
                "FROM vista_detalle_articulo_alias ";    }
   else
    {
        consulta="SELECT codigo, nombre, codigo_articulo, nombre_articulo, ruta_img_articulo "
                "FROM vista_detalle_articulo_alias WHERE ";



        if(!val->getCodigo().isNull())
        {
            consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
        }
        if(!val->getNombre().isNull())
        {
            consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
        }
        if(!val->getCodigoArticulo().isNull())
        {
            consulta=consulta+" codigo_articulo = '"+val->getCodigoArticulo()+"' AND ";
        }
        if(!val->getNombreArticulo().isNull())
        {
            consulta=consulta+" nombre_articulo like '%"+val->getNombreArticulo()+"%' AND ";
        }
        if(!val->getRutaArticulo().isNull())
        {
            consulta=consulta+" ruta_img_articulo like '%"+val->getRutaArticulo()+"%' AND ";
        }
    consulta.replace(consulta.size()-5,5," ");
    }

    consulta=consulta+Extra;

    qDebug()<<consulta;

    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();


    QSqlQuery query(consulta);

      while (query.next() ) {

          ArticuloAlias* resp=new ArticuloAlias();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoArticulo(query.value(2).toString());
          resp->setNombreArticulo(query.value(3).toString());
          resp->setRutaArticulo(query.value(4).toString());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);

      }

       return salida;
}

int PgArticuloAlias::Contar()
{
    QString consulta="SELECT count(*) FROM articulos_alias";
    QSqlQuery query(consulta);
  int num=0;
      while (query.next() )
      {
        num=query.value(0).toInt();
      }
  return num;
}

int PgArticuloAlias::ContarConsulta(ObjetoMaestro *valor)
{
    ArticuloAlias* val=(ArticuloAlias*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            " FROM vista_detalle_articulo_alias WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getCodigoArticulo().isNull())
    {
        consulta=consulta+" codigo_articulo like '%"+val->getCodigoArticulo()+"%' AND ";
    }
    if(!val->getNombreArticulo().isNull())
    {
        consulta=consulta+" nombre_articulo like '%"+val->getNombreArticulo()+"%' AND ";
    }
    if(!val->getRutaArticulo().isNull())
    {
        consulta=consulta+" ruta_img_articulo like '%"+val->getRutaArticulo()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");

    qDebug()<<"Contando desde consulta"<<consulta;
        QSqlQuery query(consulta);
        int num=0;
        while(query.next())
        {
          num=query.value(0).toInt();
        }
    qDebug()<<"Contand"<<num;
    return num;
}

QSqlQueryModel *PgArticuloAlias::BuscarTabla(ArticuloAlias valor, QString Extra, CONSULTA tipo)
{
    QString consulta;
    if(tipo==TODO)
    {
        consulta="SELECT codigo, nombre, codigo_articulo, nombre_articulo, ruta_img_articulo "
                "FROM vista_detalle_articulo_alias  ";


    }
    else
    {
        consulta="SELECT codigo, nombre, codigo_articulo, nombre_articulo, ruta_img_articulo "
                "FROM vista_detalle_articulo_alias WHERE ";



        if(!valor.getCodigo().isNull())
        {
            consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
        }
        if(!valor.getNombre().isNull())
        {
            consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
        }
        if(!valor.getCodigoArticulo().isNull())
        {
            consulta=consulta+" codigo_articulo like '%"+valor.getCodigoArticulo()+"%' AND ";
        }
        if(!valor.getNombreArticulo().isNull())
        {
            consulta=consulta+" nombre_articulo like '%"+valor.getNombreArticulo()+"%' AND ";
        }
        if(!valor.getRutaArticulo().isNull())
        {
            consulta=consulta+" ruta_img_articulo like '%"+valor.getRutaArticulo()+"%' AND ";
        }
    consulta.replace(consulta.size()-5,5," ");
    }

    consulta=consulta+Extra;
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(consulta);

    qDebug()<<"desde tabla"<<consulta;

    return model;
}
