// Fig. 2.1: fig02_01.c
// A first program in C 
#include <stdio.h>

// function main begins program execution 
int main( void )
{	
   printf( "Welcome to C!\n" );

   int length = 0;
   int width = 0;
   int area = 0;
   
   // prompt user for length
   printf("%s", "Enter the length: ");
   int check1 = (scanf("%d", &length));

   // if length is valid, prompt user for width
   if (check1 == 1) {
	   printf("%s", "Enter the width: ");
	   int check2 = scanf("%d", &width);
	 if (check2 == 1) {
		   area = length * width;
		   printf("Length: %d  Width: %d  and area is: %d\n", length, width, area);
	 } // end check2
	   else {
		   printf("%s", "You did not enter a valid integer. Run program again.");
	   }
   } // end check1
   else {
	   printf("%s", "You did not enter a valid integer. Run program again.");
   }

   // Division
   double divisionResult = ((float)length) / width;
   printf("\nThe division result is: %.1lf\n", divisionResult);
   double averageValue = ((float)length + width) / 2;
   printf("The average value of length & width is: %.1lf", averageValue);
   
   return 0;
} // end function main 


/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
