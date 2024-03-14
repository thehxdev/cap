# Cap

Cap is a single header command-line argument parser library written in C
with low memory footprint and compatible with C99 standard.



## Usage

To use Cap just include `cap.h` file then compile and link `cap.c` file with your project.



## Example

Use this code snippet to learn how to use Cap.

```c
#include <stdio.h>
#include "cap.h"

int main(int argc, char **argv) {
    int err = 0;

    // Initialize cap
    Cap_t *cap = cap_init(argc, argv);
    if (cap == NULL)
        // handle error
        return 1;

    // register a new sub-command
    // say our app is a compiler and we want a `compile` sub-command
    err = cap_register_subcmd(cap, "compile", "Compile the source files");
    if (err != 0)
        // handle error
        goto exit;

    // register a new flag
    // say we want to add a new flag to `compile` sub-command
    err = cap_register_flag(cap, "compile", "op", "optimize the source code");

    // regist a new flag with no sub-command
    err = cap_register_flag(cap, NULL, "file", "file path");


    err = cap_parse_args(cap);
    if (err != 0)
        // must handle this error
        goto exit;


    // get raw arguments for `compile` sub-command
    Cap_RawArgs_t run_args = cap_subcmd_rawargs(cap, "compile");

    // a flag is present in command-line args or not (used for boolean flags)
    // result will be 0 (false) or 1 (true)
    int op = cap_flag_provided(cap, "compile", "op");

    // get a flag's value
    char *tmp = cap_flag_getval(cap, NULL, "file");


exit:
    // deinit and free all memory allocated by cap
    cap_deinit(&cap);
    return err;
}
```

