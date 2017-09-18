#include "common.h"

void my_print( const char* format, ...)
{
   va_list args;
   //FILE* OF ;

   va_start(args,format);

  openlog( "pam_linotp2" , LOG_PID, LOG_AUTHPRIV ) ;
  vsyslog( LOG_INFO, format, args ) ;
  closelog() ;


   //OF = fopen("/tmp/otp-debug.txt","w+");
   //vfprintf(OF ,format,args);
   //fclose( OF ) ;

   va_end(args);

}
