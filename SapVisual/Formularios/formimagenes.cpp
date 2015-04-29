#include "formimagenes.h"
#include "ui_formimagenes.h"

FormImagenes::FormImagenes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormImagenes)
{
    ui->setupUi(this);
    /*Fondo Madera*/
    this->setWindowFlags(Qt::Window
                         | Qt::FramelessWindowHint
                         | Qt::WindowMinimizeButtonHint
                         | Qt::WindowMaximizeButtonHint
                         | Qt::WindowCloseButtonHint);

     QPixmap bkgnd(FondoForm);
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
     /*--------------------------*/

        FabricaBaseDatos* bd=DefBD::IniciarBD();
        bd->Fabrica->Conectar();
        FabricaImagenes* Img=bd->Fabrica->CrearImagen();
        QMap<QString,ObjetoMaestro*>* mapa=Img->BuscarMapa(Imagen(),TODO);

        QMap<QString,ObjetoMaestro*>::iterator it;


        QMap<QString,int>::iterator itc;

        this->ui->VisorArbol->setColumnCount(1);

        int n=-1;
        for(it=mapa->begin(); it!=mapa->end(); it++)
        {
           Imagen* i=(Imagen*)(it.value());
           QString Carpeta= i->getCarpeta();
           QString Nombre= i->getNombre();


            if(ListaCarpetas.contains(Carpeta))
            {
                itc=ListaCarpetas.find(Carpeta);
              QTreeWidgetItem* carp=ui->VisorArbol->topLevelItem(itc.value());
              QTreeWidgetItem *Item = new QTreeWidgetItem(carp);
              Item->setText(0, Nombre);
           //   DefBD::GuardarImagen(Carpeta+"/"+Nombre);
            }
            else
            {
                n++;
                ListaCarpetas.insert(Carpeta,n);
                QTreeWidgetItem* carp=new QTreeWidgetItem(ui->VisorArbol);
                carp->setText(0,Carpeta);

                QTreeWidgetItem *Item = new QTreeWidgetItem(carp);
                 Item->setText(0, Nombre);
               //     DefBD::GuardarImagen(Carpeta+"/"+Nombre);
            }
        }

        bd->Fabrica->Desconectar();
/*--------------*/


        mRepisa=RepisaImagenes::Iniciar();
         ui->LineNombre->setInputMask("AAAAAAAAAAAAAAAA");
}

FormImagenes::~FormImagenes()
{
    delete ui;
}

void FormImagenes::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {
    this->close();
    }
}

void FormImagenes::on_BotonImagen_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Abrir Imagen"),RutaImagenes,tr("Archivo Imagen (*.png)"));

    if (!fileName.isEmpty())
    {
      QPixmap*  pix=new QPixmap(fileName);

        ui->labelImagen_4->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        //ui->imagen->setText(fileName);

     }
}

void FormImagenes::on_BotonAgregarImagen_clicked()
{
    Imagen* Img=new Imagen();
    Img->setPixel(Definiciones::toQByteArray(fileName));

    if(fileName.isEmpty())
    {
        QMessageBox mensaje;
        mensaje.setText("Error, Imagen Necesaria");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }
    if(ui->LineCarpeta->text().isEmpty())
    {
        QMessageBox mensaje;
        mensaje.setText("Error, Carpeta Necesaria");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }
    if(ui->LineNombre->text().isEmpty())
    {
        QMessageBox mensaje;
        mensaje.setText("Error, Nombre Necesario");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }

    Img->setNombre(ui->LineNombre->text()+".png");
    Img->setCarpeta(ui->LineCarpeta->text());

    FabricaBaseDatos* bd=DefBD::IniciarBD();
    bd->Fabrica->Conectar();
    FabricaImagenes*  fi=bd->Fabrica->CrearImagen();
    if(fi->Insertar(*Img))
    {
        QTreeWidgetItem *Item = new QTreeWidgetItem(CarpetaActual);
        Item->setText(0, Img->getNombre());
        DefBD::GuardarImagen(Img->getCarpeta()+"/"+Img->getNombre());

        QMessageBox mensaje;
        mensaje.setText("La imagen fue agregada con Exito");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();

        ui->LineCarpeta->clear();
        ui->LineNombre->clear();
        mRepisa->ActualizarMapa((ObjetoMaestro*)new Imagen());
    }
    else
    {
        QMessageBox mensaje;
        mensaje.setText("La imagen no fue agregada,\n Posiblemente Exista el nombre y la carpeta ya en la base de datos, Error");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
    }
    bd->Fabrica->Desconectar();
}

void FormImagenes::on_BotonCarpetaBorrar_4_clicked()
{
    if(CarpetaActual->childCount()>0)
    {
        QMessageBox mensaje;
        mensaje.setText("Error, La Carpeta esta siendo usada");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }

    QTreeWidgetItem* item =CarpetaActual;
    int i = ui->VisorArbol->indexOfTopLevelItem(item);
    ui->VisorArbol->takeTopLevelItem(i);
    delete item;
}

void FormImagenes::on_BotonCarpetaAgregar_4_clicked()
{
    if(!ui->LineCarpetaNueva_4->text().isEmpty())
    {
        QTreeWidgetItem* carp=new QTreeWidgetItem(ui->VisorArbol);
        carp->setText(0,ui->LineCarpetaNueva_4->text());
        ListaCarpetas.insert(ui->LineCarpetaNueva_4->text(),ListaCarpetas.size()-1);
        ui->LineCarpetaNueva_4->clear();


    }
}

void FormImagenes::on_VisorArbol_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{

    if(ListaCarpetas.contains(current->text(0)))
    {
      ui->LineCarpeta->setText(current->text(0));
      CarpetaActual=current;
    }

    if(!ListaCarpetas.contains(current->text(0)))
    {
       QTreeWidgetItem*Padre= current->parent();
       CarpetaActual=Padre;
       QString TextP=Padre->text(0);
       ui->LineCarpeta->setText(TextP);
       QString name=current->text(0);
       name.chop(4);
       ui->LineNombre->setText(name);
     QString ruta=RutaImagenes+TextP+"/"+current->text(0);
      QPixmap*  pix=new QPixmap(ruta);
     ui->labelImagen_4->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    }
}
