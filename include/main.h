#pragma once

#include <stdlib.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/flash.h>

#define row_mask 0x1F //0b00011111

#define PRESCALE 1

#define BITS_PER_PIXEL 24
#define BITS_PER_CHANNEL 8

#define WIDTH 128
#define HEIGHT 64
#define ASPECT_RATIO HEIGHT/WIDTH
#define SCAN_RATE 32 // this is a 1/32 display

#define BRIGHTNESS 10 // this can be from 1 to 10

#define PIXEL(f, x, y) f[y * WIDTH + x]


inline void _error_handler(void) {while(1);};

extern volatile uint8_t bit;
extern volatile uint8_t row;
extern volatile uint8_t busyFlag;
//extern volatile uint32_t received_length;
//extern volatile uint8_t buffer_usb[];