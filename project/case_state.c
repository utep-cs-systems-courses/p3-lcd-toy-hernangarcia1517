#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

void
check_switch4()
{
  /*
  if(switch4_state == 0){
    buzzer_set_period(1000);
  }else{
    buzzer_set_period(0);
  }
  */
  switch(switch4_state){
  case 0:
    tune = tune - 500;
    break;
  case 1:
    tune = tune - 500;
    break;
  default:
    break;
  }
}
