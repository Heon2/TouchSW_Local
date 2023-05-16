
fromelf.exe --bin "bin\MFTP.axf" -o "bin\Binary\APP_SIMPLE_BOOT.bin"

copy "bin\MFTP.axf" "bin\Binary\APP_SIMPLE_BOOT.axf"
copy "bin\MFTP.hex" "bin\Binary\APP_SIMPLE_BOOT.hex"
copy "list\MFTP.map" "bin\Binary\APP_SIMPLE_BOOT.map"

fromelf -c -d -o "bin\Binary\APP_SIMPLE_BOOT.lst" "bin\Binary\APP_SIMPLE_BOOT.axf"

copy "bin\Binary\APP_SIMPLE_BOOT.bin" "..\ref\APP_SIMPLE_BOOT.bin"