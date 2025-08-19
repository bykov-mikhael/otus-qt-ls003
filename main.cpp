#include "databasemanager.hpp"
#include "header.hpp"
#include "mainwindow.hpp"
#include "sportmenmodel.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow w;

  w.show();

  return a.exec();
}
