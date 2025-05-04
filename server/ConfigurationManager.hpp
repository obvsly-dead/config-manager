#pragma once

#include <QObject>
#include <QDBusConnection>
#include <QMap>
#include <QString>
#include <QVariant>

class ConfigurationObject : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.system.configurationManager.Application.Configuration")

public:
    ConfigurationObject(const QString& name, QMap<QString, QVariant> config, QObject* parent = nullptr);

public slots:
    void ChangeConfiguration(const QString& key, const QVariant& value);
    QMap<QString, QVariant> GetConfiguration();

signals:
    void configurationChanged(QVariantMap conf);

private:
    QMap<QString, QVariant> config_;
    QString name_;
};

class ConfigurationManager {
public:
    ConfigurationManager(const QString& configDir);
    void loadConfigurations();

private:
    QString configDir_;
    QList<ConfigurationObject*> objects_;
};
