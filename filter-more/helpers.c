#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gValue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gValue = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = gValue;
            image[i][j].rgbtGreen = gValue;
            image[i][j].rgbtBlue = gValue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int rValue, gValue, bValue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][width-j-1].rgbtRed = image[i][j].rgbtRed;
            image[i][width-j-1].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width-j-1].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
