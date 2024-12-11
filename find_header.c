
#include "decoder.h"

int check_rgb_match_header(char *str)
{
    struct color color_rgb;

    color_rgb.b = str[0];
    color_rgb.g = str[1];
    color_rgb.r = str[2];
    color_rgb.unused = str[3];
    printf("BLUE:%u GREEN:%u RED:%u\n", color_rgb.b, color_rgb.g, color_rgb.r);
    // printf("A: %s\n", str);
    // if ()
    // {
    //     return (1);
    // }
    return (0);
}

void find_header(char *filename)
{
    int fd = open(filename, O_RDONLY);
    size_t bytes_to_read = 4;
    char *buffer = malloc(bytes_to_read);
    size_t bytes_read;

    while(1)
    {
        bytes_read = read(fd, buffer, bytes_to_read);
        if (bytes_read < bytes_to_read) {
            printf("Failed to read enough bytes. Expected: %zu, Got: %zd\n", bytes_to_read, bytes_read);
            break;
        }
        if (check_rgb_match_header(buffer) != 0) {
            printf("Match found!\n");
            break;
        }
    }

    free(buffer);
    close(fd);
}

void run_decoder(char *filename)
{
    find_header(filename);
}