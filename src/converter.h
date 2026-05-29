#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdbool.h>

#define MAX_LINE_LEN 1024

#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) \
        fprintf(stderr, "[DEBUG] (%s:%s:%d) " fmt, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) do {} while (0)
#endif

typedef struct {
    char *direct_url;
    char *input_file;
    char *output_platform;
    char *input_platform;
    bool auto_detect;
} Config;

void init_config(Config *config);

#endif // CONVERTER_H
