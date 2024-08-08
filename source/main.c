/* ========================================
 *
 *           KITT SCANNER
 *
 * Copyright r.nooteboom@gmail.com
 * Use freely on your own risk.
 *
 * ========================================
*/

#include "project.h"

static volatile uint8_t dummy __attribute__ ((section(".cyeeprom"),unused));        // Fix for linker error.cyeeprom data will not fit in EEPROM 

int main(void)
{
    Timer_1_Start();
    while(1) {}
}

/* [] END OF FILE */