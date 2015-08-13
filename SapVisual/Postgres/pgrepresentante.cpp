#include "pgrepresentante.h"

PgRepresentante::PgRepresentante()
{

}

bool PgRepresentante::Borrar(Representante valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM representante WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgRepresentante::Insertar(Representante valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO representate("
                    "codigo, nombre, dni, telefono, correo, codigo_cliente, nombre_cliente, codigo_imagen, ruta_imagen)"
            "VALUES (?, ?, ?, ?, ?, ?);");

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

bool PgRepresentante::Actualizar(Representante Antiguo, Representante Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE representante SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }

    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getDni().isNull())
    {
        consulta=consulta+", dni='"+Nuevo.getDni()+"'";
    }
    if(!Nuevo.getTelefono().isNull())
    {
        consulta=consulta+", telefono='"+Nuevo.getTelefono()+"'";
    }
    if(!Nuevo.getCorreo().isNull())
    {
        consulta=consulta+", correo='"+Nuevo.getCorreo()+"'";
    }
    if(!Nuevo.getCodigoCliente().isNull())
    {
        consulta=consulta+", codigo_cliente='"+Nuevo.getCodigoCliente()+"'";
    }
    if(!Nuevo.getNombreCliente().isNull())
    {
        consulta=consulta+", nombre_cliente='"+Nuevo.getNombreCliente()+"'";
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
        consulta=consulta+", codigo='"+Antiguo.getCodigo()+"'";
    }

    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Antiguo.getNombre()+"'";
    }
    if(!Antiguo.getDni().isNull())
    {
        consulta=consulta+", dni='"+Antiguo.getDni()+"'";
    }
    if(!Antiguo.getTelefono().isNull())
    {
        consulta=consulta+", telefono='"+Antiguo.getTelefono()+"'";
    }
    if(!Antiguo.getCorreo().isNull())
    {
        consulta=consulta+", correo='"+Antiguo.getCorreo()+"'";
    }
    if(!Antiguo.getCodigoCliente().isNull())
    {
        consulta=consulta+", codigo_cliente='"+Antiguo.getCodigoCliente()+"'";
    }
    if(!Antiguo.getNombreCliente().isNull())
    {
        consulta=consulta+", nombre_cliente='"+Antiguo.getNombreCliente()+"'";
    }
    if(!Antiguo.getCodigoImagen().isNull())
    {
        consulta=consulta+", codigo_imagen='"+Antiguo.getCodigoImagen()+"'";
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

Representante PgRepresentante::Buscar(Representante valor)
{
    QString consulta;

        consulta="SELECT codigo, nombre, dni, telefono, correo, codigo_cliente, nombre_cliente, codigo_imagen, ruta_img "
                "FROM vista_detalle_representante WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getDni().isNull())
    {
        consulta=consulta+" dni ilike '%"+valor.getDni()+"%' AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+valor.getTelefono()+"%' AND ";
    }
    if(!valor.getCorreo().isNull())
    {
        consulta=consulta+" correo ilike '%"+valor.getCorreo()+"%' AND ";
    }
    if(!valor.getCodigoCliente().isNull())
    {
        consulta=consulta+" codigo_cliente ilike '%"+valor.getCodigoCliente()+"%' AND ";
    }
    if(!valor.getNombreCliente().isNull())
    {
        consulta=consulta+" nombre_cliente ilike '%"+valor.getNombreCliente()+"%' AND ";
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
    Representante* resp=new Representante();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setDni(query.value(2).toString());
          resp->setTelefono(query.value(3).toString());
          resp->setCorreo(query.value(4).toString());
          resp->setCodigoCliente(query.value(5).toString());
          resp->setNombreCliente(query.value(6).toString());
          resp->setCodigoImagen(query.value(7).toString());
          resp->setRutaImagen(query.value(8).toString());

          flag=false;
      }

       return *resp;
}

QMap<QString, ObjetoMaestro *> *PgRepresentante::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Representante* val=(Representante*)(valor);
    QString consulta;

    if(Tipo==TODO)
    {
        consulta="SELECT codigo, nombre, dni, telefono, correo, codigo_cliente, nombre_cliente, codigo_imagen, ruta_img "
                "FROM vista_detalle_representante";

    }
    else
    {
        consulta="SELECT codigo, nombre, dni, telefono, correo, codigo_cliente, nombre_cliente, codigo_imagen, ruta_img "
                "FROM vista_detalle_representante WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDni().isNull())
    {
        consulta=consulta+" dni ilike '%"+val->getDni()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getCorreo().isNull())
    {
        consulta=consulta+" correo ilike '%"+val->getCorreo()+"%' AND ";
    }
    if(!val->getCodigoCliente().isNull())
    {
        consulta=consulta+" codigo_cliente ilike '%"+val->getCodigoCliente()+"%' AND ";
    }
    if(!val->getNombreCliente().isNull())
    {
        consulta=consulta+" nombre_cliente ilike '%"+val->getNombreCliente()+"%' AND ";
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
          Representante* resp=new Representante();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setDni(query.value(2).toString());
          resp->setTelefono(query.value(3).toString());
          resp->setCorreo(query.value(4).toString());
          resp->setCodigoCliente(query.value(5).toString());
          resp->setNombreCliente(query.value(6).toString());
          resp->setCodigoImagen(query.value(7).toString());
          resp->setRutaImagen(query.value(8).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgRepresentante::Contar()
{
    QString consulta="SELECT count(*) FROM representante";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}


qint64 PgRepresentante::ContarConsulta(ObjetoMaestro *valor)
{
    Representante* val=(Representante*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            "FROM vista_detalle_representante WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre ilike '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDni().isNull())
    {
        consulta=consulta+" dni ilike '%"+val->getDni()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+val->getDni()+"%' AND ";
    }
    if(!val->getCorreo().isNull())
    {
        consulta=consulta+" correo ilike '%"+val->getCorreo()+"%' AND ";
    }
    if(!val->getCodigoCliente().isNull())
    {
        consulta=consulta+" codigo_cliente ilike '%"+val->getCodigoCliente()+"%' AND ";
    }
    if(!val->getNombreCliente().isNull())
    {
        consulta=consulta+" nombre_cliente ilike '%"+val->getNombreCliente()+"%' AND ";
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

QSqlQueryModel *PgRepresentante::BuscarTabla(Representante valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

         if(tipo==TODO)
         {
             consulta="SELECT codigo, nombre, dni, telefono, correo, codigo_cliente, nombre_cliente, codigo_imagen, ruta_img "
                     "FROM vista_detalle_representante";
         }
         else
         {
             consulta="SELECT codigo, nombre, dni, telefono, correo, codigo_cliente, nombre_cliente, codigo_imagen, ruta_img "
                           "FROM vista_detalle_representante where";

         if(!valor.getCodigo().isNull())
         {
             consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
         }

         if(!valor.getNombre().isNull())
         {
             consulta=consulta+" nombre ilike '%"+valor.getNombre()+"%' AND ";
         }
         if(!valor.getDni().isNull())
         {
             consulta=consulta+" dni ilike '%"+valor.getDni()+"%' AND ";
         }
         if(!valor.getTelefono().isNull())
         {
             consulta=consulta+" telefono ilike '%"+valor.getTelefono()+"%' AND ";
         }
         if(!valor.getCorreo().isNull())
         {
             consulta=consulta+" correo ilike '%"+valor.getCorreo()+"%' AND ";
         }
         if(!valor.getCodigoCliente().isNull())
         {
             consulta=consulta+" codigo_cliente ilike '%"+valor.getCodigoCliente()+"%' AND ";
         }
         if(!valor.getNombreCliente().isNull())
         {
             consulta=consulta+" nombre_cliente ilike '%"+valor.getNombreCliente()+"%' AND ";
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

