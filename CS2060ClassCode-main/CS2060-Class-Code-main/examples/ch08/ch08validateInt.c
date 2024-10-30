
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define LENGTH 13

bool exploreValidateInt(const char* buff, int* valueToUpdate);
bool validateInt(char* buff, int* const validInt);
void printLimits();

int main(void)
{
	char inputStr[LENGTH]; // create char array
	size_t inputLength = 0; // initialize inputLength

	printLimits();

	for (unsigned int counter = 1; counter < 6; counter++)
	{
		puts("\nEnter an integer");
		fgets(inputStr, LENGTH, stdin);
		
		// calls strnlen function to determine length of char arrray inputStr
		inputLength = strnlen(inputStr, LENGTH);

		// if inputLength is corrent length and the last character is a newline
		if ((inputLength <= LENGTH - 1) && (inputStr[inputLength - 1] == '\n')) {
			// clear the buffer
			while (getchar() != '\n');
		}

		// if inputLength is above 0 and the last character in the array is a newline char
		if ((inputLength > 0) && (inputStr[inputLength - 1] == '\n'))
		{	
				// replace last character in array with null byte
				inputStr[inputLength - 1] = '\0';
				// decrement inputLength
				inputLength--;
		}
		int* valueToUpdate;
		exploreValidateInt(inputStr, &valueToUpdate);
	}

}


// Prints the limits(min/max) of various variables
void printLimits()
{
	printf("The number of bits in a byte %d\n", CHAR_BIT);

	// schar_min is the lower boundary for signed character once converted to integer
	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
	
	// UCHAR_MAX represents the maximum value an unsigned char may be once converted to numeric value
	printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

	// Displays the man/min values of short numbers
	printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

	// Displays the min & max values of the integer variables
	printf("The minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n", INT_MAX);

	// Displays the min/max values of character variables once converted to numeric values
	printf("The minimum value of CHAR = %d\n", CHAR_MIN);
	printf("The maximum value of CHAR = %d\n", CHAR_MAX);

	// Displays the min/max values of long variables
	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n", LONG_MAX);
}


bool  exploreValidateInt(const char* buff, int* valueToUpdate)
{	
	// bool flag for if output is valid int
	bool validInt = 0;
	// pointer to a character at the end of array
	char* end;
	
	// I believe this works as a primitive boolean value
	// Initialized to false?
	errno = 0;
	

	// catches a long value returned from the strtol funct. buff is a pointer to the the char 
	// array where user input is stored, &end is dereferencing the pointer to end char, and the base is 10
	// &end is a pointer to a character pointer which holds the adress of the first invalid character after conversion.
	// This is used to determine if the the whole string was converted.
	// If the strtol function is successful, it will return the converted long integer value.
	// If not successful, returns 0. And if the correct value is outside of the range, it will
	// simply return the LONG_MIN LONG_MAX value of said range.
	long intTest = strtol(buff, &end, 10);
	// You can also check that the conversion was successful by checking the value at &end after the test.

	// 
	if (end == buff) {
		fprintf(stderr, "%s: not a decimal number\n", buff);
	}
	// Test that the last character is a null byte to ensure all characters were included in conversion. 
	// If not a null byte, characters remain in the buffer.
	else if ('\0' != *end) {
		fprintf(stderr, "%s: extra characters at end of input: %s\n", buff, end);
	}
	// if input was outside or lands on the boundary values, the long min/max value is returned. Error occurs
	else if ((LONG_MIN == intTest || LONG_MAX == intTest) && ERANGE == errno) {
		fprintf(stderr, "%s out of range of type long\n", buff);
	}
	// test if the converted value is outside of the integer range max
	else if (intTest > INT_MAX) {
		fprintf(stderr, "%ld greater than INT_MAX\n", intTest);
	}
	// test if the converted value is less than the integer range minimum
	else if (intTest < INT_MIN) {
		fprintf(stderr, "%ld less than INT_MIN\n", intTest);
	}
	// if not outside ranges and no error in converting occured, explicitly cast the value to an integer
	else {
		*valueToUpdate = validInt;
		validInt = (int)intTest;
		// if conversion & casting was successful, set flag to true
		printf("%d is integer value ", validInt);
	}
}
