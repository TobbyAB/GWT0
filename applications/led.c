/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-06-08     admin       the first version
 */
#include <rtthread.h>
#include "stdint.h"
#include "device.h"
#include "pin_config.h"
#include <pin.h>

#define DBG_TAG "LED"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

static agile_led_t *RF_G = RT_NULL;
static agile_led_t *RF_R = RT_NULL;
static agile_led_t *WIFI_R = RT_NULL;
static agile_led_t *WIFI_B = RT_NULL;
static agile_led_t *beep = RT_NULL;

void LED_Init(void)
{
    if (RF_G == RT_NULL)
    {
        RF_G = agile_led_create(LED1_PIN, PIN_LOW, "200,200", -1);
    }
    if (RF_R == RT_NULL)
    {
        RF_R = agile_led_create(LED2_PIN, PIN_LOW, "200,200", -1);
    }
    if (WIFI_R == RT_NULL)
    {
        WIFI_R = agile_led_create(LED3_PIN, PIN_LOW, "200,200", -1);
    }
    if (WIFI_B == RT_NULL)
    {
        WIFI_B = agile_led_create(LED4_PIN, PIN_LOW, "200,200", -1);
    }
    if (beep == RT_NULL)
    {
        beep = agile_led_create(BUZZER_PIN, PIN_HIGH, "200,200", -1);
    }
}

void beep_start(uint8_t count)
{
    agile_led_stop(beep);
    agile_led_set_light_mode(beep, "200,200", count);
    agile_led_start(beep);
}

void beep_power(uint8_t count)
{
    agile_led_stop(beep);
    agile_led_set_light_mode(beep, "400,400", count);
    agile_led_start(beep);
}

void wifi_led(uint8_t type)
{
    switch (type)
    {
        case 0://启动失败
            agile_led_stop(WIFI_R);
            agile_led_stop(WIFI_B);
            break;
        case 1://AP慢闪
            agile_led_stop(WIFI_B);
            agile_led_set_light_mode(WIFI_R, "1000,1000", -1);
            agile_led_stop(WIFI_R);
            break;
        case 2://已配置
            agile_led_stop(WIFI_R);
            agile_led_stop(WIFI_B);
            break;
        case 3:
            agile_led_stop(WIFI_R);
            agile_led_stop(WIFI_B);
            break;
        case 4:
            agile_led_stop(WIFI_R);
            agile_led_stop(WIFI_B);
            break;
        default:
            break;
    }
}
