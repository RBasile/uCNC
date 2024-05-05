#ifndef CNC_HAL_OVERRIDES_H
#define CNC_HAL_OVERRIDES_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "cnc_hal_reset.h"
#define S_CURVE_ACCELERATION_LEVEL 0
#define ESTOP_PULLUP_ENABLE
#define SAFETY_DOOR_PULLUP_ENABLE
#define FHOLD_PULLUP_ENABLE
#define CS_RES_PULLUP_ENABLE
//#define LIMIT_X_PULLUP_ENABLE
//#define LIMIT_Y_PULLUP_ENABLE
//#define LIMIT_Z_PULLUP_ENABLE
//#define LIMIT_X2_PULLUP_ENABLE
//#define LIMIT_Y2_PULLUP_ENABLE
#define PROBE_PULLUP_ENABLE
#define TOOL1 spindle_besc
#define SPINDLE_BESC_SERVO SERVO0
#define SPINDLE_BESC_POWER_RELAY DOUT0

#define ENCODERS 0
#define ENABLE_PARSER_MODULES
//Custom configurations


//RBasile
#define SERVO_SPINDLE_MAX  1832    //(MILL MOTOR input: 1060 us equal to Full CCW, 1460us equal to zero, 1860us equal to Full CW)
#define SERVO_SPINDLE_MIN  1148
#define SERVO_SPINDLE_ZERO  1488
#define SERVO_SPINDLE_ARM  1550



#define DEFAULT_SPINDLE_MAX_RPM  14684    // spindle max rpm in marlin: RPM_SPINDLE_MAX
#define DEFAULT_SPINDLE_MIN_RPM  0     // spindle min rpm in marlin: RPM_SPINDLE_MIN



#ifdef __cplusplus
}
#endif
#endif
