
/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"

#ifdef __cplusplus
 extern "C" {
#endif

#define GPIO_PORT                                                   (GPIOA) // For simplicity only Port A is only used 

void pinMode( pin_size_t ulPin, PinMode ulMode )
{
    DL_GPIO_reset(GPIOA);
    //DL_GPIO_reset(GPIOB);

    DL_GPIO_enablePower(GPIOA);
    //DL_GPIO_enablePower(GPIOB);

    switch ( ulMode )
      {
        case INPUT:
          DL_GPIO_initDigitalInput(IOMUX_PINCM(ulPin));
        break ;
    
        case INPUT_PULLUP:
          DL_GPIO_initDigitalInputFeatures(IOMUX_PINCM(ulPin), DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
        break ;
    
        case INPUT_PULLDOWN:
          DL_GPIO_initDigitalInputFeatures(IOMUX_PINCM(ulPin), DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
        break ;
    
        case OUTPUT:
           DL_GPIO_initDigitalOutput(IOMUX_PINCM(ulPin));
        break ;
    
        default:
          // do nothing
        break ;
      }

}

void digitalWrite( pin_size_t ulPin, PinStatus ulVal )
{
  switch ( ulVal )
  {
    case LOW:
       DL_GPIO_clearPins(GPIO_PORT, ulPin);
    break ;

    default:
       DL_GPIO_setPins(GPIO_PORT, ulPin);
    break ;
  }
 
}

PinStatus digitalRead( pin_size_t ulPin )
{
  return (PinStatus)DL_GPIO_readPins(GPIO_PORT, ulPin);
}

#ifdef __cplusplus
}
#endif
