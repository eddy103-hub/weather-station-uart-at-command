#include <xc.h>
#include "sensorHandling.h"
#include "bme280.h"
#include<stdbool.h>
#include "mcc_generated_files/mcc.h"


/**
  Section: Variable Definitions
 */

bool weather_initialized = 0;
bool label_initial = false;
int16_t i16Temperature;
uint16_t u16Pressure;
uint16_t u16Humidity;
uint16_t u16LightIntensity;

int16_t i16myTime = 0;
bool bMyTimeoutFlag = false;

/**
  Section: Driver APIs
 */


int16_t getTemp(void) {
    return i16Temperature;
}

uint16_t getPressure(void) {
    return u16Pressure;
}

uint16_t getHumidity(void) {
    return u16Humidity;
}

uint16_t getLightIntensity(void) {
    return u16LightIntensity;
}

void readSensors(void) {
    if (DEFAULT_SENSOR_MODE == BME280_FORCED_MODE) {
        BME280_startForcedSensing();
    }
    BME280_readMeasurements();
}

void AmbientClick_ReadSensor(void) {
    u16LightIntensity = ADCC_GetSingleConversion(adcIn);
}

void initSensors(void) {

    BME280_reset();
    __delay_ms(50);
    BME280_readFactoryCalibrationParams();
    BME280_config(BME280_STANDBY_HALFMS, BME280_FILTER_COEFF_OFF);
    BME280_ctrl_meas(BME280_OVERSAMP_X1, BME280_OVERSAMP_X1, BME280_FORCED_MODE);
    BME280_ctrl_hum(BME280_OVERSAMP_X1);
    BME280_initializeSensor();
    weather_initialized = 1;
}

void printSensors(void) {

    if (label_initial == true) {
    }
    readSensors();
    AmbientClick_ReadSensor();

    i16Temperature = (int8_t) BME280_getTemperature();
    u16Pressure = (uint8_t) BME280_getPressure();
    u16Humidity = (uint8_t) BME280_getHumidity();

    printf("Temp: %i C \n\r", i16Temperature);
    printf("Press: %u inHg \n\r", u16Pressure);
    printf("Humid: %u%% \n\r", u16Humidity);
    printf("Light: %u \n\n\r", u16LightIntensity);

    label_initial = true;

}

void setTimeout(int16_t sec) {
    i16myTime = sec;
}

bool isTimeout(void) {
    if (bMyTimeoutFlag) {
        bMyTimeoutFlag = false;
        return true;
    }
}

void timer1Callback(void) {
    printSensors();
    if (i16myTime) {
        i16myTime--;
        if (i16myTime == 0)bMyTimeoutFlag = true;
    }
}
