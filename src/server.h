/*
 * Copyright (C) 2025 Ahmed
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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

#define S_PEN_DISTANCE_MIN 0
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
