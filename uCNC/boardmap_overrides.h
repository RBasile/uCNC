#ifndef BOADMAP_OVERRIDES_H
#define BOADMAP_OVERRIDES_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "boardmap_reset.h"
#define MCU MCU_AVR
#define KINEMATIC KINEMATIC_COREXY
#define AXIS_COUNT 3
#define TOOL_COUNT 1
#define BAUDRATE 115200
#define BOARD BOARD_RAMPS14
#define BOARD_NAME "BasileToTum"
#define UART_PORT 0
#define SPI_PORT 0
#define ITP_TIMER 1
#define RTC_TIMER 0
#define ONESHOT_TIMER 4
#define STEP0_BIT 6 // X and Y inverted
#define STEP0_PORT F
#define STEP1_BIT 0 // X and Y inverted
#define STEP1_PORT F
#define STEP2_BIT 3
#define STEP2_PORT L
#define STEP3_BIT 4
#define STEP3_PORT A
#define STEP4_BIT 1
#define STEP4_PORT C
#define DIR0_BIT 7 // X and Y inverted
#define DIR0_PORT F
#define DIR1_BIT 1 // X and Y inverted
#define DIR1_PORT F
#define DIR2_BIT 1
#define DIR2_PORT L
#define DIR3_BIT 6
#define DIR3_PORT A
#define DIR4_BIT 3
#define DIR4_PORT C
#define STEP0_EN_BIT 2 // X and Y inverted
#define STEP0_EN_PORT F
#define STEP1_EN_BIT 7 // X and Y inverted
#define STEP1_EN_PORT D
#define STEP2_EN_BIT 0
#define STEP2_EN_PORT K
#define STEP3_EN_BIT 2
#define STEP3_EN_PORT A
#define STEP4_EN_BIT 7
#define STEP4_EN_PORT C
//#define PWM0_BIT 5
//#define PWM0_PORT H
//#define PWM0_CHANNEL C
//#define PWM0_TIMER 4
//#define PWM1_BIT 6
//#define PWM1_PORT H
//#define PWM1_CHANNEL B
//#define PWM1_TIMER 2
//#define PWM2_BIT 4
//#define PWM2_PORT B
//#define PWM2_CHANNEL A
//#define PWM2_TIMER 2
#define SERVO0_BIT 5
#define SERVO0_PORT B
#define SERVO1_BIT 3
#define SERVO1_PORT H
//#define SERVO2_BIT 3
//#define SERVO2_PORT E
//#define SERVO3_BIT 5
//#define SERVO3_PORT G
#define DOUT0_BIT 0
#define DOUT0_PORT G
#define DOUT1_BIT 1
#define DOUT1_PORT A
//#define DOUT5_BIT 0
//#define DOUT5_PORT H
//#define DOUT6_BIT 1
//#define DOUT6_PORT H
//#define DOUT7_BIT 0
//#define DOUT7_PORT C
#define LIMIT_X_BIT 5
#define LIMIT_X_PORT E
#define LIMIT_X_ISR -6
#define LIMIT_Y_BIT 1
#define LIMIT_Y_PORT J
#define LIMIT_Y_ISR 1
#define LIMIT_Z_BIT 3
#define LIMIT_Z_PORT D
#define LIMIT_Z_ISR -4
#define LIMIT_X2_BIT 4
#define LIMIT_X2_PORT E
#define LIMIT_X2_ISR -5
#define LIMIT_Y2_BIT 0
#define LIMIT_Y2_PORT J
#define LIMIT_Y2_ISR 1
#define LIMIT_Z2_BIT 2
#define LIMIT_Z2_PORT D
#define LIMIT_Z2_ISR -3
#define PROBE_BIT 3
#define PROBE_PORT G
#define PROBE_ISR 2
#define SAFETY_DOOR_BIT 0
#define SAFETY_DOOR_PORT L
//#define DIN16_BIT 2
//#define DIN16_PORT C
//#define DIN16_PULLUP
//#define DIN17_BIT 4
//#define DIN17_PORT C
//#define DIN17_PULLUP
//#define DIN18_BIT 6
//#define DIN18_PORT C
//#define DIN18_PULLUP
//#define DIN19_BIT 0
//#define DIN19_PORT L
//#define DIN19_PULLUP
//#define DIN20_BIT 1
//#define DIN20_PORT K
//#define DIN20_PULLUP
//#define DIN21_BIT 2
//#define DIN21_PORT K
//#define DIN21_PULLUP
//#define DIN22_BIT 3
//#define DIN22_PORT K
//#define DIN22_PULLUP
//#define DIN23_BIT 4
//#define DIN23_PORT K
//#define DIN23_PULLUP
#define TX_BIT 1
#define TX_PORT E
#define RX_BIT 0
#define RX_PORT E
//#define SPI_CLK_BIT 1
//#define SPI_CLK_PORT B
//#define SPI_SDI_BIT 3
//#define SPI_SDI_PORT B
//#define SPI_SDO_BIT 2
//#define SPI_SDO_PORT B
//#define SPI_CS_BIT 0
//#define SPI_CS_PORT B
//#define I2C_CLK_BIT 0
//#define I2C_CLK_PORT D
//#define I2C_DATA_BIT 1
//#define I2C_DATA_PORT D
#define IC74HC595_COUNT 0
//Custom configurations


#ifdef __cplusplus
}
#endif
#endif
