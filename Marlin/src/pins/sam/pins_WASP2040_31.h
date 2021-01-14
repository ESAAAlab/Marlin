/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Arduino Mega or Due with RAMPS4DUE pin assignments
 *
 * Applies to the following boards:
 *
 *  RAMPS4DUE_EFB (Hotend, Fan, Bed)
 *  RAMPS4DUE_EEB (Hotend0, Hotend1, Bed)
 *  RAMPS4DUE_EFF (Hotend, Fan0, Fan1)
 *  RAMPS4DUE_EEF (Hotend0, Hotend1, Fan)
 *  RAMPS4DUE_SF  (Spindle, Controller Fan)
 *
 *  Differences between
 *  RAMPS_14 | RAMPS4DUE
 *       A13 | A9/D63 (shares the same pin with AUX2_4PIN)
 *       A14 | A10/D64 (shares the same pin with AUX2_5PIN)
 *       A15 | NC
 */

#if NOT_TARGET(__SAM3X8E__, __AVR_ATmega2560__)
  #error "Oops! Select 'Arduino Due' or 'Arduino/Genuino Mega or Mega 2560' in 'Tools > Board.'"
#endif

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "WASP2040_31"
#endif

// Servos
//
#if NUM_SERVOS > 0
  #define SERVO0_PIN                          11
  #if NUM_SERVOS > 1
    #define SERVO1_PIN                        12
  #endif
#endif

//
// Limit Switches
//
#define X_MIN_PIN                             31
#define X_MAX_PIN                             30
#define Y_MIN_PIN                             12
#define Y_MAX_PIN                             11
#define Z_MIN_PIN                             29
#define Z_MAX_PIN                             28

//
// Steppers
//
#define X_STEP_PIN                            25
#define X_DIR_PIN                             23
#define X_ENABLE_PIN                          27

#define Y_STEP_PIN                            31
#define Y_DIR_PIN                             33
#define Y_ENABLE_PIN                          29

#define Z_STEP_PIN                            37
#define Z_DIR_PIN                             39
#define Z_ENABLE_PIN                          35

#define E0_STEP_PIN                           43
#define E0_DIR_PIN                            45
#define E0_ENABLE_PIN                         41

// #define E1_STEP_PIN                           44
// #define E1_DIR_PIN                            36
// #define E1_ENABLE_PIN                         45

// #define E2_STEP_PIN                           42
// #define E2_DIR_PIN                            41
// #define E2_ENABLE_PIN                         43

//
// Temperature Sensors
//
#define TEMP_0_PIN                             0  // Analog Input
#define TEMP_1_PIN                             2  // Analog Input
#define TEMP_2_PIN                             3  // Analog Input
#define TEMP_3_PIN                             4  // Analog Input
#define TEMP_BED_PIN                           1  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                           2
#define HEATER_1_PIN                           7
// #define HEATER_2_PIN                           7
// #define HEATER_3_PIN                           9
#define HEATER_BED_PIN                         4

#ifndef FAN_PIN
  #define FAN_PIN                              6
#endif
#define FAN2_PIN                               5

//
// Misc. Functions
//
// #define SDSS                                  59
// #define SD_DETECT_PIN                         60
// #define LED_PIN                               13
// #define PS_ON_PIN                             32

//
// SPI Buses
//

#define DAC0_SYNC                             53  // PB14
#define SPI_CHAN_DAC                           1

#define SPI_CHAN_EEPROM1                      -1
#define SPI_EEPROM1_CS                        -1
#define SPI_EEPROM2_CS                        -1
#define SPI_FLASH_CS                          -1

#define SCK_PIN                               76
#define MISO_PIN                              74
#define MOSI_PIN                              75

// SPI for Max6675 or Max31855 Thermocouple
#define MAX6675_SS_PIN                        65
#define MAX31855_SS0                          65
#define MAX31855_SS1                          52
#define MAX31855_SS2                          50
#define MAX31855_SS3                          51

#define ENC424_SS                             61

//
// LCD / Controller
//

#define BEEPER_PIN                            27

#if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)

  #define LCD_PINS_RS                         A8  // CS chip select / SS chip slave select
  #define LCD_PINS_ENABLE                   MOSI  // SID (MOSI)
  #define LCD_PINS_D4                        SCK  // SCK (CLK) clock

  #define BTN_EN1                             20
  #define BTN_EN2                             21
  #define BTN_ENC                             64

#endif // REPRAPWORLD_GRAPHICAL_LCD
