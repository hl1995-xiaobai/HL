#ifndef _CRC_H_
#define _CRC_H_

#ifdef CRC_COOUT
unsigned short GetCRC16(unsigned char *puchMsg, unsigned char usDataLen);
#endif

unsigned short CRC16_Modbus( unsigned char* puchMsg, unsigned char len);


#endif
