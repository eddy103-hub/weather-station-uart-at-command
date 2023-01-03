#ifndef _SENSORHANDLING_H
#define	_SENSORHANDLING_H

#include <xc.h>
#include <stdint.h>
#include<stdbool.h>
#include "constants.h"
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
