#pragma once

#include <QAbstractItemDelegate>
#include <QObject>

class GypDelegate : public QAbstractItemDelegate {
  Q_OBJECT
public:
  explicit GypDelegate(QObject *parent = nullptr);

  // QAbstractItemDelegate interface
public:
  virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,
                     const QModelIndex &index) const override;
  virtual QSize sizeHint(const QStyleOptionViewItem &option,
                         const QModelIndex &index) const override;
};
