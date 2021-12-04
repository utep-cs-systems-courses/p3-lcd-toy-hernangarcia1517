#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

void
check_switch4()
{
  switch(switch4_state){
  case 1:
    use_buzzer();
    break;
  default:
    break;
  }
}
