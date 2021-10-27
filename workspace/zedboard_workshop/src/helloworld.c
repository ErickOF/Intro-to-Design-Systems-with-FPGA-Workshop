#include <stdio.h>
#include "platform.h"
#include <xgpio.h>
#include "xparameters.h"
#include "sleep.h"


int main()
{
    XGpio input;
    XGpio output;

    uint8_t button_data = 0;
    uint8_t switch_data = 0;

    // Initialize input XGpio variable
    XGpio_Initialize(&input, XPAR_AXI_GPIO_0_DEVICE_ID);
    // Initialize output XGpio variable
    XGpio_Initialize(&output, XPAR_AXI_GPIO_1_DEVICE_ID);

    // Set first channel tristate buffer to input
    XGpio_SetDataDirection(&input, 1, 0xF);
    // Set the second channel tristate buffer to input
    XGpio_SetDataDirection(&input, 2, 0xF);

    // Set first channel tristate buffer to output
    XGpio_SetDataDirection(&output, 1, 0x0);

    init_platform();

    while (1)
    {
        // Get switch data
        switch_data = XGpio_DiscreteRead(&input, 2);

        // Write switch data to the LEDs
        XGpio_DiscreteWrite(&output, 1, switch_data);

        // Get button data
        button_data = XGpio_DiscreteRead(&input, 1);

        // Print a msg, depending on whether one or more buttons are pressed
        // button_data == 0b00000 -> Do nothin, not button pressed
        if (button_data == 0b00001)
        {
            xil_printf("Button 0 pressed\n\r");
        } else if (button_data == 0b00010)
        {
            xil_printf("Button 1 pressed\n\r");
        } else if (button_data == 0b00100)
        {
            xil_printf("Button 2 pressed\n\r");
        } else if(button_data == 0b01000)
        {
            xil_printf("Button 3 pressed\n\r");
        } else if (button_data == 0b10000)
        {
            xil_printf("button 4 pressed\n\r");
        } else
        {
            xil_printf("multiple buttons pressed\n\r");
        }

        // Short delay of 200 000us or 200ms or 0.2s
        usleep(200000);
    }

    cleanup_platform();

    return 0;
}
