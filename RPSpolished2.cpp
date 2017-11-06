/*This program was made by Mason McCray
   on the 12th of October of 2017
   for my C++ midterm
   I hope to recieve wow points for extra effort
   to my future self if I ever look back
   this took me around 7 hours to make
   Developed using jgrasp
*/

#include <iostream> 
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main();

//---------------------------
//Title screen
void title()
{
   cout<< "-----------------------------------------------\n";
   cout<< "-- This is a Rock, Paper, Scissors simulator --\n";
   cout<< "-----------------------------------------------\n";
   cout<< "\nThere are two options to play\n";
   cout<< "1. Play against the computer\n";
   cout<< "2. Player vs Player\n";
   cout<< "\nIf you have never played select 3 for rules\n";
   

}

// ----------------------------
//Check user input
int entryCheck()
{
   //Checks the users entry for a valid number
   string userInput;
   int output;
   
   do
   {
      getline(cin, userInput);
      output = (int) userInput[0];
         if (output == '1')
            output=1;
         if (output == '2')
            output=2;
         if (output == '3')
            output=3;
   }
   while( output!=1 && output!=2 && output!=3);

return output;
}

// ----------------------------
//Check answer for loop
int loopCheck()
{
   //Checks the users entry for a valid number
   string userInput;
   int output;
   
   do
   {
      getline(cin, userInput);
      output = (char) userInput[0];

   }
   while( output!='Y' && output!='y' && output!='N' && output!= 'n' );

return output;
}


// ---------------------------------------

//One player game
void onePlayer()
{
   int wins=0;
   int ties=0;
   int losses=0;
   
   int choice;
   int  comp;

   char continueLoop;
   unsigned seed;
   char compChoice;
   string empty;
   
   //Ask for the user input
   do
   {
  
      cout<< "\nSelect 1 for Rock, 2 for Paper, or 3 for Scissors to start!\n";
      choice = entryCheck();

      //Display choice
      if (choice == 1)
      {
         cout<< "You chose Rock! \n";
         cout<< "The computer chose ";
      }
      
      else if (choice == 2)
      {
         cout<< "You chose Paper \n";
         cout<< "The computer chose ";
      }

      else if (choice == 3)
      {
         cout<< "You chose Scissors \n";
         cout<< "The computer chose ";
      }

      else 
      {
          cout<< "Please choose a valid number \n";
      }


      if (choice==1 || choice==2 || choice==3)
      {

         //Random generator for computer choice and displays their choice
         seed = time(0);
         srand(seed);
         comp = rand() % 3 + 1;

            //Stores computer choice for decision
            if (comp == 1)
            {
               compChoice=1;
               cout<< "Rock! \n";
             }
            else if (comp == 2)
            {
               compChoice=2;
               cout<< "Paper! \n";
            }
            else if (comp == 3)
            {
               compChoice=3;
               cout<< "Scissors! \n";
             }

            //Compare the choices and see who wins
            if ((choice==1 && compChoice==3 ) || (choice==2 && compChoice==1) || (choice==3 && compChoice==2))
            {
               cout<< "You Win! \n";
               wins++;
             }
            else if (choice==compChoice)
            {
               cout<<"There has been a tie! \n";
               ties++;
            }
            else
            {
               cout<< "The Computer Prevails \n";
               losses++;
            }
      

            //Display the current scores
            cout<< "\nThe current scores are \n";
            cout<< "Wins = " << wins << "\n";
            cout<< "Ties = " << ties << "\n";
            cout<< "Losses = " << losses << "\n";

       }
       //Continue loop
       cout << "\nEnter Y to continue or M to return to main menu, any other character will exit game \n";
		 cin >> continueLoop;
       getline(cin, empty);
       
       if (continueLoop == 'm' || continueLoop == 'M')
       {
            main();
       }
      
   }
   while (continueLoop == 'Y' || continueLoop == 'y');
}



//-----------------------------------
//Two player game
void twoPlayer()
{
   int oneChoice;
   int twoChoice;

   int oneWin=0;
   int twoWin=0;
   int tiez=0;

   char continueLoop;
   string empty;

   do
   {
   //Display
      cout<< "You have chose to play the 2 player game!\n";
      cout<< "\nPlayer 2 look away and player one pick your choice\n";
      cout<< "\nSelect 1 for Rock, 2 for Paper, or 3 for Scissors\n";
      oneChoice = entryCheck();

      //Two players make their choice
   
      if (oneChoice==1 || oneChoice==2 || oneChoice==3)
      {  
         cout << string(50, '\n');
         cout<< "\nThank you, now step away and player two make your selection\n";
         cout<< "\nSelect 1 for Rock, 2 for Paper, or 3 for Scissors\n";
         twoChoice = entryCheck();
         if (twoChoice==1 || twoChoice==2 || twoChoice==3)
         {
            //Logic to decide who wins
            if ((oneChoice==1 && twoChoice==3 ) || (oneChoice==2 && twoChoice==1) || (oneChoice==3 && twoChoice==2))
            {
               cout<< "Player one wins!\n";
               oneWin++;
            }
            else if (oneChoice == twoChoice)
            {
               cout<< "There has been a tie!\n";
               tiez++;
            }
            else 
            {
               cout<< "Player two wins!\n";
               twoWin++;
            }
      
            //Display scores
            cout<< "\nThe current scores are \n";
            cout<< "Player one wins = " << oneWin << "\n";
            cout<< "Ties = " << tiez << "\n";
            cout<< "Player two wins = " << twoWin << "\n";
         }
      }

      else 
      { 
         cout<< "Sorry Invalid number";
      }
      cout << "\nEnter Y to continue or M to return to main menu, any other character will exit game \n";
      cin >> continueLoop;
      getline(cin, empty);
      
      if (continueLoop == 'm' || continueLoop == 'M')
      {
         main();
      }
      
   }
   while (continueLoop == 'Y' || continueLoop == 'y');  
}



//-----------------------------------
//The organizer
int main()
{
   title();
   int mode;
   char loop;
   string empty;

   //User choice for game mode
   cout<< "Make your selection now:";
   cin>> mode;
   
   if (mode == 1)
   {
      onePlayer();
   }
      
   else if (mode == 2)
   {
      twoPlayer();
   }
      
   else if (mode == 3)
   {
      cout<< "\nThe rules of this game are: \n";
      cout<<  "Rock beats Scissors \n";
      cout<<  "Paper beats Rock \n";
      cout<<  "Scissors beats Paper \n\n";
         
      cout<< "Select Y to return to main menu or N to exit program\n";
      loop = loopCheck();
      
      if (loop == 'y' || loop == 'Y')
      {
         main();
      }
      else 
      {
      return 0;
      }
   }
     
   else
   {
      cout<< "Invalid choice\n";
      
      cout<< "Select Y to return to main menu or N to exit program\n";
      loop = loopCheck();
      
      if (loop == 'y' || loop == 'Y')
      {
         main();
      }
      else 
      {
      return 0;
      }
   }
   return 0;
}