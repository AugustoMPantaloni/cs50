#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++ ){
            float promedio = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            int valorRedondeado = (int) round(promedio);
            image[i][j].rgbtBlue = valorRedondeado;
            image[i][j].rgbtGreen = valorRedondeado;
            image[i][j].rgbtRed = valorRedondeado;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;

            int sepiaRed =(int) round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen =(int) round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue =(int) round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2 ; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy [i][j] = image[i][j];
        }
        
    }
    

    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
        {
            int additionRed = 0;
            int additionGreen = 0;
            int additionBlue = 0;
            int counter = 0;
            for (int di = i - 1; di <= i + 1; di++)
            {
                for (int dj = j - 1; dj <= j + 1; dj++)
                {
                    if(di >= 0 && di < height && dj >= 0 && dj < width){
                        counter ++;
                        additionRed += copy[di][dj].rgbtRed;
                        additionBlue += copy[di][dj].rgbtBlue;
                        additionGreen += copy[di][dj].rgbtGreen;
                    }
                }  
            }
            int newRed = (int) round((float) additionRed / counter);
            int newGreen =(int) round((float) additionGreen /counter);
            int newBlue =(int) round((float)additionBlue / counter);
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue =  newBlue;  
        }
    }
    return;
}
