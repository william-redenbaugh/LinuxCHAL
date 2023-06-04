#include "os_adc.h"

os_adc_t adc_one = {
    .bus = 1, 
    .fifosize = 128, 
    .num_bits = 16
};
os_adc_t adc_two = {
    .bus = 2, 
    .fifosize = 128, 
    .num_bits = 16
};
os_adc_t adc_three = {
    .bus = 3, 
    .fifosize = 128,
    .num_bits = 16
};
os_adc_t adc_four = {
    .bus = 4, 
    .fifosize = 128, 
    .num_bits = 16
};
os_adc_t adc_five = {
    .bus = 5, 
    .fifosize = 128, 
    .num_bits = 16
};
os_adc_t adc_size = {
    .bus = 6, 
    .fifosize = 128, 
    .num_bits = 16
};

int os_adc_begin(os_adc_t *adc){
        
    
    return OS_RET_OK;
}

int os_adc_end(os_adc_t *adc){
        
    
    return OS_RET_OK;
}

int os_adc_read(os_adc_t *adc, void *value){
    return OS_RET_OK;
}

int os_adc_read_values(os_adc_t *adc, uint32_t size, void *values){


    return OS_RET_OK;
}