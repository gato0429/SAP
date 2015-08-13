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
      query.prepare("INSERT INTO articulos( "
                       " nombre, codigo_unidad, vigencia, codigo_tipo, codigo_interno, "
                       " codigo_externo, codigo_imagen, codigo_marca, codigo_moneda, cantidad_min, "
                       " codigo_modelo, unico,precio) "
               " VALUES (?, ?, ?, ?, ?, ?, "
                       " ?, ?, ?, ?, ?, "
                       " ?, ?);");
      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getCodigoUnidad());
      query.addBindValue(valor.getVigencia());
      query.addBindValue(valor.getCodigoTipo());
      query.addBindValue(valor.getCodigoInterno());
      query.addBindValue(valor.getCodigoExterno());
      query.addBindValue(valor.getCodigoImagen());
      query.addBindValue(valor.getCodigoMarca());
      query.addBindValue(valor.getCodigoMoneda());
      query.addBindValue(valor.getCantidadMin());
      query.addBindValue(valor.getCodigoModelo());
      query.addBindValue(valor.getUnico());
      query.addBindValue(valor.getPrecio());



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
    if(!Nuevo.getUnico().isNull())
    {
        consulta=consulta+", unico='"+Nuevo.getUnico()+"'";
    }
    if(Nuevo.getCantidadMin()!=(-1))
    {
        consulta=consulta+", cantidad_min="+QString::number(Nuevo.getCantidadMin())+"";
    }
    if(!Nuevo.getCodigoMarca().isNull())
    {
        consulta=consulta+", codigo_marca='"+Nuevo.getCodigoMarca()+"'";
    }
    if(!Nuevo.getCodigoModelo().isNull())
    {
        consulta=consulta+", codigo_modelo='"+Nuevo.getCodigoModelo()+"'";
    }
    if(!Nuevo.getCodigoMoneda().isNull())
    {
        consulta=consulta+", codigo_moneda='"+Nuevo.getCodigoMoneda()+"'";
    }
    if(!(Nuevo.getPrecio()==-1))
    {
        consulta=consulta+", precio="+QString::number(Nuevo.getPrecio())+"";
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
    if(!Antiguo.getUnico().isNull())
    {
        consulta=consulta+", unico='"+Antiguo.getUnico()+"'";
    }
    if(Antiguo.getCantidadMin()!=(-1))
    {
        consulta=consulta+", cantidad_min="+QString::number(Antiguo.getCantidadMin())+"";
    }
    if(!Antiguo.getCodigoMarca().isNull())
    {
        consulta=consulta+", codigo_marca='"+Antiguo.getCodigoMarca()+"'";
    }
    if(!Antiguo.getCodigoModelo().isNull())
    {
        consulta=consulta+", codigo_modelo='"+Antiguo.getCodigoModelo()+"'";
    }
    if(!Antiguo.getCodigoMoneda().isNull())
    {
        consulta=consulta+", codigo_moneda='"+Antiguo.getCodigoMoneda()+"'";
    }
    if(!(Antiguo.getPrecio()==-1))
    {
        consulta=consulta+", precio="+QString::number(Antiguo.getPrecio())+"";
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

    consulta="SELECT codigo, codigo_interno, codigo_externo, nombre, cantidad_min, "
           " unico, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
            " simbolo, ruta_img_unidad, codigo_tipo, nombre_tipo, ruta_img_tipo, "
            " codigo_modelo, nombre_modelo, ruta_img_modelo, codigo_marca, "
            " nombre_marca, ruta_img_marca, codigo_moneda, nombre_moneda, simbolo_moneda, "
            " ruta_img_moneda, precio "
       " FROM vista_detalle_articulo;";




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
        consulta=consulta+" codigo_externo ilike '%"+valor.getCodigoExterno()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
    }
    if(!(valor.getCantidadMin()==(-1)))
    {
        consulta=consulta+" cantidad_min ilike '%"+valor.getCantidadMin()+"%' AND ";
    }
    if(!valor.getUnico().isNull())
    {
        consulta=consulta+" unico ilike '%"+valor.getUnico()+"%' AND ";
    }
    if(!valor.getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen ilike '%"+valor.getCodigoImagen()+"%' AND ";
    }
    if(!valor.getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img ilike '%"+valor.getRutaImagen()+"%' AND ";
    }
    if(!valor.getVigencia().isNull())
    {
        consulta=consulta+" vigencia ilike '%"+valor.getVigencia()+"%' AND ";
    }
    if(!valor.getCodigoUnidad().isNull())
    {
        consulta=consulta+" codigo_unidad ilike '%"+valor.getCodigoUnidad()+"%' AND ";
    }
    if(!valor.getNombreUnidad().isNull())
    {
        consulta=consulta+" nombre_unidad ilike '%"+valor.getNombreUnidad()+"%' AND ";
    }

    if(!valor.getSimboloUnidad().isNull())
    {
        consulta=consulta+" simbolo ilike '%"+valor.getSimboloUnidad()+"%' AND ";
    }
    if(!valor.getRutaImagenUnidad().isNull())
    {
        consulta=consulta+" ruta_img_unidad ilike '%"+valor.getRutaImagenUnidad()+"%' AND ";
    }
    if(!valor.getCodigoTipo().isNull())
    {
        consulta=consulta+" codigo_tipo ilike '%"+valor.getCodigoTipo()+"%' AND ";
    }
    if(!valor.getNombreTipo().isNull())
    {
        consulta=consulta+" nombre_tipo ilike '%"+valor.getNombreTipo()+"%' AND ";
    }
    if(!valor.getRutaImagenTipo().isNull())
    {
        consulta=consulta+" ruta_img_tipo ilike '%"+valor.getRutaImagenTipo()+"%' AND ";
    }
/**/
    if(!valor.getCodigoModelo().isNull())
    {
        consulta=consulta+" codigo_modelo ilike '%"+valor.getCodigoModelo()+"%' AND ";
    }
    if(!valor.getNombreModelo().isNull())
    {
        consulta=consulta+" nombre_modelo ilike '%"+valor.getNombreModelo()+"%' AND ";
    }
    if(!valor.getRutaImagenModelo().isNull())
    {
        consulta=consulta+" ruta_img_modelo ilike '%"+valor.getRutaImagenModelo()+"%' AND ";
    }
    if(!valor.getCodigoMarca().isNull())
    {
        consulta=consulta+" codigo_marca ilike '%"+valor.getCodigoMarca()+"%' AND ";
    }
    if(!valor.getNombreMarca().isNull())
    {
        consulta=consulta+" nombre_marca ilike '%"+valor.getNombreMarca()+"%' AND ";
    }
    if(!valor.getRutaImagenMarca().isNull())
    {
        consulta=consulta+" ruta_img_marca ilike '%"+valor.getRutaImagenMarca()+"%' AND ";
    }

    if(!valor.getCodigoMoneda().isNull())
    {
        consulta=consulta+" codigo_moneda ilike '%"+valor.getCodigoMoneda()+"%' AND ";
    }
    if(!valor.getNombreMoneda().isNull())
    {
        consulta=consulta+" nombre_moneda ilike '%"+valor.getNombreMoneda()+"%' AND ";
    }
    if(!valor.getSimboloMoneda().isNull())
    {
        consulta=consulta+" simbolo_moneda ilike '%"+valor.getSimboloMoneda()+"%' AND ";
    }
    if(!valor.getRutaImagenMoneda().isNull())
    {
        consulta=consulta+" ruta_img_moneda ilike '%"+valor.getRutaImagenMoneda()+"%' AND ";
    }

    if(!(valor.getPrecio()==-1))
    {
        consulta=consulta+" precio >="+valor.getPrecio()+" AND ";
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
          resp.setCantidadMin(query.value(4).toDouble());
          resp.setUnico(query.value(5).toString());

          resp.setCodigoImagen(query.value(6).toString());
          resp.setRutaImagen(query.value(7).toString());
          resp.setVigencia(query.value(8).toString());

          resp.setCodigoUnidad(query.value(9).toString());
          resp.setNombreUnidad(query.value(10).toString());
          resp.setSimboloUnidad(query.value(11).toString());
          resp.setRutaImagenUnidad(query.value(12).toString());

          resp.setCodigoTipo(query.value(13).toString());
          resp.setNombreTipo(query.value(14).toString());
          resp.setRutaImagenTipo(query.value(15).toString());

          resp.setCodigoModelo(query.value(16).toString());
          resp.setNombreModelo(query.value(17).toString());
          resp.setRutaImagenModelo(query.value(18).toString());

          resp.setCodigoMarca(query.value(19).toString());
          resp.setNombreMarca(query.value(20).toString());
          resp.setRutaImagenMarca(query.value(21).toString());

          resp.setCodigoMoneda(query.value(22).toString());
          resp.setNombreMoneda(query.value(23).toString());
          resp.setSimboloMoneda(query.value(24).toString());
          resp.setRutaImagenMoneda(query.value(25).toString());
          resp.setPrecio(query.value(26).toDouble());

         flag=false;
      }


    return resp;

}

QMap<QString, ObjetoMaestro *> *PgArticulo::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Articulo* val=(Articulo*)(valor);
    QString consulta;

    if(tipo==TODO)
{

        consulta="SELECT codigo, codigo_interno, codigo_externo, nombre, cantidad_min, "
               " unico, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                " simbolo, ruta_img_unidad, codigo_tipo, nombre_tipo, ruta_img_tipo, "
                " codigo_modelo, nombre_modelo, ruta_img_modelo, codigo_marca, "
                " nombre_marca, ruta_img_marca, codigo_moneda, nombre_moneda, simbolo_moneda, "
                " ruta_img_moneda, precio "
           " FROM vista_detalle_articulo;";
}
else
 {


        consulta="SELECT codigo, codigo_interno, codigo_externo, nombre, cantidad_min, "
               " unico, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                " simbolo, ruta_img_unidad, codigo_tipo, nombre_tipo, ruta_img_tipo, "
                " codigo_modelo, nombre_modelo, ruta_img_modelo, codigo_marca, "
                " nombre_marca, ruta_img_marca, codigo_moneda, nombre_moneda, simbolo_moneda, "
                " ruta_img_moneda, precio "
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
            consulta=consulta+" codigo_externo ilike '%"+val->getCodigoExterno()+"%' AND ";
        }
        if(!val->getNombre().isNull())
        {
            consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
        }
        if(!(val->getCantidadMin()==(-1)))
        {
            consulta=consulta+" cantidad_min >= "+QString::number(val->getCantidadMin())+" AND ";
        }
        if(!val->getUnico().isNull())
        {
            consulta=consulta+" unico ilike '%"+val->getUnico()+"%' AND ";
        }
        if(!val->getCodigoImagen().isNull())
        {
            consulta=consulta+" codigo_imagen ilike '%"+val->getCodigoImagen()+"%' AND ";
        }
        if(!val->getRutaImagen().isNull())
        {
            consulta=consulta+" ruta_img ilike '%"+val->getRutaImagen()+"%' AND ";
        }
        if(!val->getVigencia().isNull())
        {
            consulta=consulta+" vigencia ilike '%"+val->getVigencia()+"%' AND ";
        }
        if(!val->getCodigoUnidad().isNull())
        {
            consulta=consulta+" codigo_unidad ilike '%"+val->getCodigoUnidad()+"%' AND ";
        }
        if(!val->getNombreUnidad().isNull())
        {
            consulta=consulta+" nombre_unidad ilike '%"+val->getNombreUnidad()+"%' AND ";
        }

        if(!val->getSimboloUnidad().isNull())
        {
            consulta=consulta+" simbolo ilike '%"+val->getSimboloUnidad()+"%' AND ";
        }
        if(!val->getRutaImagenUnidad().isNull())
        {
            consulta=consulta+" ruta_img_unidad ilike '%"+val->getRutaImagenUnidad()+"%' AND ";
        }
        if(!val->getCodigoTipo().isNull())
        {
            consulta=consulta+" codigo_tipo ilike '%"+val->getCodigoTipo()+"%' AND ";
        }
        if(!val->getNombreTipo().isNull())
        {
            consulta=consulta+" nombre_tipo ilike '%"+val->getNombreTipo()+"%' AND ";
        }
        if(!val->getRutaImagenTipo().isNull())
        {
            consulta=consulta+" ruta_img_tipo ilike '%"+val->getRutaImagenTipo()+"%' AND ";
        }
    /**/
        if(!val->getCodigoModelo().isNull())
        {
            consulta=consulta+" codigo_modelo ilike '%"+val->getCodigoModelo()+"%' AND ";
        }
        if(!val->getNombreModelo().isNull())
        {
            consulta=consulta+" nombre_modelo ilike '%"+val->getNombreModelo()+"%' AND ";
        }
        if(!val->getRutaImagenModelo().isNull())
        {
            consulta=consulta+" ruta_img_modelo ilike '%"+val->getRutaImagenModelo()+"%' AND ";
        }
        if(!val->getCodigoMarca().isNull())
        {
            consulta=consulta+" codigo_marca ilike '%"+val->getCodigoMarca()+"%' AND ";
        }
        if(!val->getNombreMarca().isNull())
        {
            consulta=consulta+" nombre_marca ilike '%"+val->getNombreMarca()+"%' AND ";
        }
        if(!val->getRutaImagenMarca().isNull())
        {
            consulta=consulta+" ruta_img_marca ilike '%"+val->getRutaImagenMarca()+"%' AND ";
        }

        if(!val->getCodigoMoneda().isNull())
        {
            consulta=consulta+" codigo_moneda ilike '%"+val->getCodigoMoneda()+"%' AND ";
        }
        if(!val->getNombreMoneda().isNull())
        {
            consulta=consulta+" nombre_moneda ilike '%"+val->getNombreMoneda()+"%' AND ";
        }
        if(!val->getSimboloMoneda().isNull())
        {
            consulta=consulta+" simbolo_moneda ilike '%"+val->getSimboloMoneda()+"%' AND ";
        }
        if(!val->getRutaImagenMoneda().isNull())
        {
            consulta=consulta+" ruta_img_moneda ilike '%"+val->getRutaImagenMoneda()+"%' AND ";
        }
        if((!val->getPrecio()==-1))
        {
            consulta=consulta+" precio >="+val->getPrecio()+" AND ";
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
          resp->setCantidadMin(query.value(4).toDouble());
          resp->setUnico(query.value(5).toString());

          resp->setCodigoImagen(query.value(6).toString());
          resp->setRutaImagen(query.value(7).toString());
          resp->setVigencia(query.value(8).toString());

          resp->setCodigoUnidad(query.value(9).toString());
          resp->setNombreUnidad(query.value(10).toString());
          resp->setSimboloUnidad(query.value(11).toString());
          resp->setRutaImagenUnidad(query.value(12).toString());

          resp->setCodigoTipo(query.value(13).toString());
          resp->setNombreTipo(query.value(14).toString());
          resp->setRutaImagenTipo(query.value(15).toString());

          resp->setCodigoModelo(query.value(16).toString());
          resp->setNombreModelo(query.value(17).toString());
          resp->setRutaImagenModelo(query.value(18).toString());

          resp->setCodigoMarca(query.value(19).toString());
          resp->setNombreMarca(query.value(20).toString());
          resp->setRutaImagenMarca(query.value(21).toString());

          resp->setCodigoMoneda(query.value(22).toString());
          resp->setNombreMoneda(query.value(23).toString());
          resp->setSimboloMoneda(query.value(24).toString());
          resp->setRutaImagenMoneda(query.value(25).toString());
          resp->setPrecio(query.value(26).toDouble());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
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
        consulta=consulta+" codigo_externo ilike '%"+val->getCodigoExterno()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!(val->getCantidadMin()==(-1)))
    {
        consulta=consulta+" cantidad_min >= "+QString::number(val->getCantidadMin())+" AND ";
    }
    if(!val->getUnico().isNull())
    {
        consulta=consulta+" unico ilike '%"+val->getUnico()+"%' AND ";
    }
    if(!val->getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen ilike '%"+val->getCodigoImagen()+"%' AND ";
    }
    if(!val->getRutaImagen().isNull())
    {
        consulta=consulta+" ruta_img ilike '%"+val->getRutaImagen()+"%' AND ";
    }
    if(!val->getVigencia().isNull())
    {
        consulta=consulta+" vigencia ilike '%"+val->getVigencia()+"%' AND ";
    }
    if(!val->getCodigoUnidad().isNull())
    {
        consulta=consulta+" codigo_unidad ilike '%"+val->getCodigoUnidad()+"%' AND ";
    }
    if(!val->getNombreUnidad().isNull())
    {
        consulta=consulta+" nombre_unidad ilike '%"+val->getNombreUnidad()+"%' AND ";
    }

    if(!val->getSimboloUnidad().isNull())
    {
        consulta=consulta+" simbolo ilike '%"+val->getSimboloUnidad()+"%' AND ";
    }
    if(!val->getRutaImagenUnidad().isNull())
    {
        consulta=consulta+" ruta_img_unidad ilike '%"+val->getRutaImagenUnidad()+"%' AND ";
    }
    if(!val->getCodigoTipo().isNull())
    {
        consulta=consulta+" codigo_tipo ilike '%"+val->getCodigoTipo()+"%' AND ";
    }
    if(!val->getNombreTipo().isNull())
    {
        consulta=consulta+" nombre_tipo ilike '%"+val->getNombreTipo()+"%' AND ";
    }
    if(!val->getRutaImagenTipo().isNull())
    {
        consulta=consulta+" ruta_img_tipo ilike '%"+val->getRutaImagenTipo()+"%' AND ";
    }
/**/
    if(!val->getCodigoModelo().isNull())
    {
        consulta=consulta+" codigo_modelo ilike '%"+val->getCodigoModelo()+"%' AND ";
    }
    if(!val->getNombreModelo().isNull())
    {
        consulta=consulta+" nombre_modelo ilike '%"+val->getNombreModelo()+"%' AND ";
    }
    if(!val->getRutaImagenModelo().isNull())
    {
        consulta=consulta+" ruta_img_modelo ilike '%"+val->getRutaImagenModelo()+"%' AND ";
    }
    if(!val->getCodigoMarca().isNull())
    {
        consulta=consulta+" codigo_marca ilike '%"+val->getCodigoMarca()+"%' AND ";
    }
    if(!val->getNombreMarca().isNull())
    {
        consulta=consulta+" nombre_marca ilike '%"+val->getNombreMarca()+"%' AND ";
    }
    if(!val->getRutaImagenMarca().isNull())
    {
        consulta=consulta+" ruta_img_marca ilike '%"+val->getRutaImagenMarca()+"%' AND ";
    }

    if(!val->getCodigoMoneda().isNull())
    {
        consulta=consulta+" codigo_moneda ilike '%"+val->getCodigoMoneda()+"%' AND ";
    }
    if(!val->getNombreMoneda().isNull())
    {
        consulta=consulta+" nombre_moneda ilike '%"+val->getNombreMoneda()+"%' AND ";
    }
    if(!val->getSimboloMoneda().isNull())
    {
        consulta=consulta+" simbolo_moneda ilike '%"+val->getSimboloMoneda()+"%' AND ";
    }
    if(!val->getRutaImagenMoneda().isNull())
    {
        consulta=consulta+" ruta_img_moneda ilike '%"+val->getRutaImagenMoneda()+"%' AND ";
    }
    if(!(val->getPrecio()==-1))
    {
        consulta=consulta+" precio >= "+val->getPrecio()+" AND ";
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
        consulta="SELECT codigo, codigo_interno, codigo_externo, nombre, cantidad_min, "
               " unico, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                " simbolo, ruta_img_unidad, codigo_tipo, nombre_tipo, ruta_img_tipo, "
                " codigo_modelo, nombre_modelo, ruta_img_modelo, codigo_marca, "
                " nombre_marca, ruta_img_marca, codigo_moneda, nombre_moneda, simbolo_moneda, "
                " ruta_img_moneda , precio"
           " FROM vista_detalle_articulo;";
}
else
 {

        consulta="SELECT codigo, codigo_interno, codigo_externo, nombre, cantidad_min, "
               " unico, codigo_imagen, ruta_img, vigencia, codigo_unidad, nombre_unidad, "
                " simbolo, ruta_img_unidad, codigo_tipo, nombre_tipo, ruta_img_tipo, "
                " codigo_modelo, nombre_modelo, ruta_img_modelo, codigo_marca, "
                " nombre_marca, ruta_img_marca, codigo_moneda, nombre_moneda, simbolo_moneda, "
                " ruta_img_moneda, precio "
           " FROM vista_detalle_articulo WHERE ";



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
           consulta=consulta+" codigo_externo ilike '%"+valor.getCodigoExterno()+"%' AND ";
       }
       if(!valor.getNombre().isNull())
       {
           consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
       }
       if(!(valor.getCantidadMin()==(-1)))
       {
           consulta=consulta+" cantidad_min >= "+QString::number(valor.getCantidadMin())+" AND ";
       }
       if(!valor.getUnico().isNull())
       {
           consulta=consulta+" unico ilike '%"+valor.getUnico()+"%' AND ";
       }
       if(!valor.getCodigoImagen().isNull())
       {
           consulta=consulta+" codigo_imagen ilike '%"+valor.getCodigoImagen()+"%' AND ";
       }
       if(!valor.getRutaImagen().isNull())
       {
           consulta=consulta+" ruta_img ilike '%"+valor.getRutaImagen()+"%' AND ";
       }
       if(!valor.getVigencia().isNull())
       {
           consulta=consulta+" vigencia ilike '%"+valor.getVigencia()+"%' AND ";
       }
       if(!valor.getCodigoUnidad().isNull())
       {
           consulta=consulta+" codigo_unidad ilike '%"+valor.getCodigoUnidad()+"%' AND ";
       }
       if(!valor.getNombreUnidad().isNull())
       {
           consulta=consulta+" nombre_unidad ilike '%"+valor.getNombreUnidad()+"%' AND ";
       }

       if(!valor.getSimboloUnidad().isNull())
       {
           consulta=consulta+" simbolo ilike '%"+valor.getSimboloUnidad()+"%' AND ";
       }
       if(!valor.getRutaImagenUnidad().isNull())
       {
           consulta=consulta+" ruta_img_unidad ilike '%"+valor.getRutaImagenUnidad()+"%' AND ";
       }
       if(!valor.getCodigoTipo().isNull())
       {
           consulta=consulta+" codigo_tipo ilike '%"+valor.getCodigoTipo()+"%' AND ";
       }
       if(!valor.getNombreTipo().isNull())
       {
           consulta=consulta+" nombre_tipo ilike '%"+valor.getNombreTipo()+"%' AND ";
       }
       if(!valor.getRutaImagenTipo().isNull())
       {
           consulta=consulta+" ruta_img_tipo ilike '%"+valor.getRutaImagenTipo()+"%' AND ";
       }
   /**/
       if(!valor.getCodigoModelo().isNull())
       {
           consulta=consulta+" codigo_modelo ilike '%"+valor.getCodigoModelo()+"%' AND ";
       }
       if(!valor.getNombreModelo().isNull())
       {
           consulta=consulta+" nombre_modelo ilike '%"+valor.getNombreModelo()+"%' AND ";
       }
       if(!valor.getRutaImagenModelo().isNull())
       {
           consulta=consulta+" ruta_img_modelo ilike '%"+valor.getRutaImagenModelo()+"%' AND ";
       }
       if(!valor.getCodigoMarca().isNull())
       {
           consulta=consulta+" codigo_marca ilike '%"+valor.getCodigoMarca()+"%' AND ";
       }
       if(!valor.getNombreMarca().isNull())
       {
           consulta=consulta+" nombre_marca ilike '%"+valor.getNombreMarca()+"%' AND ";
       }
       if(!valor.getRutaImagenMarca().isNull())
       {
           consulta=consulta+" ruta_img_marca ilike '%"+valor.getRutaImagenMarca()+"%' AND ";
       }

       if(!valor.getCodigoMoneda().isNull())
       {
           consulta=consulta+" codigo_moneda ilike '%"+valor.getCodigoMoneda()+"%' AND ";
       }
       if(!valor.getNombreMoneda().isNull())
       {
           consulta=consulta+" nombre_moneda ilike '%"+valor.getNombreMoneda()+"%' AND ";
       }
       if(!valor.getSimboloMoneda().isNull())
       {
           consulta=consulta+" simbolo_moneda ilike '%"+valor.getSimboloMoneda()+"%' AND ";
       }
       if(!valor.getRutaImagenMoneda().isNull())
       {
           consulta=consulta+" ruta_img_moneda ilike '%"+valor.getRutaImagenMoneda()+"%' AND ";
       }
       if(!(valor.getPrecio()==-1))
       {
           consulta=consulta+" precio >= "+valor.getPrecio()+" AND ";
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
