#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double gValue;
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
    // for every row
    for (int i = 0; i < width; i++)
    {
        // for every column
        for (int j = 0; j < height; j++)
        {
            double rBlur = 0;
            double gBlur = 0;
            double bBlur = 0;
            int counter = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (( i + k >= 0 && i + k < width) && (j + l >= 0 && j + l < height))
                    {
                        rBlur += image[k][l].rgbtRed;
                        gBlur += image[k][l].rgbtGreen;
                        bBlur += image[k][l].rgbtBlue;
                        counter++;
                    }
                }
            }
            temparray[i][j].rgbtRed = round(rBlur / counter);
            temparray[i][j].rgbtGreen = round(gBlur / counter);
            temparray[i][j].rgbtBlue = round(bBlur / counter);
        }
    }
    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            image[m][n].rgbtRed = temparray[m][n].rgbtRed;
            image[m][n].rgbtGreen = temparray[m][n].rgbtGreen;
            image[m][n].rgbtBlue = temparray[m][n].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
