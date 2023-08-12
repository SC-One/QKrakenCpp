#ifndef QKRAKENCPP_H
#define QKRAKENCPP_H

#include <QThread>
#include <QThreadPool>
#include <QUrl>

#include "QKrakenCpp_global.h"

class QKRAKENCPP_EXPORT QKrakenCpp {
 public:
  // when I write this library it was correspond to Rest API 1.1.0 in kraken
  // documentations:
  // https://docs.kraken.com/rest/
  static const QString KRAKEN_REST_API_VERSION_DOC;

  static const QUrl PUB_URL;
  static const QUrl URI_TIME;
  static const QUrl URI_SYS_STATUS;
  static const QUrl URI_ASSETS;
  static const QUrl URI_ASSET_PAIRS;
  static const QUrl URI_TICKER;
  static const QUrl URI_OHLC;
  static const QUrl URI_DEPTH;
  static const QUrl URI_TRADES;
  static const QUrl URI_SPREAD;

  static const QUrl PV_URL;

 public:
  QKrakenCpp();
};

#endif  // QKRAKENCPP_H
