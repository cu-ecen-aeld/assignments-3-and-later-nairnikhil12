#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    openlog("writer-log", LOG_PID, LOG_USER);

    if(argc != 3) {
        printf("Error: Expected 2 arguments");
        return 1;
    }

    int fid = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);

    if(fid == -1) {
        syslog(LOG_ERR, "Error: %s", strerror(errno));
        perror("Error: Unable to open the file.");
        return 1;
    }

    int count = strlen(argv[2]);
    int nr = write(fid, argv[2], count);

    if(nr == -1) {
        printf("Error: Unable to write to the file.");
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);

    close(fid);
    closelog();
}