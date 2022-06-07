/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-06-06     admin       the first version
 */
#include <rtthread.h>
#include <spi_flash.h>
#include <drv_spi.h>
#include "flashwork_test.h"
#include "fal.h"


#include "easyflash.h"


#define DBG_TAG "FLASH"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

rt_spi_flash_device_t fm25q16;

int flash_Init(void)
{
    rt_err_t status = 0;
    extern rt_spi_flash_device_t rt_sfud_flash_probe(const char *spi_flash_dev_name, const char *spi_dev_name);
    status = rt_hw_spi_device_attach("spi1", "spi10", GPIOA, GPIO_PIN_4);
    if (status == 0) {
          LOG_E("spi_init success\r\n");
          return RT_ERROR;
      }
    fm25q16 = rt_sfud_flash_probe("norflash0", "spi10");
    if (RT_NULL == fm25q16) {
        LOG_E("sfud fail\r\n");
        return RT_ERROR;
    }
    status = fal_init();
    if (status == 0) {
        LOG_E("fal_init fail\r\n");
        return RT_ERROR;
    }
    status = easyflash_init();
    if (status != EF_NO_ERR)
    {
        LOG_E("easyflash_init fail\r\n");
        return RT_ERROR;
    }
    LOG_I("Storage Init Success\r\n");
    return RT_EOK;
}


