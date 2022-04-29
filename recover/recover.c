#include <stdio.h>
#include <stdlib.h>

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

    BYTE buffer[];
    char* filename = "000.jpg";
    int counter = 0;
    int BLOCK_SIZE = 512;
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        for (int i = 0; i < buffer; i++)
        {
            //check if start of 1st JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                FILE *img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, filename);
            }
        }
    }
    sprintf(filename, "%03i.jpg", 2);


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