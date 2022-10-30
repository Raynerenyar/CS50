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
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            BYTE blue;
            BYTE green;
            BYTE red;
            int counter;
            // loop around pixel to check if it's outside image
            for (int ver = -1; ver < 2; ver++)
            {
                for (int hor = -1; hor < 2; hor++)
                {
                    if (h + ver < 0 || h + ver > height)
                    {
                        continue
                    }
                    if (w + hor < 0 || w + hor > width)
                    {
                        continue
                    }
                    blue += image[h + ver][w + hor].rgbtBlue;
                    
                }
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
