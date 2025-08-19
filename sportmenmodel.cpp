#include "header.hpp"
#include "sportmenmodel.hpp"

SportmenModel::SportmenModel(QObject *parent) : QSqlQueryModel{parent} {}

bool SportmenModel::setData(const QModelIndex &index, const QVariant &value,
                            int role) {

  // if (index.column() < 1 || index.column() > 2) {
  //   return false;
  // }

  // QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
  // int id = data(primaryKeyIndex).toInt();

  // clear();

  // return bool{};
}

Qt::ItemFlags SportmenModel::flags(const QModelIndex &index) const {
  // Qt::ItemFlag flags = QSqlQueryModel::flags(index);

  // if (index.column() == 0 || index.column() == 2 || index.column() == 3 ||
  //     index.column() == 4 || index.column() == 5 || index.column() == 6) {
  //   return Qt::ItemIsEditable;
  // }

  // return flags;

  // return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

void SportmenModel::initializeModel() {
  this->setQuery("select * from sportmen");
  // "       GYPS.GYP_NUMBER from SPORTMEN"
  // "       INNER JOIN GYPS on SPORTMEN.GYP_ID = GYPS.GYP_ID");

  this->setHeaderData(0, Qt::Horizontal, "id");
  this->setHeaderData(1, Qt::Horizontal, "Имя");
  this->setHeaderData(2, Qt::Horizontal, "Отчество");
  this->setHeaderData(3, Qt::Horizontal, "Фамилия");
  this->setHeaderData(4, Qt::Horizontal, "№ паспорта");
  this->setHeaderData(5, Qt::Horizontal, "Дата выдачи");
  this->setHeaderData(6, Qt::Horizontal, "Дата рождения");
  this->setHeaderData(7, Qt::Horizontal, "Гып id");
}

QVariant SportmenModel::data(const QModelIndex &index, int role) const {
  // QVariant value = QSqlQueryModel::data(index, role);

  // if (role == Qt::ForegroundRole && index.column() == 6) {
  //   return QVariant ::fromValue(QColor(Qt::blue));
  // }
}
