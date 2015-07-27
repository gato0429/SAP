/********************************************************************************
** Form generated from reading UI file 'visorconsultas.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISORCONSULTAS_H
#define UI_VISORCONSULTAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisorConsultas
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *Tabla;

    void setupUi(QWidget *VisorConsultas)
    {
        if (VisorConsultas->objectName().isEmpty())
            VisorConsultas->setObjectName(QStringLiteral("VisorConsultas"));
        VisorConsultas->resize(400, 275);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        VisorConsultas->setFont(font);
        VisorConsultas->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(VisorConsultas);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Tabla = new QTableView(VisorConsultas);
        Tabla->setObjectName(QStringLiteral("Tabla"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 85, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 128, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(212, 106, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 42, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 56, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QRadialGradient gradient(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(255, 235, 235, 206));
        gradient.setColorAt(0.35, QColor(255, 188, 188, 80));
        gradient.setColorAt(0.4, QColor(255, 162, 162, 80));
        gradient.setColorAt(0.425, QColor(255, 132, 132, 156));
        gradient.setColorAt(0.44, QColor(252, 128, 128, 80));
        gradient.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush8(gradient);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush8);
        QBrush brush9(QColor(212, 170, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        QRadialGradient gradient1(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(255, 235, 235, 206));
        gradient1.setColorAt(0.35, QColor(255, 188, 188, 80));
        gradient1.setColorAt(0.4, QColor(255, 162, 162, 80));
        gradient1.setColorAt(0.425, QColor(255, 132, 132, 156));
        gradient1.setColorAt(0.44, QColor(252, 128, 128, 80));
        gradient1.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush12(gradient1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QRadialGradient gradient2(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(255, 235, 235, 206));
        gradient2.setColorAt(0.35, QColor(255, 188, 188, 80));
        gradient2.setColorAt(0.4, QColor(255, 162, 162, 80));
        gradient2.setColorAt(0.425, QColor(255, 132, 132, 156));
        gradient2.setColorAt(0.44, QColor(252, 128, 128, 80));
        gradient2.setColorAt(1, QColor(255, 255, 255, 0));
        QBrush brush14(gradient2);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush14);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Tabla->setPalette(palette);
        Tabla->setStyleSheet(QLatin1String("background-image: url(:/Imagenes/fondos/madera3.jpg);\n"
"selection-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"font: italic 12pt \"Cambria\";\n"
"border-image: url(:/Imagenes/fondos/madera1.jpg);\n"
"gridline-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        Tabla->setGridStyle(Qt::SolidLine);

        horizontalLayout->addWidget(Tabla);


        retranslateUi(VisorConsultas);

        QMetaObject::connectSlotsByName(VisorConsultas);
    } // setupUi

    void retranslateUi(QWidget *VisorConsultas)
    {
        VisorConsultas->setWindowTitle(QApplication::translate("VisorConsultas", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class VisorConsultas: public Ui_VisorConsultas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISORCONSULTAS_H
