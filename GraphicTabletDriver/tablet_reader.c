#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <linux/input.h>

// Execute 'evtest' on Linux to get the list of input events

#define DEV_PATH "/dev/input/event28" // Replace the final number for the event number

int fd = -1;

void cleanup(int signal) {
    if (fd != -1)
        close(fd);

    printf("\nProgram terminated.\n");
    exit(signal);
}

void process_event(const struct input_event *ev) {
    if (ev->type == EV_ABS) {
        if (ev->code == ABS_X) {
            printf("X: %d\n", ev->value);
        } else if (ev->code == ABS_Y) {
            printf("Y: %d\n", ev->value);
        } else if (ev->code == ABS_PRESSURE) {
            printf("Pressure: %d\n", ev->value);
        }
    } else if (ev->type == EV_KEY) {
        // Handle button pressed here
    }
}

int main() {
    struct input_event ev;

    signal(SIGINT, cleanup);

    if ((fd = open(DEV_PATH, O_RDONLY)) < 0) {
        perror("Error opening device");
        return 1;
    }

    printf("Listening to tablet events. Press Ctrl + C to exit.\n");

    while (1) {
        ssize_t n = read(fd, &ev, sizeof(ev));
        if (n == sizeof(ev)) {
            process_event(&ev);
        }
    }

    return 0;
}