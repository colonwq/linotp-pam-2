#include "common.h"

/*
 * LinOTP does not do sessions
 * this module returns success
*/

PAM_EXTERN int pam_sm_open_session( pam_handle_t *pamh,
  int flags,
  int argc,
  const char** argv ) 
{
  int retval = PAM_SUCCESS ;

  D(( "Called" )) ;

  return retval ;
}

PAM_EXTERN int pam_sm_close_session( pam_handle_t *pamh,
  int flags,
  int argc,
  const char** argv ) 
{
  int retval = PAM_SUCCESS ;

  D(( "Called" )) ;

  return retval ;
}

