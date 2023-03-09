#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// A program using encryption as a form of artistic expression
// Make print to acceptable not array but file

typedef struct char_font
{
    char letter;
    char *bytes[5];
    char ASCIIs[5];
}
char_font;

// Function Prototypes
uint8_t bi_to_int(char *binary_input);
char *int_to_bi(uint8_t charnum, char *binary_location);
bool byte_check(char *binary_being_checked, char array_checking[(126 - 33)][9]);

int main(int argc, char *argv[])
{
    bool is_encrypting;
    char *e_d_string[7];
    char *user_input;

    // Check for correct usage
    // if (argc!= 3)
    // {
    //     printf("Usage: ./ASCIIBytes encrypt|decrypt input\n");
    //     return 1;
    // }

    // Assign variables based on input
    if (strcasecmp(argv[1], "E") == 0 || strcasecmp(argv[1], "encode") == 0)
    {
        is_encrypting = true;
    } 
    else if (strcasecmp(argv[1], "D") == 0 || strcasecmp(argv[1], "decode") == 0)
    {
        is_encrypting = false;
    }
    else
    {
        printf("Input invalid.\n");
        return 1;
    }

    // Pares the input down to a-z characters
    user_input = malloc(sizeof(argv[2]));
    strcpy(user_input, argv[2]);
    for (int i = 0; i < strlen(user_input); i++)
    {
        // Could use isalpha() but doing it the granular way fits the spirit of the project
        if (toupper(user_input[i]) < 64 || toupper(user_input[i]) > 91)
        {
            printf("Alphabetical characters only, please.\n");
            free(user_input);
            return 1;
        }
    }

    // Make array of bytes that represent viable ASCII characters
    char binary_string[9];
    char acceptabytes[(126 - 33)][9];
    for (int i = 0, ASCII_index = 33; i < (126 - 33); i++, ASCII_index++)
    {
        // Memory location for int_to_bi
        int_to_bi(ASCII_index, binary_string);
        for (int j = 0; j < 9; j++)
        {
        acceptabytes[i][j] = binary_string[j];
        }
        //printf("!!! %s\n", &acceptabytes[i][0]);
    }
    //printf("%s\n", &acceptabytes[57][0]);

    // Make a font
    char_font font[26];

    font[0].letter = 'a';
    font[0].bytes[0] = "00111000";
    font[0].bytes[1] = "01000100";
    font[0].bytes[2] = "01111100";
    font[0].bytes[3] = "01000100";
    font[0].bytes[4] = "01000100";

    font[1].letter = 'b';
    font[1].bytes[0] = "01111100";
    font[1].bytes[1] = "01000010";
    font[1].bytes[2] = "01111100";
    font[1].bytes[3] = "01000010";
    font[1].bytes[4] = "01111100";

    font[2].letter = 'c';
    font[2].bytes[0] = "00111100";
    font[2].bytes[1] = "01000010";
    font[2].bytes[2] = "01000000";
    font[2].bytes[3] = "01000010";
    font[2].bytes[4] = "00111100";

    font[3].letter = 'd';
    font[3].bytes[0] = "01111100";
    font[3].bytes[1] = "01000010";
    font[3].bytes[2] = "01000001";
    font[3].bytes[3] = "01000010";
    font[3].bytes[4] = "01111100";

    font[4].letter = 'e';
    font[4].bytes[0] = "01111100";
    font[4].bytes[1] = "01000000";
    font[4].bytes[2] = "01111000";
    font[4].bytes[3] = "01000000";
    font[4].bytes[4] = "01111100";

    font[5].letter = 'f';
    font[5].bytes[0] = "01111100";
    font[5].bytes[1] = "01000000";
    font[5].bytes[2] = "01111000";
    font[5].bytes[3] = "01000000";
    font[5].bytes[4] = "01000000";

    font[6].letter = 'g';
    font[6].bytes[0] = "00111100";
    font[6].bytes[1] = "01000000";
    font[6].bytes[2] = "01000110";
    font[6].bytes[3] = "01000010";
    font[6].bytes[4] = "00111100";

    font[7].letter = 'h';
    font[7].bytes[0] = "01000100";
    font[7].bytes[1] = "01000100";
    font[7].bytes[2] = "01111100";
    font[7].bytes[3] = "01000100";
    font[7].bytes[4] = "01000100";

    font[8].letter = 'i';
    font[8].bytes[0] = "01111000";
    font[8].bytes[1] = "00110000";
    font[8].bytes[2] = "00110000";
    font[8].bytes[3] = "00110000";
    font[8].bytes[4] = "01111000";

    font[9].letter = 'j';
    font[9].bytes[0] = "01111000";
    font[9].bytes[1] = "00110000";
    font[9].bytes[2] = "00110000";
    font[9].bytes[3] = "00110000";
    font[9].bytes[4] = "01100000";

    font[10].letter = 'k';
    font[10].bytes[0] = "01001000";
    font[10].bytes[1] = "01010000";
    font[10].bytes[2] = "01100000";
    font[10].bytes[3] = "01001000";
    font[10].bytes[4] = "01000100";

    font[11].letter = 'l';
    font[11].bytes[0] = "01000000";
    font[11].bytes[1] = "01000000";
    font[11].bytes[2] = "01000000";
    font[11].bytes[3] = "01000000";
    font[11].bytes[4] = "01111100";

    font[12].letter = 'm';
    font[12].bytes[0] = "00100100";
    font[12].bytes[1] = "01011010";
    font[12].bytes[2] = "01011010";
    font[12].bytes[3] = "01000010";
    font[12].bytes[4] = "01000010";

    font[13].letter = 'n';
    font[13].bytes[0] = "01000010";
    font[13].bytes[1] = "01100010";
    font[13].bytes[2] = "01010010";
    font[13].bytes[3] = "01001010";
    font[13].bytes[4] = "01000110";

    font[14].letter = 'o';
    font[14].bytes[0] = "00111100";
    font[14].bytes[1] = "01000010";
    font[14].bytes[2] = "01000010";
    font[14].bytes[3] = "01000010";
    font[14].bytes[4] = "00111100";

    font[15].letter = 'p';
    font[15].bytes[0] = "01111100";
    font[15].bytes[1] = "01000010";
    font[15].bytes[2] = "01111100";
    font[15].bytes[3] = "01000000";
    font[15].bytes[4] = "01000000";

    font[16].letter = 'q';
    font[16].bytes[0] = "00111100";
    font[16].bytes[1] = "01000010";
    font[16].bytes[2] = "01000010";
    font[16].bytes[3] = "01000110";
    font[16].bytes[4] = "00111101";

    font[17].letter = 'r';
    font[17].bytes[0] = "01111100";
    font[17].bytes[1] = "01000010";
    font[17].bytes[2] = "01111100";
    font[17].bytes[3] = "01000100";
    font[17].bytes[4] = "01000010";

    font[18].letter = 's';
    font[18].bytes[0] = "00111100";
    font[18].bytes[1] = "01100010";
    font[18].bytes[2] = "00111000";
    font[18].bytes[3] = "01000110";
    font[18].bytes[4] = "00111100";

    font[19].letter = 't';
    font[19].bytes[0] = "01111000";
    font[19].bytes[1] = "00110000";
    font[19].bytes[2] = "00110000";
    font[19].bytes[3] = "00110000";
    font[19].bytes[4] = "00110000";

    font[20].letter = 'u';
    font[20].bytes[0] = "01000010";
    font[20].bytes[1] = "01000010";
    font[20].bytes[2] = "01000010";
    font[20].bytes[3] = "01000010";
    font[20].bytes[4] = "00111100";

    font[21].letter = 'v';
    font[21].bytes[0] = "01000010";
    font[21].bytes[1] = "01000010";
    font[21].bytes[2] = "00100100";
    font[21].bytes[3] = "00100100";
    font[21].bytes[4] = "00111000";

    font[22].letter = 'w';
    font[22].bytes[0] = "01000010";
    font[22].bytes[1] = "01000010";
    font[22].bytes[2] = "01011010";
    font[22].bytes[3] = "01011010";
    font[22].bytes[4] = "00100100";
    
    font[23].letter = 'x';
    font[23].bytes[0] = "01000010";
    font[23].bytes[1] = "00100100";
    font[23].bytes[2] = "00111100";
    font[23].bytes[3] = "00100100";
    font[23].bytes[4] = "01000010";

    font[24].letter = 'y';
    font[24].bytes[0] = "01000100";
    font[24].bytes[1] = "01101100";
    font[24].bytes[2] = "00111000";
    font[24].bytes[3] = "00111000";
    font[24].bytes[4] = "00111000";

    font[25].letter = 'z';
    font[25].bytes[0] = "01111000";
    font[25].bytes[1] = "00111000";
    font[25].bytes[2] = "00110000";
    font[25].bytes[3] = "01100000";
    font[25].bytes[4] = "01111100";


    // printf("binary: %i\n", byte_check("01000110", acceptabytes));
    printf("argv1: %s\n", argv[1]);
    printf("argv2: %s\n", argv[2]);

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 5; j++)
        {
        font[i].ASCIIs[j] = bi_to_int(font[i].bytes[j]);
        // printf("int %c\n", font[i].ASCIIs[j]);
        }
    }

    // // Checking that functions are working
    // printf("Is encrypting: %i\n", is_encrypting);
    // printf("User input: %s\n", user_input);
    // // printf("Parsed input: %s\n", parsed_input);
    // // Remember that all of the outputs are references to the holding variable. Save in a holding variable with &.
    // printf("decimal: %i\n", bi_to_int("11111111"));
    // //printf("test\n");
    // printf("binary from int: %s\n", int_to_bi(38, binary_string));

   // Run Encode/ decode depending on input

// 5 times, one for each row
//    for every char in input
// find that char's ascii value
// print the equivalent first value
    if (is_encrypting)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < strlen(user_input); j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (font[(int)(toupper(user_input[j]) - 'A')].bytes[i][k] == '0')
                    {
                        printf("\033[0;30m");
                        printf("%c", font[(int)(toupper(user_input[j]) - 'A')].bytes[i][k]);
                        printf("\033[0;30m");
                    }
                    else
                    {
                        printf("\033[0;32m");
                        printf("%c", font[(int)(toupper(user_input[j]) - 'A')].bytes[i][k]);
                        printf("\033[0;30m");
                    }
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("de");
        // decrypt
    }

    free(user_input);
    // free(parsed_input);
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
// Turn a decimal integer representing an ASCII character into a string representing a binary value.
// ASCII uses signed binary. This reflects that.
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
// Turn a string representing a byte-sized binary number into an integer.
uint8_t bi_to_int(char *binary_input)
{
    uint8_t sum = 0;
    uint8_t place_value = 128;
    for (int i = 0; i < 8; i++)
    {
        // Take each number and multiply it to the associated scale
        sum += (uint8_t)(binary_input[i] - '0') * place_value;
        place_value /= 2;
    }
    return sum;
}

// Now we need to take the string input, loop through the characters, 
// and for each character add it's 0 ascii to the string you will return, repeat through 5th index.
    // LEVEL 4 Function input: string(original) output: string(encoded)


// Now for the reverse:
    // LEVEL 5 Function input: string(encoded) output: string(decoded)
        // Will need to divide total number of characters by 5 to figure out where to put newlines







        // for (int i = 0; i < 5; i++)
        // {
        //     for (int j = 0; j < strlen(user_input); j++)
        //     {
        //            printf("%s", font[(int)(toupper(user_input[j]) - 'A')].bytes[i]);
        //     }
        //     printf("\n");
        // }




        ///-------------------------------------------------


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