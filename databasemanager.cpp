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

  _db = QSqlDatabase::addDatabase("QSQLITE");
  _db.setDatabaseName(dbName);
  if (!_db.open()) {
    QMessageBox::critical(nullptr, QObject::tr("Can't open database: "),
                          _db.lastError().text(), QMessageBox::Cancel);

    //   switch (dbType) {
    //   case dbType:
    //     _db = QSqlDatabase::addDatabase("QSQLITE");
    //     _db.setDatabaseName(dbName);
    //     if (!_db.open()) {
    //       QMessageBox::critical(nullptr, QObject::tr("Can't open database:
    //       "),
    //                             _db.lastError().text(), QMessageBox::Cancel);
    //     }
    //     break;
    //   }
    // case dbType::Other:
    //   QMessageBox::information(nullptr, QObject::tr("other driver"),
    //                            QObject::tr("in construction"),
    //                            QMessageBox::Ok);
    //   break;
    // default:
    //   QMessageBox::information(nullptr, QObject::tr("unknown driver"),
    //                            QObject::tr("unknown driver"),
    //                            QMessageBox::Ok);
    //   break;
  }
}

void DatabaseManager::initializeModel(QSqlQueryModel *model) {
  model->setQuery("select SPORTMEN.SPORTMAN_FNAME,"
                  "       SPORTMEN.SPORTMAN_MNAME,"
                  "       SPORTMEN.SPORTMAN_LNAME,"
                  "       SPORTMEN.SPORTMAN_PASSPORT_ID,"
                  "       SPORTMEN.SPORTMAN_PASSPORT_DATE,"
                  "       SPORTMEN.SPORTMAN_BIRTHDATE,"
                  "       SPORTMEN.GYP_ID"
                  "from   SPORTMEN");
  // "       GYPS.GYP_NUMBER from SPORTMEN"
  // "       INNER JOIN GYPS on SPORTMEN.GYP_ID = GYPS.GYP_ID");

  model->setHeaderData(0, Qt::Horizontal, "Имя");
  model->setHeaderData(1, Qt::Horizontal, "Отчество");
  model->setHeaderData(2, Qt::Horizontal, "Фамилия");
  model->setHeaderData(3, Qt::Horizontal, "№ паспорта");
  model->setHeaderData(4, Qt::Horizontal, "Дата выдачи");
  model->setHeaderData(5, Qt::Horizontal, "Дата рождения");
  model->setHeaderData(6, Qt::Horizontal, "Гып");
}
