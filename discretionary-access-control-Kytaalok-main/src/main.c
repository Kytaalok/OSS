#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check arguments numbers
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <mode> <file>\n", argv[0]);
        return 1;
    }
    
    // Check digits number
    if (strlen(argv[1]) > 4) {
        fprintf(stderr, "Invalid mode: mode should contain 4 digits or less: %s\n", argv[1]);
        return 1;
    }

    // Convertation from string to int
    char *endptr;
    unsigned long mode = strtoul(argv[1], &endptr, 8);  

    // Check input mode
    if (*endptr != '\0' || endptr == argv[1]) {
        fprintf(stderr, "Invalid mode: %s\n", argv[1]);
        return 1;
    }

    // Change permission
    if (chmod(argv[2], (mode_t)mode) != 0) {
        perror("chmod failed");
        return 1;
    }

    printf("Permissions changed successfully for %s to %04lo\n", argv[2], mode);
    return 0;
}