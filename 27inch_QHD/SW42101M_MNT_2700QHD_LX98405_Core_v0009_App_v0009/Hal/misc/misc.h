#ifndef MISC_H
#define MISC_H

#define uDELAY(usec)  udelay(usec)
#define mDELAY(msec)  uDELAY(msec * 1000)

void udelay (uint32_t usec);
void ReMapVectorTableToRam(void);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);

#endif	/* MISC_H */
