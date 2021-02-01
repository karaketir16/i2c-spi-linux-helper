#include "linux_i2c.h"
#include <unistd.h>

int32_t setSlaveAddress(int file, uint8_t addr)
{
    return ioctl(file, I2C_SLAVE, addr >> 1);
}

int I2C_init(const char* path)
{
    return open(path, O_RDWR);
}

int32_t i2c_read_buff(int file, uint8_t addr, uint8_t command, uint8_t* data, uint8_t len)
{
    setSlaveAddress(file, addr);
    struct i2c_rdwr_ioctl_data asd;
    asd.msgs = (struct i2c_msg *) (malloc(sizeof(struct i2c_msg)*2));
    struct i2c_msg r,w;
    w.addr = addr >> 1;
    w.flags = 0;
    w.len = 1;
    w.buf = &command;

    r.addr = addr >> 1;
    r.flags = I2C_M_RD;
    r.len = len;
    r.buf = data;

    asd.msgs[0] = w;
    asd.msgs[1] = r;
    asd.nmsgs = 2;

    return ioctl(file, I2C_RDWR, &asd);
}

int32_t i2c_write_buff(int file, uint8_t addr, uint8_t* data, uint8_t len)
{
    setSlaveAddress(file, addr);
    struct i2c_rdwr_ioctl_data asd;
    asd.msgs = (struct i2c_msg *) (malloc(sizeof(struct i2c_msg)*1));
    struct i2c_msg w;
    w.addr = addr >> 1;
    w.flags = 0;
    w.len = len;
    w.buf = data;

    asd.msgs[0] = w;
    asd.nmsgs = 1;

    return ioctl(file, I2C_RDWR, &asd);
}

void I2C_deinit(int file)
{
    if (file < 0) {
        close(file);
        file = -1;
    }
}
