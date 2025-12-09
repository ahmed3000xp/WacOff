#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/uinput.h>
#include <linux/input.h>

#ifdef SM_N960F
#define S_PEN_X_MIN 0
#define S_PEN_X_MAX 7085
#define S_PEN_X_FLAT 0
#define S_PEN_X_FUZZ 4

#define S_PEN_Y_MIN 0
#define S_PEN_Y_MAX 14563
#define S_PEN_Y_FLAT 0
#define S_PEN_Y_FUZZ 4

#define S_PEN_PRESSURE_MIN 0
#define S_PEN_PRESSURE_MAX 4095
#define S_PEN_PRESSURE_FLAT 0
#define S_PEN_PRESSURE_FUZZ 0

#define S_PEN_DISTANCE_MIN 255
#define S_PEN_DISTANCE_MAX 255
#define S_PEN_DISTANCE_FLAT 0
#define S_PEN_DISTANCE_FUZZ 0

#define S_PEN_TILT_X_MIN -63
#define S_PEN_TILT_X_MAX 63
#define S_PEN_TILT_X_FLAT 0
#define S_PEN_TILT_X_FUZZ 0

#define S_PEN_TILT_Y_MIN -63
#define S_PEN_TILT_Y_MAX 63
#define S_PEN_TILT_Y_FLAT 0
#define S_PEN_TILT_Y_FUZZ 0
#endif
