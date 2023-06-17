#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "global_includes.h"

os_spi_t spi_zero = {
    .fd = 0, 
    .xfer_speed = 1000000, 
    .bus = 0, 
    .spi_mode = 1
};

os_spi_t spi_three= {
    .fd = 0, 
    .xfer_speed = 1000000, 
    .bus = 3,
    .spi_mode = 1
};

os_spi_t spi_four = {
    .fd = 0, 
    .xfer_speed = 1000000, 
    .bus = 4,
    .spi_mode = 1
};

os_spi_t spi_five = {
    .fd = 0, 
    .xfer_speed = 1000000, 
    .bus = 5,
    .spi_mode = 1
};


int os_spi_begin(os_spi_t *spi){
    

    return OS_RET_OK;
}

int os_spi_end(os_spi_t *spi){
    

    return OS_RET_OK;    
}

int os_spi_setbus(os_spi_t *spi, uint32_t freq_hz){

    return OS_RET_OK;
}

int os_spi_transfer(os_spi_t *spi, uint8_t *rx, uint8_t *tx, size_t size){
   
    
    return OS_RET_OK;

}

int os_spi_send(os_spi_t *spi, uint8_t *buf, size_t size){
    
    return OS_RET_OK;
}

int os_spi_recieve(os_spi_t *spi, uint8_t *buf, size_t size){
    
    return OS_RET_OK;
}