#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

int toIntValue(char hexIdentifier)
{
    switch (hexIdentifier)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    case 'a':
        return 10;
        break;
    case 'b':
        return 11;
        break;
    case 'c':
        return 12;
        break;
    case 'd':
        return 13;
        break;
    case 'e':
        return 14;
        break;
    case 'f':
        return 15;
        break;
    default:
        fprintf(stderr, "Invalid hex identifier: %c\n", hexIdentifier);
        exit(0);
    }
}

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 3)
    {
        fprintf(stderr, "Usage: %s <hexstring> [i]\n", argv[0]);
        return 0;
    }

    char* bytes = argv[1];

    size_t bytesLen = strlen(bytes);
    if (bytesLen % 2 != 0)
    {
        fprintf(stderr, "Invalid hex string: incomplete byte: %c\n", bytes[bytesLen-1]);
        return 0;
    }

    // Decimal representation
    uint64_t totalValueDec = 0;
    for (int i = 0; i < bytesLen; i++)
    {
        char hexVal = bytes[bytesLen - i - 1];
        int value = toIntValue(hexVal);
        uint64_t adjustedValue = value * pow(16, i);
        // printf("Identifier %d: %c = %d\n", i, hexVal, adjustedValue);
        totalValueDec += adjustedValue;
    }

    // Char representation
    char reprDecoded[bytesLen / 2 + 1];
    for (int i = 0; i < bytesLen; i += 2)
    {
        int lower = bytes[i+1];
        int higher = bytes[i];
        reprDecoded[i/2] = toIntValue(higher) * 16 + toIntValue(lower);
    }
    reprDecoded[bytesLen / 2] = '\0';

    if (argc == 2)
    {
        printf("Representations of 0x%s\n", bytes);
        printf("Dec: %llu\n", totalValueDec);
        printf("Txt: %s\n", reprDecoded);
    }
    else if (!strcmp(argv[2], "i"))
    {
        printf("%s", reprDecoded);
    }
    else
    {
        fprintf(stderr, "Invalid flag: %s\n", argv[2]);
        exit(0);
    }
}