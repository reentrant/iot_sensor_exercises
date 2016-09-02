#include "main.h"
/* Description: Linear Active Thermistor ICs are sensors whose output voltage is
 *              directly proportional to measured temperature.
 *              The MCP9700 can accurately measure temperature from -40C to 
 *              +150C. The output of the MCP9700 is calibrated to a slope of 
 *              10mV/degC and has a DC offset of 500mV. 
 *              The offset allows reading negative temperatures without the need
 *              for a negative supply.
 */

void Temp9700Read(void) {

    ADCON0bits.ADON = 1; // turn on ADC
    ADCON0bits.CHS = 0b000101;
    __delay_us(10); // allow cap to charge
    ADC_Convert();
    ADCON0bits.ADON = 0; // turn off ADC

    Temperature = (Volts - 0.4);
    Temperature = Temperature / 0.0195;
    TEMP_F = (Temperature * 1.8) + 32.0; // temp in F
}
