#include "server.h"

int setup_uinput() {
    int ufd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if(ufd < 0){
        printf("server.c::ERROR::socket() open syscall failed to open /dev/uinput and returned code %d\n", ufd);
        return -1;
    }

#ifdef SM_N960F
    ioctl(ufd, UI_SET_EVBIT, EV_ABS);
    ioctl(ufd, UI_SET_EVBIT, EV_KEY);
    ioctl(ufd, UI_SET_EVBIT, EV_SYN);

    ioctl(ufd, UI_SET_ABSBIT, ABS_X);
    ioctl(ufd, UI_SET_ABSBIT, ABS_Y);
    ioctl(ufd, UI_SET_ABSBIT, ABS_PRESSURE);
    ioctl(ufd, UI_SET_ABSBIT, ABS_DISTANCE);
    ioctl(ufd, UI_SET_ABSBIT, ABS_TILT_X);
    ioctl(ufd, UI_SET_ABSBIT, ABS_TILT_Y);

    ioctl(ufd, UI_SET_KEYBIT, BTN_TOOL_PEN);
    ioctl(ufd, UI_SET_KEYBIT, BTN_TOUCH);

    ioctl(ufd, UI_SET_KEYBIT, INPUT_PROP_DIRECT);
#else
#error "You must select a Note 9 model to build for"
#endif

    struct uinput_user_dev dev = {0};
    snprintf(dev.name, UINPUT_MAX_NAME_SIZE, "Note9 S-Pen Tablet");

    dev.absmin[ABS_X] = S_PEN_X_MIN;
    dev.absmax[ABS_X] = S_PEN_X_MAX;
    dev.absflat[ABS_X] = S_PEN_X_FLAT;
    dev.absfuzz[ABS_X] = S_PEN_X_FUZZ;
    
    dev.absmin[ABS_Y] = S_PEN_Y_MIN;
    dev.absmax[ABS_Y] = S_PEN_Y_MAX; 
    dev.absflat[ABS_Y] = S_PEN_Y_FLAT;
    dev.absfuzz[ABS_Y] = S_PEN_Y_FUZZ;

    dev.absmin[ABS_PRESSURE] = S_PEN_PRESSURE_MIN;
    dev.absmax[ABS_PRESSURE] = S_PEN_PRESSURE_MAX;
    dev.absflat[ABS_PRESSURE] = S_PEN_PRESSURE_FLAT;
    dev.absfuzz[ABS_PRESSURE] = S_PEN_PRESSURE_FLAT;
    
    dev.absmin[ABS_DISTANCE] = S_PEN_DISTANCE_MIN;
    dev.absmax[ABS_DISTANCE] = S_PEN_DISTANCE_MAX;
    dev.absflat[ABS_DISTANCE] = S_PEN_DISTANCE_FLAT;
    dev.absfuzz[ABS_DISTANCE] = S_PEN_DISTANCE_FUZZ;
    
    dev.absmin[ABS_TILT_X] = S_PEN_TILT_X_MIN;
    dev.absmax[ABS_TILT_X] = S_PEN_TILT_X_MAX;
    dev.absflat[ABS_TILT_X] = S_PEN_TILT_X_FLAT;
    dev.absfuzz[ABS_TILT_X] = S_PEN_TILT_X_FUZZ;
    
    dev.absmin[ABS_TILT_Y] = S_PEN_TILT_Y_MIN;
    dev.absmax[ABS_TILT_Y] = S_PEN_TILT_Y_MAX;
    dev.absflat[ABS_TILT_Y] = S_PEN_TILT_Y_FLAT;
    dev.absfuzz[ABS_TILT_Y] = S_PEN_TILT_Y_FUZZ;

    dev.id.bustype = BUS_I2C; // This is how the Note 9 interfaces the S-Pen
    dev.id.vendor = 0x4e8; // Samsung vendor
    dev.id.product = 0x6864; // The Galaxy Note 9's USB Device ID
    dev.id.version = 9; // I made the version 9 cuz its a Note 9

    write(ufd, &dev, sizeof(dev));
    ioctl(ufd, UI_DEV_CREATE);

    return ufd;
}

int main() {
    int return_code = 0;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("server.c::ERROR::socket() socket syscall failed to create a network socket with code %d\n", sockfd);
        return_code = -1;
        goto exit;
    }
    struct sockaddr_in addr = {0};

    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    listen(sockfd, 1);

    int client = accept(sockfd, NULL, NULL);
    printf("Client connected\n");

    int ufd = setup_uinput();
    if(ufd < 0){
        return_code = -1;
        goto close_socket;
    }

    struct input_event ev;
    while(read(client, &ev, sizeof(ev)) > 0)
        write(ufd, &ev, sizeof(ev));

close_socket:
    close(sockfd);
exit:
    return return_code;
}
