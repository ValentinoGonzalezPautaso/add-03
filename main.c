#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main(void) {
  stdio_init_all();
  adc_init();
  adc_gpio_init(27);
  adc_select_input(1);
  float  r1 = 10000;
  float T = 0;
  float r2 = 0;
  float blanco;
  uint16_t negro = 0;
    while (1){
    uint16_t negro = adc_read();
    blanco = (negro * 3.3) / 4095; 
    r2 = r1/((3.3/blanco) - 1);
    T = 3977.0 / ((log(r2/10000.0))+(3977.0/298.0));
    printf("ADC %d VR2 %.2f\n", negro, blanco);
    printf ("R2 es: %.2f \n", r2);
    printf ("La temperatura es: %.2f \n", T - 273);
    sleep_ms(1000);
  }
}