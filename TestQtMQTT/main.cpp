#include <QCoreApplication>
#include <QDebug>
#include <QtMqtt/QtMqtt>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QMqttClient client;
  qDebug() << "QMqttClient" << client.clientId();

  return a.exec();
}
