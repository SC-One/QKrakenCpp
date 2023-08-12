#include "QKrakenCpp.h"

#include <QString>
#include <QUrl>

static QThreadPool GLOBAL_THREAD_POOL = QThreadPool();
struct ThreadPoolNumInitiator {
  ThreadPoolNumInitiator(QThreadPool* pool, const int num = 10) {
    Q_ASSERT(nullptr != pool);
    pool->setMaxThreadCount(num);
  }
};

static auto FAKE_USELESS_IN_CODE = ThreadPoolNumInitiator(&GLOBAL_THREAD_POOL);

const QString QKrakenCpp::KRAKEN_REST_API_VERSION_DOC = "1.1.0";

const QUrl QKrakenCpp::PUB_URL = QUrl("https://api.kraken.com/0/public/");
const QUrl QKrakenCpp::URI_TIME = PUB_URL.resolved(QUrl("Time"));
const QUrl QKrakenCpp::URI_SYS_STATUS = PUB_URL.resolved(QUrl("SystemStatus"));
const QUrl QKrakenCpp::URI_ASSETS = PUB_URL.resolved(QUrl("Assets"));
const QUrl QKrakenCpp::URI_ASSET_PAIRS = PUB_URL.resolved(QUrl("AssetPairs"));
const QUrl QKrakenCpp::URI_TICKER = PUB_URL.resolved(QUrl("Ticker"));
const QUrl QKrakenCpp::URI_OHLC = PUB_URL.resolved(QUrl("OHLC"));
const QUrl QKrakenCpp::URI_DEPTH = PUB_URL.resolved(QUrl("Depth"));
const QUrl QKrakenCpp::URI_TRADES = PUB_URL.resolved(QUrl("Trades"));
const QUrl QKrakenCpp::URI_SPREAD = PUB_URL.resolved(QUrl("Spread"));

const QUrl QKrakenCpp::PV_URL = QUrl("https://api.kraken.com/0/private/");

QKrakenCpp::QKrakenCpp() {}
