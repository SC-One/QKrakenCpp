#ifndef KRAKENJSONPARSER_H
#define KRAKENJSONPARSER_H
#include <Structures.h>

#include <QByteArray>

class KrakenJsonParser {
 public:
  static Structures::AssetResponse parseAssets(QByteArray const& rawJson);
};

#endif  // KRAKENJSONPARSER_H
