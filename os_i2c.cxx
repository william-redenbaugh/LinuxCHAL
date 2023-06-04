#include "os_i2c.h"
#include "../LinuxCSAL/CSAL_SHARED/os_error.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>


int os_i2c_begin(os_i2c_t *i2c){

    return OS_RET_OK;

}

int os_i2c_end(os_i2c_t *i2c){

    return OS_RET_OK;
}

int os_i2c_setbus(os_i2c_t *i2c, uint32_t freq_hz){
    
    return OS_RET_OK;
}

int os_i2c_send(os_i2c_t *i2c, uint8_t addr, uint8_t *buf, size_t size){

    return OS_RET_OK;
}

int os_i2c_recieve(os_i2c_t *i2c, uint8_t addr, uint8_t *buf, size_t size){

    return OS_RET_OK;
}