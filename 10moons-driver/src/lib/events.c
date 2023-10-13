#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/input.h>

#define EVENT_OUTPUT "/tmp/events_output.txt"
#define DEV_INPUT_EVENT "/dev/input"
#define EVENT_DEV_NAME "event"

int is_event_device(const struct dirent *dir) {
	return strncmp(EVENT_DEV_NAME, dir->d_name, 5) == 0;
}

int clear_events(void) {
    FILE *event_output;
    char command[256] = { 0 };

    snprintf(command, sizeof(command), "echo '' > %s", EVENT_OUTPUT);
    event_output = popen(command, "r");
    if (event_output == NULL) {
        perror("Error while clearing events output");
        return -1;
    }

    if (pclose(event_output) < 0) {
        perror("Failed to close pipe");
        return -1;
    }

    return 0;
}

int save_event(char *event_line) {
    FILE *event_output;
    char command[256] = { 0 };

    snprintf(command, sizeof(command), "echo '%s' >> %s", event_line, EVENT_OUTPUT);
    event_output = popen(command, "r");
    if (event_output == NULL) {
        perror("Error while registering events output");
        return -1;
    }

    if (pclose(event_output) < 0) {
        perror("Failed to close pipe");
        return -1;
    }

    return 0;
}

int scan_events(void) {
	struct dirent **namelist;
	int i, ndev, err;

	ndev = scandir(DEV_INPUT_EVENT, &namelist, is_event_device, alphasort);
	if (ndev <= 0)
		return -1;

    err = clear_events();
	for (i = 0; i < ndev; i++) {
		int fd = -1;
		char fname[64];
		char name[256] = "???";
        char event[256] = { 0 };

		snprintf(fname, sizeof(fname),
			 "%s/%s", DEV_INPUT_EVENT, namelist[i]->d_name);

		fd = open(fname, O_RDONLY);
		if (fd < 0)
			continue;

		ioctl(fd, EVIOCGNAME(sizeof(name)), name);

        snprintf(event, sizeof(event), "%s: %s\n", fname, name);

        err = save_event(event);
        if (err < 0) {
            printf("error: %d", err);
        }

		close(fd);

		free(namelist[i]);
	}

	return 0;
}
