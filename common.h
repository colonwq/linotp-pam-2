#ifndef COMMON_H
#define COMMON_H

#define PAM_SM_AUTH
#define PAM_SM_SESSION
#define PAM_SM_PASSWORD
#define PAM_SM_ACCOUNT

#include <security/pam_modules.h>
#include <security/pam_misc.h>
#include <security/_pam_macros.h>


#include <time.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdarg.h>
#include <syslog.h>

/* print the message to stdout */
#define P2STDOUT 0x0000001
/* print the message to stderr */
#define P2STDERR 0x0000010
/* print the message as debug */
#define P2DEBUG  0x0000100
/* print the message as syslog */
#define P2SYSLOG 0x0001000

void my_print( const char*, ...);

#endif
