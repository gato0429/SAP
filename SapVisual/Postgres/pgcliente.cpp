#include "pgcliente.h"

#include <qdebug.h>

PgCliente::PgCliente()
{
}


bool PgCliente::Borrar(Cliente valor)
{
    QSqlQuery query;

    bool flag=query.exec("DELETE FROM clientes WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return  flag;
}

bool PgCliente::Insertar(Cliente valor)
{
    if(valor.getDescuento()==(-1))
    {
        valor.setDescuento(0);
    }
    QSqlQuery query;
      query.prepare("INSERT INTO clientes( "
                    "codigo, tipo, nombre, direccion, pais, contacto, telefono, email, "
                    "web, descuento, fecha, codigo_interno, num_doc) "
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
                    "?, ?, ?, ?, ?);)");

      query.addBindValue(valor.getCodigo());
      query.addBindValue(valor.getTipo());
      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getDireccion());
      query.addBindValue(valor.getPais());
      query.addBindValue(valor.getContacto());
      query.addBindValue(valor.getTelefono());
      query.addBindValue(valor.getEmail());
      query.addBindValue(valor.getWeb());
      query.addBindValue(valor.getDescuento());
      query.addBindValue(valor.getFecha());
      query.addBindValue(valor.getCodigoInterno());
      query.addBindValue(valor.getNumDoc());

      bool flag=query.exec();
      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return  flag;

}

bool PgCliente::Actualizar(Cliente Antiguo, Cliente Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE clientes SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getTipo().isNull())
    {
        consulta=consulta+", tipo='"+Nuevo.getTipo()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getDireccion().isNull())
    {
        consulta=consulta+", direccion='"+Nuevo.getDireccion()+"'";
    }
    if(!Nuevo.getPais().isNull())
    {
        consulta=consulta+", pais='"+Nuevo.getPais()+"'";
    }
    if(!Nuevo.getContacto().isNull())
    {
        consulta=consulta+", contacto='"+Nuevo.getContacto()+"'";
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
    if(!(Nuevo.getDescuento()==(-1)))
    {
        consulta=consulta+", descuento='"+QString::number(Nuevo.getDescuento())+"'";
    }

    if(!(Nuevo.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+", fecha='"+(Nuevo.getFecha()).toString("dd-MM-yyyy")+"'";
    }
    if(!Nuevo.getCodigoInterno().isNull())
    {
        consulta=consulta+", codigo_interno='"+Nuevo.getCodigoInterno()+"'";
    }
    if(!Nuevo.getNumDoc().isNull())
    {
        consulta=consulta+", num_doc='"+Nuevo.getNumDoc()+"'";
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
    if(!Antiguo.getTipo().isNull())
    {
        consulta=consulta+"(tipo='"+Antiguo.getTipo()+"') AND ";
    }
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+"(nombre='"+Antiguo.getNombre()+"') AND ";
    }
    if(!Antiguo.getDireccion().isNull())
    {
        consulta=consulta+"(direccion='"+Antiguo.getDireccion()+"') AND ";
    }
    if(!Antiguo.getPais().isNull())
    {
        consulta=consulta+"(pais='"+Antiguo.getPais()+"') AND ";
    }
    if(!Antiguo.getContacto().isNull())
    {
        consulta=consulta+"(contacto='"+Antiguo.getContacto()+"') AND ";
    }
    if(!Antiguo.getTelefono().isNull())
    {
        consulta=consulta+"(telefono='"+Antiguo.getTelefono()+"') AND ";
    }
    if(!Antiguo.getEmail().isNull())
    {
        consulta=consulta+"(email='"+Antiguo.getEmail()+"') AND ";
    }
    if(!Antiguo.getWeb().isNull())
    {
        consulta=consulta+"(web='"+Antiguo.getWeb()+"') AND ";
    }
    if(!(Antiguo.getDescuento()==(-1)))
    {
        consulta=consulta+"(descuento='"+QString::number(Antiguo.getDescuento())+"') AND ";
    }

    if(!(Antiguo.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+"(fecha='"+(Antiguo.getFecha()).toString("dd-MM-yyyy")+"') AND ";
    }

    if(!Antiguo.getCodigoInterno().isNull())
    {
        consulta=consulta+"(codigo_interno='"+Antiguo.getCodigoInterno()+"') AND ";
    }
    if(!Antiguo.getNumDoc().isNull())
    {
        consulta=consulta+"(num_doc='"+Antiguo.getNumDoc()+"') AND ";
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

Cliente PgCliente::Buscar(Cliente valor)
{


    QString consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
            " web, descuento, fecha, codigo_interno, num_doc "
            " FROM clientes"
            " WHERE ";

    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+"(codigo like '%"+valor.getCodigo()+"%') AND ";
    }
    if(!valor.getTipo().isNull())
    {
        consulta=consulta+"(tipo like '%"+valor.getTipo()+"%') AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+"(nombre like '%"+valor.getNombre()+"%') AND ";
    }
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+"(direccion like '%"+valor.getDireccion()+"%') AND ";
    }
    if(!valor.getPais().isNull())
    {
        consulta=consulta+"(pais like '%"+valor.getPais()+"%') AND ";
    }
    if(!valor.getContacto().isNull())
    {
        consulta=consulta+"(contacto like '%"+valor.getContacto()+"%') AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+"(telefono like '%"+valor.getTelefono()+"%') AND ";
    }
    if(!valor.getEmail().isNull())
    {
        consulta=consulta+"(email like '%"+valor.getEmail()+"%') AND ";
    }
    if(!valor.getWeb().isNull())
    {
        consulta=consulta+"(web like '%"+valor.getWeb()+"%') AND ";
    }
    if(!(valor.getDescuento()==(-1)))
    {
        consulta=consulta+"(descuento like '%"+QString::number(valor.getDescuento())+"%') AND ";
    }

    if(!(valor.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+"(fecha='"+(valor.getFecha()).toString("yyyy-MM-dd")+"') AND ";
    }

    if(!valor.getCodigoInterno().isNull())
    {
        consulta=consulta+"(codigo_interno like '%"+valor.getCodigoInterno()+"%') AND ";
    }
    if(!valor.getNumDoc().isNull())
    {
        consulta=consulta+"(num_doc like '%"+valor.getNumDoc()+"%') AND ";
    }
    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;

    Cliente resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setTipo(query.value(1).toString());
          resp.setNombre(query.value(2).toString());
          resp.setDireccion(query.value(3).toString());
          resp.setPais(query.value(4).toString());
          resp.setContacto(query.value(5).toString());
          resp.setTelefono(query.value(6).toString());
          resp.setEmail(query.value(7).toString());
          resp.setWeb(query.value(8).toString());
          resp.setDescuento(query.value(9).toFloat());
          resp.setFecha(query.value(10).toDate());
          resp.setCodigoInterno(query.value(11).toString());
          resp.setNumDoc(query.value(12).toString());
          flag=false;
      }


    return resp;
}



int PgCliente::Contar()
{
    QString consulta="SELECT count(*) FROM clientes";
    QSqlQuery query(consulta);
  int num=0;
      while (query.next() )
      {
        num=query.value(0).toInt();
      }
  return num;
}



QMap<QString, ObjetoMaestro *> *PgCliente::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{

        Cliente* val=(Cliente*)(valor);

    QString consulta="";
    if(tipo==TODO)
{
      consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
                " web, descuento, fecha, codigo_interno, num_doc "
                " FROM clientes";

}
else
 {

        consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
                  " web, descuento, fecha, codigo_interno, num_doc "
                  " FROM clientes"
                  " WHERE ";


        if(!val->getCodigo().isNull())
        {
            consulta=consulta+"(codigo like '%"+val->getCodigo()+"%') AND ";
        }
        if(!val->getTipo().isNull())
        {
            consulta=consulta+"(tipo like '%"+val->getTipo()+"%') AND ";
        }
        if(!val->getNombre().isNull())
        {
            consulta=consulta+"(nombre like '%"+val->getNombre()+"%') AND ";
        }
        if(!val->getDireccion().isNull())
        {
            consulta=consulta+"(direccion like '%"+val->getDireccion()+"%') AND ";
        }
        if(!val->getPais().isNull())
        {
            consulta=consulta+"(pais like '%"+val->getPais()+"%') AND ";
        }
        if(!val->getContacto().isNull())
        {
            consulta=consulta+"(contacto like '%"+val->getContacto()+"%') AND ";
        }
        if(!val->getTelefono().isNull())
        {
            consulta=consulta+"(telefono like '%"+val->getTelefono()+"%') AND ";
        }
        if(!val->getEmail().isNull())
        {
            consulta=consulta+"(email like '%"+val->getEmail()+"%') AND ";
        }
        if(!val->getWeb().isNull())
        {
            consulta=consulta+"(web like '%"+val->getWeb()+"%') AND ";
        }
        if(!(val->getDescuento()==(-1)))
        {
            consulta=consulta+"(descuento like '%"+QString::number(val->getDescuento())+"%') AND ";
        }

        if(!(val->getFecha()==QDate(1,1,1)))
        {
            consulta=consulta+"(fecha='"+(val->getFecha()).toString("yyyy-MM-dd")+"') AND ";
        }

        if(!val->getCodigoInterno().isNull())
        {
            consulta=consulta+"(codigo_interno like '%"+val->getCodigoInterno()+"%') AND ";
        }
        if(!val->getNumDoc().isNull())
        {
            consulta=consulta+"(num_doc like '%"+val->getNumDoc()+"%') AND ";
        }
    consulta.replace(consulta.size()-5,5,";");
    }

    consulta=consulta+Extra;





    qDebug()<<consulta;


    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();
   QSqlQuery query(consulta);


    bool flag=true;
      while (query.next() && flag ) {
          Cliente* resp=new Cliente();
          resp->setCodigo(query.value(0).toString());
          resp->setTipo(query.value(1).toString());
          resp->setNombre(query.value(2).toString());
          resp->setDireccion(query.value(3).toString());
          resp->setPais(query.value(4).toString());
          resp->setContacto(query.value(5).toString());
          resp->setTelefono(query.value(6).toString());
          resp->setEmail(query.value(7).toString());
          resp->setWeb(query.value(8).toString());
          resp->setDescuento(query.value(9).toFloat());
          resp->setFecha(query.value(10).toDate());
          resp->setCodigoInterno(query.value(11).toString());
          resp->setNumDoc(query.value(12).toString());
          flag=false;
          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);

      }


    return salida;

}


int PgCliente::ContarConsulta(ObjetoMaestro *valor)
{

    Cliente* val=(Cliente*)(valor);

QString consulta="";

    consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
              " web, descuento, fecha, codigo_interno, num_doc "
              " FROM clientes"
              " WHERE ";


    if(!val->getCodigo().isNull())
    {
        consulta=consulta+"(codigo like '%"+val->getCodigo()+"%') AND ";
    }
    if(!val->getTipo().isNull())
    {
        consulta=consulta+"(tipo like '%"+val->getTipo()+"%') AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+"(nombre like '%"+val->getNombre()+"%') AND ";
    }
    if(!val->getDireccion().isNull())
    {
        consulta=consulta+"(direccion like '%"+val->getDireccion()+"%') AND ";
    }
    if(!val->getPais().isNull())
    {
        consulta=consulta+"(pais like '%"+val->getPais()+"%') AND ";
    }
    if(!val->getContacto().isNull())
    {
        consulta=consulta+"(contacto like '%"+val->getContacto()+"%') AND ";
    }
    if(!val->getTelefono().isNull())
    {
        consulta=consulta+"(telefono like '%"+val->getTelefono()+"%') AND ";
    }
    if(!val->getEmail().isNull())
    {
        consulta=consulta+"(email like '%"+val->getEmail()+"%') AND ";
    }
    if(!val->getWeb().isNull())
    {
        consulta=consulta+"(web like '%"+val->getWeb()+"%') AND ";
    }
    if(!(val->getDescuento()==(-1)))
    {
        consulta=consulta+"(descuento like '%"+QString::number(val->getDescuento())+"%') AND ";
    }

    if(!(val->getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+"(fecha='"+(val->getFecha()).toString("yyyy-MM-dd")+"') AND ";
    }

    if(!val->getCodigoInterno().isNull())
    {
        consulta=consulta+"(codigo_interno like '%"+val->getCodigoInterno()+"%') AND ";
    }
    if(!val->getNumDoc().isNull())
    {
        consulta=consulta+"(num_doc like '%"+val->getNumDoc()+"%') AND ";
    }

    consulta.replace(consulta.size()-5,5,";");




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

QSqlQueryModel *PgCliente::BuscarTabla(Cliente valor, QString Extra, CONSULTA tipo)
{


QString consulta="";
if(tipo==TODO)
{
  consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
            " web, descuento, fecha, codigo_interno, num_doc "
            " FROM clientes";

}
else
{

    consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
              " web, descuento, fecha, codigo_interno, num_doc "
              " FROM clientes"
              " WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+"(codigo like '%"+valor.getCodigo()+"%') AND ";
    }
    if(!valor.getTipo().isNull())
    {
        consulta=consulta+"(tipo like '%"+valor.getTipo()+"%') AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+"(nombre like '%"+valor.getNombre()+"%') AND ";
    }
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+"(direccion like '%"+valor.getDireccion()+"%') AND ";
    }
    if(!valor.getPais().isNull())
    {
        consulta=consulta+"(pais like '%"+valor.getPais()+"%') AND ";
    }
    if(!valor.getContacto().isNull())
    {
        consulta=consulta+"(contacto like '%"+valor.getContacto()+"%') AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+"(telefono like '%"+valor.getTelefono()+"%') AND ";
    }
    if(!valor.getEmail().isNull())
    {
        consulta=consulta+"(email like '%"+valor.getEmail()+"%') AND ";
    }
    if(!valor.getWeb().isNull())
    {
        consulta=consulta+"(web like '%"+valor.getWeb()+"%') AND ";
    }
    if(!(valor.getDescuento()==(-1)))
    {
        consulta=consulta+"(descuento like '%"+QString::number(valor.getDescuento())+"%') AND ";
    }

    if(!(valor.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+"(fecha='"+(valor.getFecha()).toString("yyyy-MM-dd")+"') AND ";
    }

    if(!valor.getCodigoInterno().isNull())
    {
        consulta=consulta+"(codigo_interno like '%"+valor.getCodigoInterno()+"%') AND ";
    }
    if(!valor.getNumDoc().isNull())
    {
        consulta=consulta+"(num_doc like '%"+valor.getNumDoc()+"%') AND ";
    }
consulta.replace(consulta.size()-5,5,";");
}

qDebug()<<consulta;

consulta=consulta+Extra;


    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(consulta);

    qDebug()<<consulta;

    return model;
}
