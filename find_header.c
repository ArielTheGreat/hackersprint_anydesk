
#include "decoder.h"

int check_rgb_match_header(char *str)
{
    if (str)
    {
        return (1);
    }
    return (0);
}

void find_header(unsigned short bits_per_pixel, char *filename)
{
    int fd = open(filename, O_RDONLY);
    size_t bytes_to_read = bits_per_pixel / 8;
    char *buffer = malloc(bytes_to_read);
    ssize_t bytes_read;

    while(1)
    {
        bytes_read = read(fd, buffer, bytes_to_read);
        if (check_rgb_match_header(buffer) != 0) {
            printf("Match found!\n");
            break;
        }
    }

    free(buffer);
    close(fd);
}

void run_decoder(struct bmp_header* header_image, char *filename)
{
    find_header(header_image->bit_per_pixel, filename);
}