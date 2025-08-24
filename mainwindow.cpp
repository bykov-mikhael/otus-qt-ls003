#include "./ui_mainwindow.h"
#include "gypdelegate.hpp"
#include "mainwindow.hpp"

const QString sDBName = "./db/club.db";
const QString sUSR = "usr";
const QString sPWD = "P@$$w0rd";
const QString sHost = "127.0.0.1";
const int iPort = 502;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  connect(ui->aConnectDB, &QAction::triggered, this, [this]() {
    dbManager = new DatabaseManager();

    dbManager->createConnection(sDBName, dbType::QSQLITE, sUSR, sPWD, sHost,
                                iPort);

    model = new SportmenModel();

    GypDelegate *gypDelegate = new GypDelegate();

    model->initializeModel();

    ui->tableView->setModel(model);

    // Назначаем кастомный делеган на поле "гып"
    ui->tableView->setItemDelegateForColumn(7, gypDelegate);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();

    ui->tableView->show();
  });
}

MainWindow::~MainWindow() { delete ui; }
