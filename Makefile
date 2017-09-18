CC = gcc
CFLAGS = -Wall -DLINUX_PAM -DPAM_DYNAMIC -fPIC
CFLAGS += -I./

CFLAGS += -DDEBUG -DPAM_DEBUG

LDFLAGS = -shared -Xlinker -x -lpam

PAM_MODULE_NAME = "pam_linotp2"

INSTALL_DIR = /lib64/security

TARG = pam_linotp2.so

#OBJS = pam_linotp_acct.o pam_linotp_auth.o pam_linotp_chauth.o pam_linotp_sess.o pam_linotp_setcred.o support.o
OBJS = pam_linotp_auth.o support.o

$(TARG): $(OBJS) common.h
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	#$(CC) $(LDFLAGS) -i $(OBJS) -o $@

install: $(TARG)
	cp $(TARG) $(INSTALL_DIR)

.c.o:
	$(CC) $(CFLAGS) -DPAM_MODULE_NAME=\"$(PAM_MODULE_NAME)\" -c $<

clean:
	@rm -f $(OBJS) $(TARG)
	@echo "Done."
