#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int t = 0; t < width; t++) 
        {
            float media = (image[i][t].rgbtRed + image[i][t].rgbtGreen + image[i][t].rgbtBlue) / 3.0;
            int resul = round(media);
            image[i][t].rgbtRed = resul;
            image[i][t].rgbtGreen = resul;
            image[i][t].rgbtBlue = resul;
        }
    }
    return;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

//verifying pixel
bool valid_pixel(int i, int t, int height, int width)
{
    return i >= 0 && i < height && t >= 0 && t < width;
}

RGBTRIPLE get_blurred_pixel(int i, int t, int height, int width, RGBTRIPLE image[height][width])
{
    //verifying
    int redValue, blueValue, greenValue;
    redValue = blueValue = greenValue = 0;
    int nvp = 0;
    for (int di = -1; di <= 1; di++)
    {
        for (int dt = -1; dt <= 1; dt++)
        {
            int new_i = i + di;
            int new_t = t + dt;
            if (valid_pixel(new_i, new_t, height, width))
            {
                nvp++;
                redValue += image[new_i][new_t].rgbtRed;
                blueValue += image[new_i][new_t].rgbtBlue;
                greenValue += image[new_i][new_t].rgbtGreen;
            }
        }
    }
    //finishing
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) redValue / nvp);
    blurred_pixel.rgbtBlue = round((float) blueValue / nvp);
    blurred_pixel.rgbtGreen = round((float) greenValue / nvp);
    return blurred_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //transforming
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int t = 0; t < width; t++)
        {
            image2[i][t] = get_blurred_pixel(i, t, height, width, image);
        }
    }
    
    //finish
    for (int i = 0; i < height; i++)
    {
        for (int t = 0; t < width; t++)
        {
            image[i][t] = image2[i][t];
        }
    }
}

//cap
int cap(int value)
{
    //verifying
    return value < 255 ? value : 255;
}

//edge_RGB
RGBTRIPLE edge_RGB(int i, int t, int height, int width, RGBTRIPLE image[height][width])
{
    //variables
    int RedX = 0;
    int BlueX = 0;
    int GreenX = 0;
    int RedY = 0;
    int BlueY = 0;
    int GreenY = 0;
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int pv = 0;
    
    //grade 3x3
    for (int di = -1; di <= 1; di++)
    {
        for (int dt = -1; dt <= 1; dt++)
        {
            if (valid_pixel(i + di, t + dt, height, width))
            {
                //multipling colors
                int Wx = Gx[di + 1][dt + 1];
                RedX += Wx * image[i + di][t + dt].rgbtRed;
                BlueX += Wx * image[i + di][t + dt].rgbtBlue;
                GreenX += Wx * image[i + di][t + dt].rgbtGreen;
               
                int Wy = Gy[di + 1][dt + 1];
                RedY += Wy * image[i + di][t + dt].rgbtRed;
                BlueY += Wy * image[i + di][t + dt].rgbtBlue;
                GreenY += Wy * image[i + di][t + dt].rgbtGreen;
            }
        }
    }
    //finish
    RGBTRIPLE pixel;
    pixel.rgbtRed = cap(round(sqrt(RedX * RedX + RedY * RedY)));
    pixel.rgbtBlue = cap(round(sqrt(BlueX * BlueX + BlueY * BlueY)));
    pixel.rgbtGreen = cap(round(sqrt(GreenX * GreenX + GreenY * GreenY)));
    return pixel;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //transform
    RGBTRIPLE image3[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int t = 0; t < width; t++)
        {
            image3[i][t] = edge_RGB(i, t, height, width, image);
        }
    }
    
    //transfer
    for (int i = 0; i < height; i++)
    {
        for (int t = 0; t < width; t++)
        {
            image[i][t] = image3[i][t];
        }
    }
}
