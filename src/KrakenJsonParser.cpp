#include <QKrakenCpp/KrakenJsonParser.h>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#define CHECKING_ERROR_PART(rootObj, result) \
  result.status = toRespStatus(rootObj);     \
  if (!result.status.isSuccess()) return result;

using namespace Structures;
static constexpr auto KEY_ERROR_RESPONSE = "error";
static constexpr auto KEY_RESULT_RESPONSE = "result";

static constexpr auto KEY_A_CLASS = "aclass";
static constexpr auto KEY_ALT_NAME = "altname";
static constexpr auto KEY_DECIMALS = "decimals";
static constexpr auto KEY_DISPLAY_DECIMALS = "display_decimals";
static constexpr auto KEY_COLLATERAL_VALUE = "collateral_value";
static constexpr auto KEY_ASSET_STATUS = "status";

static const QHash<QString, AssetType> AssetTypesMap = {
    {"currency", AssetType::Currency}};
static const QHash<QString, AssetStatus> AssetStatusMap = {
    {"enabled", AssetStatus::enabled},
    {"enabled", AssetStatus::deposit_only},
    {"enabled", AssetStatus::withdrawal_only},
    {"enabled", AssetStatus::funding_temporarily_disabled}};

static Asset toAsset(const QJsonObject& obj) {
  Asset result;
  result.aclass = AssetTypesMap[obj[KEY_A_CLASS].toString()];
  result.altname = obj[KEY_ALT_NAME].toString();
  result.decimals = obj[KEY_DECIMALS].toInt();
  result.display_decimals = obj[KEY_DISPLAY_DECIMALS].toInt();
  result.collateral_value = obj[KEY_COLLATERAL_VALUE].toInt();
  result.status = AssetStatusMap[obj[KEY_ASSET_STATUS].toString()];
  return result;
}
static ResponseStatus toRespStatus(const QJsonObject& obj) {
  ResponseStatus result;
  auto const& errorsArray = obj[KEY_ERROR_RESPONSE].toArray();
  for (auto const& errObj : errorsArray) {
    result.errors.push_back(errObj.toString());
  }
  return result;
}

Structures::AssetResponse KrakenJsonParser::parseAssets(
    const QByteArray& rawJson) {
  AssetResponse result;
  QJsonDocument document = QJsonDocument::fromJson(rawJson);
  QJsonObject rootObj = document.object();
  CHECKING_ERROR_PART(rootObj, result);
  {
    auto const& assetsObj = rootObj[KEY_RESULT_RESPONSE].toObject();
    auto const& assetNamess = assetsObj.keys();
    result.assets.reserve(assetNamess.size());
    for (auto const& assetName : assetNamess) {
      Asset tmp = toAsset(assetsObj[assetName].toObject());
      tmp.assetName = assetName;
      result.assets.push_back(tmp);
    }
  }

  return result;
}
