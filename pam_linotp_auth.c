#include "common.h"

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh,
  int flags,
  int argc,
  const char** argv )
{
  int retval = PAM_SUCCESS ;
  int try_first_pass = 0 ;
  int use_first_pass = 0 ;
  int debug = 0 ;
  char* user = NULL ;
  char* pass = NULL ;
  int i = 0 ;

  D(("Called")) ;
  myprint( "Called\n" ) ;

  for ( i = 0 ; i < argc; i++ )
  {
    if( strcmp( argv[i], "debug") == 0 )
    {
      debug = 1 ;
    } else if( strcmp( argv[i], "try_first_pass") == 0 )
    {
      try_first_pass = 1 ;
      D(("try first pass")) ;
    } else if( strcmp( argv[i], "use_first_pass") == 0 )
    {
      use_first_pass = 1 ;
      D(("use first pass")) ;
    }
  }

  if( ( retval = pam_get_user( pamh, (const char **)&user, NULL )) != PAM_SUCCESS )
  {
    D(("pam_get_user error: %s", pam_strerror(pamh, retval )) ) ;
    goto DONE ;
  }

  D(("User name: %s", user )) ;
  my_print("User name: %s", user) ;

  if( ( retval = pam_get_item( pamh, PAM_AUTHTOK, (const void **)&pass )) != PAM_SUCCESS )
  {
    D(("pam_get_item(AUTHTOK) error: %s", pam_strerror(pamh, retval )) ) ;
    goto DONE ;
  }

  D(("User pass: %s", pass)) ;
  my_print("User pass: %s", pass) ;

  DONE:
  return retval ;
}
