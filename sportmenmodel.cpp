#include "header.hpp"
#include "sportmenmodel.hpp"

SportmenModel::SportmenModel(QObject *parent) : QSqlQueryModel{parent} {}

void SportmenModel::initializeModel() {
  this->setQuery("SELECT SPORTMEN.SPORTMAN_ID, "
                 "       SPORTMEN.SPORTMAN_FNAME, "
                 "       SPORTMEN.SPORTMAN_MNAME, "
                 "       SPORTMEN.SPORTMAN_LNAME, "
                 "       SPORTMEN.SPORTMAN_BIRTHDATE, "
                 "       SPORTMEN.SPORTMAN_PASSPORT_ID,"
                 "       SPORTMEN.SPORTMAN_PASSPORT_DATE, "
                 "       GYPS.GYP_NUMBER, "
                 "       GYPS.BELT_COLOR "
                 "FROM SPORTMEN "
                 "INNER JOIN GYPS ON SPORTMEN.GYP_ID = GYPS.GYP_ID");

  this->setHeaderData(0, Qt::Horizontal, "ID");
  this->setHeaderData(1, Qt::Horizontal, "Имя");
  this->setHeaderData(2, Qt::Horizontal, "Отчество");
  this->setHeaderData(3, Qt::Horizontal, "Фамилия");
  this->setHeaderData(4, Qt::Horizontal, "№ паспорта");
  this->setHeaderData(5, Qt::Horizontal, "Дата выдачи");
  this->setHeaderData(6, Qt::Horizontal, "Дата рождения");
  this->setHeaderData(7, Qt::Horizontal, "Гып");
  this->setHeaderData(8, Qt::Horizontal, "Пояс");
}

Qt::ItemFlags SportmenModel::flags(const QModelIndex &index) const {
  Qt::ItemFlags flags = QSqlQueryModel::flags(index);
  if (index.column() == 1 || index.column() == 2 || index.column() == 3 ||
      index.column() == 4 || index.column() == 5 || index.column() == 6 ||
      index.column() == 7 || index.column() == 8)
    flags |= Qt::ItemIsEditable;
  return flags;
}

QVariant SportmenModel::data(const QModelIndex &index, int role) const {
  /***********************************************************************
   * Обработка NULL-значений, без этой части кода при запуске приложение *
   * вылетает                                                            *
   **********************************************************************/
  if (role == Qt::DisplayRole) {
    QVariant value = QSqlQueryModel::data(index, role);

    if (value.isNull() || value.toString().isEmpty()) {
      return tr("Не указано");
    }
  }
  /****************************************************************************
   * NOTE - сделать всплывающее окно настройки, чтобы можно было жирным шрифтом
   * подсвечивать интересющие записи
   ****************************************************************************/
  if (role == Qt::FontRole && index.column() == 7) {
    QVariant value = QSqlQueryModel::data(index, Qt::DisplayRole);
    if (value.toString().toLower() == "10") {
      QFont font;
      font.setBold(true);
      return font;
    }
  }

  return QSqlQueryModel::data(index, role);
}

bool SportmenModel::setData(const QModelIndex &index, const QVariant &value,
                            int role) {
  // QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
  // int id = data(primaryKeyIndex).toInt();

  // QSqlQuery query;

  // query.prepare(
  //     "UPDATE sportmen  SPORTMEN.SPORTMAN_FNAME = :SPORTMAN_FNAME, "
  //     "                 SPORTMEN.SPORTMAN_MNAME = :SPORTMAN_MNAME, "
  //     "                 SPORTMEN.SPORTMAN_LNAME = :SPORTMAN_LNAME, "
  //     "                 SPORTMEN.SPORTMAN_BIRTHDATE = :SPORTMAN_BIRTHDATE, "
  //     "                 SPORTMEN.SPORTMAN_PASSPORT_ID =
  //     :SPORTMAN_PASSPORT_ID, " " SPORTMEN.SPORTMAN_PASSPORT_DATE = "
  //     ":SPORTMAN_PASSPORT_DATE "
  //     "WHERE            SPORTMEN.SPORTMAN_ID = :SPORTMAN_ID");
  // query.bindValue(":SPORTMAN_FNAME", index.data().value<QString>());
}
