/********************************************************************************
** Form generated from reading UI file 'busquedamaestra.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSQUEDAMAESTRA_H
#define UI_BUSQUEDAMAESTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BusquedaMaestra
{
public:
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QComboBox *ComboCamposLabel;
    QCheckBox *checkBoxDetalle;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *LineFin_2;

    void setupUi(QWidget *BusquedaMaestra)
    {
        if (BusquedaMaestra->objectName().isEmpty())
            BusquedaMaestra->setObjectName(QStringLiteral("BusquedaMaestra"));
        BusquedaMaestra->resize(195, 133);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        font.setItalic(true);
        BusquedaMaestra->setFont(font);
        BusquedaMaestra->setCursor(QCursor(Qt::ArrowCursor));
        BusquedaMaestra->setWindowOpacity(0);
        label_2 = new QLabel(BusquedaMaestra);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 191, 121));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/fondos/busqueda.png")));
        label_2->setScaledContents(true);
        widget = new QWidget(BusquedaMaestra);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(17, 10, 160, 101));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ComboCamposLabel = new QComboBox(widget);
        ComboCamposLabel->setObjectName(QStringLiteral("ComboCamposLabel"));
        ComboCamposLabel->setMinimumSize(QSize(120, 0));
        ComboCamposLabel->setBaseSize(QSize(150, 0));
        ComboCamposLabel->setMouseTracking(false);
        ComboCamposLabel->setLayoutDirection(Qt::LeftToRight);
        ComboCamposLabel->setAutoFillBackground(false);
        ComboCamposLabel->setStyleSheet(QLatin1String("QComboBox\n"
"    {\n"
"           border: 1px solid gray;\n"
"          border-radius: 10px;\n"
"          padding: 0 8px;\n"
"          background: transparent;\n"
"          selection-background-color: darkgray;\n"
"    }\n"
"\n"
"   QComboBox QListView\n"
"    {\n"
"\n"
"            background: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));\n"
"            color: rgb(220, 220, 220);\n"
"            margin: 0 0 0 0;\n"
"                       border: 1px solid gray;\n"
"                        padding: 0 8px;\n"
"                       selection-background-color: darkgray;\n"
"                      background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));\n"
"       }"));
        ComboCamposLabel->setModelColumn(0);

        verticalLayout_2->addWidget(ComboCamposLabel);

        checkBoxDetalle = new QCheckBox(widget);
        checkBoxDetalle->setObjectName(QStringLiteral("checkBoxDetalle"));
        checkBoxDetalle->setCursor(QCursor(Qt::ArrowCursor));
        checkBoxDetalle->setMouseTracking(true);
        checkBoxDetalle->setContextMenuPolicy(Qt::DefaultContextMenu);
        checkBoxDetalle->setCheckable(true);
        checkBoxDetalle->setTristate(false);

        verticalLayout_2->addWidget(checkBoxDetalle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(68, 16777215));

        horizontalLayout->addWidget(label);

        LineFin_2 = new QSpinBox(widget);
        LineFin_2->setObjectName(QStringLiteral("LineFin_2"));
        LineFin_2->setMaximumSize(QSize(67, 16777215));
        LineFin_2->setBaseSize(QSize(0, 0));
        LineFin_2->setStyleSheet(QLatin1String(" border: 1px solid gray;\n"
" border-radius: 10px;\n"
" padding: 0 8px;\n"
" background: transparent;\n"
" selection-background-color: darkgray;"));
        LineFin_2->setAlignment(Qt::AlignCenter);
        LineFin_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        LineFin_2->setMinimum(1);
        LineFin_2->setMaximum(1000);
        LineFin_2->setValue(100);

        horizontalLayout->addWidget(LineFin_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(BusquedaMaestra);

        QMetaObject::connectSlotsByName(BusquedaMaestra);
    } // setupUi

    void retranslateUi(QWidget *BusquedaMaestra)
    {
        BusquedaMaestra->setWindowTitle(QApplication::translate("BusquedaMaestra", "Form", 0));
        label_2->setText(QString());
        checkBoxDetalle->setText(QApplication::translate("BusquedaMaestra", "Mostrar Detalles", 0));
        label->setText(QApplication::translate("BusquedaMaestra", "Registros:", 0));
    } // retranslateUi

};

namespace Ui {
    class BusquedaMaestra: public Ui_BusquedaMaestra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSQUEDAMAESTRA_H
