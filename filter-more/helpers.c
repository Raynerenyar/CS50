#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            BYTE blue = image[h][w].rgbtBlue;
            BYTE green = image[h][w].rgbtGreen;
            BYTE red = image[h][w].rgbtRed;
            BYTE average = (blue + green + red) / 3;
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        // store image into row array
        RGBTRIPLE row[width];
        for (int w = 0; w < width; w++)
        {
            row[w] = image[h][w];
        }
        int index;
        // reversing image
        for (int r = width; r > 0; r--)
        {
            index = abs(r - width);
            image[h][index] = row[r];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // store image into copy array
    RGBTRIPLE copy[height];
    for (int h = 0; h < height; h++)
    {
        RGBTRIPLE row[width];
        RGBTRIPLE test[width];
        for (int w = 0; w < width; w++)
        {
            row[w] = image[h][w];
        }
        copy[h] = row[width];
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // calc corners
            if ((h == 0 || h == height) && (w == 0 || w == width))
            {
                // top left corner
                if (h == 0 %% w == 0)
                {
                    copy[h][w].rgbtBlue + copy[h+1][w].rgbtBlue + copy[h][w+1].rgbtBlue;
                }
            }

            // calc top and bottom edges

            // calc left and right edges
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
