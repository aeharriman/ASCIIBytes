# ASCIIBytes

## A program using encryption as a form of artistic expression.

This was a project I thought up after finishing all the projects in C for CS50.
I thought it would be fun to play with the ways the same data can be repesented viusally.
Instead of ASCII art, it is binary art!

Option 1: ./ASCIIBytes e|encrypt "plaintext"
It prints an encrypted message

Option 2: ./ASCIIBytes d|decrypt "ciphertext"
It takes the encrypted message and turns each character into the associated ASCII number.
Then it turns that number into binary.
When you stack them together 5 tall, it forms your message out of 1's and 0's!

Option 3: ./ASCIIBytes c|convert "plaintext"
For directly turning the text into binary font without encyption.

I planned it out in pseudocode before writing it, which helped give me experience in project planning:
```
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

/////////-------------------------------------------------------------------------------------------```