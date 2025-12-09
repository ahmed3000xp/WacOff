#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <linux/input.h>

#ifdef SM_N960F
#define S_PEN_EVDEV_PATH "/dev/input/event2"
#endif
