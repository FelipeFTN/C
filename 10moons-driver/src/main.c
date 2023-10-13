#include <stdio.h>
#include <stdlib.h>
/* #include <unistd.h> */
#include <string.h>

#include "lib/events.h"
#include "handler/events.h"

int main() {
    int err;
    int tablet_events[10];

    err = scan_events();
    if (err < 0)
        return -1;

    err = get_tablet_events(tablet_events);
    if (err < 0)
        return -1;

    printf("tablet events: %d", tablet_events[0]);

    return 0;
}
