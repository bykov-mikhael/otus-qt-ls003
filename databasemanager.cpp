#include "databasemanager.hpp"
#include "header.hpp"

DatabaseManager::DatabaseManager(QObject *parent) : QObject{parent} {}

DatabaseManager::~DatabaseManager() {
  // if (_db.isOpen()) {
  //   _db.close();
  //   ;
  // }
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
  default:
    QMessageBox::information(nullptr, "Other diver", "Incorrect driber name",
                             QMessageBox::Ok);
    break;
  }

  QMessageBox::information(
      nullptr, "Driver name: " + _db.driverName(),
      "Connection name: " + _db.connectionName() + "; Connection parameter: " +
          _db.connectOptions() + "; Database name: " + _db.databaseName(),
      QMessageBox::Ok);
}
