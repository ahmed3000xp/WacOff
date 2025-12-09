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
