#include "os_gpio.h"
#include "../LinuxCSAL/CSAL_SHARED/os_error.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int os_gpio_config(os_gpio_conf_t *conf){
    

    return OS_RET_OK;
}

int os_gpio_get_config(os_gpio_conf_t *conf){

    
    return OS_RET_OK;
}

int os_gpio_isr_config(os_gpio_isr_conf_t *conf){
   
    return OS_RET_OK;
}

int os_gpio_get_isr_conf(os_gpio_isr_conf_t *conf){
    
    return OS_RET_OK;
}

int os_gpio_enable_int(int pin, bool en){
   
    return OS_RET_OK;
}

int os_gpio_set(int gpio_pin, os_gpio_set_t set){
    return OS_RET_OK;
}

int os_gpio_read(int gpio_pin){
    return OS_RET_OK;
}