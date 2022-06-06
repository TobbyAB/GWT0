/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-06-06     RT-Thread    first version
 */

#include <rtthread.h>
#include "flashwork_test.h"
#include "stdint.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

int main(void)
{
    int count = 1;
    flash_Init();
    uint8_t i = 1 ;

    while (i++)
    {
        LOG_D("Hello RT-Thread cubemx! %d",i);
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
