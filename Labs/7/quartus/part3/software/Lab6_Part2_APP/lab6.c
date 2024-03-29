#include <sys/alt_irq.h>                // for IRQ support function
#include "alt_types.h"                  // for standard embedded types
#include "altera_nios2_gen2_irq.h"      // for standard embedded types
#include "system.h"                     // for Qsys #defines
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

// create standard embedded type definitions
typedef signed char    sint8;  // signed 8 bit values
typedef unsigned char  uint8;  // unsigned 8 bit values
typedef signed short   sint16; // signed 16 bit values
typedef unsigned short uint16; // unsigned 16 bit values
typedef signed long    sint32; // signed 32 bit values
typedef unsigned long  uint32; // unsigned 32 bit values
typedef float          real32; // 32 bit real values

volatile uint32 *KeyPtr  = (uint32 *) PUSHBUTTONS_BASE;
volatile uint32 *LEDSPtr = (uint32 *) LEDS_BASE;
uint32 *RamPtr           = (uint32 *) INFERRED_RAM_BASE ; // servo base address

void RAMTest8(uint8 *start_address, unsigned int BYTES,unsigned int test_data)
{
    for(int i = 0; i < BYTES; i++)
    {
        *(RamPtr + i) = test_data;
    }
    for(int i = 0; i < BYTES; i++)
    {
        if (test_data != *(RamPtr + i))
        {
            *LEDSPtr = 0xFF;
        }
    }
}

void RAMTest16(uint16 *start_address, unsigned int BYTES,unsigned int test_data)
{
    for(int i = 0; i < BYTES; i++)
    {
        *(RamPtr + i) = test_data;

    }
    for(int i = 0; i < BYTES; i++)
    {
        if (test_data != *(RamPtr + i))
        {
            *LEDSPtr = 0xFF;
        }
    }
}

void RAMTest32(uint32 *start_address, unsigned int BYTES,unsigned int test_data)
{
    for(int i = 0; i < BYTES; i++)
    {
        *(RamPtr + i) = test_data;

    }
    for(int i = 0; i < BYTES; i++)
    {
        if (test_data != *(RamPtr + i))
        {
            *LEDSPtr = 0xFF;
        }
    }
}

int main()
{
    *LEDSPtr = 0; //initial value to LEDs

    while(1)
    {
        RAMTest32(RamPtr, 4096, 0x12345678);
    }

    return(0);

}
