#pragma once

#include <QAbstractItemDelegate>
#include <QObject>

class GypDelegate : public QAbstractItemDelegate {
  Q_OBJECT
public:
  explicit GypDelegate(QObject *parent = nullptr);
};
