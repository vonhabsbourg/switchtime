/* The ntp_packet struct uses code licensed under the BSD 3-clause. See LICENSE-THIRD-PARTY for more
information. */

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#include <switch.h>

#define NTP_TIMESTAMP_DELTA 2208988800ull

/* ------------- BEGIN BSD 3-CLAUSE LICENSED CODE-------------------- */
// https://www.cisco.com/c/en/us/about/press/internet-protocol-journal/back-issues/table-contents-58/154-ntp.html
// Struct adapted from https://github.com/lettier/ntpclient , see LICENSE-THIRD-PARTY for more information.
typedef struct {
    uint8_t li_vn_mode;  // li: two bits, leap indicator. vn: three bits, protocol version number. mode: three bits,
                         // client mode.

    uint8_t stratum;    // Stratum level of the local clock.
    uint8_t poll;       // Maximum interval between successive messages.
    uint8_t precision;  // Precision of the local clock.

    uint32_t rootDelay;       // Total round trip delay time.
    uint32_t rootDispersion;  // Max error allowed from primary clock source.
    uint32_t refId;           // Reference clock identifier.

    uint32_t refTm_s;  // Reference time-stamp seconds.
    uint32_t refTm_f;  // Reference time-stamp fraction of a second.

    uint32_t origTm_s;  // Originate time-stamp seconds.
    uint32_t origTm_f;  // Originate time-stamp fraction of a second.

    uint32_t rxTm_s;  // Received time-stamp seconds.
    uint32_t rxTm_f;  // Received time-stamp fraction of a second.

    uint32_t txTm_s;  // Transmit time-stamp seconds.
    uint32_t txTm_f;  // Transmit time-stamp fraction of a second.
} ntp_packet;
/* ------------- END BSD 3-CLAUSE LICENSED CODE-------------------- */

bool nifmInternetIsConnected();

Result ntpGetTime(time_t *p_resultTime);