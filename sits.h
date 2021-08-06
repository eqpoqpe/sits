/* SITS H FILE
 *
 * (C) Copyright Ryan Martin (ISNTL) 2021 <?>
 */

#ifndef _SITS_H
#define _SITS_H

#include <string.h>
#include <ctype.h>

/* Numbers
 * Letters
 */

/* C99 */
#if defined(__gnu_linux__)

#define OK      2048
#define _OK     1024
#define NK      0

#include <stdint.h>

static inline uint32_t s_cmp(char *s0, char *s1)
{
    uint32_t lo_size;
    uint32_t index = 0;
    uint32_t s0_len = strlen(s0);
    uint32_t s1_len = strlen(s1);
    lo_size = ((s0_len < s1_len) ? s0_len : s1_len);
    for (; index < lo_size; index++) {
        if (isdigit(*(s0 + index)) == OK && isdigit(*(s1 + index)) == OK) {
            if ((int) (*(s0 + index) - '0') != (int) *(s1 + index) - '0') {
                return ((*(s0 + index) - '0') < (*(s1 + index) - '0') ? 0 : 1);
            }
        } else {
            if (isdigit(*(s0 + index)) == OK) {
                return 0;
            } else if (isdigit(*(s1 + index)) == OK) {
                return 1;
            } else {
                if (*(s0 + index) < *(s1 + index)) return 0;
                else if (*(s0 + index) > *(s1 + index)) return 1;
            }
        }
    }
}

#endif /* _SITS_H */
#endif /* __linux__ */
