#include "main.h"

void CalcEulerAngles(void) {

    Ry2 = (-1 * ACCL_X / sqrt(pow(ACCL_Y, 2) + pow(ACCL_Z, 2)));
    Roll = atan(Ry2) * RADIANS_TO_DEGREES;

    Rx2 = (ACCL_Y / sqrt(pow(ACCL_X, 2) + pow(ACCL_Z, 2)));
    Pitch = atan(Rx2) * RADIANS_TO_DEGREES;

}
