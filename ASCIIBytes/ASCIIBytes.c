#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// A program using encryption as a form of artistic expression
// added args to launch.json for debugging

// Make print to acceptable not array but file

// Turn space into indicator to make new line

// Split into different files. Maybe a different file for font 

// Figure out why gitignore is not working on .exe and .json

typedef struct char_font
{
    char *bytes[5];
    char ASCIIs[5];
}
char_font;

// Function Prototypes
uint8_t bi_to_int(char *binary_input);
char *int_to_bi(uint8_t charnum, char *binary_location);
bool byte_check(char *binary_being_checked, char array_checking[(126 - 33)][9]);
void encrypt(char *e_input, char_font e_font[26]);
void decrypt(char *d_input, char_font d_font[26]);
void convert(char *c_input, char_font c_font[26]);

int main(int argc, char *argv[])
{
    char option_e_d_c;
    char *e_d_string[7];
    char *user_input;

    // Checks for correct usage. Had to disable when debugging because debugger adds extra aguments
    if (argc!= 3)
    {
        printf("Usage: ./ASCIIBytes encrypt|e|decrypt|d|convert|c \"input\"\n");
        return 1;
    }

    // Assign variables based on input
    if (strcasecmp(argv[1], "E") == 0 || strcasecmp(argv[1], "encode") == 0)
    {
        option_e_d_c = 'e';
    } 
    else if (strcasecmp(argv[1], "D") == 0 || strcasecmp(argv[1], "decode") == 0)
    {
        option_e_d_c = 'd';
    }
    else if (strcasecmp(argv[1], "C") == 0 || strcasecmp(argv[1], "convert") == 0)
    {
        option_e_d_c = 'c';
    }
    else
    {
        printf("Input invalid.\n");
        return 1;
    }

    // Pares the input down to a-z characters when not decrypting
    user_input = malloc(sizeof(argv[2]));
    strcpy(user_input, argv[2]);
    if (option_e_d_c != 'd')
    {
        for (int i = 0; i < strlen(user_input); i++)
        {
            // Could use isalpha() but the granular way fits the spirit of the project
            if (toupper(user_input[i]) < 64 || toupper(user_input[i]) > 91)
            {
                printf("Alphabetical characters only, please.\n");
                free(user_input);
                return 1;
            }
        }
    }

    // Make array of bytes that represent viable ASCII characters for use in the font
    char binary_string[9];
    char acceptabytes[(126 - 33)][9];
    for (int i = 0, ASCII_index = 33; i < (126 - 33); i++, ASCII_index++)
    {
        int_to_bi(ASCII_index, binary_string);
        for (int j = 0; j < 9; j++)
        {
            acceptabytes[i][j] = binary_string[j];
        }
    }

    // Make a font
    char_font font[26];

    // A
    font[0].bytes[0] = "00111000";
    font[0].bytes[1] = "01000100";
    font[0].bytes[2] = "01111100";
    font[0].bytes[3] = "01000100";
    font[0].bytes[4] = "01000100";

    // B
    font[1].bytes[0] = "01111100";
    font[1].bytes[1] = "01000010";
    font[1].bytes[2] = "01111100";
    font[1].bytes[3] = "01000010";
    font[1].bytes[4] = "01111100";

    // C
    font[2].bytes[0] = "00111100";
    font[2].bytes[1] = "01000010";
    font[2].bytes[2] = "01000000";
    font[2].bytes[3] = "01000010";
    font[2].bytes[4] = "00111100";

    // D
    font[3].bytes[0] = "01111100";
    font[3].bytes[1] = "01000010";
    font[3].bytes[2] = "01000001";
    font[3].bytes[3] = "01000010";
    font[3].bytes[4] = "01111100";

    // E
    font[4].bytes[0] = "01111100";
    font[4].bytes[1] = "01000000";
    font[4].bytes[2] = "01111000";
    font[4].bytes[3] = "01000000";
    font[4].bytes[4] = "01111100";

    // F
    font[5].bytes[0] = "01111100";
    font[5].bytes[1] = "01000000";
    font[5].bytes[2] = "01111000";
    font[5].bytes[3] = "01000000";
    font[5].bytes[4] = "01000000";

    // G
    font[6].bytes[0] = "00111100";
    font[6].bytes[1] = "01000000";
    font[6].bytes[2] = "01000110";
    font[6].bytes[3] = "01000010";
    font[6].bytes[4] = "00111100";

    // H
    font[7].bytes[0] = "01000100";
    font[7].bytes[1] = "01000100";
    font[7].bytes[2] = "01111100";
    font[7].bytes[3] = "01000100";
    font[7].bytes[4] = "01000100";

    // I
    font[8].bytes[0] = "01111000";
    font[8].bytes[1] = "00110000";
    font[8].bytes[2] = "00110000";
    font[8].bytes[3] = "00110000";
    font[8].bytes[4] = "01111000";

    // J
    font[9].bytes[0] = "01111000";
    font[9].bytes[1] = "00110000";
    font[9].bytes[2] = "00110000";
    font[9].bytes[3] = "00110000";
    font[9].bytes[4] = "01110000";

    // K
    font[10].bytes[0] = "01001100";
    font[10].bytes[1] = "01011000";
    font[10].bytes[2] = "01110000";
    font[10].bytes[3] = "01011000";
    font[10].bytes[4] = "01000110";

    // L
    font[11].bytes[0] = "01000000";
    font[11].bytes[1] = "01000000";
    font[11].bytes[2] = "01000000";
    font[11].bytes[3] = "01000000";
    font[11].bytes[4] = "01111100";

    // M
    font[12].bytes[0] = "01100110";
    font[12].bytes[1] = "01011010";
    font[12].bytes[2] = "01011010";
    font[12].bytes[3] = "01000010";
    font[12].bytes[4] = "01000010";

    // N
    font[13].bytes[0] = "01000010";
    font[13].bytes[1] = "01100010";
    font[13].bytes[2] = "01010010";
    font[13].bytes[3] = "01001010";
    font[13].bytes[4] = "01000110";

    // O
    font[14].bytes[0] = "00111100";
    font[14].bytes[1] = "01000010";
    font[14].bytes[2] = "01000010";
    font[14].bytes[3] = "01000010";
    font[14].bytes[4] = "00111100";

    // P
    font[15].bytes[0] = "01111100";
    font[15].bytes[1] = "01000010";
    font[15].bytes[2] = "01111100";
    font[15].bytes[3] = "01000000";
    font[15].bytes[4] = "01000000";

    // Q
    font[16].bytes[0] = "00111100";
    font[16].bytes[1] = "01000010";
    font[16].bytes[2] = "01000010";
    font[16].bytes[3] = "01000110";
    font[16].bytes[4] = "00111101";

    // R
    font[17].bytes[0] = "01111100";
    font[17].bytes[1] = "01000010";
    font[17].bytes[2] = "01111100";
    font[17].bytes[3] = "01000100";
    font[17].bytes[4] = "01000010";

    // S
    font[18].bytes[0] = "00111100";
    font[18].bytes[1] = "01100010";
    font[18].bytes[2] = "00111000";
    font[18].bytes[3] = "01000110";
    font[18].bytes[4] = "00111100";

    // T
    font[19].bytes[0] = "01111000";
    font[19].bytes[1] = "00110000";
    font[19].bytes[2] = "00110000";
    font[19].bytes[3] = "00110000";
    font[19].bytes[4] = "00110000";

    // U
    font[20].bytes[0] = "01000010";
    font[20].bytes[1] = "01000010";
    font[20].bytes[2] = "01000010";
    font[20].bytes[3] = "01000010";
    font[20].bytes[4] = "00111100";

    // V
    font[21].bytes[0] = "01000010";
    font[21].bytes[1] = "01000010";
    font[21].bytes[2] = "01100110";
    font[21].bytes[3] = "01101100";
    font[21].bytes[4] = "00111000";

    // W
    font[22].bytes[0] = "01000010";
    font[22].bytes[1] = "01000010";
    font[22].bytes[2] = "01011010";
    font[22].bytes[3] = "01011010";
    font[22].bytes[4] = "01100110";
    
    // X
    font[23].bytes[0] = "01000010";
    font[23].bytes[1] = "01100110";
    font[23].bytes[2] = "00111100";
    font[23].bytes[3] = "01100110";
    font[23].bytes[4] = "01000010";

    // Y
    font[24].bytes[0] = "01000100";
    font[24].bytes[1] = "01101100";
    font[24].bytes[2] = "00111000";
    font[24].bytes[3] = "00111000";
    font[24].bytes[4] = "00111000";

    // Z
    font[25].bytes[0] = "01111000";
    font[25].bytes[1] = "00111000";
    font[25].bytes[2] = "00110000";
    font[25].bytes[3] = "01110000";
    font[25].bytes[4] = "01111100";

    // Adds the associated ASCII characters for each row of binary font
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 5; j++)
        {
        font[i].ASCIIs[j] = bi_to_int(font[i].bytes[j]);
        // printf("int %c\n", font[i].ASCIIs[j]);
        }
    }

    // Run Encrypt/Decrypt/Convert depending on input
    if (option_e_d_c == 'e')
    {
        encrypt(user_input, font);
    }
    else if (option_e_d_c == 'd')
    {
        decrypt(user_input, font);
    }
    else
    {
        convert(user_input, font);
    }

    free(user_input);
    return 0;
}

//--------------------------------------------------------------------------------------------------------------
// Check if a byte you want to use in your font represents a viabla ASCII character.
    // Recognize that I did not need to fill an array before checking and that the checking could be a simple loop.
    // I realized I was lacking the ability to do it this way so it was part of my learning curve.
    // This way I got practice with 2d arrays.
    // May simplify in later version.
bool byte_check(char *binary_being_checked, char array_checking[(126 - 33)][9])
{
    for (int i = 0; i < (126 - 33); i++)
    {
        //printf("%s = %s ?\n", acceptabytes[i], binary_being_checked);
        if (strcmp(array_checking[i], binary_being_checked) == 0)
        {
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------------------------------------------------------

// Turn a decimal integer representing an ASCII character into a byte-sized string of bits.
// In this case, using the convention that a byte be 8 bits.
// ASCII uses 7 bits, so for this program each leading number is 0.
char *int_to_bi(uint8_t charnum, char *binary_location)
{
    uint8_t place_value = 128;

    for (int i = 0; i < 8; i++)
    {
        if (charnum >= place_value)
        {
            binary_location[i] = '1';
            charnum -= place_value;
            place_value /= 2;
        }
        else
        {
            binary_location[i] = '0';
            place_value /= 2;
        }
    }
    return binary_location;
}

//--------------------------------------------------------------------------------------------------------------

// Turn a string representing 8 bits into a decimal integer.
uint8_t bi_to_int(char *binary_input)
{
    uint8_t sum = 0;
    uint8_t place_value = 128;
    for (int i = 0; i < 8; i++)
    {
        sum += (uint8_t)(binary_input[i] - '0') * place_value;
        place_value /= 2;
    }
    return sum;
}

//-------------------------------------------------------------------------------------------

// Takes input from user and turns it into a string of characters representing the bytes that will make letters
void encrypt(char *e_input, char_font e_font[26])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < strlen(e_input); j++)
        {
            printf("%c", e_font[(int)(toupper(e_input[j]) - 'A')].ASCIIs[i]);
        }
    }
}

//-------------------------------------------------------------------------------------------

// Takes input and turns the integers that represent the characters in ASCII into bytes
void decrypt(char *c_input, char_font c_font[26])
{
    char binary_storage[9];

    for (int i = 0; i < strlen(c_input); i++)
    {
        int_to_bi(((int) c_input[i]), binary_storage);

        //adds a /n every line
        if (i % (strlen(c_input) / 5) == 0 && i != 0)
        {
            printf("\n");
        }

        for (int k = 0; k < 8; k++)
        {
            if (binary_storage[k] == '0')
            {
                printf("\033[0;90m");
                printf("%c", binary_storage[k]);
                printf("\033[0;37m");
            }
            else
            {
                printf("\033[0;32m");
                printf("%c", binary_storage[k]);
                printf("\033[0;37m");
            }
        }
        
    }
    
}

//-------------------------------------------------------------------------------------------

// Turn input directly into binary without encrypting
void convert(char *c_input, char_font c_font[26])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < strlen(c_input); j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (c_font[(int)(toupper(c_input[j]) - 'A')].bytes[i][k] == '0')
                {
                    printf("\033[0;30m");
                    printf("%c", c_font[(int)(toupper(c_input[j]) - 'A')].bytes[i][k]);
                    printf("\033[0;30m");
                }
                else
                {
                    printf("\033[0;32m");
                    printf("%c", c_font[(int)(toupper(c_input[j]) - 'A')].bytes[i][k]);
                    printf("\033[0;30m");
                }
            }
        }
        printf("\n");
    }
}



//----------------------------------------------------------------------
// Ultimate functionality:
    // get string from user
    // If non-encoded, Print encoded
    // If encoded, print 5 lines of 1s and 0s that form letters and highlight the 1s in green.
//----------------------------------------------------------------------------

// Need functions to assist with writing program:

// LEVEL 3 Function to check if a byte you want to use in your font is acceptable.
    // input: pointer to string 8 char's long (9 with \0)
    // output: boolean yes/no

        // Since there are only 100 or so things to search, a simple loop through a list of acceptable bytes should be fine.

            // LEVEL 2 Function: Get a list of acceptable bytes to build font with.
            // input: void. output: void. Include as part of main instead of breaking out into function.
            // loop through 33 and 126 (viable characters) and convert those uint8_t to string of 1s and 0s

                // LEVEL 1 Function: input: uint8_t output: string
                // Could just make a printout of available bytes but this function will come in handy later anyway.

// Now that we can check whether a byte is acceptable, we can pick certain byes to build our font out of.
// Fill an array with structs that have letter and array of bytes and array of equivalent ASCII.
    // LEVEL 1 Function: Convert byte to uint8_t input: byte output: uint8_t
    // Loop through array and for each fill out the ASCII array.

// Now we need to take the string input, loop through the characters, 
// and for each character add it's 0 ascii to the string you will return, repeat through 5th index.
    // LEVEL 4 Function input: string(original) output: string(encoded)

// Now for the reverse:
    // LEVEL 4 Function input: string(encoded) output: string(decoded)
        // Will need to divide total number of characters by 5 to figure out where to put newlines

/////////-------------------------------------------------------------------------------------------