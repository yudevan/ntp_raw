/*
 * ntp.h -- Network Time Protocol header file.
 *
 * Structs gleaned from W. Richard Stevens' et al. Unix Network 
 * Programming Vol. 1
 *
 * Author: Denis Kobozev <d.v.kobozev@gmail.com>
 */

#ifndef _NTP_H
#define _NTP_H

/* 1970 - 1900 in seconds */
#define JAN_1970 2208988800UL

/* 64-bit fixed point */
struct l_fixedpt {
    uint32_t int_part;
    uint32_t fraction;
};

/* 32-bit fixed point */
struct s_fixedpt {
    uint16_t int_part;
    uint16_t fraction;
};

/* NTP header */
struct ntpdata {
    u_char status;
    u_char stratum;
    u_char ppoll;
    int precision:8;
    struct s_fixedpt distance;
    struct s_fixedpt dispersion;
    uint32_t refid;
    struct l_fixedpt reftime;
    struct l_fixedpt org;
    struct l_fixedpt rec;
    struct l_fixedpt xmt;
};

#define VERSION_MASK 0x38
#define MODE_MASK 0x07

#define MODE_CLIENT 3
#define MODE_SERVER 4
#define MODE_BROADCAST 5

#endif /* _NTP_H */
