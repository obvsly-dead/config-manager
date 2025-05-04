#include "ConfigurationManager.hpp"
#include <QFile>
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

ConfigurationObject::ConfigurationObject(const QString& name, QMap<QString, QVariant> config, QObject* parent)
    : QObject(parent), config_(std::move(config)), name_(name)
{
    QString path = "/com/system/configurationManager/Application/" + name_;
    QDBusConnection::sessionBus().registerObject(path, this, QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals);
    qDebug() << "Registered D-Bus object at" << path;
}

void ConfigurationObject::ChangeConfiguration(const QString& key, const QVariant& value)
{
    config_[key] = value;
    emit configurationChanged(config_);
    qDebug() << "Configuration changed for" << name_ << ":" << config_;
}

QMap<QString, QVariant> ConfigurationObject::GetConfiguration()
{
    qDebug() << "GetConfiguration called for" << name_ << ":" << config_;
    return config_;
}

ConfigurationManager::ConfigurationManager(const QString& configDir)
    : configDir_(configDir)
{
    QDBusConnection::sessionBus().registerService("com.system.configurationManager");
    loadConfigurations();
}

void ConfigurationManager::loadConfigurations()
{
    QDirIterator it(configDir_, QStringList() << "*.json", QDir::Files);
    while (it.hasNext()) {
        QFile file(it.next());
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "Failed to open config file" << file.fileName();
            continue;
        }
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();
        if (!doc.isObject()) {
            qWarning() << "Invalid JSON object in file" << file.fileName();
            continue;
        }
        QJsonObject obj = doc.object();

        QMap<QString, QVariant> config;
        for (auto it = obj.begin(); it != obj.end(); ++it)
            config[it.key()] = it.value().toVariant();

        QString appName = QFileInfo(file).baseName();
        auto* object = new ConfigurationObject(appName, config);
        objects_.append(object);
        qDebug() << "Loaded config for" << appName << ":" << config;
    }
}
