/*
 * Cap - Command-line argument parser library in single header file.
 * Author: Hossein Khosravi (https://github.com/thehxdev)
 * Repository: https://github.com/thehxdev/cap
 *
 *
 * MIT License
 * 
 * Copyright (c) 2024 Hossein Khosravi (@thehxdev)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __CAP_H__
#define __CAP_H__


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define CAP_VERSION "1.1.0"
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


/* is a flag present in arguments or not */
int cap_flag_provided(Cap_t *cap,
                      const char *subcmd,
                      const char *name);


/* get provided sub-command in command-line */
int cap_subcmd_provided(Cap_t *cap, const char *subcmd);


/* get sub-command's arguments as raw arguments */
Cap_RawArgs_t cap_subcmd_rawargs(Cap_t *cap, const char *subcmd);


/* parse the command-line arguments */
int cap_parse_args(Cap_t *cap);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __CAP_H__ */
