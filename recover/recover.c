#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Open files and determine error
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    //define buffer;
    BYTE buffer[512];
    while (fread(buffer, sizeof(BYTE), 512, file) == BLOCK_SIZE)
    {


    }
    sprintf(filename, "%03i.jpg", 2);
    FILE *img = fopen(filename, "w");
    fwrite(buffer, sizeof(BYTE), 512, filename);
    FILE *img = fclose(filename);
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