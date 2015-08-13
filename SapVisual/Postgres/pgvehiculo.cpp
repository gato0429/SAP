#include "pgvehiculo.h"

PgVehiculo::PgVehiculo()
{

}

bool PgVehiculo::Borrar(Vehiculo valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM vehiculo WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgVehiculo::Insertar(Vehiculo valor)
{
    QSqlQuery query;
      query.prepare("INSERT INTO vehiculo( codigo, placa, placa_antigua, fecha_ingreso)"
           " VALUES (?, ?, ?, ?);");

      query.addBindValue(valor.getPlaca());
      query.addBindValue(valor.getPlacaAntigua());

      bool flag=query.exec();
      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;
}

bool PgVehiculo::Actualizar(Vehiculo Antiguo, Vehiculo Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE marca SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }

    if(!Nuevo.getPlaca().isNull())
    {
        consulta=consulta+", placa='"+Nuevo.getPlaca()+"'";
    }
    if(!Nuevo.getPlacaAntigua().isNull())
    {
        consulta=consulta+", placa_antigua='"+Nuevo.getPlacaAntigua()+"'";
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

    if(!Antiguo.getPlaca().isNull())
    {
        consulta=consulta+"(placa='"+Antiguo.getPlaca()+"') AND ";
    }
    if(!Antiguo.getPlacaAntigua().isNull())
    {
        consulta=consulta+"(placa_antigua='"+Antiguo.getPlacaAntigua()+"') AND ";
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

Vehiculo PgVehiculo::Buscar(Vehiculo valor)
{
    QString consulta;

        consulta="SELECT codigo, placa, placa_antigua, fecha_ingreso"
                "FROM vehiculo ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getPlaca().isNull())
    {
        consulta=consulta+" placa ilike '%"+valor.getPlaca()+"%' AND ";
    }
    if(!valor.getPlacaAntigua().isNull())
    {
        consulta=consulta+" placa_antigua ilike '%"+valor.getPlacaAntigua()+"%' AND ";
    }
    if(!valor.getFechaIngreso().isNull())
    {
        consulta=consulta+" fecha_ingreso ilike '%"+valor.getFechaIngreso()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    Vehiculo* resp=new Vehiculo();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setPlaca(query.value(1).toString());
          resp->setPlacaAntigua(query.value(2).toString());
          resp->setFechaIngreso(query.value(3).toString());
          flag=false;
      }

       return *resp;

}

QMap<QString, ObjetoMaestro *> *PgVehiculo::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    MapaRepisaGlobal=new QList<ObjetoMaestro*>();

    Vehiculo* val=(Vehiculo*)(valor);
    QString consulta;

    if(tipo==TODO)
    {
        consulta="SELECT codigo, placa, placa_antigua, fecha_ingreso"
                "FROM vehiculo;";

    }
    else
    {
        consulta="SELECT codigo, placa, placa_antigua, fecha_ingreso"
                "FROM vehiculo";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getPlaca().isNull())
    {
        consulta=consulta+" placa ilike '%"+val->getPlaca()+"%' AND ";
    }
    if(!val->getPlacaAntigua().isNull())
    {
        consulta=consulta+" placa_antigua ilike '%"+val->getPlacaAntigua()+"%' AND ";
    }
    if(!val->getFechaIngreso().isNull())
    {
        consulta=consulta+" fecha_ingreso ilike '%"+val->getFechaIngreso()+"%' AND ";
    }

    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;
    qDebug()<<consulta;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
         Vehiculo* resp=new Vehiculo();
          resp->setCodigo(query.value(0).toString());
          resp->setPlaca(query.value(1).toString());
          resp->setPlacaAntigua(query.value(2).toString());
          resp->setFechaIngreso(query.value(3).toString());


          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
          MapaRepisaGlobal->push_front((ObjetoMaestro*)resp);
      }


    return salida;
}

qint64 PgVehiculo::Contar()
{
    QString consulta="SELECT count(*) FROM vehiculo";
    qint64 num=0;

    QSqlQuery query(consulta);

      while (query.next() )
      {
        num=query.value(0).toLongLong();
        return num;
      }

  return num;
}

qint64 PgVehiculo::ContarConsulta(ObjetoMaestro *valor)
{
    Vehiculo* val=(Vehiculo*)(valor);
    QString consulta;

    consulta="SELECT codigo, placa, placa_antigua, fecha_ingreso"
            "FROM vehiculo ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo ilike '%"+val->getCodigo()+"%' AND ";
    }

    if(!val->getPlaca().isNull())
    {
        consulta=consulta+" placa ilike '%"+val->getPlaca()+"%' AND ";
    }
    if(!val->getPlacaAntigua().isNull())
    {
        consulta=consulta+" placa_antigua ilike '%"+val->getPlacaAntigua()+"%' AND ";
    }
    if(!val->getFechaIngreso().isNull())
    {
        consulta=consulta+" fecha_ingreso ilike '%"+val->getFechaIngreso()+"%' AND ";
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

QSqlQueryModel *PgVehiculo::BuscarTabla(Vehiculo valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

     if(tipo==TODO)
     {
         consulta="SELECT codigo, placa, placa_antigua, fecha_ingreso"
                " FROM vehiculo";
     }
     else
     {
         consulta="SELECT codigo, placa, placa_antigua, fecha_ingreso"
                 "FROM vehiculo";

     if(!valor.getCodigo().isNull())
     {
         consulta=consulta+" codigo ilike '%"+valor.getCodigo()+"%' AND ";
     }

     if(!valor.getPlaca().isNull())
     {
         consulta=consulta+" placa ilike '%"+valor.getPlaca()+"%' AND ";
     }
     if(!valor.getPlacaAntigua().isNull())
     {
         consulta=consulta+" placa_antigua ilike '%"+valor.getPlacaAntigua()+"%' AND ";
     }
     if(!valor.getFechaIngreso().isNull())
     {
         consulta=consulta+" fecha_ingreso like '%"+valor.getFechaIngreso()+"%' AND ";
     }

     consulta.replace(consulta.size()-5,5," ");
     }
     consulta=consulta+Extra;

     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery(consulta);

     qDebug()<<consulta;

     return model;
}

