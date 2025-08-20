#include "./ui_mainwindow.h"
#include "mainwindow.hpp"

const QString sDBName = "./db/club.db";
const QString sUSR = "usr";
const QString sPWD = "P@$$w0rd";
const QString sHost = "127.0.0.1";
const int iPort = 502;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(sDBName);
  db.open();
  // dbManager->createConnection(sDBName, dbType::QSQLITE, sUSR, sPWD, sHost,
  //                             iPort);

  model = new SportmenModel();

  model->initializeModel();

  ui->tableView->setModel(model);

  ui->tableView->show();
}

MainWindow::~MainWindow() { delete ui; }
