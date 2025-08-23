#pragma once

#include "header.hpp"

#include <QObject>

class SportmenModel : public QSqlQueryModel {
  Q_OBJECT

public:
  explicit SportmenModel(QObject *parent = nullptr);

  void initializeModel();

  virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

  // QAbstractItemModel interface
public:
  virtual QVariant data(const QModelIndex &index, int role) const override;
};
