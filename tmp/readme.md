# tmp/ folder

The tmp folder holds Egg.exe from the build process before it is converted to bytes header file.

## OPTIONAL: Developers

If you want to package in a default payload, then you may use HxD or a similar program to extract the bytes & size to a C header include file like Hatchling.h

You can also use /utils/BTCH like so:

```
./utils/BTCH.exe ./tmp/Egg.exe /tmp/Egg.h
```
