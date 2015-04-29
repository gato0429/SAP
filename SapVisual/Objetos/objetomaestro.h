#ifndef OBJETOMAESTRO_H
#define OBJETOMAESTRO_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
#include <QFile>
#include <QIcon>
#include <QSqlError>
#include "../Extras/mensajeemergente.h"

using namespace std;
class ObjetoMaestro:public QIcon
{
public:
    ObjetoMaestro();
    virtual ~ObjetoMaestro()=0;
};

#endif // OBJETOMAESTRO_H
