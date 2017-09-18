#include "common.h"

PAM_EXTERN int pam_sm_acct_mgmt( pam_handle_t *pamh,
  int flags,
  int argc, 
  const char** argv )
{
  int retval = PAM_SUCCESS ;

  D(("Called")) ;

  return retval ;
}
