/*
 * Cap - Command-line argument parser library in single header file.
 * Author: Hossein Khosravi (https://github.com/thehxdev)
 * Repository: https://github.com/thehxdev/cap
 */


#ifndef __CAP_H__
#define __CAP_H__


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define CAP_VERSION "1.0.0"
#define CAP_DEINIT __attribute__((cleanup(cap_deinit)))


typedef struct Cap_RawArgs_t {
    char **argv;
    int argc;
} Cap_RawArgs_t;

typedef struct Cap_t Cap_t;


/* initialize cap */
Cap_t *cap_init(int argc, char **argv);


/* free all memory allocated by cap */
void cap_deinit(Cap_t **cap);


/* register a new sub-command */
int cap_register_subcmd(Cap_t *cap,
                        const char *name,
                        const char *help);


/* register a new flag 
 *
 * @subcmd can be NULL */
int cap_register_flag(Cap_t *cap,
                      const char *subcmd,
                      const char *name,
                      const char *help);


/* get a flag's value after parsing arguments
 *
 * @subcmd can be NULL */
char *cap_flag_getval(Cap_t *cap,
                      const char *subcmd,
                      const char *name);


int cap_flag_provided(Cap_t *cap,
                      const char *subcmd,
                      const char *name);


Cap_RawArgs_t cap_subcmd_rawargs(Cap_t *cap, const char *subcmd);

int cap_parse_args(Cap_t *cap);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __CAP_H__ */
