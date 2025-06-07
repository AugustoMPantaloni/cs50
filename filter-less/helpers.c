#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++ ){
            int promedio = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = promedio;
            image[i][j].rgbtGreen = promedio;
            image[i][j].rgbtRed = promedio;
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

            int sepiaRed =(int)(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen =(int)(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue =(int)(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

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
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
        {
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    
                }
                
            }
            
        }
        
    }
    return;
}
