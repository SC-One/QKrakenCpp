#ifndef STRUCTURES_H
#define STRUCTURES_H
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
};
struct AssetResponse {
  ResponseStatus status;
  QVector<Asset> assets;
};

}  // namespace Structures
#endif  // STRUCTURES_H
