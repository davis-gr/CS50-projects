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
    RGBTRIPLE temparray[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temparray[i][width-1-j].rgbtRed = image[i][j].rgbtRed;
            temparray[i][width-1-j].rgbtGreen = image[i][j].rgbtGreen;
            temparray[i][width-1-j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = temparray[k][l].rgbtRed;
            image[k][l].rgbtGreen = temparray[k][l].rgbtGreen;
            image[k][l].rgbtBlue = temparray[k][l].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temparray[height][width];
    float rBlur, gBlur, bBlur;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i > 0 && j > 0 && i < height - 1 && j < width -1)
            {
                rBlur = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed +
                        image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed +
                        image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9);
                gBlur = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen +
                        image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen +
                        image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9);
                bBlur = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue +
                        image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue +
                        image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9);
                temparray[i][j].rgbtRed = rBlur;
                temparray[i][j].rgbtGreen = gBlur;
                temparray[i][j].rgbtBlue = bBlur;
            }
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = temparray[k][l].rgbtRed;
            image[k][l].rgbtGreen = temparray[k][l].rgbtGreen;
            image[k][l].rgbtBlue = temparray[k][l].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
