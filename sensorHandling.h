#ifndef _SENSORHANDLING_H
#define	_SENSORHANDLING_H

#include <xc.h>
#include <stdint.h>
#include<stdbool.h>
/**
  Section: Macro Declarations
 */

#define DEFAULT_STANDBY_TIME    BME280_STANDBY_HALFMS
#define DEFAULT_FILTER_COEFF    BME280_FILTER_COEFF_OFF
#define DEFAULT_TEMP_OSRS       BME280_OVERSAMP_X1
#define DEFAULT_PRESS_OSRS      BME280_OVERSAMP_X1
#define DEFAULT_HUM_OSRS        BME280_OVERSAMP_X1
#define DEFAULT_SENSOR_MODE     BME280_FORCED_MODE

/**
  Section: Sensor Functions
 */

void initSensors(void);
void readSensors(void);
void printSensors(void);
void timer1Callback(void);
void readAmbientSensor(void);
void readCOSensor(void);
int16_t getTemp(void);
uint16_t getPressure(void);
uint16_t getHumidity(void);
uint16_t getLightIntensity(void);
uint16_t getC0Sensor(void);
void setTimeout(int16_t sec);
bool isTimeout(void);

#endif
