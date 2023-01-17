#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;

    // USE FOR LOOP TO ACCESS EACH PIXEL COLOR
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // getting the avaerage value of RGB (EACH BYTE >> 3 BYTES)
            int temp = round(((float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)) / 3);

            // ASSIGNING THE AVAERAGE VALUE TO EACH PIXEL'S COLOR
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtBlue = temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // CONVERTING EACH PIXEL TO FLOATING VALUE FOR FURTHER CALCULATION
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;

            int TR, TG, TB;

            // AFTER CALCULATION, ROUNDING THE EACH PIXEL'S VALUE FOR THE CORRECT OUTPUT
            TR = round(0.393 * R + 0.769 * G + 0.189 * B);
            TG = round(0.349 * R + 0.686 * G + 0.168 * B);
            TB = round(0.272 * R + 0.534 * G + 0.131 * B);

            // CHECK IF THE EACH PIXEL'S OUTPUT EXCEED 255
            if (TR > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = TR;
            }

            if (TG > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = TG;
            }

            if (TB > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = TB;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < (width / 2); j++)
        {
            // SETTING EACH PIXEL TO BE INTEGER VARIABLE
            int temp_r, temp_g, temp_b;

            // swap PIXEL'S ELEMENT ONE BY ONE >> ROW UNCHANGE
            //  THE FIRST AND THE LAST ROW
            //  THE 2ND AND THE 2ND LAST ELEMENT OF THE ROW
            temp_r = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = temp_r;

            temp_g = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = temp_g;

            temp_b = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = temp_b;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;

    // CREATING A DUPLIACTE OF ARRAY RGBTRIPLE FOR FURTHER VALUE CHANGE BEFORE OVERWRITE THE EXISTING RGBTRIPLE ARRAY
    RGBTRIPLE copy[height][width];

    // BLURRING PIXEL REQUIRE TO AVERAGE THE PIXEL AND ITS SERROUNDED 8 PIXEL
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            float n = 1;

            // CHECK IF THE PREVIOUS/NEXT ROW AND ELEMENT OF THE ROW EXIST WITHIN THE IMAGE FILE'S BOUNDARY
            // EACH PIXEL'S CALCULATION IS DEFFER >> THE INCLUDED PIXEL'S COLOUR ELEMENT BASE ON EACH CONDITION
            // CHECKING THE PREVIOUS ROW
            if (i == 0)
            {
                // CHECKING THE PREVIOUS ELEMENT (PREVIOUS ROW)
                if (j == 0)
                {
                    copy[i][j].rgbtRed = round(((float)(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j +
                                                        1].rgbtRed)) / 4);
                    copy[i][j].rgbtGreen = round(((float)(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j
                                                          + 1].rgbtGreen)) / 4);
                    copy[i][j].rgbtBlue = round(((float)(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j +
                                                         1].rgbtBlue)) / 4);
                }
                // CHECKING THE NEXT ELEMENT (PREVIOUS ROW)
                else if (j == (width - 1))
                {
                    copy[i][j].rgbtRed = round(((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i +
                                                        1][j].rgbtRed)) / 4);
                    copy[i][j].rgbtGreen = round(((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i +
                                                          1][j].rgbtGreen)) / 4);
                    copy[i][j].rgbtBlue = round(((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i +
                                                         1][j].rgbtBlue)) / 4);
                }
                // INCLUDE ALL 9 PIXEL WHEN NO PIXEL IS EXCLUDED (NEXT ROW)
                else
                {
                    copy[i][j].rgbtRed = round(((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                                        image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)) / 6);
                    copy[i][j].rgbtGreen = round(((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                                          image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)) / 6);
                    copy[i][j].rgbtBlue = round(((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                                         image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) / 6);
                }
            }
            // CHECKING THE NEXT ROW
            else if (i == (height - 1))
            {
                // CHECKING THE PREVIOUS ELEMENT (NEXT ROW)
                if (j == 0)
                {
                    copy[i][j].rgbtRed = round(((float)(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j +
                                                        1].rgbtRed)) / 4);
                    copy[i][j].rgbtGreen = round(((float)(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i -
                                                          1][j + 1].rgbtGreen)) / 4);
                    copy[i][j].rgbtBlue = round(((float)(image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j
                                                         + 1].rgbtBlue)) / 4);
                }
                // CHECKING THE NEXT ELEMENT (NEXT ROW)
                else if (j == (width - 1))
                {
                    copy[i][j].rgbtRed = round(((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i -
                                                        1][j].rgbtRed)) / 4);
                    copy[i][j].rgbtGreen = round(((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i
                                                          - 1][j].rgbtGreen)) / 4);
                    copy[i][j].rgbtBlue = round(((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i -
                                                         1][j].rgbtBlue)) / 4);
                }
                // INCLUDE ALL 9 PIXEL WHEN NO PIXEL IS EXCLUDED (NEXT ROW)
                else
                {
                    copy[i][j].rgbtRed = round(((float)(image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                                        image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed)) / 6);
                    copy[i][j].rgbtGreen = round(((float)(image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                                          image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen)) / 6);
                    copy[i][j].rgbtBlue = round(((float)(image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue +
                                                         image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue)) / 6);
                }
            }
            // WHEN THE PREVIOUS AND NEXT ROW IS NOT EXCLUDED
            else
            {
                // CHECKING THE PREVIOUS ELEMENT (MIDDLE PART - 2ND - LAST 2ND ROW)
                if (j == 0)
                {
                    copy[i][j].rgbtRed = round(((float)(image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed +
                                                        image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)) / 6);

                    copy[i][j].rgbtGreen = round(((float)(image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen +
                                                          image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)) / 6);

                    copy[i][j].rgbtBlue = round(((float)(image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue +
                                                         image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) / 6);
                }
                // CHECKING THE NEXT ELEMENT (MIDDLE PART - 2ND - LAST 2ND ROW)
                else if (j == (width - 1))
                {
                    copy[i][j].rgbtRed = round(((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed +
                                                        image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed)) / 6);
                    copy[i][j].rgbtGreen = round(((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen +
                                                          image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen)) / 6);
                    copy[i][j].rgbtBlue = round(((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue +
                                                         image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue)) / 6);
                }
                // INCLUDE ALL 9 PIXEL WHEN NO PIXEL IS EXCLUDE
                else
                {
                    copy[i][j].rgbtRed = round(((float)(image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                                        image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                                        image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed)) / 9);
                    copy[i][j].rgbtGreen = round(((float)(image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                                          image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                                          image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen)) / 9);
                    copy[i][j].rgbtBlue = round(((float)(image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                                         image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                                         image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue)) / 9);
                }
            }
        }
    }

    // OVERWRITEN CHANGE OF THE DUPLICATE ARRAY RGBTRIPLE TO THE ORIGINAL ARRAY
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
