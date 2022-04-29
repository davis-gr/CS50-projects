#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    //deffine buffer;
    while (fread(buffer, sizeof(BYTE), 512, file) == BLOCK_SIZE)
    {


    }
    sprintf(filename, "%03i.jpg", 2);
    FILE *img = fopen(filename, "w");
}