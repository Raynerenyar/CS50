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
            int count;
            // loop around pixel to check if it's outside image
            for (int ver = -1; ver < 2; ver++)
            {
                for (int hor = -1; hor < 2; hor++)
                {
                    // check if pixel is outside min h or max h
                    if (h + ver < 0 || h + ver > height)
                    {
                        continue;
                    }
                    // check if pixel is outside min w or max w
                    if (w + hor < 0 || w + hor > width)
                    {
                        continue;
                    }
                    // if pixel is not outside, sum them.
                    blue += copy[h + ver][w + hor].rgbtBlue;
                    green += copy[h + ver][w + hor].rgbtGreen;
                    red += copy[h + ver][w + hor].rgbtRed;
                    count++;
                }
            }
            image[h][w].rgbtBlue = blue / count;
            image[h][w].rgbtGreen = green / count;
            image[h][w].rgbtRed = red / count;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
