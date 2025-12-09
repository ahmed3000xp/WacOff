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

#include "client.h"

#ifdef SM_N960F
void (*the_void)(void);
#else
#error "You must select a Note 9 model to build for"
#endif

int main(){
    int return_code = 0;
    
    char server_ip[64];

    printf("Enter server IP: ");
    fflush(stdout);
    fgets(server_ip, sizeof(server_ip), stdin);

    server_ip[strcspn(server_ip, "\n")] = 0;

    int s_pen_fd = open(S_PEN_EVDEV_PATH, O_RDONLY);
    if(s_pen_fd < 0){
        printf("client.c::ERROR::open() open syscall failed with code %d when opening %s to use the S-Pen\n", s_pen_fd, S_PEN_EVDEV_PATH);
        return_code = -1;
        goto exit;
    }

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0){
        printf("client.c::ERROR::socket() socket syscall failed to create a network socket with code %d\n", server_sock);
        return_code = -1;
        goto close_s_pen_fd;
    }
    struct sockaddr_in server = {0};

    server.sin_family = AF_INET;
    server.sin_port = htons(5000); 
    server.sin_addr.s_addr = inet_addr(server_ip);

    int connect_status = connect(server_sock, (struct sockaddr*)&server, sizeof(server));
    if(connect_status < 0){
        printf("client.c::ERROR::connect() connect syscall failed to connect to the server with code %d\n", connect_status);
        return_code = -1;
        goto close_server_sock;
    }

    struct input_event s_pen_ev;
    while(read(s_pen_fd, &s_pen_ev, sizeof(s_pen_ev)) > 0)
        write(server_sock, &s_pen_ev, sizeof(s_pen_ev));

close_server_sock:
    close(server_sock);
close_s_pen_fd:
    close(s_pen_fd);
exit:
    return return_code;
}
