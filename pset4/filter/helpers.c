#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Calculate the average colour for each pixel and then write it on the image pointer
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Avg = round(((double) image[i][j].rgbtBlue + (double) image[i][j].rgbtGreen + (double) image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = Avg;
            image[i][j].rgbtGreen = Avg;
            image[i][j].rgbtRed = Avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Create temporary variables
            double tempB = image[i][j].rgbtBlue;
            double tempG = image[i][j].rgbtGreen;
            double tempR = image[i][j].rgbtRed;

            double varB = round((0.272 * tempR) + (0.534 * tempG) + (0.131 * tempB));
            double varG = round((0.349 * tempR) + (0.686 * tempG) + (0.168 * tempB));
            double varR = round((0.393 * tempR) + (0.769 * tempG) + (0.189 * tempB));

            // Conditions to limit overflow of variable above 255
            if (varB > 255)
            {
                varB = 255;
            }
            if (varG > 255)
            {
                varG = 255;
            }
            if (varR > 255)
            {
                varR = 255;
            }

            // write the new data to the image
            image[i][j].rgbtBlue = varB;
            image[i][j].rgbtGreen = varG;
            image[i][j].rgbtRed = varR;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create temporary variable
    RGBTRIPLE imageT[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageT[i][j] = image[i][j];
        }
    }
    // reflect the image on the vertical axis
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageT[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Initialise two temporary image buffers
    RGBTRIPLE imageT[height][width];
    RGBTRIPLE imageT2[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageT[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            double avgB = 0, avgG = 0, avgR = 0;
            // x is for height and y is for width
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if ((i + x < 0) || (i + x > (height - 1)))
                    {
                        continue;
                    }
                    if ((j + y < 0) || (j + y > (width - 1)))
                    {
                        continue;
                    }
                    counter++;
                    avgB += imageT[(i + x)][(j + y)].rgbtBlue;
                    avgG += imageT[(i + x)][(j + y)].rgbtGreen;
                    avgR += imageT[(i + x)][(j + y)].rgbtRed;
                }
            }
            imageT2[i][j].rgbtBlue = round(avgB / counter);
            imageT2[i][j].rgbtGreen = round(avgG / counter);
            imageT2[i][j].rgbtRed = round(avgR / counter);
        }
    }

    // writes the blurred image data to the image variable
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageT2[i][j];
        }
    }

    return;
}