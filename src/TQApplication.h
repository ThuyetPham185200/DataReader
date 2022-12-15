#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>

// Work around circular header includes
class TToolBox;

class TQApplication : public QApplication {
    Q_OBJECT
public:
    TQApplication(int &argc, char *argv[]);
    ~TQApplication();

    // Still working on getting rid of this and using dependency injection instead for everything
    TToolBox *toolbox(void) {
        return toolbox_;
    }

    QQmlApplicationEngine *qmlAppEngine(void) {
        return qmlAppEngine_;
    }

public:
    /// @brief Perform initialize which is common to both normal application running and unit tests.
    ///         Although public should only be called by main.
    void initCommon();

    /// @brief Initialize the application for normal application boot. Or in other words we are not going to run
    ///         unit tests. Although public should only be called by main.
    bool initForNormalApp();

    static TQApplication  *app_;   ///< Our own singleton. Should be reference directly by qdtApp

    /// Shutdown the application object
    void shutdown();

private:
    /// @brief Initialize the automatic process.
    void startAutoProcess();

private:
    QQmlApplicationEngine *qmlAppEngine_    = nullptr;
    TToolBox            *toolbox_         = nullptr;
};

/// @brief Returns the QDTApplication object singleton.
TQApplication *qdtApp(void);


#endif // TAPPLICATION_H
