#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILENAME\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    unsigned char buffer[512];
    FILE *output = NULL;
    int fileCount = 0;

    while (fread(buffer, 512, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (output != NULL)
            {
                fclose(output);
            }

            char fileName[8];
            sprintf(fileName, "%03d.jpg", fileCount);
            output = fopen(fileName, "wb");
            if (output == NULL)
            {
                printf("Error creating file\n");
                return 1;
            }
            fileCount++;
        }
        if (output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);
    return 0;
}