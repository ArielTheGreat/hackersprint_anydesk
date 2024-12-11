# ifndef DECODER_H
# define DECODER_H

# include <pthread.h>
#include <immintrin.h>

// System Headers
#include <sys/stat.h>    // For file status operations (e.g., stat, chmod)
#include <sys/mman.h>    // For memory management (e.g., mmap, munmap)
#include <fcntl.h>       // For file control options (e.g., open, O_RDONLY)
#include <unistd.h>      // For POSIX operating system API (e.g., read, write, close)

// Standard Headers
#include <stdint.h>      // For fixed-width integer types (e.g., int32_t, uint64_t)
#include <stdio.h>       // For input/output operations (e.g., printf, fopen)
#include <stdlib.h>      // For general utilities (e.g., malloc, exit)
#include <string.h>      // For string handling (e.g., strcpy, memcmp)

typedef char i8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int i32;
typedef unsigned u32;
typedef unsigned long u64;

struct bmp_header
{
	// Note: header
	i8  signature[2]; // should equal to "BM"
	u32 file_size;
	u32 unused_0;
	u32 data_offset;

	// Note: info header
	u32 info_header_size;
	u32 width; // in px
	u32 height; // in px
	u16 number_of_planes; // should be 1
	u16 bit_per_pixel; // 1, 4, 8, 16, 24 or 32
	u32 compression_type; // should be 0
	u32 compressed_image_size; // should be 0
	// Note: there are more stuff there but it is not important here
};


#define PRINT_ERROR(cstring) write(STDERR_FILENO, cstring, sizeof(cstring) - 1)

# endif