#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
           float n = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
           image[i][j].rgbtRed = n;
           image[i][j].rgbtGreen = n;
           image[i][j].rgbtBlue = n;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
    int  rgbtRed;
    int  rgbtGreen;
    int  rgbtBlue;
    }
    image1;

    image1 image2[height][width];

    for(int i=0; i< height; i++)
    {
        for(int j=0; j< width; j++)
        {
           image2[i][j].rgbtRed = image[i][j].rgbtRed;
           image2[i][j].rgbtGreen = image[i][j].rgbtGreen;
           image2[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for(int i=0; i< height; i++)
    {
        for(int j=0; j< width; j++)
        {
           image[i][j].rgbtRed = image2[i][(width-1)-j].rgbtRed;
           image[i][j].rgbtGreen = image2[i][(width-1)-j].rgbtGreen;
           image[i][j].rgbtBlue = image2[i][(width-1)-j].rgbtBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i< height; i++)
    {
        for(int j=0; j< width; j++)
        {
           if(i!=0 && j!=0 && i!=(height-1) && j!=(width-1))
           {
               float pr1 = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/9);
               image[i][j].rgbtRed= pr1;
               float pg1 = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/9);
               image[i][j].rgbtGreen= pg1;
               float pb1 = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/9);
               image[i][j].rgbtBlue= pb1;
           }
           if(i==0 && j==0)
           {
               float pr2 = round((image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/4);
               image[i][j].rgbtRed= pr2;
               float pg2 = round((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/4);
               image[i][j].rgbtGreen= pg2;
               float pb2 = round((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/4);
               image[i][j].rgbtBlue= pb2;
           }
           if(i==0 && j==(width-1))
           {
               float pr3 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed)/4);
               image[i][j].rgbtRed= pr3;
               float pg3 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen)/4);
               image[i][j].rgbtGreen= pg3;
               float pb3 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue)/4);
               image[i][j].rgbtBlue= pb3;
           }
           if(i==(height-1) && j==0)
           {
               float pr4 = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed)/4);
               image[i][j].rgbtRed= pr4;
               float pg4 = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen)/4);
               image[i][j].rgbtGreen= pg4;
               float pb4 = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue)/4);
               image[i][j].rgbtBlue= pb4;
           }
           if(i==(height-1) && j==(width-1))
           {
               float pr5 = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i][j-1].rgbtRed)/4);
               image[i][j].rgbtRed= pr5;
               float pg5 = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i][j-1].rgbtGreen)/4);
               image[i][j].rgbtGreen= pg5;
               float pb5 = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i][j-1].rgbtBlue)/4);
               image[i][j].rgbtBlue= pb5;
           }
           if(i==0 && j!=0 && j!=(width-1))
           {
               float pr6 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/6);
               image[i][j].rgbtRed= pr6;
               float pg6 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
               image[i][j].rgbtGreen= pg6;
               float pb6 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/6);
               image[i][j].rgbtBlue= pb6;
           }
           if(i==(height-1) && j!=0 && j!=(width-1))
           {
               float pr7 = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/6);
               image[i][j].rgbtRed= pr7;
               float pg7 = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/6);
               image[i][j].rgbtGreen= pg7;
               float pb7 = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/6);
               image[i][j].rgbtBlue= pb7;
           }
           if(j==0 && i!=0 && i!=(height-1))
           {
               float pr8 = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed)/6);
               image[i][j].rgbtRed= pr8;
               float pg8 = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
               image[i][j].rgbtGreen= pg8;
               float pb8 = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue)/6);
               image[i][j].rgbtBlue= pb8;
           }
           if(j==(width-1) && i!=0 && i!=(height-1))
           {
               float pr9 = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed)/6);
               image[i][j].rgbtRed= pr9;
               float pg9 = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen)/6);
               image[i][j].rgbtGreen= pg9;
               float pb9 = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue)/6);
               image[i][j].rgbtBlue= pb9;
           }
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
          if(i!=0 && j!=0 && i!=(height-1) && j!=(width-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*1 + image[i][j-1].rgbtRed*-2 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*2 + image[i+1][j-1].rgbtRed*-1 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*1);
               int gyr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*-2 + image[i-1][j+1].rgbtRed*-1 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*1 + image[i+1][j].rgbtRed*2 + image[i+1][j+1].rgbtRed*1);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*1 + image[i][j-1].rgbtGreen*-2 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*2 + image[i+1][j-1].rgbtGreen*-1 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*1);
               int gyg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*-2 + image[i-1][j+1].rgbtGreen*-1 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*1 + image[i+1][j].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*1);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*1 + image[i][j-1].rgbtBlue*-2 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*2 + image[i+1][j-1].rgbtBlue*-1 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*1);
               int gyb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*-2 + image[i-1][j+1].rgbtBlue*-1 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*1 + image[i+1][j].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*1);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(i==0 && j==0)
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*2 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*1);
               int gyr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*2 + image[i+1][j+1].rgbtRed*1);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*2 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*1);
               int gyg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*1);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*2 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*1);
               int gyb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*1);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(i==0 && j==(width-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*-2 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*-1 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               int gyr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*1 + image[i+1][j].rgbtRed*2 + image[i+1][j+1].rgbtRed*0);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*2 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*-1 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               int gyg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*1 + image[i+1][j].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*0);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*2 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*-1 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               int gyb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*1 + image[i+1][j].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*0);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(i==(height-1) && j==0)
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*1 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*2 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               int gyr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*-2 + image[i-1][j+1].rgbtRed*-1 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*1 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*2 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               int gyg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*2 + image[i-1][j+1].rgbtGreen*-1 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*1 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*2 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               int gyb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*2 + image[i-1][j+1].rgbtBlue*-1 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(i==(height-1) && j==(width-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*-2 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               int gyr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*-2 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*2 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               int gyg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*-2 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*2 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               int gyb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*-2 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(i==0 && j!=0 && j!=(width-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*1 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*2 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*1);
               int gyr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*-2 + image[i-1][j+1].rgbtRed*-1 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*2 + image[i+1][j+1].rgbtRed*1);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*1 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*2 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*1);
               int gyg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*-2 + image[i-1][j+1].rgbtGreen*-1 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*1);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*1 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*2 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*1);
               int gyb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*-2 + image[i-1][j+1].rgbtBlue*-1 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*1);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(i==(height-1) && j!=0 && j!=(width-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*1 + image[i][j-1].rgbtRed*-2 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*2 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               int gyr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*-2 + image[i-1][j+1].rgbtRed*-1 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*0 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*1 + image[i][j-1].rgbtGreen*2 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*2 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               int gyg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*-2 + image[i-1][j+1].rgbtGreen*-1 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*0 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*1 + image[i][j-1].rgbtBlue*2 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*2 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               int gyb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*-2 + image[i-1][j+1].rgbtBlue*-1 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*0 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(j==0 && i!=0 && i!=(height-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*-2 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*2 + image[i+1][j-1].rgbtRed*-1 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*1);
               int gyr1 = (image[i-1][j-1].rgbtRed*0 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*1 + image[i+1][j].rgbtRed*2 + image[i+1][j+1].rgbtRed*1);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*2 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*2 + image[i+1][j-1].rgbtGreen*-1 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*1);
               int gyg1 = (image[i-1][j-1].rgbtGreen*0 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*1 + image[i+1][j].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*1);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*2 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*2 + image[i+1][j-1].rgbtBlue*-1 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*1);
               int gyb1 = (image[i-1][j-1].rgbtBlue*0 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*1 + image[i+1][j].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*1);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
           if(j==(width-1) && i!=0 && i!=(height-1))
           {
               int gxr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*0 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*-2 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*-1 + image[i+1][j].rgbtRed*0 + image[i+1][j+1].rgbtRed*0);
               int gyr1 = (image[i-1][j-1].rgbtRed*-1 + image[i-1][j].rgbtRed*2 + image[i-1][j+1].rgbtRed*0 + image[i][j-1].rgbtRed*0 + image[i][j].rgbtRed*0 + image[i][j+1].rgbtRed*0 + image[i+1][j-1].rgbtRed*1 + image[i+1][j].rgbtRed*2 + image[i+1][j+1].rgbtRed*0);
               float nr1 = round(sqrtf(gxr1*gxr1 + gyr1*gyr1));
               image[i][j].rgbtRed= nr1;
               int gxg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*0 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*2 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*-1 + image[i+1][j].rgbtGreen*0 + image[i+1][j+1].rgbtGreen*0);
               int gyg1 = (image[i-1][j-1].rgbtGreen*-1 + image[i-1][j].rgbtGreen*2 + image[i-1][j+1].rgbtGreen*0 + image[i][j-1].rgbtGreen*0 + image[i][j].rgbtGreen*0 + image[i][j+1].rgbtGreen*0 + image[i+1][j-1].rgbtGreen*1 + image[i+1][j].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*0);
               float ng1 = round(sqrtf(gxg1*gxg1 + gyg1*gyg1));
               image[i][j].rgbtGreen= ng1;
               int gxb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*0 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*2 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*-1 + image[i+1][j].rgbtBlue*0 + image[i+1][j+1].rgbtBlue*0);
               int gyb1 = (image[i-1][j-1].rgbtBlue*-1 + image[i-1][j].rgbtBlue*2 + image[i-1][j+1].rgbtBlue*0 + image[i][j-1].rgbtBlue*0 + image[i][j].rgbtBlue*0 + image[i][j+1].rgbtBlue*0 + image[i+1][j-1].rgbtBlue*1 + image[i+1][j].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*0);
               float nb1 = round(sqrtf(gxb1*gxb1 + gyb1*gyb1));
               image[i][j].rgbtBlue= nb1;
           }
        }
    }

    return;
}
