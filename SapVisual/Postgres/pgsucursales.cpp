#include "pgsucursales.h"

PgSucursales::PgSucursales()
{

}

bool PgSucursales::Borrar(Sucursales valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM sucursales WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgSucursales::Insertar(Sucursales valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO sucursales("
                    "codigo, nombre, direccion, telefono, fecha_ingreso)"
                    "VALUES (?, ?, ?, ?, ?);");

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

bool PgSucursales::Actualizar(Sucursales Antiguo, Sucursales Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE sucursales SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }

    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getDireccion().isNull())
    {
        consulta=consulta+", direccion='"+Nuevo.getDireccion()+"'";
    }
    if(!Nuevo.getTelefono().isNull())
    {
        consulta=consulta+", telefono='"+Nuevo.getTelefono()+"'";
    }
    if(!Nuevo.getRuc().isNull())
    {
        consulta=consulta+", ruc='"+Nuevo.getRuc()+"'";
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
    if(!Antiguo.getDireccion().isNull())
    {
        consulta=consulta+"(direccion='"+Antiguo.getDireccion()+"') AND ";
    }
    if(!Antiguo.getTelefono().isNull())
    {
        consulta=consulta+"(telefono='"+Antiguo.getTelefono()+"') AND ";
    }
    if(!Antiguo.getRuc().isNull())
    {
        consulta=consulta+"(ruc='"+Antiguo.getRuc()+"') AND ";
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

Sucursales PgSucursales::Buscar(Sucursales valor)
{
    QString consulta;

        consulta="SELECT codigo, nombre, direccion, telefono, ruc, codigo_imagen, ruta_img "
                "FROM vista_detalle_modelo WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+" direcion ilike '%"+valor.getDireccion()+"%' AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+valor.getTelefono()+"%' AND ";
    }
    if(!valor.getRuc().isNull())
    {
        consulta=consulta+" ruc ilike '%"+valor.getRuc()+"%' AND ";
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
    Sucursales* resp=new Sucursales();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setDireccion(query.value(2).toString());
          resp->setTelefono(query.value(3).toString());
          resp->setRuc(query.value(4).toString());
          resp->setCodigoImagen(query.value(5).toString());
          resp->setRutaImagen(query.value(6).toString());
          flag=false;
      }

       return *resp;
}

QMap<QString, ObjetoMaestro *> *PgSucursales::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Sucursales* val=(Sucursales*)(valor);
    QString consulta;

    if(Tipo==TODO)
    {
        consulta="SELECT codigo, nombre, direccion, telefono, ruc, codigo_imagen, ruta_img "
                "FROM vista_detalle_sucursales";

    }
    else
    {
        consulta="SELECT codigo, nombre, direccion, telefono, ruc, codigo_imagen, ruta_img "
                "FROM vista_detalle_sucursales WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+" direccion ilike '%"+val->getDireccion()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getRuc().isNull())
    {
        consulta=consulta+" ruc ilike '%"+val->getRuc()+"%' AND ";
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
          Sucursales* resp=new Sucursales();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setDireccion(query.value(2).toString());
          resp->setTelefono(query.value(3).toString());
          resp->setRuc(query.value(4).toString());
          resp->setCodigoImagen(query.value(5).toString());
          resp->setRutaImagen(query.value(6).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgSucursales::Contar()
{
    QString consulta="SELECT count(*) FROM sucursales";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgSucursales::ContarConsulta(ObjetoMaestro *valor)
{
    Sucursales* val=(Sucursales*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_sucursales WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+" direccion ilike '%"+val->getDireccion()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getRuc().isNull())
    {
        consulta=consulta+" ruc ilike '%"+val->getRuc()+"%' AND ";
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

QSqlQueryModel *PgSucursales::BuscarTabla(Sucursales valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

         if(tipo==TODO)
         {
             consulta="SELECT codigo, nombre, direccion, telefono, ruc, codigo_imagen, ruta_img "
                     "FROM vista_detalle_sucursales";
         }
         else
         {
             consulta="SELECT codigo, nombre, direccion, telefono, ruc, codigo_imagen, ruta_img "
                           "FROM vista_detalle_sucursales where";

         if(!valor.getCodigo().isNull())
         {
             consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
         }

         if(!valor.getNombre().isNull())
         {
             consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
         }
         if(!valor.getDireccion().isNull())
         {
             consulta=consulta+" direccion ilike '%"+valor.getDireccion()+"%' AND ";
         }
         if(!valor.getTelefono().isNull())
         {
             consulta=consulta+" telefono ilike '%"+valor.getTelefono()+"%' AND ";
         }
         if(!valor.getRuc().isNull())
         {
             consulta=consulta+" ruc ilike '%"+valor.getRuc()+"%' AND ";
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
         }
         consulta=consulta+Extra;

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery(consulta);

         qDebug()<<consulta;
         return model;
}

