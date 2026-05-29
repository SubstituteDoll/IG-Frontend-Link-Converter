#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdbool.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *direct_url;
    char *input_file;
    char *output_platform;
    char *input_platform;
    bool auto_detect;
} Config;

void init_config(Config *config);

#endif // CONVERTER_H
