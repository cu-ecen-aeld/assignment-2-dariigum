#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Open syslog
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Validate input arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        printf("Usage: %s <file-path> <string>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *file_path = argv[1];
    const char *string_to_write = argv[2];

    // Open the file
    FILE *file = fopen(file_path, "w");
    if (!file) {
        syslog(LOG_ERR, "Error opening file %s: %s", file_path, strerror(errno));
        perror("Error");
        closelog();
        return 1;
    }

    // Write the string to the file
    if (fprintf(file, "%s", string_to_write) < 0) {
        syslog(LOG_ERR, "Error writing to file %s: %s", file_path, strerror(errno));
        fclose(file);
        closelog();
        return 1;
    }

    // Log success
    syslog(LOG_DEBUG, "Writing \"%s\" to %s", string_to_write, file_path);

    // Clean up
    fclose(file);
    closelog();

    return 0;
}
