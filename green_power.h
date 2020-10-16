/*
 * Copyright (c) 2020 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */


#ifndef GREEN_POWER_H
#define GREEN_POWER_H

#include <array>
#include <deconz.h>

#define GREEN_POWER_CLUSTER_ID  0x0021
#define GREEN_POWER_ENDPOINT    0xf2
#define GP_SECURITY_KEY_SIZE 16

using GpKey_t = std::array<unsigned char, GP_SECURITY_KEY_SIZE>;

GpKey_t GP_DecryptSecurityKey(quint32 sourceID, const GpKey_t &securityKey);
bool GP_SendProxyCommissioningMode(deCONZ::ApsController *apsCtrl, quint8 zclSeqNo);
bool GP_SendPairing(quint32 gpdSrcId, quint16 sinkGroupId, quint8 deviceId, quint32 frameCounter, const GpKey_t &key, deCONZ::ApsController *apsCtrl, quint8 zclSeqNo);

#endif // GREEN_POWER_H
