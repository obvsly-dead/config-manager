#include "ConfManagerApplication.hpp"
#include <QDBusMessage>
#include <QDBusConnectionInterface>
#include <QVariant>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include <QMetaType>

ConfManagerApplication::ConfManagerApplication() {
    qRegisterMetaType<QVariantMap>("QVariantMap"); // регистрация типа

    timeout_ = 1000;
    phrase_ = "Default";

    loopTimer_ = new QTimer(this);
    connect(loopTimer_, &QTimer::timeout, this, [this]() {
        qDebug() << phrase_;
    });

    interface_ = new QDBusInterface(
        "com.system.configurationManager",
        "/com/system/configurationManager/Application/confManagerApplication1",
        "com.system.configurationManager.Application.Configuration",
        QDBusConnection::sessionBus(), this);

    if (!interface_->isValid()) {
        qWarning() << "Interface is not valid.";
        return;
    }

    QDBusConnection::sessionBus().connect(
        "com.system.configurationManager",
        "/com/system/configurationManager/Application/confManagerApplication1",
        "com.system.configurationManager.Application.Configuration",
        "configurationChanged",
        this,
        SLOT(onConfigurationChanged(QVariantMap)));

    QDBusMessage reply = interface_->call("GetConfiguration");
    if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().size() > 0) {
        QVariantMap conf = qdbus_cast<QVariantMap>(reply.arguments().at(0));
        qDebug() << "Parsed config:" << conf;
        onConfigurationChanged(conf);
    } else {
        qWarning() << "Failed to get initial configuration.";
    }

    serverCheckTimer_ = new QTimer(this);
    connect(serverCheckTimer_, &QTimer::timeout, this, &ConfManagerApplication::checkServer);
    serverCheckTimer_->start(2000); // check every 2 sec
}

void ConfManagerApplication::onConfigurationChanged(QVariantMap conf) {
    qDebug() << "Received config map:" << conf;
    if (conf.contains("Timeout"))
        timeout_ = conf["Timeout"].toUInt();
    if (conf.contains("TimeoutPhrase"))
        phrase_ = conf["TimeoutPhrase"].toString();
    if (loopTimer_)
        loopTimer_->start(timeout_);
}

void ConfManagerApplication::checkServer() {
    bool available = QDBusConnection::sessionBus().interface()->isServiceRegistered("com.system.configurationManager");
    if (!available) {
        qWarning() << "Server is no longer available. Exiting.";
        QCoreApplication::quit();
    }
}

void ConfManagerApplication::run() {
    if (loopTimer_)
        loopTimer_->start(timeout_);
}
