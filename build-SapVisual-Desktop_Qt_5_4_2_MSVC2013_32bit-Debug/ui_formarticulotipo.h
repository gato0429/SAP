/********************************************************************************
** Form generated from reading UI file 'formarticulotipo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMARTICULOTIPO_H
#define UI_FORMARTICULOTIPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormArticuloTipo
{
public:
    QFormLayout *formLayout;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *imagenlabel;
    QLineEdit *codigo;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nombre;
    QSpacerItem *horizontalSpacer;
    QToolButton *BotonArchivo;
    QHBoxLayout *horizontalLayout;
    QPushButton *guardar;
    QPushButton *modificar;
    QPushButton *eliminar;
    QLineEdit *imagen;
    QWidget *tab_2;

    void setupUi(QWidget *FormArticuloTipo)
    {
        if (FormArticuloTipo->objectName().isEmpty())
            FormArticuloTipo->setObjectName(QStringLiteral("FormArticuloTipo"));
        FormArticuloTipo->resize(346, 203);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        font.setItalic(true);
        FormArticuloTipo->setFont(font);
        FormArticuloTipo->setStyleSheet(QStringLiteral(""));
        formLayout = new QFormLayout(FormArticuloTipo);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(0, QFormLayout::LabelRole, horizontalSpacer_3);

        tabWidget = new QTabWidget(FormArticuloTipo);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        tabWidget->setFont(font1);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 3, 1, 1, 1);

        imagenlabel = new QLabel(tab);
        imagenlabel->setObjectName(QStringLiteral("imagenlabel"));

        gridLayout_2->addWidget(imagenlabel, 0, 3, 2, 2);

        codigo = new QLineEdit(tab);
        codigo->setObjectName(QStringLiteral("codigo"));
        codigo->setInputMethodHints(Qt::ImhNone);
        codigo->setReadOnly(true);

        gridLayout_2->addWidget(codigo, 0, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        nombre = new QLineEdit(tab);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setInputMethodHints(Qt::ImhFormattedNumbersOnly);

        gridLayout_2->addWidget(nombre, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        BotonArchivo = new QToolButton(tab);
        BotonArchivo->setObjectName(QStringLiteral("BotonArchivo"));

        gridLayout_2->addWidget(BotonArchivo, 2, 3, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        guardar = new QPushButton(tab);
        guardar->setObjectName(QStringLiteral("guardar"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Imagenes/iconos/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        guardar->setIcon(icon);
        guardar->setIconSize(QSize(40, 40));
        guardar->setAutoDefault(false);
        guardar->setFlat(true);

        horizontalLayout->addWidget(guardar);

        modificar = new QPushButton(tab);
        modificar->setObjectName(QStringLiteral("modificar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Imagenes/iconos/editar.png"), QSize(), QIcon::Normal, QIcon::Off);
        modificar->setIcon(icon1);
        modificar->setIconSize(QSize(40, 40));
        modificar->setAutoDefault(false);
        modificar->setDefault(false);
        modificar->setFlat(true);

        horizontalLayout->addWidget(modificar);

        eliminar = new QPushButton(tab);
        eliminar->setObjectName(QStringLiteral("eliminar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Imagenes/iconos/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        eliminar->setIcon(icon2);
        eliminar->setIconSize(QSize(40, 40));
        eliminar->setFlat(true);

        horizontalLayout->addWidget(eliminar);


        gridLayout_2->addLayout(horizontalLayout, 4, 0, 1, 5);

        imagen = new QLineEdit(tab);
        imagen->setObjectName(QStringLiteral("imagen"));
        imagen->setReadOnly(true);

        gridLayout_2->addWidget(imagen, 2, 1, 1, 2);


        horizontalLayout_2->addLayout(gridLayout_2);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, icon2, QString());

        formLayout->setWidget(0, QFormLayout::FieldRole, tabWidget);


        retranslateUi(FormArticuloTipo);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormArticuloTipo);
    } // setupUi

    void retranslateUi(QWidget *FormArticuloTipo)
    {
        FormArticuloTipo->setWindowTitle(QApplication::translate("FormArticuloTipo", "Form", 0));
        imagenlabel->setText(QApplication::translate("FormArticuloTipo", "imagen", 0));
        label_3->setText(QApplication::translate("FormArticuloTipo", "Imagen", 0));
        label->setText(QApplication::translate("FormArticuloTipo", "Codigo:", 0));
        label_2->setText(QApplication::translate("FormArticuloTipo", "Nombre:", 0));
        BotonArchivo->setText(QApplication::translate("FormArticuloTipo", "...", 0));
        guardar->setText(QString());
        modificar->setText(QString());
        eliminar->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class FormArticuloTipo: public Ui_FormArticuloTipo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMARTICULOTIPO_H
