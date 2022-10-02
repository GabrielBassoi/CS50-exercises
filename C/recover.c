#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#define BS 512
#define FNS 8

typedef uint8_t BYTE;

bool is_start_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    //verifing
    if (argc != 2)
    {
        printf("\nUsage: ./recover image\n\n");
        return 1;
    }
    
    //verifing if it's possible to open
    if (!fopen(argv[1], "r"))
    {
        printf("\nIt is not possible to open!\n\n");
        return 1;
    }
    //open file
    FILE *file = fopen(argv[1], "r");
    
    BYTE buffer[BS];
    int file_index = 0;
    
    bool found_first_jpg = false;
    FILE *outfile;
    
    while (fread(buffer, BS, 1, file))
    {
        if (is_start_new_jpeg(buffer))
        {
            if (!found_first_jpg)
            {
                found_first_jpg = true;
            }
            else
            {
                fclose(outfile);
            }
            
            char filename[FNS];
            //creating file
            sprintf(filename, "%03i.jpg", file_index++);
            //verifying
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                return 1;
            }
            fwrite(buffer, BS, 1, outfile);
        }
        else if (found_first_jpg)
        {
            fwrite(buffer, BS, 1, outfile);
        }
        
    }
    //close files
    fclose(outfile);
    fclose(file);
}

//verifying
bool is_start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}