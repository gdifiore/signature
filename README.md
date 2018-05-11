# signature

signature - tool to grab sha256 of file or text

## Compiling
### Windows
        gcc src\main.c src\signature.c -o .\signaturetest.exe -I C:\MinGW\include\ -L C:\MinGW\lib\ -lcrypto