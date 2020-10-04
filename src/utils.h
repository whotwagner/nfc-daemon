#ifndef _NFC_UTILS_H_
#define _NFC_UTILS_H_

#include  <stdlib.h>
#include  <string.h>
void print_nfc_target(const nfc_target *pnt, bool verbose);
void snprint_UID(char *dst, size_t size, const nfc_target *pnt);
#endif
