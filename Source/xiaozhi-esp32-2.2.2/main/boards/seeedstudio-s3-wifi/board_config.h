#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include <driver/gpio.h>

// Audio rate
#define AUDIO_INPUT_REFERENCE true
#define AUDIO_INPUT_SAMPLE_RATE 16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Enable Simplex (two bus systems)
#define AUDIO_I2S_METHOD_SIMPLEX

// ==========================================
// 修复后的扬声器引脚 (Bus #0)
// ==========================================
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_7  // 对应物理引脚 D8
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_8  // 对应物理引脚 D9
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_9  // 对应物理引脚 D10

// ==========================================
// 修复后的麦克风引脚 (Bus #1) —— 避开串口冲突
// ==========================================
#define AUDIO_I2S_MIC_GPIO_SCK GPIO_NUM_2   // 对应物理引脚 D1
#define AUDIO_I2S_MIC_GPIO_WS  GPIO_NUM_3   // 对应物理引脚 D2
#define AUDIO_I2S_MIC_GPIO_DIN GPIO_NUM_4   // 对应物理引脚 D3


// OLED I2C (SDA/SCL)
// D4 -> GPIO5 : SDA
// D5 -> GPIO6 : SCL
#define DISPLAY_SDA_PIN GPIO_NUM_5
#define DISPLAY_SCL_PIN GPIO_NUM_6
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT 32
#elif CONFIG_OLED_SSD1306_128X64
#define DISPLAY_HEIGHT 64
#elif CONFIG_OLED_SH1106_128X64
#define DISPLAY_HEIGHT 64
#define SH1106
#else
#error "OLED screen type not selected"
#endif

#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

// Onboard LED
#define BUILTIN_LED_GPIO GPIO_NUM_21

// ==========================================
// 修复后的按钮引脚 —— 挪到不用的引脚，防止冲突
// ==========================================
#define BOOT_BUTTON_GPIO GPIO_NUM_0         // 板载 Boot
#define VOLUME_UP_BUTTON_GPIO GPIO_NUM_1    // 改到 D0 (闲置)
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_10 // 未引出引脚，占位防报错

// The touch keys are not needed for now, but we've provided a placeholder for them to ensure
// compatibility with the code's constructor.
#define TOUCH_BUTTON_GPIO GPIO_NUM_1        // 改到 D0 (闲置)

#endif  // BOARD_CONFIG_H_
