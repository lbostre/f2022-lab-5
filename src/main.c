/**
  ******************************************************************************
  * @file    main.c
  * @author  Weili An
  * @version V1.0
  * @date    Oct 10, 2022
  * @brief   ECE 362 Lab 5 template
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include <stdint.h>

void initb();
void initc();
void setn(int32_t pin_num, int32_t val);
int32_t readpin(int32_t pin_num);
void buttons(void);
void keypad(void);

void mysleep(void) {
    for(int n = 0; n < 1000; n++);
}

int main(void) {
    // Uncomment when most things are working
    autotest();
    
    initb();
    initc();

    // uncomment one of the loops, below, when ready
    // while(1) {
    //   buttons();
    // }

    // while(1) {
    //   keypad();
    // }

    for(;;);
}

/**
 * @brief Init GPIO port B
 *        Pin 0: input
 *        Pin 4: input
 *        Pin 8-11: output
 *
 */
void initb() {
    RCC -> AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIOB -> MODER &= ~0x00ff0000;
    GPIOB -> MODER |= 0x00550000; // set pins 8-11 to 01 for output
    GPIOB -> MODER &= ~0x00000303; // set pins 0 and 4 to 00 for input
}

/**
 * @brief Init GPIO port C
 *        Pin 0-3: inputs with internal pull down resistors
 *        Pin 4-7: outputs
 *
 */
void initc() {
    RCC -> AHBENR |= RCC_AHBENR_GPIOCEN;
    GPIOC -> MODER &= ~0x0000ff00;
    GPIOC -> MODER |= 0x00005500; // sets pins 4-7 to 01 for output
    GPIOC -> MODER &= ~0x000000ff; // sets pins 0-3 to 00 for input
    GPIOC -> PUPDR &= ~0x000000ff; // sets pins 0-3 to 00 to use pull down resistors
    GPIOC -> PUPDR |= 0x000000aa; // sets pins 0-3 to 01 to use pull down resistors
}

/**
 * @brief Set GPIO port B pin to some value
 *
 * @param pin_num: Pin number in GPIO B
 * @param val    : Pin value, if 0 then the
 *                 pin is set low, else set high
 */
void setn(int32_t pin_num, int32_t val) {

    if(val == 0) {
        GPIOB -> BRR = (1 << pin_num);
    } else {
        GPIOB -> BSRR = (1 << pin_num);
    }
}

/**
 * @brief Read GPIO port B pin values
 *
 * @param pin_num   : Pin number in GPIO B to be read
 * @return int32_t  : 1: the pin is high; 0: the pin is low
 */
int32_t readpin(int32_t pin_num) {
    return ((GPIOB -> IDR) & (1 << pin_num)) ? 0x1 : 0x0;
}

/**
 * @brief Control LEDs with buttons
 *        Use PB0 value for PB8
 *        Use PB4 value for PB9
 *
 */
void buttons(void) {

}

/**
 * @brief Control LEDs with keypad
 *
 */
void keypad(void) {

}
