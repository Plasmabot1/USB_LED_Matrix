// STM32F4Discovery
//#define HSE_VALUE ((uint32_t)8000000)
#include "main.h"
#include "systick.h"
#include "led.h"
#include "init.h"
#include "cdcacm.h"

volatile uint8_t bit;
volatile uint8_t row;
volatile uint8_t busyFlag;
uint8_t usbd_control_buffer[128];
usbd_device *usbd_dev;

uint8_t *nextBuffer;

void otg_fs_isr(void) {
	usbd_poll(usbd_dev);
}

int main(void) {
    init();
    initUSB();
    rcc_periph_clock_enable(RCC_GPIOD);
    gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12 | GPIO13 | GPIO14 | GPIO15);
    gpio_clear(GPIOD, GPIO12 | GPIO13 | GPIO14 | GPIO15);
    uint8_t i = 12;
    uint32_t current_buffer, start_time;
    while(1) {
        start_time = millis();
        while(busyFlag);
        busyFlag = 1;
        //current_buffer = DMA2_Stream2->CR | DMA_SxCR_CT;
        current_buffer = dma_get_target(DMA2, DMA_STREAM2);
        nextBuffer = current_buffer ? buffer2 : buffer1;
        while(busyFlag);
        busyFlag = 1;
        
        //LED_Lines(frame);
        //LED_Pixel(frame);
        //LED_plasmaEffect(frame);
        //LED_waveEffect(frame);
        LED_fillBuffer(frame, nextBuffer);
        //if(index > WIDTH*HEIGHT*3) index = 0;
        gpio_clear(GPIOD, 1<<i);
        i++;
        if(i > 15) {
            i = 12;
        } 
        gpio_set(GPIOD, 1<<i);
    }
    return 0;
}