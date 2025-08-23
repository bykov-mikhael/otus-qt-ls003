#include "gypdelegate.hpp"
#include "header.hpp"

GypDelegate::GypDelegate(QObject *parent) : QAbstractItemDelegate{parent} {}

void GypDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const {
  QVariant value = index.data(Qt::DisplayRole);

  QRect rect = option.rect;

  painter->save();

  if (value.isValid()) {
    QLinearGradient gradient(option.rect.topLeft(), option.rect.topRight());

    if (value == "10") {
      gradient.setColorAt(0, Qt::white);
      gradient.setColorAt(1, Qt::white);
    }

    if (value == "9") {
      gradient.setColorAt(0, Qt::white);
      gradient.setColorAt(1, Qt::yellow);
    }

    if (value == "8") {
      gradient.setColorAt(0, Qt::yellow);
      gradient.setColorAt(1, Qt::yellow);
    }

    if (value == "7") {
      gradient.setColorAt(0, Qt::yellow);
      gradient.setColorAt(1, Qt::green);
    }

    if (value == "6") {
      gradient.setColorAt(0, Qt::green);
      gradient.setColorAt(1, Qt::green);
    }

    if (value == "5") {
      gradient.setColorAt(0, Qt::green);
      gradient.setColorAt(1, Qt::blue);
    }

    if (value == "4") {
      gradient.setColorAt(0, Qt::blue);
      gradient.setColorAt(1, Qt::blue);
    }

    if (value == "3") {
      gradient.setColorAt(0, Qt::blue);
      gradient.setColorAt(1, Qt::red);
    }

    if (value == "2") {
      gradient.setColorAt(0, Qt::red);
      gradient.setColorAt(1, Qt::red);
    }

    if (value == "1") {
      gradient.setColorAt(0, Qt::red);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "I") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "II") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "III") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "IV") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "V") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "VI") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "VIII") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "IX") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    if (value == "X") {
      gradient.setColorAt(0, Qt::black);
      gradient.setColorAt(1, Qt::black);
    }

    painter->fillRect(option.rect, gradient);
    painter->setPen(Qt::darkGray);
    painter->drawRect(option.rect);
    painter->drawText(rect.x() + rect.width() / 2,
                      rect.y() + (rect.height() / 2) + 4,
                      index.data().value<QString>());
  } else {
    painter->fillRect(option.rect, option.palette.base());
  }

  painter->restore();
}

QSize GypDelegate::sizeHint(const QStyleOptionViewItem &option,
                            const QModelIndex &index) const {
  return QSize{100, 10};
}
