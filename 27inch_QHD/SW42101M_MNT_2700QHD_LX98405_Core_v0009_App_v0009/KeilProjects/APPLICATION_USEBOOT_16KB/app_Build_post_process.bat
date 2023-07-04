
C:\Keil_v5\ARM\ARMCC\bin\fromelf.exe --bin "bin\MFTP.axf" -o "bin\Binary\APP.bin"

copy "bin\MFTP.axf" "bin\Binary\APP.axf"
copy "bin\MFTP.hex" "bin\Binary\APP.hex"
copy "list\MFTP.map" "bin\Binary\APP.map"

fromelf -c -d -o "bin\Binary\APP.lst" "bin\Binary\APP.axf"

..\tool\Bin_Tool_Firmware_Boot_16KB.exe "..\APPLICATION_USEBOOT_16KB\bin\Binary\APP.bin" "..\APPLICATION_USEBOOT_16KB\bin\Binary\SW42101_VBS_140FHD_APP_vxx.xx.img"

copy /b "..\tool\ECC_BOOT_x_xx.img" + "..\APPLICATION_USEBOOT_16KB\bin\Binary\SW42101_VBS_140FHD_APP_vxx.xx.img" "..\APPLICATION_USEBOOT_16KB\bin\Binary\SW42101_VBS_140FHD_TOTAL_vxx.xx.img"