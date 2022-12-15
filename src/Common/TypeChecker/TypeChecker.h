#ifndef TYPECHECKER_H
#define TYPECHECKER_H
#include <QObject>
#include <QtGlobal>

class TypeChecker : public QObject
{
    Q_OBJECT
public:
    static void initQML();
    enum class enumTypeCommu : int {
        Multicast,
        Broadcast
    };
    Q_ENUM(enumTypeCommu)

    enum class enumTypeData : int {
        CRL,
        KLV
    };
    Q_ENUM(enumTypeData)

    enum class enumLengthBuff : int {
        LengthFirst,
        LengthSecond,
        LengthThird
    };
    Q_ENUM(enumLengthBuff)
};

#endif // TYPECHECKER_H
