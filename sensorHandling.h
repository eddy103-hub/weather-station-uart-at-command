#ifndef _SENSORHANDLING_H
#define	_SENSORHANDLING_H

#include <xc.h>
#include <stdint.h>

/**
  Section: Macro Declarations
 */

#define DEFAULT_STANDBY_TIME    BME280_STANDBY_HALFMS
#define DEFAULT_FILTER_COEFF    BME280_FILTER_COEFF_OFF
#define DEFAULT_TEMP_OSRS       BME280_OVERSAMP_X1
#define DEFAULT_PRESS_OSRS      BME280_OVERSAMP_X1
#define DEFAULT_HUM_OSRS        BME280_OVERSAMP_X1
#define DEFAULT_SENSOR_MODE     BME280_FORCED_MODE

/*extern variable to be used for MQTT*/
extern int16_t temp_string; // Temperature
extern uint16_t press_string; // Pressure
extern uint16_t humid_string; // Humidity
extern uint16_t light_raw; // Ambient Light
/**
  Section: Weather Click Driver APIs
 */

void WeatherStation_initialize(void);
void WeatherClick_readSensors(void);
void WeatherStation_Print(void);
void timer1Callback(void);
#endif
