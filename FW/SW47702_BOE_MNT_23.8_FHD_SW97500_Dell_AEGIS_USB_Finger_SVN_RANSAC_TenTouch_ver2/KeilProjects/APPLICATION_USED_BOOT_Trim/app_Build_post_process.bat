
fromelf.exe --bin "bin\MFTP.axf" -o "bin\Binary\APP.bin"

copy "bin\MFTP.axf" "bin\Binary\APP.axf"
copy "bin\MFTP.hex" "bin\Binary\APP.hex"
copy "list\MFTP.map" "bin\Binary\APP.map"

fromelf -c -d -o "bin\Binary\APP.lst" "bin\Binary\APP.axf"

..\tool\arm-none-eabi-objcopy -I elf32-little -O binary "bin\app_info.o" "bin\Binary\APP_INFO.bin"
..\tool\bin_tool.exe -fullsbtotal "bin\Binary\APP_FULLMEM.img" "bin\Binary\TOTAL_FULLMEM.img" "..\ref\BOOT_Trim_702_v01.03.img" "bin\Binary\APP.bin" "..\ref\APP_SIMPLE_BOOT.bin"
