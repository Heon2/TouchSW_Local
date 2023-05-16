
fromelf.exe --bin "bin\MFTP.axf" -o "bin\Binary\APP.bin"

copy "bin\MFTP.axf" "bin\Binary\APP.axf"
copy "bin\MFTP.hex" "bin\Binary\APP.hex"
copy "list\MFTP.map" "bin\Binary\APP.map"

fromelf -c -d -o "bin\Binary\APP.lst" "bin\Binary\APP.axf"

..\tool\arm-none-eabi-objcopy -I elf32-little -O binary "..\APPLICATION_CONFIG\bin\custom_config_fixed.o" "..\APPLICATION_CONFIG\bin\Binary\CONFIG.bin"
..\tool\arm-none-eabi-objcopy -I elf32-little -O binary "..\APPLICATION_CONFIG\bin\app_info.o" "..\APPLICATION_CONFIG\bin\Binary\APP_INFO.bin"
..\tool\bin_tool.exe -fulltotal "..\APPLICATION_CONFIG\bin\Binary\APP_FULLMEM.img" "..\APPLICATION_CONFIG\bin\Binary\TOTAL_FULLMEM.img" "..\ref\BOOT.img" "..\APPLICATION_CONFIG\bin\Binary\APP.bin" "..\APPLICATION_CONFIG\bin\Binary\CONFIG.bin"


