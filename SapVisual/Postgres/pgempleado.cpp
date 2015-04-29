#include "pgempleado.h"

PgEmpleado::PgEmpleado()
{
}

bool PgEmpleado::Borrar(Empleado valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM empleado WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;

}

bool PgEmpleado::Insertar(Empleado valor)
{

    QSqlQuery query;
      query.prepare("INSERT INTO empleado("
                    " nombre, direccion, email, descuento, fecha_ingreso,dni,telefono,sexo,codigo_interno )"
                    " VALUES (?, ?, ?, ?, ?, ?,?,?,?)");


      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getDireccion());
      query.addBindValue(valor.getEmail());
      query.addBindValue(valor.getDescuento());
      query.addBindValue(valor.getFechaIngreso());
      query.addBindValue(valor.getDni());
      query.addBindValue(valor.getTelefono());
      query.addBindValue(valor.getSexo());
      query.addBindValue(valor.getCodigoInterno());

      bool flag= query.exec();

      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;

}

bool PgEmpleado::Actualizar(Empleado Antiguo, Empleado Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE empleado SET ";

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
    if(!Nuevo.getEmail().isNull())
    {
        consulta=consulta+", email='"+Nuevo.getEmail()+"'";
    }

    if(!(Nuevo.getDescuento()==(-1)))
    {
        consulta=consulta+", descuento='"+QString::number(Nuevo.getDescuento())+"'";
    }
    if(!(Nuevo.getFechaIngreso()==QDate(1,1,1)))
    {
        consulta=consulta+", fecha_ingreso='"+Nuevo.getFechaIngreso().toString("dd-MM-yyyy")+"'";
    }

    if(!(Nuevo.getDni().isNull()))
    {
        consulta=consulta+", dni='"+Nuevo.getDni()+"'";
    }
    if(!(Nuevo.getTelefono().isNull()))
    {
        consulta=consulta+", telefono='"+Nuevo.getTelefono()+"'";
    }
    if(!(Nuevo.getSexo().isNull()))
    {
        consulta=consulta+", sexo='"+Nuevo.getSexo()+"'";
    }
    if(!(Nuevo.getCodigoInterno().isNull()))
    {
        consulta=consulta+", codigo_interno='"+Nuevo.getCodigoInterno()+"'";
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
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+" nombre='"+Antiguo.getNombre()+"' AND ";
    }
    if(!Antiguo.getDireccion().isNull())
    {
        consulta=consulta+" direccion='"+Antiguo.getDireccion()+"' AND ";
    }
    if(!Antiguo.getEmail().isNull())
    {
        consulta=consulta+" email='"+Antiguo.getEmail()+"' AND ";
    }
    if(!(Antiguo.getDescuento()==(-1)))
    {
        consulta=consulta+" descuento='"+QString::number(Antiguo.getDescuento())+"' AND ";
    }
    if(!(Antiguo.getFechaIngreso()==QDate(1,1,1)))
    {
        consulta=consulta+" fecha_ingreso='"+Antiguo.getFechaIngreso().toString("dd-MM-yyyy")+"' AND ";
    }

    if(!(Antiguo.getDni().isNull()))
    {
        consulta=consulta+" dni='"+Antiguo.getDni()+"' AND ";
    }
    if(!(Antiguo.getTelefono().isNull()))
    {
        consulta=consulta+" telefono='"+Antiguo.getTelefono()+"' AND ";
    }
    if(!(Antiguo.getSexo().isNull()))
    {
        consulta=consulta+" sexo='"+Antiguo.getSexo()+"'";
    }
    if(!(Antiguo.getCodigoInterno().isNull()))
    {
        consulta=consulta+" codigo_interno='"+Antiguo.getCodigoInterno()+"'";
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

Empleado PgEmpleado::Buscar(Empleado valor)
{
    QString consulta;

    consulta="SELECT codigo, codigo_interno, nombre, direccion, email, descuento, fecha_ingreso, dni, telefono,sexo "
             "FROM empleado WHERE";

    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno like '%"+valor.getCodigoInterno()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+" direccion like '%"+valor.getDireccion()+"%' AND ";
    }
    if(!valor.getEmail().isNull())
    {
        consulta=consulta+" email like '%"+valor.getEmail()+"%' AND ";
    }
    if(!(valor.getDescuento()==(-1)))
    {
        consulta=consulta+" descuento like '%"+QString::number(valor.getDescuento())+"%' AND ";
    }
    if(!(valor.getFechaIngreso()==QDate(1,1,1)))
    {
        consulta=consulta+" fecha_ingreso BETWEEN '"+valor.getFechaIngreso().toString("dd-MM-yyyy")+"' AND '"+valor.getFechaFin().toString("dd-MM-yyyy") +"' AND ";
    }

    if(!valor.getDni().isNull())
    {
        consulta=consulta+" dni like '%"+valor.getDni()+"%' AND ";
    }

    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+" telefono like '%"+valor.getTelefono()+"%' AND ";
    }

    if(!valor.getSexo().isNull())
    {
        consulta=consulta+" sexo like '%"+valor.getSexo()+"%' AND ";
    }

    consulta.replace(consulta.size()-6,5," ");

    qDebug()<<consulta;

    Empleado resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setCodigoInterno(query.value(1).toString());
          resp.setNombre(query.value(2).toString());
          resp.setDireccion(query.value(3).toString());
          resp.setEmail(query.value(4).toString());
          resp.setDescuento(query.value(5).toDouble());
          resp.setFechaIngreso(query.value(6).toDate());
          resp.setDni(query.value(7).toString());
          resp.setTelefono(query.value(8).toString());
          resp.setSexo(query.value(9).toString());

         flag=false;
      }


    return resp;
}

QMap<QString, ObjetoMaestro *> *PgEmpleado::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{
    Empleado* val=(Empleado*)(valor);
    QString consulta;

    if(tipo==TODO)
    {
    consulta="SELECT codigo,codigo_interno, nombre, direccion, email, descuento, fecha_ingreso, dni, telefono, sexo "
             "FROM empleado WHERE";
    }
    else
    {
        consulta="SELECT codigo,codigo_interno, nombre, direccion, email, descuento, fecha_ingreso, dni, telefono, sexo  "
                 "FROM empleado WHERE";


    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+" direccion like '%"+val->getDireccion()+"%' AND ";
    }
    if(!val->getEmail().isNull())
    {
        consulta=consulta+" email like '%"+val->getEmail()+"%' AND ";
    }
    if(!(val->getDescuento()==(-1)))
    {
        consulta=consulta+" descuento like '%"+QString::number(val->getDescuento())+"%' AND ";
    }
    if(!(val->getFechaIngreso()==QDate(1,1,1)))
    {
        consulta=consulta+" fecha_ingreso BETWEEN '"+val->getFechaIngreso().toString("dd-MM-yyyy")+"' AND '"+val->getFechaFin().toString("dd-MM-yyyy") +"' AND ";
    }
    if(!val->getDni().isNull())
    {
        consulta=consulta+" dni like '%"+val->getDni()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono like '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getSexo().isNull())
    {
        consulta=consulta+" sexo like '%"+val->getSexo()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");
}
    consulta=consulta+Extra;
    qDebug()<<consulta+Extra;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
    QSqlQuery query(consulta);

      while (query.next() ) {
          Empleado* resp=new Empleado();
          resp->setCodigo(query.value(0).toString());
          resp->setCodigoInterno(query.value(1).toString());
          resp->setNombre(query.value(2).toString());
          resp->setDireccion(query.value(3).toString());
          resp->setEmail(query.value(4).toString());
          resp->setDescuento(query.value(5).toDouble());
          resp->setFechaIngreso(query.value(6).toDate());
          resp->setDni(query.value(7).toString());
          resp->setTelefono(query.value(8).toString());
          resp->setSexo(query.value(9).toString());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);
      }


    return salida;
}

int PgEmpleado::Contar()
{
    QString consulta="SELECT count(*) FROM empleado";
    QSqlQuery query(consulta);
  int num=0;
      while (query.next() )
      {
        num=query.value(0).toInt();
      }
  return num;
}

int PgEmpleado::ContarConsulta(ObjetoMaestro *valor)
{
    Empleado* val=(Empleado*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            " FROM empleado WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno like '%"+val->getCodigoInterno()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+" direccion like '%"+val->getDireccion()+"%' AND ";
    }
    if(!val->getEmail().isNull())
    {
        consulta=consulta+" email like '%"+val->getEmail()+"%' AND ";
    }
    if(!(val->getDescuento()==(-1)))
    {
        consulta=consulta+" descuento like '%"+QString::number(val->getDescuento())+"%' AND ";
    }
    if(!(val->getFechaIngreso()==QDate(1,1,1)))
    {
        consulta=consulta+" fecha_ingreso BETWEEN '"+val->getFechaIngreso().toString("dd-MM-yyyy")+"' AND '"+val->getFechaFin().toString("dd-MM-yyyy") +"' AND ";
    }
    if(!val->getDni().isNull())
    {
        consulta=consulta+" dni like '%"+val->getDni()+"%' AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+" telefono like '%"+val->getTelefono()+"%' AND ";
    }
    if(!val->getSexo().isNull())
    {
        consulta=consulta+" sexo like '%"+val->getSexo()+"%' AND ";
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

QSqlQueryModel *PgEmpleado::BuscarTabla(Empleado valor, QString Extra, CONSULTA tipo)
{
    QString consulta;

    if(tipo==TODO)
    {
    consulta="SELECT codigo,codigo_interno, dni,sexo, nombre, direccion, email, descuento, fecha_ingreso,telefono "
             "FROM empleado ";
    }
    else
    {
        consulta="SELECT codigo, codigo_interno, dni, sexo, nombre, direccion, email, descuento, fecha_ingreso, telefono "
                 "FROM empleado WHERE";

    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getCodigoInterno().isNull())
    {
        consulta=consulta+" codigo_interno like '%"+valor.getCodigoInterno()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+" direccion like '%"+valor.getDireccion()+"%' AND ";
    }
    if(!valor.getEmail().isNull())
    {
        consulta=consulta+" email like '%"+valor.getEmail()+"%' AND ";
    }
    if(!(valor.getDescuento()==(-1)))
    {
        consulta=consulta+" descuento like '%"+QString::number(valor.getDescuento())+"%' AND ";
    }
    if(!(valor.getFechaIngreso()==QDate(1,1,1)))
    {
        consulta=consulta+" fecha_ingreso BETWEEN '"+valor.getFechaIngreso().toString("dd-MM-yyyy")+"' AND '"+valor.getFechaFin().toString("dd-MM-yyyy") +"' AND ";

    }
    if(!valor.getDni().isNull())
    {
        consulta=consulta+" dni like '%"+valor.getDni()+"%' AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+" telefono like '%"+valor.getTelefono()+"%' AND ";
    }
    if(!valor.getSexo().isNull())
    {
        consulta=consulta+" sexo like '%"+valor.getSexo()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");
    }
    consulta=consulta+Extra;

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(consulta);

    qDebug()<<consulta;

    return model;

}
