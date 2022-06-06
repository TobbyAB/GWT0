/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-05-20     admin       the first version
 */
#ifndef APPLICATIONS_FLASHWORK_TEST_H_
#define APPLICATIONS_FLASHWORK_TEST_H_

#include "rtthread.h"
#include "stdint.h"
int flash_Init(void);

#define MaxSupport 50
#define MainSupport 3

typedef struct
{
    uint8_t Num;
    uint8_t MainNum;
    uint8_t Rssi[MaxSupport];
    uint8_t Moto[MaxSupport];
    uint8_t Heart[MaxSupport];
    uint8_t HeartRetry[MaxSupport];
    uint8_t HeartRecv[MaxSupport];
    uint8_t UploadFlag[MaxSupport];
    uint8_t SyncRetry[MaxSupport];
    uint32_t ID[MaxSupport];
    uint32_t Bind_ID[MaxSupport];

} Device_Info;

typedef struct
{
    uint8_t Num;
    uint32_t ID[MaxSupport];
}Remote_Info;

#endif /* APPLICATIONS_FLASHWORK_TEST_H_ */
