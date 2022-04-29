#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Open files and determine error
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    // this a bit stupid, but you have to define empty array and initialize it with sprintf
    char filename[8];
    int counter = 0;
    sprintf(filename, "%03i.jpg", counter);
    FILE *img = fopen(filename, "w");
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        //check if start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if 1st JPEG
            if (counter == 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
                counter++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                counter++;
            }
        }
        // this check is needed because before first IMG there's a bunch of garbage in the raw file
        else if (counter != 0)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    fclose(img);
}
