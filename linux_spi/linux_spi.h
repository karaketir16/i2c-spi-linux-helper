#ifndef Spi_H
#define Spi_H

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <linux/ioctl.h>
#include <sys/stat.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

#define SPI_PATH "/dev/spidev3.0"
#define SPI_CLOCK_SPEED 1000000



void SPI_init(const char * path, uint32_t spd);

void SPI_transfer(uint8_t const *tx, uint8_t const *rx, size_t len);

void SPI_end(void);



#endif // Spi_H

