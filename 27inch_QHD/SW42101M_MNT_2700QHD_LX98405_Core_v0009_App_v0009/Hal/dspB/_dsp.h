#ifndef _DSP_H_
#define _DSP_H_


typedef union
{
    struct {
        unsigned    XSIZE0:                    8;
        unsigned    XSIZE1:                    8;
        unsigned    XSIZE2:                    8;
        unsigned    XSIZE3:                    8;
    } b;
    __IO uint32_t w;
} t_TDSP_DMA_XSIZE;

typedef union
{
    struct {
        unsigned    YSIZE0:                    8;
        unsigned    YSIZE1:                    8;
        unsigned    YSIZE2:                    8;
        unsigned    YSIZE3:                    8;
    } b;
    __IO uint32_t w;
} t_TDSP_DMA_YSIZE;


typedef struct
{
    __IO uint32_t                    TDSP_REGA0;                     //0x0000
    __IO uint32_t                    TDSP_REGA1;                     //0x0001
    __IO uint32_t                    TDSP_REGA2;                     //0x0002
    __IO uint32_t                    TDSP_REGA3;                     //0x0003
    __IO uint32_t                    TDSP_REGA4;                     //0x0004
    __IO uint32_t                    TDSP_REGA5;                     //0x0005
    __IO uint32_t                    TDSP_REGA6;                     //0x0006
    __IO uint32_t                    TDSP_REGA7;                     //0x0007
    __IO uint32_t                    TDSP_REGB0;                     //0x0008
    __IO uint32_t                    TDSP_REGB1;                     //0x0009
    __IO uint32_t                    TDSP_REGB2;                     //0x000A
    __IO uint32_t                    TDSP_REGB3;                     //0x000B
    __IO uint32_t                    TDSP_REGB4;                     //0x000C
    __IO uint32_t                    TDSP_REGB5;                     //0x000D
    __IO uint32_t                    TDSP_REGB6;                     //0x000E
    __IO uint32_t                    TDSP_REGB7;                     //0x000F
    __IO uint32_t                    TDSP_REGC0;                     //0x0010
    __IO uint32_t                    TDSP_REGC1;                     //0x0011
    __IO uint32_t                    TDSP_REGC2;                     //0x0012
    __IO uint32_t                    TDSP_REGC3;                     //0x0013
    __IO uint32_t                    TDSP_REGC4;                     //0x0014
    __IO uint32_t                    TDSP_REGC5;                     //0x0015
    __IO uint32_t                    TDSP_REGC6;                     //0x0016
    __IO uint32_t                    TDSP_REGC7;                     //0x0017
    __IO uint32_t                    TDSP_RESERVED00;                //0x0018
    __IO uint32_t                    TDSP_RESERVED01;                //0x0019
    __IO uint32_t                    TDSP_RESERVED02;                //0x001A
    __IO uint32_t                    TDSP_RESERVED03;                //0x001B
    __IO uint32_t                    TDSP_RESERVED04;                //0x001C
    __IO uint32_t                    TDSP_RESERVED05;                //0x001D
    __IO uint32_t                    TDSP_RESERVED06;                //0x001E
    __IO uint32_t                    TDSP_RESERVED07;                //0x001F
    __I  uint32_t                    TDSP_RESERVED07_1;              //0x0020
    __IO uint32_t                    TDSP_RESERVED07_2;              //0x0021
    __IO uint32_t                    TDSP_RESERVED08;                //0x0022
    __IO uint32_t                    TDSP_RESERVED09;                //0x0023
    __IO uint32_t                    TDSP_RESERVED10;                //0x0024
    __IO uint32_t                    TDSP_RESERVED11;                //0x0025
    __IO uint32_t                    TDSP_RESERVED12;                //0x0026
    __IO uint32_t                    TDSP_RESERVED13;                //0x0027
    __IO uint32_t                    TDSP_RESERVED14;                //0x0028
    __IO uint32_t                    TDSP_RESERVED15;                //0x0029
    __IO uint32_t                    TDSP_RESERVED16;                //0x002A
    __IO uint32_t                    TDSP_RESERVED17;                //0x002B
    __IO uint32_t                    TDSP_RESERVED18;                //0x002C
    __IO uint32_t                    TDSP_RESERVED19;                //0x002D
    __IO uint32_t                    TDSP_RESERVED20;                //0x002E
    __IO uint32_t                    TDSP_RESERVED21;                //0x002F
    __IO uint32_t                    TDSP_RESERVED22;                //0x0030
    __IO uint32_t                    TDSP_RESERVED23;                //0x0031
    __IO uint32_t                    TDSP_RESERVED24;                //0x0032
    __IO uint32_t                    TDSP_RESERVED25;                //0x0033
    __IO uint32_t                    TDSP_RESERVED26;                //0x0034
    __IO uint32_t                    TDSP_RESERVED27;                //0x0035
    __IO uint32_t                    TDSP_RESERVED28;                //0x0036
    __IO uint32_t                    TDSP_RESERVED29;                //0x0037
    __IO uint32_t                    TDSP_RESERVED30;                //0x0038
    __IO uint32_t                    TDSP_RESERVED31;                //0x0039
    __IO uint32_t                    TDSP_RESERVED32;                //0x003A
    __IO uint32_t                    TDSP_RESERVED33;                //0x003B
    __IO uint32_t                    TDSP_RESERVED34;                //0x003C
    __IO uint32_t                    TDSP_RESERVED35;                //0x003D
    __IO uint32_t                    TDSP_RESERVED36;                //0x003E
    __IO uint32_t                    TDSP_RESERVED37;                //0x003F
    __IO uint32_t                    TDSP_PC;                        //0x0040
    __I  uint32_t                    TDSP_RESERVED37_1;                //0x0041
    __IO uint32_t                    TDSP_RESERVED37_2;                //0x0042
    __IO uint32_t                    TDSP_RESERVED37_3;                //0x0043
    __IO uint32_t                    TDSP_RESERVED37_4;                //0x0044
    __IO uint32_t                    TDSP_RESERVED37_5;                //0x0045
    __I  uint32_t                    TDSP_RESERVED37_6;                //0x0046
    __I  uint32_t                    TDSP_RESERVED37_7;                //0x0047
    __I  uint32_t                    TDSP_RESERVED37_8;                //0x0048
    __I  uint32_t                    TDSP_BUSY;                      //0x0049
    __IO uint32_t                    TDSP_CACHE_BASE;                //0x004A
    __IO uint32_t                    TDSP_RESERVED37_9;                //0x004B
    __IO uint32_t            	     TDSP_RESERVED37_10;                 //0x004C
    __IO uint32_t            		 TDSP_RESERVED37_11;                 //0x004D
    __IO uint32_t            		 TDSP_RESERVED37_12;                 //0x004E
    __IO uint32_t            		 TDSP_RESERVED37_13;                 //0x004F
    __IO uint32_t           		 TDSP_RESERVED37_14;                //0x0050
    __I  uint32_t           		 TDSP_RESERVED37_15;                //0x0051
    __IO uint32_t         			 TDSP_RESERVED37_16;              //0x0052
    __IO uint32_t         			 TDSP_RESERVED37_17;              //0x0053
    __IO uint32_t         			 TDSP_RESERVED37_18;              //0x0054
    __IO uint32_t         			 TDSP_RESERVED37_19;              //0x0055
    __I  uint32_t                    TDSP_RESERVED38;                //0x0056
    __IO uint32_t                    TDSP_RESERVED39;                //0x0057
    __IO uint32_t                    TDSP_RESERVED40;                //0x0058
    __IO uint32_t                    TDSP_RESERVED41;                //0x0059
    __IO uint32_t                    TDSP_RESERVED42;                //0x005A
    __IO uint32_t                    TDSP_RESERVED43;                //0x005B
    __IO uint32_t                    TDSP_RESERVED44;                //0x005C
    __IO uint32_t                    TDSP_RESERVED45;                //0x005D
    __IO uint32_t                    TDSP_RESERVED46;                //0x005E
    __IO uint32_t                    TDSP_RESERVED47;                //0x005F
    __IO uint32_t                    TDSP_RESERVED48;                //0x0060
    __IO uint32_t                    TDSP_RESERVED49;                //0x0061
    __IO uint32_t                    TDSP_RESERVED50;                //0x0062
    __IO uint32_t                    TDSP_RESERVED51;                //0x0063
    __IO uint32_t                    TDSP_RESERVED52;                //0x0064
    __IO uint32_t                    TDSP_RESERVED53;                //0x0065
    __IO uint32_t                    TDSP_RESERVED54;                //0x0066
    __IO uint32_t                    TDSP_RESERVED55;                //0x0067
    __IO uint32_t                    TDSP_RESERVED56;                //0x0068
    __IO uint32_t                    TDSP_RESERVED57;                //0x0069
    __IO uint32_t                    TDSP_RESERVED58;                //0x006A
    __IO uint32_t                    TDSP_RESERVED59;                //0x006B
    __IO uint32_t                    TDSP_RESERVED60;                //0x006C
    __IO uint32_t                    TDSP_RESERVED61;                //0x006D
    __IO uint32_t                    TDSP_RESERVED62;                //0x006E
    __IO uint32_t                    TDSP_RESERVED63;                //0x006F
    __IO uint32_t                    TDSP_RESERVED64;                //0x0070
    __IO uint32_t                    TDSP_RESERVED65;                //0x0071
    __IO uint32_t                    TDSP_RESERVED66;                //0x0072
    __IO uint32_t                    TDSP_RESERVED67;                //0x0073
    __IO uint32_t                    TDSP_RESERVED68;                //0x0074
    __IO uint32_t                    TDSP_RESERVED69;                //0x0075
    __IO uint32_t                    TDSP_RESERVED70;                //0x0076
    __IO uint32_t                    TDSP_RESERVED71;                //0x0077
    __IO uint32_t                    TDSP_RESERVED72;                //0x0078
    __IO uint32_t                    TDSP_RESERVED73;                //0x0079
    __IO uint32_t                    TDSP_RESERVED74;                //0x007A
    __IO uint32_t                    TDSP_RESERVED75;                //0x007B
    __IO uint32_t                    TDSP_RESERVED76;                //0x007C
    __IO uint32_t                    TDSP_RESERVED77;                //0x007D
    __IO uint32_t                    TDSP_RESERVED78;                //0x007E
    __IO uint32_t                    TDSP_RESERVED79;                //0x007F
    __IO t_TDSP_DMA_XSIZE            TDSP_DMA_XSIZE;                 //0x0080
    __IO t_TDSP_DMA_YSIZE            TDSP_DMA_YSIZE;                 //0x0081
    __IO uint32_t                    TDSP_DMA_ADD;                   //0x0082
} DSP_CONTROL_TypeDef;


#endif /* _DSP_H_ */
