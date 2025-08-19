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

  return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

QVariant SportmenModel::data(const QModelIndex &index, int role) const {
  // QVariant value = QSqlQueryModel::data(index, role);

  // if (role == Qt::ForegroundRole && index.column() == 6) {
  //   return QVariant ::fromValue(QColor(Qt::blue));
  // }
}
