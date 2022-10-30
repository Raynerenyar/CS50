#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float blue = image[h][w].rgbtBlue;
            float green = image[h][w].rgbtGreen;
            float red = image[h][w].rgbtRed;
            float average = round((blue + green + red) / 3);
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;

            // // Get RGBTriple values
            // float blue = image[h][w].rgbtBlue;
            // float green = image[h][w].rgbtGreen;
            // float red = image[h][w].rgbtRed;
            // // Calculate average
            // int average = round((red + blue + green) / 3);
            // // Set all values to average
            // image[h][w].rgbtBlue = image[h][w].rgbtGreen = image[h][w].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE row[height][width];
    for (int h = 0; h < height; h++)
    {
        // store image into row array
        for (int w = 0; w < width; w++)
        {
            row[h][w] = image[h][w];
        }
    }
    for (int h = 0; h < height; h++)
    {
        int index;
        // reversing image
        for (int w = 0; w < width; w++)
        {
            index = width - 1 - w;
            image[h][w] = row[h][index];
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
            float blue = 0;
            float green = 0;
            float red = 0;
            int count = 0;
            // loop around pixel to check if it's outside image
            for (int ver = -1; ver < 2; ver++)
            {
                for (int hor = -1; hor < 2; hor++)
                {
                    // check if pixel is outside min h or max h
                    if (h + ver < 0 || h + ver >= height)
                    {
                        continue;
                    }
                    // check if pixel is outside min w or max w
                    if (w + hor < 0 || w + hor >= width)
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
            // average of colours
            image[h][w].rgbtBlue = round(blue / count);
            image[h][w].rgbtGreen = round(green / count);
            image[h][w].rgbtRed = round(red / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
    // sobel arrays
    int gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int gy[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float Gx_red = 0;
            float Gx_green = 0;
            float Gx_blue = 0;
            float Gy_red = 0;
            float Gy_green = 0;
            float Gy_blue = 0;
            // loop around pixel to check if it's outside image
            for (int ver = -1; ver < 2; ver++)
            {
                for (int hor = -1; hor < 2; hor++)
                {
                    // check if pixel is outside min h or max h
                    if (h + ver < 0 || h + ver >= height)
                    {
                        continue;
                    }
                    // check if pixel is outside min w or max w
                    if (w + hor < 0 || w + hor >= width)
                    {
                        continue;
                    }
                    Gx_red += copy[h + ver][w + hor].rgbtRed * gx[h + ver][w + hor];
                    Gx_blue += copy[h + ver][w + hor].rgbtBlue * gx[h + ver][w + hor];
                    Gx_green += copy[h + ver][w + hor].rgbtGreen * gx[h + ver][w + hor];
                    Gy_red += copy[h + ver][w + hor].rgbtRed * gx[h + ver][w + hor];
                    Gy_blue += copy[h + ver][w + hor].rgbtBlue * gx[h + ver][w + hor];
                    Gy_green += copy[h + ver][w + hor].rgbtGreen * gx[h + ver][w + hor];
                }
            }
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));

            // check for 255 cap
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            image[h][w].rgbtRed = red;
            image[h][w].rgbtBlue = blue;
            image[h][w].rgbtGreen = green;
        }
    }
    return;
}
