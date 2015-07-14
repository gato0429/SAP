/********************************************************************************
** Form generated from reading UI file 'formempleado.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEMPLEADO_H
#define UI_FORMEMPLEADO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEmpleado
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *BotonGuardar;
    QPushButton *BotonModificar;
    QPushButton *BotonEliminar;
    QPushButton *BotonEliminar_2;
    QGridLayout *gridLayout_2;
    QLineEdit *LineNombre;
    QLabel *label_10;
    QComboBox *ComboSexo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *LineMail;
    QLabel *label_6;
    QLabel *label_7;
    QDateEdit *DateIngreso;
    QLineEdit *LineDni;
    QLineEdit *LineDireccion;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *LineTelefono;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer;
    QLabel *label_12;
    QLineEdit *LineCodigo;
    QLineEdit *LineCodigo_Interno;
    QLabel *label_13;
    QDoubleSpinBox *LineDescuento;
    QFrame *line_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *FormEmpleado)
    {
        if (FormEmpleado->objectName().isEmpty())
            FormEmpleado->setObjectName(QStringLiteral("FormEmpleado"));
        FormEmpleado->resize(377, 441);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        font.setItalic(true);
        FormEmpleado->setFont(font);
        FormEmpleado->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(FormEmpleado);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(FormEmpleado);
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
"\n"
"\n"
""));
        tabWidget->setTabPosition(QTabWidget::East);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(30, 30));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(-1, -1, -1, 33);
        BotonGuardar = new QPushButton(tab);
        BotonGuardar->setObjectName(QStringLiteral("BotonGuardar"));
        BotonGuardar->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Imagenes/iconos/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonGuardar->setIcon(icon);
        BotonGuardar->setIconSize(QSize(40, 40));
        BotonGuardar->setFlat(true);

        verticalLayout->addWidget(BotonGuardar);

        BotonModificar = new QPushButton(tab);
        BotonModificar->setObjectName(QStringLiteral("BotonModificar"));
        BotonModificar->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Imagenes/iconos/editar.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonModificar->setIcon(icon1);
        BotonModificar->setIconSize(QSize(40, 40));
        BotonModificar->setFlat(true);

        verticalLayout->addWidget(BotonModificar);

        BotonEliminar = new QPushButton(tab);
        BotonEliminar->setObjectName(QStringLiteral("BotonEliminar"));
        BotonEliminar->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Imagenes/iconos/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonEliminar->setIcon(icon2);
        BotonEliminar->setIconSize(QSize(40, 40));
        BotonEliminar->setFlat(true);

        verticalLayout->addWidget(BotonEliminar);

        BotonEliminar_2 = new QPushButton(tab);
        BotonEliminar_2->setObjectName(QStringLiteral("BotonEliminar_2"));
        BotonEliminar_2->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Imagenes/iconos/izquierda.png"), QSize(), QIcon::Normal, QIcon::Off);
        BotonEliminar_2->setIcon(icon3);
        BotonEliminar_2->setIconSize(QSize(40, 40));
        BotonEliminar_2->setFlat(true);

        verticalLayout->addWidget(BotonEliminar_2);


        gridLayout->addLayout(verticalLayout, 5, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        LineNombre = new QLineEdit(tab);
        LineNombre->setObjectName(QStringLiteral("LineNombre"));
        LineNombre->setFont(font);

        gridLayout_2->addWidget(LineNombre, 4, 2, 1, 3);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        ComboSexo = new QComboBox(tab);
        ComboSexo->setObjectName(QStringLiteral("ComboSexo"));
        ComboSexo->setFont(font);

        gridLayout_2->addWidget(ComboSexo, 3, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 9, 4, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_2->addWidget(label_5, 8, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 5, 0, 1, 1);

        LineMail = new QLineEdit(tab);
        LineMail->setObjectName(QStringLiteral("LineMail"));
        LineMail->setFont(font);

        gridLayout_2->addWidget(LineMail, 6, 2, 1, 3);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 9, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        DateIngreso = new QDateEdit(tab);
        DateIngreso->setObjectName(QStringLiteral("DateIngreso"));
        DateIngreso->setFont(font);
        DateIngreso->setCalendarPopup(true);

        gridLayout_2->addWidget(DateIngreso, 9, 2, 1, 1);

        LineDni = new QLineEdit(tab);
        LineDni->setObjectName(QStringLiteral("LineDni"));
        LineDni->setFont(font);

        gridLayout_2->addWidget(LineDni, 2, 2, 1, 3);

        LineDireccion = new QLineEdit(tab);
        LineDireccion->setObjectName(QStringLiteral("LineDireccion"));
        LineDireccion->setFont(font);

        gridLayout_2->addWidget(LineDireccion, 5, 2, 1, 3);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 8, 4, 1, 1);

        LineTelefono = new QLineEdit(tab);
        LineTelefono->setObjectName(QStringLiteral("LineTelefono"));
        LineTelefono->setFont(font);

        gridLayout_2->addWidget(LineTelefono, 7, 2, 1, 3);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        gridLayout_2->addWidget(label_11, 7, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(172, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 4, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        gridLayout_2->addWidget(label_12, 8, 3, 1, 1);

        LineCodigo = new QLineEdit(tab);
        LineCodigo->setObjectName(QStringLiteral("LineCodigo"));
        LineCodigo->setFont(font);
        LineCodigo->setReadOnly(true);

        gridLayout_2->addWidget(LineCodigo, 0, 2, 1, 1);

        LineCodigo_Interno = new QLineEdit(tab);
        LineCodigo_Interno->setObjectName(QStringLiteral("LineCodigo_Interno"));
        LineCodigo_Interno->setFont(font);
        LineCodigo_Interno->setReadOnly(false);

        gridLayout_2->addWidget(LineCodigo_Interno, 1, 2, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        LineDescuento = new QDoubleSpinBox(tab);
        LineDescuento->setObjectName(QStringLiteral("LineDescuento"));
        LineDescuento->setFont(font);
        LineDescuento->setAlignment(Qt::AlignCenter);
        LineDescuento->setButtonSymbols(QAbstractSpinBox::NoButtons);
        LineDescuento->setProperty("showGroupSeparator", QVariant(false));

        gridLayout_2->addWidget(LineDescuento, 8, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 5, 0, 1, 1);

        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFont(font);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 5, 1, 1, 1);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 3, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(60, 80));
        label_15->setFont(font);

        horizontalLayout_3->addWidget(label_15);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_8);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(60, 80));
        label_9->setBaseSize(QSize(50, 0));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 3);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Imagenes/iconos/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon4, QString());

        horizontalLayout->addWidget(tabWidget);

        QWidget::setTabOrder(LineCodigo, LineCodigo_Interno);
        QWidget::setTabOrder(LineCodigo_Interno, LineDni);
        QWidget::setTabOrder(LineDni, ComboSexo);
        QWidget::setTabOrder(ComboSexo, LineNombre);
        QWidget::setTabOrder(LineNombre, LineDireccion);
        QWidget::setTabOrder(LineDireccion, LineMail);
        QWidget::setTabOrder(LineMail, LineTelefono);
        QWidget::setTabOrder(LineTelefono, DateIngreso);
        QWidget::setTabOrder(DateIngreso, tabWidget);

        retranslateUi(FormEmpleado);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormEmpleado);
    } // setupUi

    void retranslateUi(QWidget *FormEmpleado)
    {
        FormEmpleado->setWindowTitle(QApplication::translate("FormEmpleado", "Form", 0));
        BotonGuardar->setText(QString());
        BotonModificar->setText(QString());
        BotonEliminar->setText(QString());
        BotonEliminar_2->setText(QString());
        label_10->setText(QApplication::translate("FormEmpleado", "Codigo:", 0));
        ComboSexo->clear();
        ComboSexo->insertItems(0, QStringList()
         << QApplication::translate("FormEmpleado", "Masculino", 0)
         << QApplication::translate("FormEmpleado", "Femenino", 0)
        );
        label_4->setText(QApplication::translate("FormEmpleado", "E-mail:", 0));
        label_5->setText(QApplication::translate("FormEmpleado", "Descuento:", 0));
        label_3->setText(QApplication::translate("FormEmpleado", "Direcci\303\263n:", 0));
        label_6->setText(QApplication::translate("FormEmpleado", "Fecha Ingreso:", 0));
        label_7->setText(QApplication::translate("FormEmpleado", "Sexo:", 0));
        label_2->setText(QApplication::translate("FormEmpleado", "Nombre:", 0));
        label->setText(QApplication::translate("FormEmpleado", "Dni:", 0));
        label_11->setText(QApplication::translate("FormEmpleado", "Telefono:", 0));
        label_12->setText(QApplication::translate("FormEmpleado", "%", 0));
        label_13->setText(QApplication::translate("FormEmpleado", "Codigo Interno:", 0));
        label_15->setText(QApplication::translate("FormEmpleado", "TextLabel", 0));
        label_8->setText(QApplication::translate("FormEmpleado", "Empleado", 0));
        label_9->setText(QApplication::translate("FormEmpleado", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
    } // retranslateUi

};

namespace Ui {
    class FormEmpleado: public Ui_FormEmpleado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEMPLEADO_H
