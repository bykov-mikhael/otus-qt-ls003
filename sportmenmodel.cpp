#include "header.hpp"
#include "sportmenmodel.hpp"

SportmenModel::SportmenModel(QObject *parent) : QSqlQueryModel{parent} {}

void SportmenModel::initializeModel() {
  this->setQuery("select * from sportmen");
  // "       GYPS.GYP_NUMBER from SPORTMEN"
  // "       INNER JOIN GYPS on SPORTMEN.GYP_ID = GYPS.GYP_ID");

  this->setHeaderData(0, Qt::Horizontal, "Спортсмен id");
  this->setHeaderData(1, Qt::Horizontal, "Имя");
  this->setHeaderData(2, Qt::Horizontal, "Отчество");
  this->setHeaderData(3, Qt::Horizontal, "Фамилия");
  this->setHeaderData(4, Qt::Horizontal, "№ паспорта");
  this->setHeaderData(5, Qt::Horizontal, "Дата выдачи");
  this->setHeaderData(6, Qt::Horizontal, "Дата рождения");
  this->setHeaderData(7, Qt::Horizontal, "Гып id");
}
