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

#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/ioctl.h>

void dump_abs(int fd, int code, const char *name){
    struct input_absinfo ai;
    if(ioctl(fd, EVIOCGABS(code), &ai) == 0)
        printf("%s: min=%d max=%d flat=%d fuzz=%d res=%d\n",name, ai.minimum, ai.maximum, ai.flat, ai.fuzz, ai.resolution);
}

int main(){
    int fd = open("/dev/input/event2", O_RDONLY);
    if (fd < 0) return 1;

    char namebuf[256];
    ioctl(fd, EVIOCGNAME(sizeof(namebuf)), namebuf);
    printf("Device: %s\n\n", namebuf);

    dump_abs(fd, ABS_X, "X");
    dump_abs(fd, ABS_Y, "Y");
    dump_abs(fd, ABS_PRESSURE, "Pressure");
    dump_abs(fd, ABS_DISTANCE, "Distance");
    dump_abs(fd, ABS_TILT_X, "Tilt X");
    dump_abs(fd, ABS_TILT_Y, "Tilt Y");

    printf("\n--- events ---\n");
    struct input_event ev;
    while (read(fd, &ev, sizeof(ev)) > 0) {
        if(ev.type == EV_ABS)
            printf("ABS %d = %d\n", ev.code, ev.value);
        else if(ev.type == EV_KEY)
            printf("KEY %d = %d\n", ev.code, ev.value);
        else if(ev.type == EV_SW)
            printf("SW %d = %d\n", ev.code, ev.value);
    }

    return 0;
}
