/********************************************************************************
** Form generated from reading UI file 'mensajeemergente.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENSAJEEMERGENTE_H
#define UI_MENSAJEEMERGENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MensajeEmergente
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelImagen;
    QLabel *LabelMensaje;
    QPushButton *pushButton;

    void setupUi(QDialog *MensajeEmergente)
    {
        if (MensajeEmergente->objectName().isEmpty())
            MensajeEmergente->setObjectName(QStringLiteral("MensajeEmergente"));
        MensajeEmergente->resize(247, 109);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(11);
        font.setItalic(true);
        MensajeEmergente->setFont(font);
        verticalLayout = new QVBoxLayout(MensajeEmergente);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LabelImagen = new QLabel(MensajeEmergente);
        LabelImagen->setObjectName(QStringLiteral("LabelImagen"));
        LabelImagen->setMaximumSize(QSize(60, 60));
        LabelImagen->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/iconos/candado.png")));
        LabelImagen->setScaledContents(true);

        horizontalLayout->addWidget(LabelImagen);

        LabelMensaje = new QLabel(MensajeEmergente);
        LabelMensaje->setObjectName(QStringLiteral("LabelMensaje"));

        horizontalLayout->addWidget(LabelMensaje);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(MensajeEmergente);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(MensajeEmergente);

        QMetaObject::connectSlotsByName(MensajeEmergente);
    } // setupUi

    void retranslateUi(QDialog *MensajeEmergente)
    {
        MensajeEmergente->setWindowTitle(QApplication::translate("MensajeEmergente", "Dialog", 0));
        LabelImagen->setText(QString());
        LabelMensaje->setText(QApplication::translate("MensajeEmergente", "Aqui ira el Mensaje", 0));
        pushButton->setText(QApplication::translate("MensajeEmergente", "Aceptar", 0));
    } // retranslateUi

};

namespace Ui {
    class MensajeEmergente: public Ui_MensajeEmergente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENSAJEEMERGENTE_H
