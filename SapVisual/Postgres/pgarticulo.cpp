#include "pgarticulo.h"


PgArticulo::PgArticulo()
{
}


bool PgArticulo::Borrar(Articulo valor)
{
    QSqlQuery query;
    bool flag=query.exec("DELETE FROM articulos WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgArticulo::Insertar(Articulo valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO articulos("
                   "codigo_interno,codigo_externo,nombre, codigo_unidad, vigencia, codigo_tipo, codigo_imagen) "
                       " VALUES ( ?,?,?, ?, ?, ?, ?)");

      query.addBindValue(valor.getCodigoInterno());
      query.addBindValue(valor.getCodigoExterno());
      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getCodigoUnidad());
      query.addBindValue(valor.getVigencia());
      query.addBindValue(valor.getCodigoTipo());
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

bool PgArticulo::Actualizar(Articulo Antiguo, Articulo Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE articulos SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getCodigoInterno().isNull())
    {
        consulta=consulta+", codigo_interno='"+Nuevo.getCodigoInterno()+"'";
    }
    if(!Nuevo.getCodigoExterno().isNull())
    {
        consulta=consulta+", codigo_externo='"+Nuevo.getCodigoExterno()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getCodigoUnidad().isNull())
    {
        consulta=consulta+", codigo_unidad='"+Nuevo.getCodigoUnidad()+"'";
    }
    if(!Nuevo.getVigencia().isNull())
    {
        consulta=consulta+", vigencia='"+Nuevo.getVigencia()+"'";
    }
    if(!Nuevo.getCodigoTipo().isNull())
    {
        consulta=consulta+", codigo_tipo='"+Nuevo.getCodigoTipo()+"'";
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
        consulta=consulta+" codigo='"+Antiguo.getCodigo()+"' AND ";
    }
    if(!Antiguo.getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno='"+Antiguo.getCodigoInterno()+"' AND ";
    }
    if(!Antiguo.getCodigoExterno().isNull())
    {
        consulta=consulta+" codigo_externo='"+Antiguo.getCodigoExterno()+"' AND ";
    }
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+" nombre='"+Antiguo.getNombre()+"' AND ";
    }
    if(!Antiguo.getCodigoUnidad().isNull())
    {
        consulta=consulta+" codigo_unidad='"+Antiguo.getCodigoUnidad()+"' AND ";
    }
    if(!Antiguo.getVigencia().isNull())
    {
        consulta=consulta+" vigencia='"+Antiguo.getVigencia()+"' AND ";
    }
    if(!Antiguo.getCodigoTipo().isNull())
    {
        consulta=consulta+" codigo_tipo='"+Antiguo.getCodigoTipo()+"' AND ";
    }
    if(!Antiguo.getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen='"+Antiguo.getCodigoImagen()+"' AND ";
    }
    /*----*/

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

Articulo PgArticulo::Buscar(Articulo valor)
{
    QString consulta;

    consulta="SELECT codigo,codigo_interno, codigo_externo, nombre, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
            "simbolo, ruta_img_unidad,  codigo_tipo, nombre_tipo, "
            "ruta_img_tipo "
       "FROM vista_detalle_articulo WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno like '%"+valor.getCodigoInterno()+"%' AND ";
    }
    if(!valor.getCodigoExterno().isNull())
    {
        consulta=consulta+" codigo_externo like '%"+valor.getCodigoExterno()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen like '%"+valor.getCodigoImagen()+"%' AND ";
    }
    if(!valor.getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img like '%"+valor.getRutaImagen()+"%' AND ";
    }
    if(!valor.getVigencia().isNull())
    {
        consulta=consulta+" vigencia like '%"+valor.getVigencia()+"%' AND ";
    }
    if(!valor.getCodigoUnidad().isNull())
    {
        consulta=consulta+" codigo_unidad like '%"+valor.getCodigoUnidad()+"%' AND ";
    }
    if(!valor.getNombreUnidad().isNull())
    {
        consulta=consulta+" nombre_unidad like '%"+valor.getNombreUnidad()+"%' AND ";
    }

    if(!valor.getSimboloUnidad().isNull())
    {
        consulta=consulta+" simbolo like '%"+valor.getSimboloUnidad()+"%' AND ";
    }
    if(!valor.getRutaImagenUnidad().isNull())
    {
        consulta=consulta+" ruta_img_unidad like '%"+valor.getRutaImagenUnidad()+"%' AND ";
    }
    if(!valor.getCodigoTipo().isNull())
    {
        consulta=consulta+" codigo_tipo like '%"+valor.getCodigoTipo()+"%' AND ";
    }
    if(!valor.getNombreTipo().isNull())
    {
        consulta=consulta+" nombre_tipo like '%"+valor.getNombreTipo()+"%' AND ";
    }
    if(!valor.getRutaImagenTipo().isNull())
    {
        consulta=consulta+" ruta_img_tipo like '%"+valor.getRutaImagenTipo()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");

    qDebug()<<consulta;

    Articulo resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {

          resp.setCodigo(query.value(0).toString());
          resp.setCodigoInterno(query.value(1).toString());
          resp.setCodigoExterno(query.value(2).toString());

          resp.setNombre(query.value(3).toString());
          resp.setCodigoImagen(query.value(4).toString());
          resp.setRutaImagen(query.value(5).toString());
          resp.setVigencia(query.value(6).toString());

          resp.setCodigoUnidad(query.value(7).toString());
          resp.setNombreUnidad(query.value(8).toString());
          resp.setSimboloUnidad(query.value(9).toString());
          resp.setRutaImagenUnidad(query.value(10).toString());

          resp.setCodigoTipo(query.value(11).toString());
          resp.setNombreTipo(query.value(12).toString());
          resp.setRutaImagenTipo(query.value(13).toString());

         flag=false;
      }


    return resp;

}

QMap<QString, ObjetoMaestro *> *PgArticulo::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    Articulo* val=(Articulo*)(valor);
    QString consulta;

    if(tipo==TODO)
{
        consulta="SELECT codigo,codigo_interno, codigo_externo, nombre, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                 "simbolo, ruta_img_unidad,  codigo_tipo, nombre_tipo, "
                 "ruta_img_tipo "
            "FROM vista_detalle_articulo ";
}
else
 {

       consulta="SELECT codigo,codigo_interno, codigo_externo, nombre, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                "simbolo, ruta_img_unidad,  codigo_tipo, nombre_tipo, "
                "ruta_img_tipo "
           "FROM vista_detalle_articulo WHERE ";



        if(!val->getCodigo().isNull())
        {
            consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
        }
        if(!val->getCodigoInterno().isNull())
        {
            consulta=consulta+" codigo_interno like '%"+val->getCodigoInterno()+"%' AND ";
        }
        if(!val->getCodigoExterno().isNull())
        {
            consulta=consulta+" codigo_externo like '%"+val->getCodigoExterno()+"%' AND ";
        }
        if(!val->getNombre().isNull())
        {
            consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
        }
        if(!val->getCodigoImagen().isNull())
        {
            consulta=consulta+" codigo_imagen like '%"+val->getCodigoImagen()+"%' AND ";
        }
        if(!val->getRutaImagen().isNull())
        {
            consulta=consulta+" ruta_img like '%"+val->getRutaImagen()+"%' AND ";
        }
        if(!val->getVigencia().isNull())
        {
            consulta=consulta+" vigencia like '%"+val->getVigencia()+"%' AND ";
        }
        if(!val->getCodigoUnidad().isNull())
        {
            consulta=consulta+" codigo_unidad like '%"+val->getCodigoUnidad()+"%' AND ";
        }
        if(!val->getNombreUnidad().isNull())
        {
            consulta=consulta+" nombre_unidad like '%"+val->getNombreUnidad()+"%' AND ";
        }

        if(!val->getSimboloUnidad().isNull())
        {
            consulta=consulta+" simbolo like '%"+val->getSimboloUnidad()+"%' AND ";
        }
        if(!val->getRutaImagenUnidad().isNull())
        {
            consulta=consulta+" ruta_img_unidad like '%"+val->getRutaImagenUnidad()+"%' AND ";
        }
        if(!val->getCodigoTipo().isNull())
        {
            consulta=consulta+" codigo_tipo like '%"+val->getCodigoTipo()+"%' AND ";
        }
        if(!val->getNombreTipo().isNull())
        {
            consulta=consulta+" nombre_tipo like '%"+val->getNombreTipo()+"%' AND ";
        }
        if(!val->getRutaImagenTipo().isNull())
        {
            consulta=consulta+" ruta_img_tipo like '%"+val->getRutaImagenTipo()+"%' AND ";
        }

        consulta.replace(consulta.size()-5,5," ");

  }

    consulta=consulta+Extra;

    qDebug()<<consulta;



     QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

    while (query.next())
    {
          Articulo *resp=new Articulo();
          resp->setCodigo(query.value(0).toString());
          resp->setCodigoInterno(query.value(1).toString());
          resp->setCodigoExterno(query.value(2).toString());
          resp->setNombre(query.value(3).toString());
          resp->setCodigoImagen(query.value(4).toString());
          resp->setRutaImagen(query.value(5).toString());
          resp->setVigencia(query.value(6).toString());

          resp->setCodigoUnidad(query.value(7).toString());
          resp->setNombreUnidad(query.value(8).toString());
          resp->setSimboloUnidad(query.value(9).toString());
          resp->setRutaImagenUnidad(query.value(10).toString());

          resp->setCodigoTipo(query.value(11).toString());
          resp->setNombreTipo(query.value(12).toString());
          resp->setRutaImagenTipo(query.value(13).toString());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
      }


    return salida;

}

int PgArticulo::Contar()
{
    QString consulta="SELECT count(*) FROM articulos";
    QSqlQuery query(consulta);
  int num=0;
      while (query.next() )
      {
        num=query.value(0).toInt();
      }
  return num;
}

int PgArticulo::ContarConsulta(ObjetoMaestro *valor)
{
    Articulo* val=(Articulo*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            " FROM vista_detalle_articulo WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno like '%"+val->getCodigoInterno()+"%' AND ";
    }
    if(!val->getCodigoExterno().isNull())
    {
        consulta=consulta+" codigo_externo like '%"+val->getCodigoExterno()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen like '%"+val->getCodigoImagen()+"%' AND ";
    }
    if(!val->getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img like '%"+val->getRutaImagen()+"%' AND ";
    }
    if(!val->getVigencia().isNull())
    {
        consulta=consulta+" vigencia like '%"+val->getVigencia()+"%' AND ";
    }
    if(!val->getCodigoUnidad().isNull())
    {
        consulta=consulta+" codigo_unidad like '%"+val->getCodigoUnidad()+"%' AND ";
    }
    if(!val->getNombreUnidad().isNull())
    {
        consulta=consulta+" nombre_unidad like '%"+val->getNombreUnidad()+"%' AND ";
    }

    if(!val->getSimboloUnidad().isNull())
    {
        consulta=consulta+" simbolo like '%"+val->getSimboloUnidad()+"%' AND ";
    }
    if(!val->getRutaImagenUnidad().isNull())
    {
        consulta=consulta+" ruta_img_unidad like '%"+val->getRutaImagenUnidad()+"%' AND ";
    }
    if(!val->getCodigoTipo().isNull())
    {
        consulta=consulta+" codigo_tipo like '%"+val->getCodigoTipo()+"%' AND ";
    }
    if(!val->getNombreTipo().isNull())
    {
        consulta=consulta+" nombre_tipo like '%"+val->getNombreTipo()+"%' AND ";
    }
    if(!val->getRutaImagenTipo().isNull())
    {
        consulta=consulta+" ruta_img_tipo like '%"+val->getRutaImagenTipo()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");

        QSqlQuery query(consulta);
        int num=0;
        while(query.next())
        {
          num=query.value(0).toInt();
        }

    return num;
}

QSqlQueryModel *PgArticulo::BuscarTabla(Articulo valor, QString Extra, CONSULTA tipo)
{

    QString consulta;

    if(tipo==TODO)
{
        consulta="SELECT codigo,codigo_interno, codigo_externo, nombre, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                 "simbolo, ruta_img_unidad,  codigo_tipo, nombre_tipo, "
                 "ruta_img_tipo "
            "FROM vista_detalle_articulo ";
}
else
 {

       consulta="SELECT codigo, codigo_interno, codigo_externo, nombre, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                "simbolo, ruta_img_unidad,  codigo_tipo, nombre_tipo, "
                "ruta_img_tipo "
           "FROM vista_detalle_articulo WHERE ";



        if(!valor.getCodigo().isNull())
        {
            consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
        }
        if(!valor.getCodigoInterno().isNull())
        {
            consulta=consulta+" codigo_interno like '%"+valor.getCodigoInterno()+"%' AND ";
        }
        if(!valor.getCodigoExterno().isNull())
        {
            consulta=consulta+" codigo_externo like '%"+valor.getCodigoExterno()+"%' AND ";
        }

        if(!valor.getNombre().isNull())
        {
            consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
        }
        if(!valor.getCodigoImagen().isNull())
        {
            consulta=consulta+" codigo_imagen like '%"+valor.getCodigoImagen()+"%' AND ";
        }
        if(!valor.getRutaImagen().isNull())
        {
            consulta=consulta+" ruta_img like '%"+valor.getRutaImagen()+"%' AND ";
        }
        if(!valor.getVigencia().isNull())
        {
            consulta=consulta+" vigencia like '%"+valor.getVigencia()+"%' AND ";
        }
        if(!valor.getCodigoUnidad().isNull())
        {
            consulta=consulta+" codigo_unidad like '%"+valor.getCodigoUnidad()+"%' AND ";
        }
        if(!valor.getNombreUnidad().isNull())
        {
            consulta=consulta+" nombre_unidad like '%"+valor.getNombreUnidad()+"%' AND ";
        }

        if(!valor.getSimboloUnidad().isNull())
        {
            consulta=consulta+" simbolo like '%"+valor.getSimboloUnidad()+"%' AND ";
        }
        if(!valor.getRutaImagenUnidad().isNull())
        {
            consulta=consulta+" ruta_img_unidad like '%"+valor.getRutaImagenUnidad()+"%' AND ";
        }
        if(!valor.getCodigoTipo().isNull())
        {
            consulta=consulta+" codigo_tipo like '%"+valor.getCodigoTipo()+"%' AND ";
        }
        if(!valor.getNombreTipo().isNull())
        {
            consulta=consulta+" nombre_tipo like '%"+valor.getNombreTipo()+"%' AND ";
        }
        if(!valor.getRutaImagenTipo().isNull())
        {
            consulta=consulta+" ruta_img_tipo like '%"+valor.getRutaImagenTipo()+"%' AND ";
        }

        consulta.replace(consulta.size()-5,5," ");

  }


    consulta=consulta+Extra;

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(consulta);

    qDebug()<<consulta;

    return model;

}

QSqlQueryModel *PgArticulo::FuncionArticulos(Articulo valor,  QString Extra)
{
    QString consulta;
/*
        consulta="select * from consultaarticulo( ";

        consulta=consulta+"'"+valor.getCodigo()+"', ";
        consulta=consulta+"'"+valor.getNombre()+"',";
        consulta=consulta+"'"+valor.getUnidad()+"',";
        consulta=consulta+"'"+valor.getVigencia()+"',";
        consulta=consulta+"'"+valor.getNombreTipo()+"') ";

        consulta=consulta+Extra;*/
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery(consulta);

        qDebug()<<consulta;

        return model;

}
