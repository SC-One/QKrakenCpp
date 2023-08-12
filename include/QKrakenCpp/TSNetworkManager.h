#ifndef TSNETWORKMANAGER_H
#define TSNETWORKMANAGER_H
#include <QMap>
#include <QNetworkAccessManager>

/// \brief network manager per thread.
class TSNetworkManager {
 public:
  static QNetworkAccessManager& myNetwork();
};

#endif  // TSNETWORKMANAGER_H
