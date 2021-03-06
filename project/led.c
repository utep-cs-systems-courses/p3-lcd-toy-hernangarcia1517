#include <msp430.h>
#include "libTimer.h"
#include "led.h"

// led states, red starts off green starts on
unsigned char red_on = 0, green_on = 1;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P3DIR |= LEDS;		        // bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update(){
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P3OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P3OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
}

/*
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const int secondLimit = 250;
  static int variableLimit = 5;
  static int blinkCount = 0;
  blinkCount++;
  if(blinkCount >= variableLimit) {
    blinkCount = 0;
    red_on = 1 - red_on;
    led_changed = 1;
    led_update();
  }
}
*/
