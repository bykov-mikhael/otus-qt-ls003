#include "./ui_mainwindow.h"
#include "mainwindow.hpp"

const QString sDBName = "./club.db";
const QString sUSR = "usr";
const QString sPWD = "P@$$w0rd";
const QString sHost = "localhost";
const int iPort = 502;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  dbManager = new DatabaseManager();
  model = new SportmenModel();

  dbManager->createConnection(sDBName, dbType::QSQLITE, sUSR, sPWD, sHost,
                              iPort);

  dbManager->initializeModel(model);

  ui->tableView->setModel(model);

  ui->tableView->show();
}

MainWindow::~MainWindow() { delete ui; }
