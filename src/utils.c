
#include <nfc/nfc.h>
#include "logger.h"

void print_nfc_target(const nfc_target *pnt, bool verbose)
{
	char *s;
	str_nfc_target(&s, pnt, verbose);
	printf("%s", s);
	nfc_free(s);
}

int snprint_hex(char *dst, size_t size, const uint8_t *pbtData, const size_t szBytes)
{
  size_t  szPos;
  size_t res = 0;
  for (szPos = 0; szPos < szBytes; szPos++) {
    res += snprintf(dst + res, size - res, "%02x  ", pbtData[szPos]);
  }
  /* res += snprintf(dst + res, size - res, "\n"); */
  return res;
}


void snprint_UID(char *dst, size_t size, const nfc_target *pnt)
{
  if (NULL != pnt) {
    switch (pnt->nm.nmt) {
      case NMT_ISO14443A:
	snprint_hex(dst,size,pnt->nti.nai.abtUid,pnt->nti.nai.szUidLen);
        break;
      case NMT_JEWEL:
	log_warn("Unsupported RFID-Tag");
        break;
      case NMT_FELICA:
	log_warn("Unsupported RFID-Tag");
        break;
      case NMT_ISO14443B:
	log_warn("Unsupported RFID-Tag");
        break;
      case NMT_ISO14443BI:
	log_warn("Unsupported RFID-Tag");
        break;
      case NMT_ISO14443B2SR:
	log_warn("Unsupported RFID-Tag");
        break;
      case NMT_ISO14443B2CT:
	log_warn("Unsupported RFID-Tag");
        break;
      case NMT_DEP:
	log_warn("Unsupported RFID-Tag");
        break;
    }
  }
}

