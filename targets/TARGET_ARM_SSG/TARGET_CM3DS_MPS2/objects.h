/* mbed Microcontroller Library
 * Copyright (c) 2006-2017 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __MBED_OBJECTS_H__
#define __MBED_OBJECTS_H__

#include "cmsis.h"
#include "PortNames.h"
#include "PeripheralNames.h"
#include "PinNames.h"
#include "platform_devices.h"
#include "gpio_objects.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gpio_s {
    struct arm_gpio_dev_t *gpio_dev;
    struct arm_mps2_io_dev_t *mps2_io_dev;
    uint32_t pin_number;
    PinDirection direction;
} gpio_t;

struct gpio_irq_s {
    struct arm_gpio_dev_t *gpio_dev;
    uint32_t pin_number;             /* Pin number inside the GPIO */
    uint32_t exp_pin_number;         /* Pin number on the expension port */
    IRQn_Type irq_number;            /* IRQ number of the GPIO interrupt of
                                        this pin */
};

struct port_s {
    struct arm_gpio_dev_t *gpio_dev;
};

struct serial_s {
    CMSDK_UART_TypeDef *uart;
    int index;
};

struct i2c_s {
    MPS2_I2C_TypeDef *i2c;
    uint32_t freq_us;       /* Stores I2C frequency in microseconds */
};

struct tsc_s {
    MPS2_I2C_TypeDef *tsc;
};

struct audio_s {
    MPS2_I2S_TypeDef *audio_I2S;
    MPS2_I2C_TypeDef *audio_I2C;
};

struct spi_s {
    MPS2_SSP_TypeDef *spi;
};

struct clcd_s {
    MPS2_SSP_TypeDef *clcd;
};

struct analogin_s {
    uint16_t ctrl_register;  /* Control bits with the channel identifier */
};

#ifdef __cplusplus
}
#endif

#endif /* __MBED_OBJECTS_H__ */
