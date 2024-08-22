#include <stdio.h>
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_3

void initGPIO(){
    gpio_config_t configLED = {.mode = GPIO_MODE_OUTPUT, .intr_type = GPIO_INTR_DISABLE, .pin_bit_mask = LED_PIN , .pull_up_en = GPIO_PULLUP_ENABLE, .pull_down_en = GPIO_PULLDOWN_ENABLE};
    configLED.mode = GPIO_MODE_OUTPUT;
    configLED.intr_type = GPIO_INTR_DISABLE;

    if(gpio_config(&configLED) == ESP_OK){
        printf("GPIO successful configured!\n");
    }
    else{
        printf("GPIO configuration failed!\n");
    }

}

void app_main(void)
{
    initGPIO();
    // gpio_set_direction(LED_PIN,GPIO_MODE_INPUT_OUTPUT);

    gpio_set_level(LED_PIN,1);

    // gpio_set_level(LED_PIN,0);
    gpio_dump_io_configuration(stdout, SOC_GPIO_VALID_GPIO_MASK);

}