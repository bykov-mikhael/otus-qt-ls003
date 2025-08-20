#pragma once

#include "header.hpp"

#include <QObject>

class SportmenModel : public QSqlQueryModel {
  Q_OBJECT

public:
  explicit SportmenModel(QObject *parent = nullptr);

  void initializeModel();
};
