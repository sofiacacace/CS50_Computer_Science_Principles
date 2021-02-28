#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512 //La memoria la imaginamos como dividida en bloques de 512 bytes.
                       //Es una buena práctica colocarlo acá para que sea más fácil modificarlo.

#define FILE_NAME_SIZE 8 //Tamaño del nombre del archivo.

bool is_start_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    //chequea que se ingrese un sólo archivo:
    if(argc != 2)
    {
        printf("Write only one command-line argument.\n");
        return 1;
    }

    //abre el documento como lectura:
    FILE* file= fopen(argv[1],"r");

    //si no puede leerlo, file obtendría valor nulo.
    if(file == NULL)
    {
        printf( "File can't open.\n" );
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    int file_index = 0;
    bool have_found_first_jpg = false;
    FILE* outfile; //Define nombre de un nuevo archivo.

    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        if(is_start_new_jpeg(buffer))
        {
           if(!have_found_first_jpg)
           {
               have_found_first_jpg = true;
           }
           else
           {
               fclose(outfile);
           }

           char filename[FILE_NAME_SIZE];

           sprintf(filename, "%03i.jpg", file_index++); //Le asigna nombre al archivo. %03i significa añadir 3 números enteros.

           outfile = fopen(filename, "w");

           if(outfile == NULL)
           {
               return 1;
           }

           fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (have_found_first_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(file);
}

bool is_start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
