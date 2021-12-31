#include "helpers.h"
#include <math.h>
#include <limits.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbgray;

    for (int i = 0; i < width; i++)
    {
        for (int g = 0; g < height; g++)
        {
            rgbgray = round((image[g][i].rgbtBlue + image[g][i].rgbtGreen + image[g][i].rgbtRed) / 3.0);

            image[g][i].rgbtBlue = rgbgray;
            image[g][i].rgbtGreen = rgbgray;
            image[g][i].rgbtRed = rgbgray;
        }
    }
}
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue;
    int sepiaRed;
    int sepiaGreen;
    for (int i = 0; i < width; i++)
    {
        for (int g = 0; g < height; g++)
        {
            sepiaBlue = limit(round(0.272 * image[g][i].rgbtRed + 0.534 * image[g][i].rgbtGreen + 0.131 * image[g][i].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[g][i].rgbtRed + 0.686 * image[g][i].rgbtGreen + 0.168 * image[g][i].rgbtBlue));
            sepiaRed = limit(round(0.393 * image[g][i].rgbtRed + 0.769 * image[g][i].rgbtGreen + 0.189 * image[g][i].rgbtBlue));

            image[g][i].rgbtBlue = sepiaBlue;
            image[g][i].rgbtGreen = sepiaGreen;
            image[g][i].rgbtRed = sepiaRed;
        }
    }
}
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int colr[3];
    for (int g = 0; g < height; g++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            colr[0] = image[g][i].rgbtBlue;
            colr[1] = image[g][i].rgbtGreen;
            colr[2] = image[g][i].rgbtRed;
            image[g][i].rgbtBlue = image[g][width - i - 1].rgbtBlue;
            image[g][i].rgbtGreen = image[g][width - i - 1].rgbtGreen;
            image[g][i].rgbtRed = image[g][width - i - 1].rgbtRed;

            image[g][width - i - 1].rgbtBlue = colr[0];
            image[g][width - i - 1].rgbtGreen = colr[1];
            image[g][width - i - 1].rgbtRed = colr[2];
        }
    }
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumofblue;
    int sumofgreen;
    int sumofred;
    float counter;
    RGBTRIPLE colr[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int g = 0; g < height; g++)
        {
            sumofblue = 0;
            sumofgreen = 0;
            sumofred = 0;
            counter = 0;
            for (int c = -1; c < 2; c++)
            {
                if (g + c < 0 || g + c > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumofblue += image[g + c][i + h].rgbtBlue;
                    sumofgreen += image[g + c][i + h].rgbtGreen;
                    sumofred += image[g + c][i + h].rgbtRed;
                    counter++;
                }
            }
            colr[g][i].rgbtBlue = round(sumofblue / counter);
            colr[g][i].rgbtGreen = round(sumofgreen / counter);
            colr[g][i].rgbtRed = round(sumofred / counter);
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int g = 0; g < height; g++)
        {
            image[g][i].rgbtBlue = colr[g][i].rgbtBlue;
            image[g][i].rgbtGreen = colr[g][i].rgbtGreen;
            image[g][i].rgbtRed = colr[g][i].rgbtRed;
        }
    }
}