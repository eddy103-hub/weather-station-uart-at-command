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
void WeatherClick_readSensors(void) {
    if (DEFAULT_SENSOR_MODE == BME280_FORCED_MODE) {
        BME280_startForcedSensing();
    }
    BME280_readMeasurements();
}

void AmbientClick_ReadSensor(void) {
    u16LightIntensity = ADCC_GetSingleConversion(adcIn);
}

void WeatherStation_initialize(void) {
    
    BME280_reset();
    __delay_ms(50);
    BME280_readFactoryCalibrationParams();

    // TODO #2 Set the BME280 Filter coefficient OFF in the function BME280_config()
    // Hint: Pass parameter BME280_FILTER_COEFF_OFF in the function BME280_config()
     BME280_config(BME280_STANDBY_HALFMS, BME280_FILTER_COEFF_OFF);

    BME280_ctrl_meas(BME280_OVERSAMP_X1, BME280_OVERSAMP_X1, BME280_FORCED_MODE);

    // TODO #3 Set the Humidity oversampling coefficient to X1
    // Hint : Pass parameter BME280_OVERSAMP_X1 in the function below
    BME280_ctrl_hum(BME280_OVERSAMP_X1);
    BME280_initializeSensor();
    weather_initialized = 1;
}

void WeatherStation_Print(void) {
    
    if (label_initial == true) {
    }
    WeatherClick_readSensors();
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

void timer1Callback(void) {
    WeatherStation_Print();
}