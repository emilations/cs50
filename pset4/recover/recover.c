#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCKSIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover name.raw. \n");
        return 1;
    }
    // Open input file and check if error
    FILE *inputr = fopen(argv[1], "r");
    if (inputr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Buffer to inspect the bits of read data
    BYTE *buffer = malloc(BLOCKSIZE);

    // Filename variable counter and initialize the first 000.jpg file
    char *naming = malloc(8);
    int count = 0;
    sprintf(naming, "%03i.jpg", count);
    FILE *destination = fopen(naming, "w");

    // Check if first 512 bytes starts as a JPEG
    while (fread(buffer, sizeof(BYTE), BLOCKSIZE, inputr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(naming, "%03i.jpg", count);
            if (destination != NULL)
            {
                fclose(destination);
            }

            destination = fopen(naming, "w");
            if (destination == NULL)
            {
                printf("Could not open destination file %s \n", naming);
                return 1;
            }
            fwrite(buffer, sizeof(BYTE), BLOCKSIZE, destination);
            count ++;
        }
        else if (count > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCKSIZE, destination);
        }
    }
    // Close and tidy up all files and pointers
    fclose(inputr);
    fclose(destination);
    free(naming);
    free(buffer);
    return 0;
}