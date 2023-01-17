#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // checking input keyword no.
    if (argc != 2)
    {
        printf("Only input one command-line argument");
        return 1;
    }

    // open the input file and checking if there is containing info.
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("%s cannot open for read.\n", argv[1]);
        return 2;
    }

    // buffer MUST BE BYTE to store a byte of data >> as jpeg is stored with BYTE data
    uint8_t str[512];

    // counting image file no.
    int count = 0;

    // initialising an image pointer for storing
    // this could be editing later >> such as rename it
    // the file pointer (DESTINATION FILE FOR WRITE) could be NULL
    FILE *img_pointer = NULL;

    // declaring the length of file's name >>
    // since we know that the namefile will consist of 8 char
    char filename[8];
    // int fr = 0;

    // WHILE loop >> RUNNING until fread stop (return smaller element that 512 at a time)
    // for loop is not neccessary when dont know how many int i will have to run
    while (fread(&str, 512, sizeof(uint8_t), infile) == sizeof(uint8_t))
    {
        // printf("fread %i started\n", fr); ->> for taracking fread's time
        // fr++;

        // checking if the header byte of each 512 byte block start with these significant value >> to identify that the block contain jpeg file
        if ((str[0] == 0xff) && (str[1] == 0xd8) && (str[2] == 0xff) && ((str[3] & 0xf0) == 0xe0))
        {
            // check if there is a file already opened
            //close the previous and open a new one to write
            if (count != 0)
            {
                fclose(img_pointer);
                // printf("SUCCESS %03i.jpg\n", count);
            }

            // rename before open it as a new file by ing_pointer
            sprintf(filename, "%03i.jpg", count);
            img_pointer = fopen(filename, "w");

            //tell if a file is already created
            count++;
        }

        // check if there is a file already opened
        if (count != 0)
        {
            fwrite(&str, 512, 1, img_pointer);
        }
    }
    //close all the opened file, incase not close yet
    fclose(infile);
    fclose(img_pointer);

    return 0;
}
