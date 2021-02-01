#ifndef pinCtl_H
#define pinCtl_H

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/ioctl.h>
#include <sys/stat.h>
#include <linux/types.h>

#define pinCtl_PDPIN "79" // SODIMM_124 (GPIO)
#define pinCtl_CSPIN "77" // SODIMM_120 (GPIO)

#define LOW "0"
#define HIGH "1"

void pinCtl_pd_connect(void);
void pinCtl_pd_disconnect(void);
void pinCtl_cs_connect(void);
void pinCtl_cs_disconnect(void);
void pinCtl_pdSet(const char *);
void pinCtl_csSet(const char *);

#endif // pinCtl_H

