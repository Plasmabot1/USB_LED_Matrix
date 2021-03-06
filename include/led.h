#pragma once

#define GAMMA_LUT_ENABLE

struct RGB {
	uint8_t R;
	uint8_t G;
	uint8_t B;
};

typedef struct RGB RGB_t;

extern RGB_t frame[];
extern uint8_t buffer1[];
extern uint8_t buffer2[];

void LED_waveEffect(RGB_t *frame);
void LED_waveEffectVertical(RGB_t *frame);
void LED_plasmaEffect(RGB_t *frame);
void LED_Pixel(RGB_t *frame);
void LED_Lines(RGB_t *frame);
void LED_fillFrame(RGB_t *frame, uint8_t r, uint8_t g, uint8_t b);
void LED_gradient(RGB_t *frame);
void LED_fillBuffer(RGB_t *frame, uint8_t *buffer);
