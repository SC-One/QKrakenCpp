#include <QKrakenCpp/KrakenJsonParser.h>
#include <QKrakenCpp/QKrakenCpp.h>
#include <QKrakenCpp/TSNetworkManager.h>

#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QUrl>
#include <QtConcurrent>

struct CommonWorker {
  static QThreadPool GLOBAL_THREAD_POOL;

 private:
  void operator=(CommonWorker const &other) = delete;
  CommonWorker(CommonWorker const &other) = delete;
  CommonWorker() = delete;
  CommonWorker(const int num = 10) {
    GLOBAL_THREAD_POOL.setMaxThreadCount(num);
  }

 public:
  static CommonWorker &globalWorker() {
    static auto GB_THREAD_POOL = CommonWorker(12);
    return GB_THREAD_POOL;
  }
  template <typename FUNC>
  auto work(FUNC &&taskFunc) {
    return QtConcurrent::run(&GLOBAL_THREAD_POOL, taskFunc);
  }
};
QThreadPool CommonWorker::GLOBAL_THREAD_POOL = QThreadPool();

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

QFuture<Structures::AssetResponse> QKrakenCpp::assets() const {
  return CommonWorker::globalWorker().work([]() -> Structures::AssetResponse {
    auto &network = TSNetworkManager::myNetwork();
    QNetworkRequest assetRequest(URI_ASSETS);
    assetRequest.setHeader(QNetworkRequest::ContentTypeHeader,
                           "application/json");
    QNetworkReply *response = network.get(assetRequest);
    QEventLoop syncEvent;
    QObject::connect(response, SIGNAL(finished()), &syncEvent, SLOT(quit()));
    syncEvent.exec();
    auto const &result = response->readAll();
    auto parsedResult = KrakenJsonParser::parseAssets(result);
    return parsedResult;
  });
}
