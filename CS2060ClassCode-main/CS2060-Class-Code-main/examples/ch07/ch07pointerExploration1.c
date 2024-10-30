/*******************
 Understanding pointers

 Add comments to explain the code
**************/

#include <stdio.h>


int main ()
{
	// Initalize houseNum
	int houseNum = 13;
	int calcHouseNum1 = 0;
	int calcHouseNum2 = 0;
	int *houseNumPtr = &houseNum;
	// Print the value stored at houseNum
	printf("houseNum %d\n", houseNum);
	// Print the address of variable houseNum
	printf("&houseNum %p\n\n", &houseNum);

	// Print the value that the pointer is pointing to
	printf ("*houseNumPtr  %d\n", *houseNumPtr);
	// Print the value stored at the address of pointer variable. This is 
	// the address of the value the pointer is pointing to. It's the same 
	// as the address of the variable houseNum.
	printf ("houseNumPtr %p\n\n", houseNumPtr);

	// Now print the address of the pointer variable houseNumPtr
	printf ("&houseNumPtr %p\n\n", &houseNumPtr);
	// Using the asterisk to dereference and grab the value being pointed to by houseNumPtr
	// Adding the values being pointed to by houseNumPtr two times.
	calcHouseNum1 =  *houseNumPtr + *houseNumPtr;
	// Should be 26.
	printf("*houseNumPtr + *houseNumPtr is %d\n\n", calcHouseNum1);
	// It is 26!
	calcHouseNum2 = 2 * (*houseNumPtr);
	// If parenthesis are used, a dereferenced pointer can be treated as a regular variable
	// in a mathematical equation
	// Should be 26, and it is!
	printf("2 * (*houseNumPtr) is %d\n\n", calcHouseNum2);
	// This last part is demonstrating that there is no difference between using *& or &* before
	// a pointer. Both will return the address of the value being pointed to by houseNumPtr.
	printf("\n&*houseNumPtr = %p"
		"\n*&houseNumPtr = %p\n", &*houseNumPtr, *&houseNumPtr);
			
	return 0;
}
