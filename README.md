# weather-station-uart-at-command
 # Related Documentation
  * [PIC18F57Q43 Curiosity Nano Hardware User Guide](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC18F57Q43-Curiosity-Nano-HW-UserGuide-DS40002186B.pdf)
  * [PIC18F57Q43 Data Sheet](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18F27-47-57Q43-Data-Sheet-40002147F.pdf)
  * [WFI32-IoT Board User's Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/WSG/ProductDocuments/UserGuides/EV36W50A-WFI32-IoT-Board-Users-Guide-DS50003262.pdf)
  * [Curiosity Nano Base for Click boards Hardware User Guide](https://ww1.microchip.com/downloads/en/DeviceDoc/Curiosity-Nano-Base-for-Click-boards-User-Guide-50002839B.pdf)
   * [AT Command Reference](https://github.com/MicrochipTech/PIC32MZW1_AnyCloud/blob/main/doc/ATCommandReference.pdf)
   * [Cloud Set Up Procedure](https://github.com/MicrochipTech/PIC32MZW1_AnyCloud/blob/main/doc/CloudSetupProcedure.pdf)

# Software Used
 * [MPLAB® X IDE v6.00](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide) or newer
 * [MPLAB® XC8 v2.36](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC8) or newer
 * Microchip PIC18F-Q Series Device Support (1.13.211) or newer (https://packs.download.microchip.com/)
 * [Tera Term](https://www.heise.de/download/product/tera-term-51776) or any terminal emulator
 
 
# Hardware Used
* [PIC18F57Q43 Curiosity Nano Evaluation Kit](https://www.microchip.com/en-us/development-tool/DM164150)
* [WFI32-IoT Development Board](https://www.microchip.com/en-us/development-tool/ev36w50a)
* [Curiosity Nano Base for Click boards](https://www.microchip.com/en-us/development-tool/AC164162)
* [Ambient Click](https://www.mikroe.com/ambient-click)
* [Weather click](https://www.mikroe.com/weather-click)
* [CO Click](https://www.mikroe.com/co-click)

# Project Overview
![image](https://user-images.githubusercontent.com/66494140/210653101-183635bc-77fd-4552-836f-0da1a8c2038a.png)

# Project Set Up
![image](https://user-images.githubusercontent.com/66494140/210337188-ab79ea28-23ab-4905-aa64-39d6da203ac9.png)
## MCC Settings:
### Oscillator Set Up
![image](https://user-images.githubusercontent.com/66494140/210337697-29d7a107-b246-49b3-b573-4947f21eca07.png)

### ADCC Set Up
![image](https://user-images.githubusercontent.com/66494140/210337668-b13b7690-e8e0-40d3-895a-c9ecf77ab980.png)
### Timer1 Set Up
![image](https://user-images.githubusercontent.com/66494140/210337778-b18e8f7c-ffbd-4bf1-addb-f6c358beff75.png)
### UART1 Set Up
![image](https://user-images.githubusercontent.com/66494140/210337859-0c139426-2f23-439e-b992-404f27201dd3.png)
### UART3 Set Up
![image](https://user-images.githubusercontent.com/66494140/210337936-d7841e0a-5574-4c10-b0b4-da914ea7da38.png)
### Pinout - Diagram
![image](https://user-images.githubusercontent.com/66494140/210652519-d1f53080-9e12-469d-b56a-3f7c207057f9.png)

## Amazon AWS Set Up
![image](https://user-images.githubusercontent.com/66494140/210338429-54cb1eb5-d3af-43db-ab1f-d44d8d9d2a9e.png)
# Implementation and Testing
![image](https://user-images.githubusercontent.com/66494140/210340002-3b21c62e-c6f4-4c0a-b19a-46841843405b.png)

### MQTT Client Test
![image](https://user-images.githubusercontent.com/66494140/210338515-3b11a6a6-3416-482a-96b7-5d492f3cff08.png)
### Amazon AWS Quicksight Dashboard
![image](https://user-images.githubusercontent.com/66494140/210338657-12f9d23c-9cf5-49f7-b9b1-addd42a00e81.png)





