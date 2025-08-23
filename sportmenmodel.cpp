#include "header.hpp"
#include "sportmenmodel.hpp"

SportmenModel::SportmenModel(QObject *parent) : QSqlQueryModel{parent} {}

void SportmenModel::initializeModel() {
  this->setQuery("SELECT SPORTMEN.SPORTMAN_FNAME, "
                 "       SPORTMEN.SPORTMAN_MNAME, "
                 "       SPORTMEN.SPORTMAN_LNAME, "
                 "       SPORTMEN.SPORTMAN_BIRTHDATE, "
                 "       SPORTMEN.SPORTMAN_PASSPORT_ID,"
                 "       SPORTMEN.SPORTMAN_PASSPORT_DATE, "
                 "       GYPS.GYP_NUMBER, "
                 "       GYPS.BELT_COLOR "
                 "FROM SPORTMEN "
                 "INNER JOIN GYPS ON SPORTMEN.GYP_ID = GYPS.GYP_ID");

  this->setHeaderData(0, Qt::Horizontal, "Имя");
  this->setHeaderData(1, Qt::Horizontal, "Отчество");
  this->setHeaderData(2, Qt::Horizontal, "Фамилия");
  this->setHeaderData(3, Qt::Horizontal, "№ паспорта");
  this->setHeaderData(4, Qt::Horizontal, "Дата выдачи");
  this->setHeaderData(5, Qt::Horizontal, "Дата рождения");
  this->setHeaderData(6, Qt::Horizontal, "Гып");
  this->setHeaderData(7, Qt::Horizontal, "Пояс");
}

Qt::ItemFlags SportmenModel::flags(const QModelIndex &index) const {
  Qt::ItemFlags flags = QSqlQueryModel::flags(index);
  if (index.column() == 0 || index.column() == 1 || index.column() == 2 ||
      index.column() == 3 || index.column() == 4 || index.column() == 5 ||
      index.column() == 6 || index.column() == 7)
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
  /* ****************************************************
   * Закраска номера гыпа в соответствии с цветов пояса *
   *  FIXME необходимо разобраться как вернуть размеры
   *  ячейки, чтобы указать в качестве параметра при
   *  градиенте
   * **************************************************/
  if (role == Qt::BackgroundRole && index.column() == 6) {
    QLinearGradient gradient(0, 0, 100, 0);
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::yellow);
    return QBrush(gradient);
  }
  return QSqlQueryModel::data(index, role);
  /****************************************************************************
   * NOTE - сделать всплывающее окно настройки, чтобы можно было жирным шрифтом
   * подсвечивать интересющие записи
   ****************************************************************************/
  if (role == Qt::FontRole && index.column() == 6) {
    QVariant value = QSqlQueryModel::data(index, Qt::DisplayRole);
    if (value.toString().toLower() == "10") {
      QFont font;
      font.setBold(true);
      return font;
    }
  }

  return QSqlQueryModel::data(index, role);
}
