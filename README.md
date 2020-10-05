# nfc-daemon
nfc-daemon is a very simple event daemon that reads out the UID of nfc-tags and executes scripts.
It is based on nfc-poll.c from libnfc.

# Dependencies

* libnfc 1.7.1
* properly configured nfc-device

On Raspberry Pi OS:

```
apt update && apt install libnfc-bin libnfc-dev
```

# Installation

Compile:
```
make
```

Install:
```
sudo make install
```

# Configuration

nfc-daemon can be executed with the following parameters:
```
pi@raspi$ nfc-daemon -h
usage: nfc-daemon [-v]
  -v		 verbose display
  -h		 print help screen
  -t		 dry-run. no script-execution
  -l [0-4]	 use loglevel
```

Per default, nfc-daemon executes **/usr/local/share/nfc-daemon/run_script** 
when a nfc-tag is hold to the reader and **/usr/local/share/nfc-daemon/end_script**
on releasing the nfc-tag. 

# Example

The following sample shows the output of nfc-daemon with debug-loglevel:
```
pi@raspi$ nfc-daemon -l 4
Mon Oct  5 20:37:30 2020 [debug] runscript is /usr/local/share/nfc-daemon/run_script
Mon Oct  5 20:37:30 2020 [info] nfc-daemon uses libnfc 1.7.1
Mon Oct  5 20:37:31 2020 [info] NFC reader: pn532_spi:/dev/spidev0.0 opened
Mon Oct  5 20:37:31 2020 [debug] NFC device will poll during 382500 ms (255 pollings of 300 ms for 5 modulations)
Mon Oct  5 20:37:36 2020 [info] UID: d9  bc  c2  a1  
Mon Oct  5 20:37:36 2020 [info] Executing /usr/local/share/nfc-daemon/run_script with UID: d9  bc  c2  a1  
Mon Oct  5 20:37:36 2020 [debug] I am the parent. Stuff get serious here
Mon Oct  5 20:37:36 2020 [info] Waiting for card removing...
Mon Oct  5 20:37:36 2020 [debug] child process id: 3012
hello world: d9  bc  c2  a1
Mon Oct  5 20:37:38 2020 [info] Executing /usr/local/share/nfc-daemon/end_script
Mon Oct  5 20:37:38 2020 [debug] I am the parent. Stuff get serious here
Mon Oct  5 20:37:38 2020 [info] done.
Mon Oct  5 20:37:38 2020 [info] Accepting new nfc-tag
Mon Oct  5 20:37:38 2020 [debug] NFC device will poll during 382500 ms (255 pollings of 300 ms for 5 modulations)
Mon Oct  5 20:37:38 2020 [debug] child process id: 3013
Goodbye World
```

# Uninstall
```
sudo make uninstall
```
