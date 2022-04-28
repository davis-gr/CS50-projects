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
            // 2 loops for catching the nearby pixels of every pixel
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // if statement checking if nearby pixels are not beyond the edges of the picture
                    if (( i + k >= 0 && i + k < width) && (j + l >= 0 && j + l < height))
                    {
                        // adding RGB values to variables and counter for every addition
                        rBlur += image[l+j][i+k].rgbtRed;
                        gBlur += image[l+j][i+k].rgbtGreen;
                        bBlur += image[l+j][i+k].rgbtBlue;
                        counter++;
                    }
                }
            }
            // calculating blurred pixel values and storing them in temp pixel array
            temparray[j][i].rgbtRed = round(rBlur / counter);
            temparray[j][i].rgbtGreen = round(gBlur / counter);
            temparray[j][i].rgbtBlue = round(bBlur / counter);
        }
    }
    // swapping temp image array to the real one
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
    RGBTRIPLE temparray[height][width];
    // for every row
    for (int i = 0; i < width; i++)
    {
        // for every column
        for (int j = 0; j < height; j++)
        {
            double xRed = 0;
            double xGreen = 0;
            double xBlue = 0;
            double yRed = 0;
            double yGreen = 0;
            double yBlue = 0;
            // 2 loops for catching the nearby pixels of every pixel
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // if statement checking if nearby pixels are not beyond the edges of the picture
                    if (( i + k >= 0 && i + k < width) && (j + l >= 0 && j + l < height))
                    {
                        // left top
                        if (k == -1 && l == -1)
                        {
                        xRed += image[l+j][i+k].rgbtRed * -1;
                        xGreen += image[l+j][i+k].rgbtGreen * -1;
                        xBlue += image[l+j][i+k].rgbtBlue * -1;
                        yRed += xRed;
                        yGreen += xGreen;
                        yBlue += xBlue;
                        }
                        // left middle
                        else if (k == -1 && l == 0)
                        {
                        xRed = image[l+j][i+k].rgbtRed * -2;
                        xGreen = image[l+j][i+k].rgbtGreen * -2;
                        xBlue = image[l+j][i+k].rgbtBlue * -2;
                        }
                        // left bottom
                        else if (k == -1 && l == 1)
                        {
                        xRed = image[l+j][i+k].rgbtRed * -1;
                        xGreen = image[l+j][i+k].rgbtGreen * -1;
                        xBlue = image[l+j][i+k].rgbtBlue * -1;
                        yRed = image[l+j][i+k].rgbtRed;
                        yGreen = image[l+j][i+k].rgbtGreen;
                        yBlue = image[l+j][i+k].rgbtBlue;
                        }
                        // middle top
                        else if (k == 0 && l == -1)
                        {
                        yRed = image[l+j][i+k].rgbtRed * -2;
                        yGreen = image[l+j][i+k].rgbtGreen * -2;
                        yBlue = image[l+j][i+k].rgbtBlue * -2;
                        }
                        // middle bottom
                        else if (k == 0 && l == 1)
                        {
                        yRed = image[l+j][i+k].rgbtRed * 2;
                        yGreen = image[l+j][i+k].rgbtGreen * 2;
                        yBlue = image[l+j][i+k].rgbtBlue * 2;
                        }
                        // right top
                        else if (k == 1 && l == -1)
                        {
                        xRed = image[l+j][i+k].rgbtRed;
                        xGreen = image[l+j][i+k].rgbtGreen;
                        xBlue = image[l+j][i+k].rgbtBlue;
                        yRed = image[l+j][i+k].rgbtRed * -1;
                        yGreen = image[l+j][i+k].rgbtGreen * -1;
                        yBlue = image[l+j][i+k].rgbtBlue * -1;
                        }
                        // right middle
                        else if (k == 1 && l == 0)
                        {
                        xRed = image[l+j][i+k].rgbtRed * 2;
                        xGreen = image[l+j][i+k].rgbtGreen * 2;
                        xBlue = image[l+j][i+k].rgbtBlue * 2;
                        }
                        // right bottom
                        else if (k == 1 && l == 1)
                        {
                        xRed = image[l+j][i+k].rgbtRed;
                        xGreen = image[l+j][i+k].rgbtGreen;
                        xBlue = image[l+j][i+k].rgbtBlue;
                        yRed = xRed;
                        yGreen = xGreen;
                        yBlue = xBlue;
                        }
                    }
                }
            }
            // calculating blurred pixel values and storing them in temp pixel array
            temparray[j][i].rgbtRed = round(rBlur / counter);
            temparray[j][i].rgbtGreen = round(gBlur / counter);
            temparray[j][i].rgbtBlue = round(bBlur / counter);
        }
    }
    // swapping temp image array to the real one
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
