#ifndef MICROPY_INCLUDED_ARDUPY_MODMACHINE_H
#define MICROPY_INCLUDED_ARDUPY_MODMACHINE_H

#include "py/obj.h"

typedef enum {
    //MACHINE_WAKE_IDLE=0x01,
    MACHINE_WAKE_SLEEP=0x02,
    MACHINE_WAKE_DEEPSLEEP=0x04
} wake_type_t;


extern const mp_obj_type_t machine_pin_type;
extern const mp_obj_type_t machine_adc_type;
extern const mp_obj_type_t machine_dac_type;
extern const mp_obj_type_t machine_pwm_type;
extern const mp_obj_type_t machine_lcd_type;


#endif // MICROPY_INCLUDED_ARDUPY_MODMACHINE_H
