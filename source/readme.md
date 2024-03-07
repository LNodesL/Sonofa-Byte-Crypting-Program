# EspanaKrypt Source
Included is the EspanaKrypt.cpp (crypter), Armada.cpp (original stub), Galleon.h (the bytes array header include of compiled Armada.exe).

## EspanaKrypt.cpp
This is the main crypter file that includes the Galleon.h file include and all needed logic to replace a resource for future crypts to replace the program that is executed in runtime.

## Galleon.h
Generated by utils/BTCH as a header file include containing the bytes data for tmp/Armada.exe 

## Armada.cpp
The original stub file that has all logic for executing a binary in runtime. Is used to compile the tmp/Armada.exe for the build process.

## helloworld.cpp
Simple test file to compile into a PE to test the crypter (EspanaKrypt.exe) by dragging & dropping helloworld onto the crypter, or by CLI.

## Forked / Origin Story
EspanaKrypt is a fork of Ricky5Spanish's PE Runtime Crypter. 

Changes made:

- addition of skCrypter for compile time string encryption & runtime decryption
- an easier method to convert the original PE to bytes for inclusion in the crypter (BTCH)

If you are interested in the original code, visit Ricky5Spanish Github below. Note: I have no affiliation with this user.

https://github.com/Ricky5panish/PE-Runtime-Crypter

Most recent commit reference: https://github.com/Ricky5panish/PE-Runtime-Crypter/commit/9f969150f0d87c6df36facb4bbe1dbfe08fdfd52