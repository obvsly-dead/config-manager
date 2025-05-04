#pragma once

#include <QObject>
#include <QDBusInterface>
#include <QDBusConnection>
#include <QVariantMap>
#include <QTimer>

class ConfManagerApplication : public QObject {
    Q_OBJECT
public:
    ConfManagerApplication();
    void run();

public slots:
    void onConfigurationChanged(QVariantMap conf);
    void checkServer();

private:
    QDBusInterface* interface_;
    QTimer* loopTimer_;
    QTimer* serverCheckTimer_;
    uint timeout_ = 1000;
    QString phrase_ = "Default";
};
