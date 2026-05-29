#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter.h"

// Prints a short introduction message
void print_intro(void);
// Prints syntax error message
void print_syntax_err(void);
// Prints syntax guide message
void print_usage_guide(FILE *stream);

int main(int argc, char **argv) {
    DEBUG_PRINT("Debug mode executable active.\n");

    // Intercept empty execution immediately
    if (argc < 2) {
        print_syntax_err();
        print_usage_guide(stderr);
        return EXIT_FAILURE;
    }

    // Intercept Global Context Help requests
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_intro();
        print_usage_guide(stderr);
        return EXIT_SUCCESS;
    }

    Config config;
    init_config(&config);

    // Initial validation check for proper single/batch mode entry patterns
    if (argv[1][0] == '-') {
        if (strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "--from-file") != 0) {
            // Reject non-file leading flags
            // First argument must either be a direct URL or the file flag
            print_syntax_err();
            print_usage_guide(stdout);
            return EXIT_FAILURE;
        }
    }

    DEBUG_PRINT("All syntax guides centered in main.c. Ready to parse further arguments.\n");
    return EXIT_SUCCESS;
}

void print_intro() {
    printf("IGconvert - Alternative Instagram Frontend Link Converter\n\n");
}

void print_syntax_err(void) {
    printf("Syntax Error.\n\n");
}

void print_usage_guide(FILE *stream) {
    fprintf(stream, "Usage:\n");
    fprintf(stream, "  Single URL Mode (Default):\n");
    fprintf(stream, "    ./IGconvert [URL] -OP [output_platform]\n\n");
    fprintf(stream, "  Batch File Mode:\n");
    fprintf(stream, "    ./IGconvert -f [file_name] -OP [output_platform]\n\n");
    fprintf(stream, "Options:\n");
    fprintf(stream, "  -h, --help               Display this help text manual\n");
    fprintf(stream, "  -OP, --output-platform   Specify the target platform to translate links to\n");
    fprintf(stream, "  -f, --from-file          Specify a text file containing batch links to convert\n");
}

