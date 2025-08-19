#include "databasemanager.hpp"
#include "header.hpp"

DatabaseManager::DatabaseManager(QObject *parent) : QObject{parent} {}

DatabaseManager::~DatabaseManager() {
  if (_db.isOpen()) {
    _db.close();
    ;
  }
}

void DatabaseManager::createConnection(const QString &dbName,
                                       const dbType &dbType, const QString &usr,
                                       const QString &pwd, const QString &host,
                                       const int port) {
  switch (dbType) {
  case dbType::QSQLITE:
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(dbName);
    if (!_db.open()) {
      QMessageBox::critical(nullptr, QObject::tr("Can't open database: "),
                            _db.lastError().text(), QMessageBox::Cancel);
      return;
    }
    break;
  case dbType::Other:
    QMessageBox::information(nullptr, QObject::tr("other driver"),
                             QObject::tr("in construction"), QMessageBox::Ok);
    break;
  default:
    QMessageBox::information(nullptr, QObject::tr("unknown driver"),
                             QObject::tr("unknown driver"), QMessageBox::Ok);
    break;
  }
  QMessageBox::information(
      nullptr, "Driver name: " + _db.driverName(),
      "Connection name: " + _db.connectionName() + "; Connection parameter: " +
          _db.connectOptions() + "; Database name: " + _db.databaseName(),
      QMessageBox::Ok);
}

void DatabaseManager::initializeModel(QSqlQueryModel *model) {
  model->setQuery("select * from sportmen");
  // "       GYPS.GYP_NUMBER from SPORTMEN"
  // "       INNER JOIN GYPS on SPORTMEN.GYP_ID = GYPS.GYP_ID");

  model->setHeaderData(0, Qt::Horizontal, "id");
  model->setHeaderData(1, Qt::Horizontal, "Имя");
  model->setHeaderData(2, Qt::Horizontal, "Отчество");
  model->setHeaderData(3, Qt::Horizontal, "Фамилия");
  model->setHeaderData(4, Qt::Horizontal, "№ паспорта");
  model->setHeaderData(5, Qt::Horizontal, "Дата выдачи");
  model->setHeaderData(6, Qt::Horizontal, "Дата рождения");
  model->setHeaderData(7, Qt::Horizontal, "Гып id");
}
