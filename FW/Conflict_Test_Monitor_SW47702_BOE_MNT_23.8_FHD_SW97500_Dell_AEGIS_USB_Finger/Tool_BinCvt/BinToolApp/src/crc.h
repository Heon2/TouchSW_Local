#ifndef __CRC_H__
#define __CRC_H__

extern uint16_t Crc16WordCalc(const uint16_t *DataIn, uint32_t DataLen, uint16_t InitVal);
extern uint32_t GetCRCValue(const uint16_t * pFWBuf, uint32_t ulSize);

#endif//__CRC_H__
