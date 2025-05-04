#include "ConfigurationManager.hpp"
#include <QCoreApplication>

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    ConfigurationManager manager("configs");
    return app.exec();
}
