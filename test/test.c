/* Standard library */
#include <stdio.h>
#include <string.h>

/* Cap */
#include "../src/cap.h"


int main(int argc, char **argv) {
    int err;
    Cap_t *cap = cap_init(argc, argv);
    if (cap == NULL)
        return 1;

    err = cap_register_subcmd(cap, "run", "run a source file");
    if (err)
        goto exit;

    err = cap_register_flag(cap, NULL, "file", "file path");
    if (err)
        goto exit;

    err = cap_register_flag(cap, "run", "file", "file path");
    if (err)
        goto exit;

    err = cap_parse_args(cap);
    if (err)
        goto exit;

    Cap_RawArgs_t run_args = cap_subcmd_rawargs(cap, "run");

    for (int i = 0; i < run_args.argc; i++)
        printf("%s\n", run_args.argv[i]);

exit:
    cap_deinit(&cap);
    return 0;
}
