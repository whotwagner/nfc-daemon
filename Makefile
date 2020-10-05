SUBDIRS = src
export PREFIX = /usr/local

.PHONY: subdirs $(SUBDIRS)
.PHONY: all install uninstall

subdirs: $(SUBDIRS)
all: $(SUBDIRS)
$(SUBDIRS): 
	$(MAKE) -C $@

install:
	$(MAKE) -C src -f Makefile install
	test -d $(PREFIX)/share/nfc-daemon || mkdir -p $(PREFIX)/share/nfc-daemon
	chown root.root $(PREFIX)/share/nfc-daemon
	chmod 755 $(PREFIX)/share/nfc-daemon
	cp scripts/* $(PREFIX)/share/nfc-daemon
	chown root.root $(PREFIX)/share/nfc-daemon/*
	chmod 755 $(PREFIX)/share/nfc-daemon/*

uninstall:
	$(MAKE) -C src -f Makefile uninstall
	test -d $(PREFIX)/share/nfc-daemon && rm -rf $(PREFIX)/share/nfc-daemon

.PHONY: clean 
clean:
	$(MAKE) -C src -f Makefile clean
