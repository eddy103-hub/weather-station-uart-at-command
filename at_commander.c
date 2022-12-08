/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#include "at_commander.h"
#include "sensorHandling.h"
#include "mcc_generated_files/mcc.h"
const char my_ap[] = "iPhone13";
const char my_pw[] = "eddymeshack";
const char my_ts[] = "pool.ntp.org";
const char my_ba[] = "a3a2c3qx9uoi5k-ats.iot.us-east-2.amazonaws.com";
const char my_ci[] = "pic32";
const char ok_res[] = "OK\r\n>";
 char json[MQTT_PAYLOAD_SIZE];



ATCMD_STATES ATCMD_state = STATE_INIT;
uint8_t ATCMD_Error_Code = 0;

char ATCMD_TransmittBuffer[ATCMD_PRINT_BUFFER_SIZE];
char ATCMD_ReceiveBuffer[ATCMD_RECEIVE_BUFFER_SIZE];

void  createPubMQTTString() {
    uint16_t message = 0;
    int16_t temp = getTemp();
    uint16_t pres = getPressure();
    uint16_t humid = getHumidity();
    uint16_t light = getLightIntensity();
    
    message = snprintf(json,MQTT_PAYLOAD_SIZE, "Light:%u,Temp:%d,Press:%u,Humid:%u",
            light, temp, pres, humid);
}

void ATCMD_Task(void) {
    switch (ATCMD_state) {
        case STATE_INIT:
            ATCMD_Print("AT+WSTAC=%d,\"%s\"\r\n", ID_SSID, my_ap);
            ATCMD_Print("AT+WSTAC=%d,%d\r\n", ID_SEC_TYPE, PAR_SEC_TYPE_WPA2);
            ATCMD_Print("AT+WSTAC=%d,\"%s\"\r\n", ID_CREDENTIALS, my_pw);
            ATCMD_Print("AT+WSTAC=%d,%d\r\n", ID_CHANNEL, PAR_ANY_CHANNEL);
            ATCMD_Print("AT+WSTAC=%d,\"%s\"\r\n", ID_NTP_SVR, my_ts);
            ATCMD_Print("AT+WSTAC=%d,%d\r\n", ID_NTP_STATIC, PAR_NTP_STATIC);
            ATCMD_state = STATE_START_WLAN;
            break;

        case STATE_START_WLAN:
            ATCMD_Print("AT+WSTA=%d\r\n", PAR_USE_CONFIGURATION);
            ATCMD_ReadLine();
            ATCMD_ReadLine();
            ATCMD_state = STATE_WAIT_FOR_AP_CONNECT;
            break;

        case STATE_WAIT_FOR_AP_CONNECT:
            ATCMD_Print("AT+WSTA\r\n");
            ATCMD_ReadLine();
            if (ATCMD_strcon(ATCMD_ReceiveBuffer, "+WSTALD\r\n") != 1) {
                ATCMD_state = STATE_CONFIGURE_CLOUD;
            }
            break;

        case STATE_CONFIGURE_CLOUD:
            ATCMD_Print("AT+MQTTC=%d,\"%s\"\r\n", ID_MQTT_BROKER_ADDR, my_ba);
            ATCMD_Print("AT+MQTTC=%d,%d\r\n", ID_MQTT_BROKER_PORT, MQTT_BROKER_PORT);
            ATCMD_Print("AT+MQTTC=%d,\"%s\"\r\n", ID_MQTT_CLIENT_ID, my_ci);
            ATCMD_Print("AT+MQTTCONN=%d\r\n", MQTT_RCLEAN);
            ATCMD_state = STATE_PUBLISH_CLOUD;
            break;

        case STATE_PUBLISH_CLOUD:
            createPubMQTTString();
            ATCMD_Print("AT+MQTTPUB=%d,%d,%d,\"%s\",\"%s\"\r\n", MQTT_DUP, MQTT_QOS,
                    MQTT_RETAIN, MQTT_PUB_TOPIC, json);
            ATCMD_state = STATE_IDLE;
            break;

        case STATE_IDLE:
            break;

        default:
            break;
    }

}

void ATCMD_Print(const char *format, ...) {
    size_t len = 0;
    va_list args = {0};
    int ix;
    LED0_Toggle();
    /* Get the variable arguments in va_list */
    va_start(args, format);

    len = vsnprintf(ATCMD_TransmittBuffer, ATCMD_PRINT_BUFFER_SIZE, format, args);

    va_end(args);

    ATCMD_Error_Code = 0;

    if ((len > 0) && (len < ATCMD_PRINT_BUFFER_SIZE)) {
        ATCMD_TransmittBuffer[len] = '\0';
    }

    for (ix = 0; ix < len; ix++) {
        while (!UART3_is_tx_ready()); // BLOCKING
        UART3_Write(ATCMD_TransmittBuffer[ix]);
    }

    for (ix = 0; ix < (len + 5); ix++) {
        while (!UART3_is_rx_ready()); // BLOCKING
        ATCMD_ReceiveBuffer[ix] = UART3_Read();

    }

    for (ix = len; ix < (len + 5); ix++) {
        if (ok_res[ix] != ATCMD_ReceiveBuffer[ix]) {
            ATCMD_Error_Code = 1;
            return;
        }
    }

}

uint8_t ATCMD_ReadLine(void) {
    uint8_t ix;
    uint8_t byte;

    for (ix = 0; ix < ATCMD_RECEIVE_BUFFER_SIZE; ix++) {
        while (!UART3_is_rx_ready()); // BLOCKING
        byte = UART3_Read();
        if (byte == '\n') {
            ATCMD_ReceiveBuffer[ix] = 0;
            break;
        } else {
            ATCMD_ReceiveBuffer[ix] = byte;
        }
    }
    return ix;

}

int ATCMD_strcon(char a[], char b[]) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            break;
        }
        i++;
    }
    if (b[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}
