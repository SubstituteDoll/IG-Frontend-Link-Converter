#include "converter.h"
#include <stddef.h>

void init_config(Config *config) {
    config->direct_url = NULL;
    config->input_file = NULL;
    config->output_platform = NULL;
    config->input_platform = NULL;
    config->auto_detect = true;
}
