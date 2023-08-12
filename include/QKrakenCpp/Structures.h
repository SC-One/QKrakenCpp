#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <QDebug>
#include <QString>
#include <QStringList>

namespace Structures {
enum AssetType { Currency = 0 };
enum AssetStatus {
  enabled,
  deposit_only,
  withdrawal_only,
  funding_temporarily_disabled
};

struct ResponseStatus {
  inline bool isSuccess() const { return errors.isEmpty(); }
  QStringList errors;
};

struct Asset {
  ResponseStatus respStatus;

  QString assetName;
  AssetType aclass;
  QString altname;
  int decimals;
  int display_decimals;
  int collateral_value;
  AssetStatus status;

  operator QString() const {
    static const QString AssetBaseVerbose(
        "assetName: %1\t,"
        "altname: %2\t,"
        "aclass: %3\t,"
        "status: %4");
    QString result =
        AssetBaseVerbose.arg(assetName).arg(altname).arg(aclass).arg(status);
    return result;
  }
};
struct AssetResponse {
  ResponseStatus status;
  QVector<Asset> assets;
  operator QString() const {
    QString AssetBaseVerbose("isOk: %1\t , Errors: %2 \n%3");
    AssetBaseVerbose =
        AssetBaseVerbose.arg((status.isSuccess() ? "True" : "false"))
            .arg(status.errors.join(" , "));
    QStringList assetsStr;
    for (auto const& asset : assets) {
      assetsStr << asset;
    }
    return AssetBaseVerbose.arg(assetsStr.join(" , "));
  }
};

}  // namespace Structures
#endif  // STRUCTURES_H
