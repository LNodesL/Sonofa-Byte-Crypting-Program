# SonofaByteCryptingProgram Builder

Folders:

- dist/ contains the final SonofaByteCryptingProgram.exe crypter program, and an example helloworld.exe program
- source/ contains the source of the SonofaByteCryptingProgram (crypter) program, Hatchling (stub) program
- utils/ contains any tools for the builder

Compile source/Egg.cpp to create the original PE.

```
g++ ./source/Egg.cpp -static -o ./tmp/Egg.exe
```

Convert Egg.exe to bytes array C++ header file, for an input file to become a header file for our source.

```
./utils/BTCH.exe ./tmp/Egg.exe ./source/Hatchling.h
```

Compile source/SonofaByteCryptingProgram.cpp

```
g++ ./source/SonofaByteCryptingProgram.cpp -static -o ./dist/SonofaByteCryptingProgram.exe
```

## Optional

You can modify BTCH (Bytes to C++ Header) in utils/source/BTCH.cpp if you want a custom header file in the future.
