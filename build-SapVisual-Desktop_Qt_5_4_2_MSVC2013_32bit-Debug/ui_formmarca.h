/********************************************************************************
** Form generated from reading UI file 'formmarca.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMARCA_H
#define UI_FORMMARCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMarca
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *LabelImage;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label;
    QToolButton *ButtonArchivoImagen;
    QLabel *label_2;
    QLineEdit *LineNombre;
    QLineEdit *LineImagen;
    QSpacerItem *horizontalSpacer;
    QLineEdit *LineCodigo;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonGuardar;
    QPushButton *ButtonModificar;
    QPushButton *ButtonEliminar;
    QPushButton *ButtonRegresar;

    void setupUi(QWidget *FormMarca)
    {
        if (FormMarca->objectName().isEmpty())
            FormMarca->setObjectName(QStringLiteral("FormMarca"));
        FormMarca->resize(321, 342);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        FormMarca->setFont(font);
        gridLayout = new QGridLayout(FormMarca);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        label_6 = new QLabel(FormMarca);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(60, 80));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_4 = new QLabel(FormMarca);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 80));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        LabelImage = new QLabel(FormMarca);
        LabelImage->setObjectName(QStringLiteral("LabelImage"));
        LabelImage->setMinimumSize(QSize(60, 80));
        LabelImage->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(LabelImage);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        tabWidget = new QTabWidget(FormMarca);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane { \n"
"font: bold 14px;\n"
"   background: transparent; \n"
"  margin: 0px,0px,0px,0px;\n"
"   border: 0px solid transparent;  \n"
"  }\n"
"\n"
"QTabBar::tab {\n"
"    background: transparent;\n"
"    border: 2px solid transparent;\n"
"    border-bottom-color: transparent; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
""));
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(40, 40));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(12);
        font1.setItalic(true);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        ButtonArchivoImagen = new QToolButton(tab);
        ButtonArchivoImagen->setObjectName(QStringLiteral("ButtonArchivoImagen"));
        ButtonArchivoImagen->setFont(font1);

        gridLayout_2->addWidget(ButtonArchivoImagen, 2, 3, 1, 2);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        LineNombre = new QLineEdit(tab);
        LineNombre->setObjectName(QStringLiteral("LineNombre"));
        LineNombre->setFont(font1);
        LineNombre->setInputMethodHints(Qt::ImhFormattedNumbersOnly);

        gridLayout_2->addWidget(LineNombre, 1, 1, 1, 4);

        LineImagen = new QLineEdit(tab);
        LineImagen->setObjectName(QStringLiteral("LineImagen"));
        LineImagen->setFont(font1);
        LineImagen->setReadOnly(true);

        gridLayout_2->addWidget(LineImagen, 2, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        LineCodigo = new QLineEdit(tab);
        LineCodigo->setObjectName(QStringLiteral("LineCodigo"));
        LineCodigo->setFont(font1);
        LineCodigo->setInputMethodHints(Qt::ImhNone);
        LineCodigo->setReadOnly(true);

        gridLayout_2->addWidget(LineCodigo, 0, 1, 1, 3);


        horizontalLayout_2->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        ButtonGuardar = new QPushButton(tab);
        ButtonGuardar->setObjectName(QStringLiteral("ButtonGuardar"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Imagenes/iconos/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonGuardar->setIcon(icon);
        ButtonGuardar->setIconSize(QSize(40, 40));
        ButtonGuardar->setAutoDefault(false);
        ButtonGuardar->setFlat(true);

        verticalLayout_2->addWidget(ButtonGuardar);

        ButtonModificar = new QPushButton(tab);
        ButtonModificar->setObjectName(QStringLiteral("ButtonModificar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Imagenes/iconos/editar.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonModificar->setIcon(icon1);
        ButtonModificar->setIconSize(QSize(40, 40));
        ButtonModificar->setAutoDefault(false);
        ButtonModificar->setDefault(false);
        ButtonModificar->setFlat(true);

        verticalLayout_2->addWidget(ButtonModificar);

        ButtonEliminar = new QPushButton(tab);
        ButtonEliminar->setObjectName(QStringLiteral("ButtonEliminar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Imagenes/iconos/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonEliminar->setIcon(icon2);
        ButtonEliminar->setIconSize(QSize(40, 40));
        ButtonEliminar->setFlat(true);

        verticalLayout_2->addWidget(ButtonEliminar);

        ButtonRegresar = new QPushButton(tab);
        ButtonRegresar->setObjectName(QStringLiteral("ButtonRegresar"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Imagenes/iconos/izquierda.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonRegresar->setIcon(icon3);
        ButtonRegresar->setIconSize(QSize(40, 40));
        ButtonRegresar->setFlat(true);

        verticalLayout_2->addWidget(ButtonRegresar);


        horizontalLayout_2->addLayout(verticalLayout_2);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon4, QString());

        gridLayout->addWidget(tabWidget, 4, 0, 1, 1);


        retranslateUi(FormMarca);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormMarca);
    } // setupUi

    void retranslateUi(QWidget *FormMarca)
    {
        FormMarca->setWindowTitle(QApplication::translate("FormMarca", "Form", 0));
        label_6->setText(QApplication::translate("FormMarca", "Icono", 0));
        label_4->setText(QApplication::translate("FormMarca", "Marca", 0));
        LabelImage->setText(QApplication::translate("FormMarca", "Imagen", 0));
        label_3->setText(QApplication::translate("FormMarca", "Imagen", 0));
        label->setText(QApplication::translate("FormMarca", "Codigo:", 0));
        ButtonArchivoImagen->setText(QApplication::translate("FormMarca", "...", 0));
        label_2->setText(QApplication::translate("FormMarca", "Nombre:", 0));
        ButtonGuardar->setText(QString());
        ButtonModificar->setText(QString());
        ButtonEliminar->setText(QString());
        ButtonRegresar->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
    } // retranslateUi

};

namespace Ui {
    class FormMarca: public Ui_FormMarca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMARCA_H
