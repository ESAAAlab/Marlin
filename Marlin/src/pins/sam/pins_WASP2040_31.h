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

//
// Limit Switches
//
#define X_MAX_PIN                             24  // OK
#define Y_MAX_PIN                             28  // OK
#define Z_MAX_PIN                             32  // OK

#define FIL_RUNOUT_PIN                        26  // OK

//
// Steppers
//
#define X_STEP_PIN                            25  // OK
#define X_DIR_PIN                             23  // OK
#define X_ENABLE_PIN                          27  // OK

#define Y_STEP_PIN                            31  // OK
#define Y_DIR_PIN                             33  // OK
#define Y_ENABLE_PIN                          29  // OK

#define Z_STEP_PIN                            37  // OK
#define Z_DIR_PIN                             39  // OK
#define Z_ENABLE_PIN                          35  // OK

#define E0_STEP_PIN                           43  // OK
#define E0_DIR_PIN                            45  // OK
#define E0_ENABLE_PIN                         41  // OK

// #define E1_STEP_PIN                           50  // OK
// #define E1_DIR_PIN                            47  // OK
// #define E1_ENABLE_PIN                         48  // OK

// #define E2_STEP_PIN                           44  // OK
// #define E2_DIR_PIN                            46  // OK
// #define E2_ENABLE_PIN                         23  // CANTX OK

#define MOTOR_CURRENT_PWM_XY_PIN              8
#define MOTOR_CURRENT_PWM_Z_PIN               8
#define MOTOR_CURRENT_PWM_E_PIN               8
// Motor current PWM conversion, PWM value = MotorCurrentSetting * 255 / range
#ifndef MOTOR_CURRENT_PWM_RANGE
  #define MOTOR_CURRENT_PWM_RANGE            2000
#endif
#define DEFAULT_PWM_MOTOR_CURRENT  { 1300, 1300, 1250}

//
// Temperature Sensors
//
#define TEMP_0_PIN                             8  // Analog Input
// #define TEMP_1_PIN                             2  // Analog Input
// #define TEMP_2_PIN                             3  // Analog Input
// #define TEMP_3_PIN                             4  // Analog Input
#define TEMP_BED_PIN                           10  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                           2  // EXTRUDER / HEATER1
// #define HEATER_1_PIN                           3  // UNPOPULATED
// #define HEATER_2_PIN                           
// #define HEATER_3_PIN                           
#define HEATER_BED_PIN                         4  // OK

#undef E0_AUTO_FAN_PIN
#define E0_AUTO_FAN_PIN                        7  // OK

// #ifndef FAN_PIN
//   #define FAN_PIN                              7  // AUX1
// #endif
// #define FAN2_PIN                               77  // AUX2 / DAC1 UNPOPULATED
// #define FAN3_PIN                               24  // AUX3 / CANRX UNPOPULATED

//
// Misc. Functions
//
// #define LED_PIN                               13
// #define PS_ON_PIN                             32

/**
 * SD Card Reader
 *
 * Software SPI is used to interface with a stand-alone SD card reader connected to EXP1.
 * Hardware SPI can't be used because P0_17 (MISO) is not brought out on this board.
 */
#if ENABLED(SDSUPPORT)
  #define SCK_PIN                               76 // OK
  #define MISO_PIN                              74 // OK
  #define MOSI_PIN                              75 // OK
  #define SD_DETECT_PIN                         38  // OK
#endif // SDSUPPORT

#define SDSS                                  53  // OK ?

//
// LCD / Controller
//
#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
  #define BEEPER_PIN                            18  // OK
  #define BTN_EN1                               40  // OK
  #define BTN_EN2                               42  // OK
  #define BTN_ENC                               19  // OK
  #define LCD_PINS_RS                           14  // OK
  #define LCD_PINS_ENABLE                       17  // OK
  #define LCD_PINS_D4                           16  // OK
  #define LCD_PINS_D5                           15  // OK
  #define LCD_PINS_D6                           5   // OK
  #define LCD_PINS_D7                           6   // OK
#endif

// EEPROM
#if ENABLED(EEPROM_SETTINGS)
#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE 0x10000 // 64K in a 24C512
#endif
