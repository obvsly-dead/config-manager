#include "ConfManagerApplication.hpp"
#include <QCoreApplication>
#include <QTimer>
#include <QMetaType>
#include <QVariant>
#include <QVariantMap>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Регистрация необходимых типов для Qt D-Bus
    qRegisterMetaType<QVariant>("QVariant");
    qRegisterMetaType<QVariantMap>("QVariantMap");

    ConfManagerApplication confApp;
    QTimer::singleShot(0, [&]() { confApp.run(); });

    return app.exec();
}
