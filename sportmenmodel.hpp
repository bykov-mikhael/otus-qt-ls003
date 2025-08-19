#pragma once

#include <QObject>
#include <QSqlQueryModel>

class SportmenModel : public QSqlQueryModel {
  Q_OBJECT

public:
  explicit SportmenModel(QObject *parent = nullptr);

  virtual bool setData(const QModelIndex &index, const QVariant &value,
                       int role) override;
  virtual QVariant data(const QModelIndex &index, int role) const override;
  virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

  void initializeModel();
};
