#pragma once

#include "header.hpp"

#include <QObject>

enum class dbType { QSQLITE = 0, Other = 1 };

class DatabaseManager : public QObject {
  Q_OBJECT
public:
  explicit DatabaseManager(QObject *parent = nullptr);
  ~DatabaseManager();

  void createConnection(const QString &dbName, const dbType &dbType,
                        const QString &usr, const QString &pwd,
                        const QString &host, const int port);

private:
  QSqlDatabase _db;
  QString _dbName;
  QString _dbType;
  QString _usr;
  QString _pwd;
  QString _host;
  int _port;
};
