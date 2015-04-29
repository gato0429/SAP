#include "pgunidad.h"


PgUnidad::PgUnidad()
{
}


bool PgUnidad::Borrar(Unidad valor)
{
    QSqlQuery query;


    bool flag=query.exec("DELETE FROM unidad WHERE codigo='"+valor.getCodigo()+"'");

    if(!flag)
    {
        MensajeEmergente mensaje;
        mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
        mensaje.exec();
    }
    return flag;

}

bool PgUnidad::Insertar(Unidad valor)
{

    QSqlQuery query;
      query.prepare("INSERT INTO unidad( "
                   "simbolo, nombre, codigo_imagen) "
            "VALUES ( ?, ?, ?);");


      query.addBindValue(valor.getSimbolo());
      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getCodigoImagen());


      bool flag=query.exec();

      if(!flag)
      {
          MensajeEmergente mensaje;
          mensaje.SetMensaje(query.lastError().databaseText(),ADVERTENCIA);
          mensaje.exec();
      }
      return flag;

}

bool PgUnidad::Actualizar(Unidad Antiguo, Unidad Nuevo)
{
    QSqlQuery query;

    QString consulta;
    consulta="UPDATE unidad SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getSimbolo().isNull())
    {
        consulta=consulta+", simbolo='"+Nuevo.getSimbolo()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
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

    if(!Antiguo.getSimbolo().isNull())
    {
        consulta=consulta+"(simbolo='"+Antiguo.getSimbolo()+"') AND ";
    }
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+"(nombre='"+Antiguo.getNombre()+"') AND ";
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

Unidad PgUnidad::Buscar(Unidad valor)
{


    QString consulta;

        consulta="SELECT codigo, nombre, simbolo, codigo_imagen, ruta "
                "FROM vista_detalle_unidad WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getSimbolo().isNull())
    {
        consulta=consulta+" simbolo like '%"+valor.getSimbolo()+"%' AND ";
    }
    if(!valor.getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen like '%"+valor.getCodigoImagen()+"%' AND ";
    }
    if(!valor.getRutaImagen().isNull())
    {
        consulta=consulta+" ruta like '%"+valor.getRutaImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");


    consulta=consulta;

    qDebug()<<consulta;



    QSqlQuery query(consulta);

    bool flag=true;
    Unidad* resp=new Unidad();
      while (query.next()&&flag ) {

          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setSimbolo(query.value(2).toString());
          resp->setCodigoImagen(query.value(3).toString());
          resp->setRutaImagen(query.value(4).toString());
          flag=false;
      }

       return *resp;
}



QMap<QString, ObjetoMaestro *> *PgUnidad::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{

    Unidad* val=(Unidad*)(valor);
   qDebug()<<val->getCodigo();
    QString consulta;
    if(tipo==TODO)
    {
            consulta="SELECT codigo, nombre, simbolo, codigo_imagen, ruta "
                    "FROM vista_detalle_unidad";

    }
   else
    {
        consulta="SELECT codigo, nombre, simbolo, codigo_imagen, ruta "
                "FROM vista_detalle_unidad WHERE ";


    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getSimbolo().isNull())
    {
        consulta=consulta+" simbolo like '%"+val->getSimbolo()+"%' AND ";
    }
    if(!val->getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen like '%"+val->getCodigoImagen()+"%' AND ";
    }
    if(!val->getRutaImagen().isNull())
    {
        consulta=consulta+" ruta like '%"+val->getRutaImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");
    }

    consulta=consulta+Extra;

    qDebug()<<consulta;

    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();


    QSqlQuery query(consulta);

      while (query.next() ) {

          Unidad* resp=new Unidad();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setSimbolo(query.value(2).toString());
          resp->setCodigoImagen(query.value(3).toString());
          resp->setRutaImagen(query.value(4).toString());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);

      }

       return salida;
}

int PgUnidad::Contar()
{
    QString consulta="SELECT count(*) FROM unidad";
    QSqlQuery query(consulta);
  int num=0;
      while (query.next() )
      {
        num=query.value(0).toInt();
      }
  return num;
}

int PgUnidad::ContarConsulta(ObjetoMaestro *valor)
{
    Unidad* val=(Unidad*)(valor);
    QString consulta;

    consulta="SELECT count(*) "
            " FROM vista_detalle_unidad WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getSimbolo().isNull())
    {
        consulta=consulta+" simbolo like '%"+val->getSimbolo()+"%' AND ";
    }
    if(!val->getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen like '%"+val->getCodigoImagen()+"%' AND ";
    }
    if(!val->getRutaImagen().isNull())
    {
        consulta=consulta+" ruta like '%"+val->getRutaImagen()+"%' AND ";
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

QSqlQueryModel *PgUnidad::BuscarTabla(Unidad valor, QString Extra, CONSULTA tipo)
{
    QString consulta;
    if(tipo==TODO)
    {
            consulta="SELECT codigo, nombre, simbolo, codigo_imagen, ruta "
                    "FROM vista_detalle_unidad";

    }
   else
    {
        consulta="SELECT codigo, nombre, simbolo, codigo_imagen, ruta "
                "FROM vista_detalle_unidad WHERE ";


    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getSimbolo().isNull())
    {
        consulta=consulta+" simbolo like '%"+valor.getSimbolo()+"%' AND ";
    }
    if(!valor.getCodigoImagen().isNull())
    {
        consulta=consulta+" codigo_imagen like '%"+valor.getCodigoImagen()+"%' AND ";
    }
    if(!valor.getRutaImagen().isNull())
    {
        consulta=consulta+" ruta like '%"+valor.getRutaImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");
    }

    consulta=consulta+Extra;


    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(consulta);

    qDebug()<<"desde tabla"<<consulta;

    return model;
}
