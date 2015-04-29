#include "busquedaempleado.h"

BusquedaEmpleado::BusquedaEmpleado(QWidget *parent):BusquedaMaestra(parent)
{
    IniciarCampos();
    Fab=BD->Fabrica->CrearEmpleado();
}


void BusquedaEmpleado::ObtenerConsulta()
{

    QString fin=LineFin->text();
    QString ord;
    int index=ComboCampos->currentIndex();


    if(GrupoBoton->button(1)->isChecked())
    {
        ord="asc";
    }
    if(GrupoBoton->button(2)->isChecked())
    {
        ord="desc";
    }

    Empleado ObjetoConsulta;

    switch (index)
    {
    case 1:
        ObjetoConsulta.setCodigo(LineNombre->text());
        break;
    case 2:
        ObjetoConsulta.setCodigoInterno(LineNombre->text());
        break;
    case 3:
        ObjetoConsulta.setNombre(LineNombre->text());
        break;
    case 4:
        ObjetoConsulta.setDireccion(LineNombre->text());
        break;
    case 5:
        ObjetoConsulta.setEmail(LineNombre->text());
        break;
    case 6:
        ObjetoConsulta.setDescuento(LineNombre->text().toDouble());
        break;
    case 7:
        ObjetoConsulta.setFechaIngreso(FechaEdit->date());
        ObjetoConsulta.setFechaFin(FechaEditFin->date());

        break;
    case 8:
        ObjetoConsulta.setSexo(ComboTipos->currentText());
        break;
    case 9:
        ObjetoConsulta.setDni(LineNombre->text());
        break;
    case 10:
        ObjetoConsulta.setTelefono(LineNombre->text());
        break;
    default:
        break;
    }


    BD->Fabrica->Conectar();

    QString Extra=" order by codigo "+ord+" LIMIT "+fin+" offset 0";
    QSqlQueryModel* Model= Fab->BuscarTabla(ObjetoConsulta,Extra,CAMPOS);
    BD->Fabrica->Desconectar();


    Model->setHeaderData(0,Qt::Horizontal,"Codigo");
    Model->setHeaderData(1,Qt::Horizontal,"Codigo Interno");
    Model->setHeaderData(2,Qt::Horizontal,"Dni");
    Model->setHeaderData(3,Qt::Horizontal,"Sexo");
    Model->setHeaderData(4,Qt::Horizontal,"Nombre");
    Model->setHeaderData(5,Qt::Horizontal,"Direccion");
    Model->setHeaderData(6,Qt::Horizontal,"Email");
    Model->setHeaderData(7,Qt::Horizontal,"Descuento");
    Model->setHeaderData(8,Qt::Horizontal,"Fecha");
    Model->setHeaderData(9,Qt::Horizontal,"Telefono");

    QList<bool> CamposVisibles;
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);
    CamposVisibles.push_back(true);


    emit my_signal(Model,CamposVisibles);
    emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta),fin.toInt(),ord);
    VisorConsulta->move(this->x(),this->y()+this->height());

}

void BusquedaEmpleado::IniciarCampos()
{
    QStringList campos;
    campos <<"Codigo" <<"Codigo Interno"<< "Nombre"<<"Direccion"<<"Email"<<"Descuento"<<"Fecha"<<"Sexo"<<"Dni"<<"Telefono";
    ComboCampos->addItems(campos);
}

void BusquedaEmpleado::CambiarCombo(int index)
{
    if(index==8)
    {
        VisibleCombo();

        ComboTipos->addItem("Masculino");
        ComboTipos->addItem("Femenino");

        return;
    }

    if(index==7)
    {
        VisibleFecha();

        return;

    }

    VisibleLine();

    return;
}
