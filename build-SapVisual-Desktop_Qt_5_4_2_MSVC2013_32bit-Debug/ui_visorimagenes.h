/********************************************************************************
** Form generated from reading UI file 'visorimagenes.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISORIMAGENES_H
#define UI_VISORIMAGENES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisorImagenes
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *LineCarpeta;
    QLabel *label_2;
    QFrame *line_2;
    QLineEdit *LineNombre;
    QTreeWidget *VisorArbol;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLabel *labelImagen;
    QLabel *label;
    QLineEdit *LineCodigo;
    QPushButton *ButonSeleccion;
    QWidget *tab_2;

    void setupUi(QDialog *VisorImagenes)
    {
        if (VisorImagenes->objectName().isEmpty())
            VisorImagenes->setObjectName(QStringLiteral("VisorImagenes"));
        VisorImagenes->resize(374, 331);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        VisorImagenes->setFont(font);
        gridLayout = new QGridLayout(VisorImagenes);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(VisorImagenes);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 4, 1, 1, 1);

        LineCarpeta = new QLineEdit(tab);
        LineCarpeta->setObjectName(QStringLiteral("LineCarpeta"));
        LineCarpeta->setReadOnly(true);

        gridLayout_2->addWidget(LineCarpeta, 3, 2, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 1, 1, 1);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 3, 1, 1);

        LineNombre = new QLineEdit(tab);
        LineNombre->setObjectName(QStringLiteral("LineNombre"));
        LineNombre->setReadOnly(true);

        gridLayout_2->addWidget(LineNombre, 4, 2, 1, 1);

        VisorArbol = new QTreeWidget(tab);
        VisorArbol->setObjectName(QStringLiteral("VisorArbol"));

        gridLayout_2->addWidget(VisorArbol, 0, 1, 1, 2);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 4, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelImagen = new QLabel(tab);
        labelImagen->setObjectName(QStringLiteral("labelImagen"));
        labelImagen->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelImagen);


        gridLayout_2->addLayout(verticalLayout, 0, 4, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 1, 1, 1);

        LineCodigo = new QLineEdit(tab);
        LineCodigo->setObjectName(QStringLiteral("LineCodigo"));
        LineCodigo->setReadOnly(true);

        gridLayout_2->addWidget(LineCodigo, 2, 2, 1, 1);

        ButonSeleccion = new QPushButton(tab);
        ButonSeleccion->setObjectName(QStringLiteral("ButonSeleccion"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButonSeleccion->setIcon(icon);
        ButonSeleccion->setIconSize(QSize(45, 45));
        ButonSeleccion->setFlat(true);

        gridLayout_2->addWidget(ButonSeleccion, 2, 4, 3, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Imagenes/iconos/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon1, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(VisorImagenes);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VisorImagenes);
    } // setupUi

    void retranslateUi(QDialog *VisorImagenes)
    {
        VisorImagenes->setWindowTitle(QApplication::translate("VisorImagenes", "MainWindow", 0));
        label_3->setText(QApplication::translate("VisorImagenes", "Nombre:", 0));
        label_2->setText(QApplication::translate("VisorImagenes", "Carpeta:", 0));
        QTreeWidgetItem *___qtreewidgetitem = VisorArbol->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("VisorImagenes", "Codigo", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("VisorImagenes", "Imagenes", 0));
        labelImagen->setText(QApplication::translate("VisorImagenes", "TextLabel", 0));
        label->setText(QApplication::translate("VisorImagenes", "Codigo:", 0));
        ButonSeleccion->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class VisorImagenes: public Ui_VisorImagenes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISORIMAGENES_H
