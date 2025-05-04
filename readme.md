# CONFIG-MANAGER

Проект демонстрирует использование **QtDBus** для реализации D-Bus сервиса конфигурации и клиента, подписанного на сигналы.

## Структура

- **server/** — Qt-приложение, предоставляющее D-Bus сервис. Загружает конфигурации из JSON-файлов и предоставляет доступ к ним.
- **app/** — Qt-клиент, подключающийся к серверу и реагирующий на сигналы конфигурации.
- **configs/** — JSON-файлы с конфигурациями для приложений.

## Пример конфигурации

```json
{
  "Timeout": 2000,
  "TimeoutPhrase": "i can't stop! prrr"
}
```

## Сборка

```bash
mkdir -p build
cd build
cmake ..
make -j$(nproc)
```

## Запуск

Запусти сервер в одной консоли:

```bash
./build/server/config_server
```

А затем клиент в другой:

```bash
./build/app/conf_manager_app
```

### Что произойдет

- Сервер зарегистрирует конфигурацию по пути `/com/system/configurationManager/Application/confManagerApplication1`.
- Клиент подключится к этому объекту, получит конфигурацию и начнёт печатать `TimeoutPhrase` каждые `Timeout` миллисекунд.
- Если сервер завершит работу — клиент автоматически выйдет.

## Интерфейс

**Service name:** `com.system.configurationManager`  
**Object path:** `/com/system/configurationManager/Application/<appName>`  
**Interface:** `com.system.configurationManager.Application.Configuration`

### Методы:
- `QMap<QString, QVariant> GetConfiguration()`
- `void ChangeConfiguration(QString key, QVariant value)`

### Сигналы:
- `void configurationChanged(QVariantMap config)`

## Особенности

- Используется `QDBusInterface` для вызова методов и подписки на сигналы.
- Конфигурация автоматически применяется при изменении.
- Клиент следит за наличием сервиса через `isServiceRegistered`.
