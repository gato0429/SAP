#include "mensajeemergente.h"
#include "ui_mensajeemergente.h"

MensajeEmergente::MensajeEmergente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MensajeEmergente)
{
    ui->setupUi(this);

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
}

void MensajeEmergente::SetMensaje(QString Mensaje, TIPOMENSAJE tipo)
{
    ui->LabelMensaje->setText(Mensaje);
}

MensajeEmergente::~MensajeEmergente()
{
    delete ui;
}

void MensajeEmergente::on_pushButton_clicked()
{
    this->close();
    this->destroy();
}
