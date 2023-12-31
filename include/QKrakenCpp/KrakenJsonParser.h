#ifndef KRAKENJSONPARSER_H
#define KRAKENJSONPARSER_H
#include <QKrakenCpp/Structures.h>

#include <QByteArray>

class KrakenJsonParser {
 public:
  static Structures::AssetResponse parseAssets(QByteArray const& rawJson);
};

#endif  // KRAKENJSONPARSER_H
