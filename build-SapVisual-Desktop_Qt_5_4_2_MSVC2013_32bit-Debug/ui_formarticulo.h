/********************************************************************************
** Form generated from reading UI file 'formarticulo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMARTICULO_H
#define UI_FORMARTICULO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormArticulo
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_16;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout;
    QLabel *label_12;
    QLineEdit *LineCodTipo;
    QLabel *label_13;
    QLineEdit *LineNombreTipo;
    QFrame *line_7;
    QLabel *LabelTipoImagen;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_15;
    QFrame *line_4;
    QListWidget *ListaTipo;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_17;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_2;
    QLabel *label_14;
    QLineEdit *LineCodUnidad;
    QLabel *label_18;
    QLineEdit *LineNombreUnidad;
    QFrame *line_10;
    QLabel *LabelUnidadImagen;
    QLabel *label_23;
    QLineEdit *LineSimbolo;
    QFrame *line_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_19;
    QFrame *line_12;
    QListWidget *ListaUnidad;
    QWidget *tab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QComboBox *ComboVigencia;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *LineImagen;
    QLabel *label_11;
    QLineEdit *LineNombre;
    QLineEdit *LineCodigo;
    QToolButton *BotonBusquedaImagen;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *LineCodigoInterno;
    QLineEdit *LineCodigoExterno;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QLabel *LabelImagen;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *BotonGuardar;
    QPushButton *BotonModificar;
    QPushButton *BotonEliminar;
    QSpacerItem *verticalSpacer;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_20;
    QFrame *line_13;
    QHBoxLayout *horizontalLayout_8;
    QFormLayout *formLayout_3;
    QLabel *label_21;
    QLineEdit *LineCodigoAlias;
    QLabel *label_22;
    QLineEdit *LineNombreAlias;
    QFrame *line_14;
    QLabel *LabelImagenAlias;
    QFrame *line_15;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_24;
    QFrame *line_16;
    QListWidget *ListaAlias;
    QFrame *line_17;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BotonNuevoAlias;
    QPushButton *BotonGuardarAlias;
    QPushButton *BotonModificarAlias;
    QPushButton *BotonEliminarAlias;
    QWidget *tab_2;

    void setupUi(QWidget *FormArticulo)
    {
        if (FormArticulo->objectName().isEmpty())
            FormArticulo->setObjectName(QStringLiteral("FormArticulo"));
        FormArticulo->resize(401, 338);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        font.setItalic(true);
        FormArticulo->setFont(font);
        verticalLayout_4 = new QVBoxLayout(FormArticulo);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget = new QTabWidget(FormArticulo);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::StrongFocus);
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_16);

        line_6 = new QFrame(tab_3);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_12);

        LineCodTipo = new QLineEdit(tab_3);
        LineCodTipo->setObjectName(QStringLiteral("LineCodTipo"));
        LineCodTipo->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, LineCodTipo);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_13);

        LineNombreTipo = new QLineEdit(tab_3);
        LineNombreTipo->setObjectName(QStringLiteral("LineNombreTipo"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LineNombreTipo);

        line_7 = new QFrame(tab_3);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(2, QFormLayout::SpanningRole, line_7);

        LabelTipoImagen = new QLabel(tab_3);
        LabelTipoImagen->setObjectName(QStringLiteral("LabelTipoImagen"));
        LabelTipoImagen->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/iconos/plus_grey.png")));
        LabelTipoImagen->setScaledContents(true);

        formLayout->setWidget(3, QFormLayout::SpanningRole, LabelTipoImagen);


        horizontalLayout_6->addLayout(formLayout);

        line_5 = new QFrame(tab_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_15);

        line_4 = new QFrame(tab_3);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        ListaTipo = new QListWidget(tab_3);
        ListaTipo->setObjectName(QStringLiteral("ListaTipo"));
        ListaTipo->setMinimumSize(QSize(40, 40));

        verticalLayout_3->addWidget(ListaTipo);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_17);

        line_9 = new QFrame(tab_4);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_14 = new QLabel(tab_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_14);

        LineCodUnidad = new QLineEdit(tab_4);
        LineCodUnidad->setObjectName(QStringLiteral("LineCodUnidad"));
        LineCodUnidad->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, LineCodUnidad);

        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_18);

        LineNombreUnidad = new QLineEdit(tab_4);
        LineNombreUnidad->setObjectName(QStringLiteral("LineNombreUnidad"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, LineNombreUnidad);

        line_10 = new QFrame(tab_4);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, line_10);

        LabelUnidadImagen = new QLabel(tab_4);
        LabelUnidadImagen->setObjectName(QStringLiteral("LabelUnidadImagen"));
        LabelUnidadImagen->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/iconos/plus_grey.png")));
        LabelUnidadImagen->setScaledContents(true);

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, LabelUnidadImagen);

        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_23);

        LineSimbolo = new QLineEdit(tab_4);
        LineSimbolo->setObjectName(QStringLiteral("LineSimbolo"));
        LineSimbolo->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, LineSimbolo);


        horizontalLayout_7->addLayout(formLayout_2);

        line_11 = new QFrame(tab_4);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_19);

        line_12 = new QFrame(tab_4);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_12);

        ListaUnidad = new QListWidget(tab_4);
        ListaUnidad->setObjectName(QStringLiteral("ListaUnidad"));
        ListaUnidad->setMinimumSize(QSize(40, 40));

        verticalLayout_6->addWidget(ListaUnidad);


        horizontalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_5->addLayout(horizontalLayout_7);


        gridLayout_4->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_8);

        line_8 = new QFrame(tab);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ComboVigencia = new QComboBox(tab);
        ComboVigencia->setObjectName(QStringLiteral("ComboVigencia"));

        gridLayout_2->addWidget(ComboVigencia, 4, 1, 1, 2);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        LineImagen = new QLineEdit(tab);
        LineImagen->setObjectName(QStringLiteral("LineImagen"));
        LineImagen->setReadOnly(true);

        gridLayout_2->addWidget(LineImagen, 5, 1, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 5, 0, 1, 1);

        LineNombre = new QLineEdit(tab);
        LineNombre->setObjectName(QStringLiteral("LineNombre"));

        gridLayout_2->addWidget(LineNombre, 3, 1, 1, 2);

        LineCodigo = new QLineEdit(tab);
        LineCodigo->setObjectName(QStringLiteral("LineCodigo"));
        LineCodigo->setReadOnly(true);

        gridLayout_2->addWidget(LineCodigo, 0, 1, 1, 2);

        BotonBusquedaImagen = new QToolButton(tab);
        BotonBusquedaImagen->setObjectName(QStringLiteral("BotonBusquedaImagen"));

        gridLayout_2->addWidget(BotonBusquedaImagen, 5, 2, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        LineCodigoInterno = new QLineEdit(tab);
        LineCodigoInterno->setObjectName(QStringLiteral("LineCodigoInterno"));
        LineCodigoInterno->setReadOnly(false);

        gridLayout_2->addWidget(LineCodigoInterno, 1, 1, 1, 2);

        LineCodigoExterno = new QLineEdit(tab);
        LineCodigoExterno->setObjectName(QStringLiteral("LineCodigoExterno"));
        LineCodigoExterno->setReadOnly(false);

        gridLayout_2->addWidget(LineCodigoExterno, 2, 1, 1, 2);


        horizontalLayout_5->addLayout(gridLayout_2);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        LabelImagen = new QLabel(tab);
        LabelImagen->setObjectName(QStringLiteral("LabelImagen"));

        verticalLayout_2->addWidget(LabelImagen);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_9->addLayout(horizontalLayout_5);

        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BotonGuardar = new QPushButton(tab);
        BotonGuardar->setObjectName(QStringLiteral("BotonGuardar"));
        BotonGuardar->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Imagenes/iconos/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonGuardar->setIcon(icon);
        BotonGuardar->setIconSize(QSize(40, 40));
        BotonGuardar->setFlat(true);

        horizontalLayout->addWidget(BotonGuardar);

        BotonModificar = new QPushButton(tab);
        BotonModificar->setObjectName(QStringLiteral("BotonModificar"));
        BotonModificar->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Imagenes/iconos/editar.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonModificar->setIcon(icon1);
        BotonModificar->setIconSize(QSize(40, 40));
        BotonModificar->setFlat(true);

        horizontalLayout->addWidget(BotonModificar);

        BotonEliminar = new QPushButton(tab);
        BotonEliminar->setObjectName(QStringLiteral("BotonEliminar"));
        BotonEliminar->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Imagenes/iconos/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonEliminar->setIcon(icon2);
        BotonEliminar->setIconSize(QSize(40, 40));
        BotonEliminar->setFlat(true);

        horizontalLayout->addWidget(BotonEliminar);


        verticalLayout_9->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_20 = new QLabel(tab_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_20);

        line_13 = new QFrame(tab_5);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_13);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_21 = new QLabel(tab_5);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_21);

        LineCodigoAlias = new QLineEdit(tab_5);
        LineCodigoAlias->setObjectName(QStringLiteral("LineCodigoAlias"));
        LineCodigoAlias->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, LineCodigoAlias);

        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_22);

        LineNombreAlias = new QLineEdit(tab_5);
        LineNombreAlias->setObjectName(QStringLiteral("LineNombreAlias"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, LineNombreAlias);

        line_14 = new QFrame(tab_5);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, line_14);

        LabelImagenAlias = new QLabel(tab_5);
        LabelImagenAlias->setObjectName(QStringLiteral("LabelImagenAlias"));
        LabelImagenAlias->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/iconos/plus_grey.png")));
        LabelImagenAlias->setScaledContents(true);

        formLayout_3->setWidget(3, QFormLayout::SpanningRole, LabelImagenAlias);


        horizontalLayout_8->addLayout(formLayout_3);

        line_15 = new QFrame(tab_5);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_15);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_24 = new QLabel(tab_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_24);

        line_16 = new QFrame(tab_5);
        line_16->setObjectName(QStringLiteral("line_16"));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_16);

        ListaAlias = new QListWidget(tab_5);
        ListaAlias->setObjectName(QStringLiteral("ListaAlias"));
        ListaAlias->setMinimumSize(QSize(40, 40));

        verticalLayout_8->addWidget(ListaAlias);


        horizontalLayout_8->addLayout(verticalLayout_8);


        verticalLayout_7->addLayout(horizontalLayout_8);

        line_17 = new QFrame(tab_5);
        line_17->setObjectName(QStringLiteral("line_17"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_17);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        BotonNuevoAlias = new QPushButton(tab_5);
        BotonNuevoAlias->setObjectName(QStringLiteral("BotonNuevoAlias"));
        BotonNuevoAlias->setMaximumSize(QSize(40, 40));
        BotonNuevoAlias->setIcon(icon3);
        BotonNuevoAlias->setIconSize(QSize(40, 40));
        BotonNuevoAlias->setAutoDefault(false);
        BotonNuevoAlias->setFlat(true);

        horizontalLayout_2->addWidget(BotonNuevoAlias);

        BotonGuardarAlias = new QPushButton(tab_5);
        BotonGuardarAlias->setObjectName(QStringLiteral("BotonGuardarAlias"));
        BotonGuardarAlias->setMaximumSize(QSize(40, 40));
        BotonGuardarAlias->setIcon(icon);
        BotonGuardarAlias->setIconSize(QSize(40, 40));
        BotonGuardarAlias->setAutoDefault(false);
        BotonGuardarAlias->setFlat(true);

        horizontalLayout_2->addWidget(BotonGuardarAlias);

        BotonModificarAlias = new QPushButton(tab_5);
        BotonModificarAlias->setObjectName(QStringLiteral("BotonModificarAlias"));
        BotonModificarAlias->setMaximumSize(QSize(40, 40));
        BotonModificarAlias->setIcon(icon1);
        BotonModificarAlias->setIconSize(QSize(40, 40));
        BotonModificarAlias->setFlat(true);

        horizontalLayout_2->addWidget(BotonModificarAlias);

        BotonEliminarAlias = new QPushButton(tab_5);
        BotonEliminarAlias->setObjectName(QStringLiteral("BotonEliminarAlias"));
        BotonEliminarAlias->setMaximumSize(QSize(40, 40));
        BotonEliminarAlias->setIcon(icon2);
        BotonEliminarAlias->setIconSize(QSize(40, 40));
        BotonEliminarAlias->setFlat(true);

        horizontalLayout_2->addWidget(BotonEliminarAlias);


        verticalLayout_7->addLayout(horizontalLayout_2);


        gridLayout_5->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, icon2, QString());

        verticalLayout_4->addWidget(tabWidget);

        QWidget::setTabOrder(tabWidget, LineCodTipo);
        QWidget::setTabOrder(LineCodTipo, LineNombreTipo);
        QWidget::setTabOrder(LineNombreTipo, ListaTipo);
        QWidget::setTabOrder(ListaTipo, LineCodUnidad);
        QWidget::setTabOrder(LineCodUnidad, LineNombreUnidad);
        QWidget::setTabOrder(LineNombreUnidad, LineSimbolo);
        QWidget::setTabOrder(LineSimbolo, ListaUnidad);
        QWidget::setTabOrder(ListaUnidad, ComboVigencia);
        QWidget::setTabOrder(ComboVigencia, LineImagen);
        QWidget::setTabOrder(LineImagen, LineNombre);
        QWidget::setTabOrder(LineNombre, LineCodigo);
        QWidget::setTabOrder(LineCodigo, BotonBusquedaImagen);
        QWidget::setTabOrder(BotonBusquedaImagen, LineCodigoInterno);
        QWidget::setTabOrder(LineCodigoInterno, LineCodigoExterno);
        QWidget::setTabOrder(LineCodigoExterno, BotonGuardar);
        QWidget::setTabOrder(BotonGuardar, BotonModificar);
        QWidget::setTabOrder(BotonModificar, BotonEliminar);
        QWidget::setTabOrder(BotonEliminar, LineCodigoAlias);
        QWidget::setTabOrder(LineCodigoAlias, LineNombreAlias);
        QWidget::setTabOrder(LineNombreAlias, ListaAlias);
        QWidget::setTabOrder(ListaAlias, BotonNuevoAlias);
        QWidget::setTabOrder(BotonNuevoAlias, BotonGuardarAlias);
        QWidget::setTabOrder(BotonGuardarAlias, BotonModificarAlias);
        QWidget::setTabOrder(BotonModificarAlias, BotonEliminarAlias);

        retranslateUi(FormArticulo);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(FormArticulo);
    } // setupUi

    void retranslateUi(QWidget *FormArticulo)
    {
        FormArticulo->setWindowTitle(QApplication::translate("FormArticulo", "Form", 0));
        label_16->setText(QApplication::translate("FormArticulo", "Tipo de Articulo", 0));
        label_12->setText(QApplication::translate("FormArticulo", "Codigo:", 0));
        label_13->setText(QApplication::translate("FormArticulo", "Nombre:", 0));
        LabelTipoImagen->setText(QString());
        label_15->setText(QApplication::translate("FormArticulo", "Tipos Existentes", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FormArticulo", "Page", 0));
        label_17->setText(QApplication::translate("FormArticulo", "Tipo de Unidad", 0));
        label_14->setText(QApplication::translate("FormArticulo", "Codigo:", 0));
        label_18->setText(QApplication::translate("FormArticulo", "Nombre:", 0));
        LabelUnidadImagen->setText(QString());
        label_23->setText(QApplication::translate("FormArticulo", "Simbolo:", 0));
        label_19->setText(QApplication::translate("FormArticulo", "Unidades Existentes", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("FormArticulo", "Page", 0));
        label_8->setText(QApplication::translate("FormArticulo", "Articulo", 0));
        ComboVigencia->clear();
        ComboVigencia->insertItems(0, QStringList()
         << QApplication::translate("FormArticulo", "vigente", 0)
         << QApplication::translate("FormArticulo", "caducado", 0)
        );
        label->setText(QApplication::translate("FormArticulo", "Codigo:", 0));
        label_5->setText(QApplication::translate("FormArticulo", "Nombre:", 0));
        label_7->setText(QApplication::translate("FormArticulo", "Vigencia:", 0));
        label_11->setText(QApplication::translate("FormArticulo", "Imagen:", 0));
        BotonBusquedaImagen->setText(QApplication::translate("FormArticulo", "...", 0));
        label_3->setText(QApplication::translate("FormArticulo", "Codigo Interno:", 0));
        label_4->setText(QApplication::translate("FormArticulo", "Codigo Externo:", 0));
        LineCodigoInterno->setText(QApplication::translate("FormArticulo", "0000", 0));
        LineCodigoExterno->setText(QApplication::translate("FormArticulo", "0000", 0));
        LabelImagen->setText(QApplication::translate("FormArticulo", "Imagen Articulo", 0));
        BotonGuardar->setText(QString());
        BotonModificar->setText(QString());
        BotonEliminar->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        label_20->setText(QApplication::translate("FormArticulo", "Alias del Articulo", 0));
        label_21->setText(QApplication::translate("FormArticulo", "Codigo:", 0));
        label_22->setText(QApplication::translate("FormArticulo", "Nombre:", 0));
        LabelImagenAlias->setText(QString());
        label_24->setText(QApplication::translate("FormArticulo", "Alias Asignados", 0));
        BotonNuevoAlias->setText(QString());
        BotonGuardarAlias->setText(QString());
        BotonModificarAlias->setText(QString());
        BotonEliminarAlias->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("FormArticulo", "Page", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class FormArticulo: public Ui_FormArticulo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMARTICULO_H
