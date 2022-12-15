#include "TypeChecker.h"
#include <QtQml>
#include <QMetaType>


void TypeChecker::initQML()
{
    qmlRegisterUncreatableType<TypeChecker>("TApplication", 1, 0, "TypeChecker",
                                             "Cannot create TypeChecker in QML");
}
