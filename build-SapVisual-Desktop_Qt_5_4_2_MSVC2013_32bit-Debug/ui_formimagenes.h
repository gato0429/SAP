/********************************************************************************
** Form generated from reading UI file 'formimagenes.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMIMAGENES_H
#define UI_FORMIMAGENES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormImagenes
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTreeWidget *VisorArbol;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelImagen_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *BotonCarpetaBorrar_4;
    QPushButton *BotonCarpetaAgregar_4;
    QLineEdit *LineCarpetaNueva_4;
    QFrame *line;
    QLabel *label_2;
    QLineEdit *LineCarpeta;
    QPushButton *BotonImagen;
    QLabel *label_3;
    QLineEdit *LineNombre;
    QPushButton *BotonAgregarImagen;
    QWidget *widget;

    void setupUi(QWidget *FormImagenes)
    {
        if (FormImagenes->objectName().isEmpty())
            FormImagenes->setObjectName(QStringLiteral("FormImagenes"));
        FormImagenes->resize(490, 355);
        verticalLayout_2 = new QVBoxLayout(FormImagenes);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(FormImagenes);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        VisorArbol = new QTreeWidget(tab);
        VisorArbol->setObjectName(QStringLiteral("VisorArbol"));

        gridLayout_2->addWidget(VisorArbol, 0, 0, 1, 2);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 2, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        labelImagen_4 = new QLabel(tab);
        labelImagen_4->setObjectName(QStringLiteral("labelImagen_4"));
        labelImagen_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(labelImagen_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BotonCarpetaBorrar_4 = new QPushButton(tab);
        BotonCarpetaBorrar_4->setObjectName(QStringLiteral("BotonCarpetaBorrar_4"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Imagenes/iconos/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonCarpetaBorrar_4->setIcon(icon);
        BotonCarpetaBorrar_4->setIconSize(QSize(40, 40));
        BotonCarpetaBorrar_4->setCheckable(false);
        BotonCarpetaBorrar_4->setAutoDefault(false);
        BotonCarpetaBorrar_4->setFlat(true);

        horizontalLayout->addWidget(BotonCarpetaBorrar_4);

        BotonCarpetaAgregar_4 = new QPushButton(tab);
        BotonCarpetaAgregar_4->setObjectName(QStringLiteral("BotonCarpetaAgregar_4"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonCarpetaAgregar_4->setIcon(icon1);
        BotonCarpetaAgregar_4->setIconSize(QSize(40, 40));
        BotonCarpetaAgregar_4->setFlat(true);

        horizontalLayout->addWidget(BotonCarpetaAgregar_4);


        verticalLayout_5->addLayout(horizontalLayout);

        LineCarpetaNueva_4 = new QLineEdit(tab);
        LineCarpetaNueva_4->setObjectName(QStringLiteral("LineCarpetaNueva_4"));

        verticalLayout_5->addWidget(LineCarpetaNueva_4);


        gridLayout_2->addLayout(verticalLayout_5, 0, 3, 1, 1);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 3, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        LineCarpeta = new QLineEdit(tab);
        LineCarpeta->setObjectName(QStringLiteral("LineCarpeta"));
        LineCarpeta->setReadOnly(true);

        gridLayout_2->addWidget(LineCarpeta, 2, 1, 1, 1);

        BotonImagen = new QPushButton(tab);
        BotonImagen->setObjectName(QStringLiteral("BotonImagen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Imagenes/iconos/buscar.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonImagen->setIcon(icon2);
        BotonImagen->setIconSize(QSize(40, 40));
        BotonImagen->setFlat(true);

        gridLayout_2->addWidget(BotonImagen, 2, 3, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        LineNombre = new QLineEdit(tab);
        LineNombre->setObjectName(QStringLiteral("LineNombre"));

        gridLayout_2->addWidget(LineNombre, 3, 1, 1, 1);

        BotonAgregarImagen = new QPushButton(tab);
        BotonAgregarImagen->setObjectName(QStringLiteral("BotonAgregarImagen"));
        BotonAgregarImagen->setIcon(icon1);
        BotonAgregarImagen->setIconSize(QSize(40, 40));
        BotonAgregarImagen->setFlat(true);

        gridLayout_2->addWidget(BotonAgregarImagen, 3, 3, 1, 1);

        tabWidget->addTab(tab, icon1, QString());
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        tabWidget->addTab(widget, icon, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(FormImagenes);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormImagenes);
    } // setupUi

    void retranslateUi(QWidget *FormImagenes)
    {
        FormImagenes->setWindowTitle(QApplication::translate("FormImagenes", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = VisorArbol->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("FormImagenes", "Imagenes", 0));
        labelImagen_4->setText(QApplication::translate("FormImagenes", "Imagen", 0));
        BotonCarpetaBorrar_4->setText(QString());
        BotonCarpetaAgregar_4->setText(QString());
        label_2->setText(QApplication::translate("FormImagenes", "Carpeta:", 0));
        BotonImagen->setText(QString());
        label_3->setText(QApplication::translate("FormImagenes", "Nombre:", 0));
        BotonAgregarImagen->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(widget), QString());
    } // retranslateUi

};

namespace Ui {
    class FormImagenes: public Ui_FormImagenes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMIMAGENES_H
