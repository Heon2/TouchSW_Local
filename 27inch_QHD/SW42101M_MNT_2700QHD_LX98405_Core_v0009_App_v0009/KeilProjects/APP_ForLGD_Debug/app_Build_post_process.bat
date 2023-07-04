
fromelf.exe --bin "bin\MFTP.axf" -o "bin\Binary\APP.bin"

copy "bin\MFTP.axf" "bin\Binary\APP.axf"
copy "bin\MFTP.hex" "bin\Binary\APP.hex"
copy "list\MFTP.map" "bin\Binary\APP.map"

fromelf -c -d -o "bin\Binary\APP.lst" "bin\Binary\APP.axf"

