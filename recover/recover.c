#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    int buffer[BLOCK_SIZE];
    char* filename = "000.jpg";
    int counter = 0;
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
        else
        {
            if ()
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    fclose(img);
}


// open memory card
// repeat until end of card:
    //read 512 bytes in buffer
    // If start of new JPEG
        // If first JPEG
        //...
        // Else
        //...
    //Else
        // If already found JPEG
        //...
//Close any remaining files