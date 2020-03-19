#include "mfxstm32l152.h"
#include "stm32756g_eval.h"
#include "stm32756g_eval_io.h"

#include "zerynth.h"

C_NATIVE(_c_start) {
    NATIVE_UNWARN();
    *res = MAKE_NONE();
    int err = ERR_OK;
    if(BSP_IO_Init() == IO_OK){ // Initialize the MFX
        return ERR_OK;
    }
    else {
        return -1;
    }
}

C_NATIVE(_pin_read) {
    NATIVE_UNWARN();
    *res = MAKE_NONE();
    int err = ERR_OK;
    int pin, pin_val;
    if (parse_py_args("i", nargs, args, &pin) != 1)
        return ERR_TYPE_EXC;
    pin_val = BSP_IO_ReadPin(pin);
    *res = PSMALLINT_NEW(pin_val);
    return err;
}

C_NATIVE(_pin_write) {
    NATIVE_UNWARN();
    *res = MAKE_NONE();
    int err = ERR_OK;
    int pin, pin_val;
    if (parse_py_args("ii", nargs, args, &pin, &pin_val) != 2)
        return ERR_TYPE_EXC;
    BSP_IO_WritePin(pin, pin_val);
    return err;
}

C_NATIVE(_toggle_pin) {
    NATIVE_UNWARN();
    *res = MAKE_NONE();
    int err = ERR_OK;
    int pin;
    if (parse_py_args("i", nargs, args, &pin) != 1)
        return ERR_TYPE_EXC;
    BSP_IO_TogglePin(pin);
    return err;
}

C_NATIVE(_pin_mode) {
    NATIVE_UNWARN();
    *res = MAKE_NONE();
    int err = ERR_OK;
    int pin, pin_mode, mode;

    if (parse_py_args("ii", nargs, args, &pin, &pin_mode) != 2)
        return ERR_TYPE_EXC;
    
    switch (pin_mode) {
        case PINMODE_INPUT_PULLNONE:
            mode = IO_MODE_INPUT_PU;
            break;
        case PINMODE_INPUT_PULLDOWN:
            mode = IO_MODE_INPUT_PD;
            break;
        case PINMODE_OUTPUT_PUSHPULL:
            mode = IO_MODE_OUTPUT_PP_PU;
            break;
        case PINMODE_OUTPUT_HIGHDRIVE:
            mode = IO_MODE_OUTPUT_OD_PD;
            break;
        case PINMODE_INPUT_ANALOG:
            mode = IO_MODE_ANALOG;
            break;
        default:
            return ERR_TYPE_EXC;
            break;
    }

    BSP_IO_ConfigPin(pin, mode);
    
    return err;
}
