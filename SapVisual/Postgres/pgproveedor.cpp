#include "pgproveedor.h"

PgProveedor::PgProveedor()
{

}

bool PgProveedor::Borrar(Proveedor valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM proveedor WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;

}

bool PgProveedor::Insertar(Proveedor valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO proveedor("
                   " codigo, tipo, nombre, direccion, telefono, email, web, estado, "
                    "fecha_ingreso)"
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?,"
                  "  ?);");

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

bool PgProveedor::Actualizar(Proveedor Antiguo, Proveedor Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE proveedor SET ";

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
    if(!Nuevo.getDireccion().isNull())
    {
        consulta=consulta+", direccion='"+Nuevo.getDireccion()+"'";
    }
    if(!Nuevo.getTelefono().isNull())
    {
        consulta=consulta+", telefono='"+Nuevo.getTelefono()+"'";
    }
    if(!Nuevo.getEmail().isNull())
    {
        consulta=consulta+", email='"+Nuevo.getEmail()+"'";
    }
    if(!Nuevo.getWeb().isNull())
    {
        consulta=consulta+", web='"+Nuevo.getWeb()+"'";
    }
    /*if(!Nuevo.getEstado().isNull())
    {
        consulta=consulta+", estado='"+Nuevo.getEstado()+"'";
    }*/
    if(!Nuevo.getFechaIngreso().isNull())
    {
        consulta=consulta+", fecha_ingreso='"+Nuevo.getTipo()+"'";
    }
    if(!Nuevo.getDocumento().isNull())
    {
        consulta=consulta+", documeto='"+Nuevo.getDocumento()+"'";
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
        consulta=consulta+"(tipo='"+Antiguo.getTipo()+"') AND ";
    }
    if(!Antiguo.getDireccion().isNull())
    {
        consulta=consulta+"(direccion='"+Antiguo.getDireccion()+"') AND ";
    }
    if(!Antiguo.getTelefono().isNull())
    {
        consulta=consulta+"(telefono='"+Antiguo.getTelefono()+"') AND ";
    }
    if(!Antiguo.getEmail().isNull())
    {
        consulta=consulta+"(email='"+Antiguo.getEmail()+"') AND ";
    }
    if(!Antiguo.getEmail().isNull())
    {
        consulta=consulta+"(email='"+Antiguo.getEmail()+"') AND ";
    }
    if(!Antiguo.getWeb().isNull())
    {
        consulta=consulta+"(web='"+Antiguo.getWeb()+"') AND ";
    }
   /*if(!Antiguo.getEstado().isNull())
    {
       consulta=consulta+"(estado='"+Antiguo.getEstado()+"') AND ";
    }*/
   /* if(!Antiguo.getFechaIngreso().isNull())
    {
        consulta=consulta+"(fecha_ingreso='"+Antiguo.getFechaIngreso()+"') AND ";
    }*/
    if(!Antiguo.getDocumento().isNull())
    {
        consulta=consulta+"(documento='"+Antiguo.getDocumento()+"') AND ";
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

Proveedor PgProveedor::Buscar(Proveedor valor)
{
    QString consulta;
        consulta="SELECT codigo, tipo, nombre, direccion, telefono, email, web, estado, "
          "      fecha_ingreso"
           "FROM proveedor ";


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
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+" direccion ilike '%"+valor.getDireccion()+"%' AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+valor.getTelefono()+"%' AND ";
    }
    if(!valor.getEmail().isNull())
    {
        consulta=consulta+" email ilike '%"+valor.getEmail()+"%' AND ";
    }
    if(!valor.getWeb().isNull())
    {
        consulta=consulta+" web ilike '%"+valor.getWeb()+"%' AND ";
    }
    /*if(!valor.getEstado().isNull())
    {
        consulta=consulta+" estado ilike '%"+valor.getEstado()+"%' AND ";
    }*/
   /* if(!valor.getFechaIngreso().isNull())
    {
        consulta=consulta+" fecha_ingreso ilike '%"+valor.getFechaIngreso()+"%' AND ";
    }*/
    if(!valor.getDocumento().isNull())
    {
        consulta=consulta+" documento ilike '%"+valor.getDocumento()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    Proveedor* resp=new Proveedor();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoImagen(query.value(2).toString());
          resp->setRutaImagen(query.value(3).toString());
          flag=false;
      }

       return *resp;
}

QMap<QString, ObjetoMaestro *> *PgProveedor::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA Tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Proveedor* val=(Proveedor*)(valor);
    QString consulta;

    if(Tipo==TODO)
    {
        consulta="SELECT codigo, tipo, nombre, direccion, telefono, email, web, estado,"
                 "fecha_ingreso"
                 " FROM proveedor;";

    }
    else
    {
        consulta="SELECT codigo, tipo, nombre, direccion, telefono, email, web, estado,"
                 "fecha_ingreso"
                 " FROM proveedor";
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
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+" direccion ilike '%"+val->getDireccion()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getEmail().isNull())
    {
        consulta=consulta+" email ilike '%"+val->getEmail()+"%' AND ";
    }
    if(!val->getWeb().isNull())
    {
        consulta=consulta+" web ilike '%"+val->getWeb()+"%' AND ";
    }
    /*if(!val->getEstado().isNull())
    {
        consulta=consulta+" estado ilike '%"+val->getEstado()+"%' AND ";
    }*/
    /*if(!val->getFechaIngreso().isNull())
    {
        consulta=consulta+" fecha_ingreso ilike '%"+val->getFechaIngreso()+"%' AND ";
    }*/
    if(!val->getDocumento().isNull())
    {
        consulta=consulta+" documento ilike '%"+val->getDocumento()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;
    qDebug()<<consulta;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
          Proveedor* resp=new Proveedor();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setCodigoImagen(query.value(2).toString());
          resp->setRutaImagen(query.value(3).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgProveedor::Contar()
{
    QString consulta="SELECT count(*) FROM proveedor";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgProveedor::ContarConsulta(ObjetoMaestro *valor)
{
    Proveedor* val=(Proveedor*)(valor);
    QString consulta;

    consulta="SELECT codigo, tipo, nombre, direccion, telefono, email, web, estado,"
        "    fecha_ingreso"
       "FROM proveedor ";

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
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+" direccion ilike '%"+val->getDireccion()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono ilike '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getEmail().isNull())
    {
        consulta=consulta+" email ilike '%"+val->getEmail()+"%' AND ";
    }
    if(!val->getWeb().isNull())
    {
        consulta=consulta+" web ilike '%"+val->getWeb()+"%' AND ";
    }
    /*if(!val->getEstado().isNull())
    {
        consulta=consulta+" estado ilike '%"+val->getEstado()+"%' AND ";
    }*/
    /*if(!val->getFechaIngreso().isNull())
    {
        consulta=consulta+" fecha_ingreso ilike '%"+val->getFechaIngreso()+"%' AND ";
    }*/
    if(!val->getDocumento().isNull())
    {
        consulta=consulta+" documento ilike '%"+val->getDocumento()+"%' AND ";
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

QSqlQueryModel *PgProveedor::BuscarTabla(Proveedor valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

         if(tipo==TODO)
         {
             consulta="SELECT codigo, tipo, nombre, direccion, telefono, email, web, estado,"
                      "    fecha_ingreso"
                     "FROM proveedor ";

         }
         else
         {
             consulta="SELECT codigo, tipo, nombre, direccion, telefono, email, web, estado,"
                      "    fecha_ingreso"
                     "FROM proveedor ";

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
         if(!valor.getDireccion().isNull())
         {
             consulta=consulta+" direccion ilike '%"+valor.getDireccion()+"%' AND ";
         }
         if(!valor.getTelefono().isNull())
         {
             consulta=consulta+" telefono ilike '%"+valor.getTelefono()+"%' AND ";
         }
         if(!valor.getEmail().isNull())
         {
             consulta=consulta+" email ilike '%"+valor.getEmail()+"%' AND ";
         }
         if(!valor.getWeb().isNull())
         {
             consulta=consulta+" web ilike '%"+valor.getWeb()+"%' AND ";
         }
         /*if(!valor.getEstado().isNull())
         {
             consulta=consulta+" estado ilike '%"+valor.getEstado()+"%' AND ";
         }*/
         if(!valor.getFechaIngreso().isNull())
       /*  {
             consulta=consulta+" fecha_ingreso ilike '%"+valor.getFechaIngreso()+"%' AND ";
         }*/
         if(!valor.getDocumento().isNull())
         {
             consulta=consulta+" documento ilike '%"+valor.getDocumento()+"%' AND ";
         }


         consulta.replace(consulta.size()-5,5," ");
         }
         consulta=consulta+Extra;

         QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery(consulta);

         qDebug()<<consulta;
         return model;
}

