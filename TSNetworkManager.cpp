#include "TSNetworkManager.h"

thread_local QNetworkAccessManager network;
QNetworkAccessManager &TSNetworkManager::myNetwork() { return network; }
