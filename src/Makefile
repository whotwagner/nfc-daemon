CC = "gcc"
LIBS = -lnfc
CFLAGS = -Wall -Wextra -Werror
PROGNAME = "nfc-daemon"
OBJ = nfc-daemon.o utils.o logger.o runner.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nfc-daemon: $(OBJ)
	$(CC) $(LIBS) -o $@ $^ $(CFLAGS)

clean: nfc-daemon
	rm *.o
	rm nfc-daemon
