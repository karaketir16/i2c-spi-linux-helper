#ifndef I2C_H
#define I2C_H
#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <sys/ioctl.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>

#include <stdint.h>


int32_t setSlaveAddress(int file, uint8_t addr);

int I2C_init(const char * path);
void I2C_deinit(int file);

int32_t i2c_read_buff(int file, uint8_t addr, uint8_t command, uint8_t* data, uint8_t len);

int32_t i2c_write_buff(int file, uint8_t addr, uint8_t* data, uint8_t len);

#endif // I2C_H
