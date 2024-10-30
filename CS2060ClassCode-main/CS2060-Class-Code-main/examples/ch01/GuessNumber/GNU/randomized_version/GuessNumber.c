/*
* The program randomly generates numbers   
* between 1 and 1000 for the user to guess.
*/


// Preprocessors. Inlcude header files.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// constant MIN_NUMBER serves as lower boundary for range of numbers. Is this a global constant variable?
#define MIN_NUMBER 1

// Good use of proper naming conventions
const int MAX_NUMBER = 100;

// void as a parameter means no parameter for function.
// boolean for guess is correct is returned from function called, "isCorrect"
void guessGame(void); 
bool isCorrect(int, int); 


int main(void)
{
   // srand is for generating pseudo random num. requires a seed.
   // srand(time(0));

   // This is calling a function, "guessGame"
   guessGame(); 

   // End main function?
   return 0;
}

// This is the function 
void guessGame(void)
{
    // Declare and initialize some variables to zero.
   int answer = 0; 
   int guess = 0; 
   int response = 0; 

   do {

       // Ahh, yes. A do-While loop.Declares variable "answer" and sets 
       // it to MIN_NUMBER + a random number's remainder after being divided by MAX_NUBER.
      answer = MIN_NUMBER + rand() % MAX_NUMBER;


      // The indentation here is really messy. Should be aligned w/ first double quote.
      printf("Hello, I have a number between %d and %d .\n" 
           "Can you guess my number?\n"
           "Please type your first guess.", MIN_NUMBER, MAX_NUMBER);

      // My first nested do-while loop in C!
      do
      {
          // Scan user input, store in variable "guess".
          // Enter the function "isCorrect" w/ parameters "guess" & "answer"
          // While return boolean is false, keep prompting for play again
          scanf("%d", &guess);
      } while (!isCorrect(guess, answer));
         
      // Outside of the boolean == false loop, the answer is correct. Prompt for another play.
      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");

      printf("%s", "Please type ( 1=yes, 2=no ) ");
      scanf("%d", &response);

      puts("");
   } while (response == 1);
} 

// This function is sent two parameters, guess & answer. Function returns isCorrect = true, if they match.
bool isCorrect(int g, int a)
{
    // Create boolean for whether guess is correct or not
    bool found = false;

    // If answer != guess, then if it's too high or too low, try again.
    if (g == a){
        found = true;
    }else  if (g < a)
      printf( "%s", "Too low. Try again.\n? " );
   else
      printf( "%s", "Too high. Try again.\n? " );

    // return the value of the boolean value "found". This return value controls while loop above.
   return found;
} 

