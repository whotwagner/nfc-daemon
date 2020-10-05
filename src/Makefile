CC = "gcc"
LIBS = -lnfc
CFLAGS = -Wall -Wextra -Werror
PROGNAME = "nfc-daemon"
OBJ = nfc-daemon.o utils.o logger.o runner.o
SCRIPTMACRO = -D _RUNSCRIPT="\"$(PREFIX)/share/nfc-daemon/$(RUNSCRIPT)\"" -D _ENDSCRIPT="\"$(PREFIX)/share/nfc-daemon/$(ENDSCRIPT)\""

%.o: %.c $(DEPS)
	$(CC) -c $(SCRIPTMACRO) -o $@ $< $(CFLAGS)

nfc-daemon: $(OBJ)
	$(CC) $(LIBS) -o $@ $^ $(CFLAGS)

.PHONY: clean install uninstall

install: nfc-daemon
	cp $(PROGNAME) $(PREFIX)/bin
	chown root.root $(PREFIX)/bin/$(PROGNAME)
	chmod 755 $(PREFIX)/bin/$(PROGNAME)

uninstall: install
	test -e $(PREFIX)/bin/$(PROGNAME) && rm $(PREFIX)/bin/$(PROGNAME)

clean: nfc-daemon
	rm *.o
	rm nfc-daemon
