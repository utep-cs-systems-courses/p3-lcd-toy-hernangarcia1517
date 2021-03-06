#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "buzzer.h"
#include "case_state.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  configureClocks();
  buzzer_init();
  lcd_init();
  clearScreen(background_color);
  switch_p2_init();
  
  init_shapes();

  enableWDTInterrupts();

  or_sr(0x18);	/**< CPU off , GIE on*/
}
