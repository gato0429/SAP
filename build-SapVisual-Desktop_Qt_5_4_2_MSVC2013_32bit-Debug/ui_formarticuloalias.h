/********************************************************************************
** Form generated from reading UI file 'formarticuloalias.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMARTICULOALIAS_H
#define UI_FORMARTICULOALIAS_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormArticuloAlias
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QLineEdit *LineCodigoArticulo;
    QLineEdit *LineNombreArticulo;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *guardar;
    QPushButton *modificar;
    QPushButton *eliminar;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *LineCodigoAlias;
    QLabel *label_4;
    QLineEdit *LineNombreAlias;
    QLabel *imagenlabel;
    QWidget *tab_2;

    void setupUi(QWidget *FormArticuloAlias)
    {
        if (FormArticuloAlias->objectName().isEmpty())
            FormArticuloAlias->setObjectName(QStringLiteral("FormArticuloAlias"));
        FormArticuloAlias->resize(375, 234);
        gridLayout = new QGridLayout(FormArticuloAlias);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(FormArticuloAlias);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        tabWidget->setFont(font);
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

        gridLayout_2->addItem(verticalSpacer, 4, 1, 1, 1);

        LineCodigoArticulo = new QLineEdit(tab);
        LineCodigoArticulo->setObjectName(QStringLiteral("LineCodigoArticulo"));
        LineCodigoArticulo->setInputMethodHints(Qt::ImhNone);
        LineCodigoArticulo->setReadOnly(true);

        gridLayout_2->addWidget(LineCodigoArticulo, 0, 1, 1, 1);

        LineNombreArticulo = new QLineEdit(tab);
        LineNombreArticulo->setObjectName(QStringLiteral("LineNombreArticulo"));
        LineNombreArticulo->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        LineNombreArticulo->setReadOnly(true);

        gridLayout_2->addWidget(LineNombreArticulo, 1, 1, 1, 2);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

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


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        LineCodigoAlias = new QLineEdit(tab);
        LineCodigoAlias->setObjectName(QStringLiteral("LineCodigoAlias"));
        LineCodigoAlias->setReadOnly(true);

        gridLayout_2->addWidget(LineCodigoAlias, 2, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        LineNombreAlias = new QLineEdit(tab);
        LineNombreAlias->setObjectName(QStringLiteral("LineNombreAlias"));
        LineNombreAlias->setReadOnly(false);

        gridLayout_2->addWidget(LineNombreAlias, 3, 1, 1, 2);

        imagenlabel = new QLabel(tab);
        imagenlabel->setObjectName(QStringLiteral("imagenlabel"));

        gridLayout_2->addWidget(imagenlabel, 0, 3, 4, 2);


        horizontalLayout_2->addLayout(gridLayout_2);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, icon2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FormArticuloAlias);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormArticuloAlias);
    } // setupUi

    void retranslateUi(QWidget *FormArticuloAlias)
    {
        FormArticuloAlias->setWindowTitle(QApplication::translate("FormArticuloAlias", "Form", 0));
        label->setText(QApplication::translate("FormArticuloAlias", "Codigo:", 0));
        label_3->setText(QApplication::translate("FormArticuloAlias", "Codigo Alias:", 0));
        label_2->setText(QApplication::translate("FormArticuloAlias", "Nombre:", 0));
        guardar->setText(QString());
        modificar->setText(QString());
        eliminar->setText(QString());
        label_4->setText(QApplication::translate("FormArticuloAlias", "Nombre Alias:", 0));
        imagenlabel->setText(QApplication::translate("FormArticuloAlias", "imagen", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
    } // retranslateUi

};

namespace Ui {
    class FormArticuloAlias: public Ui_FormArticuloAlias {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMARTICULOALIAS_H
