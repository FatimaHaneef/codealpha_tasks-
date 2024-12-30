#include<iostream>
#include<cstdlib> // for srand() and rand()
#include<ctime>   // for time
#include<limits>  // for numeric_limits

using namespace std;

int main()
{   
    char replay_choice;  //  ask the user if they want to replay the game
    int attempts_count;  //  count the number of attempts
    int guessNumber = 0; //  store the user's guess
    int randomNumber;    // store the randomly generated number
    
    do {
        attempts_count = 0;  // Reset attempts count for each game
        srand(time(0));  // Initialize random seed using current time to generate different numbers every time
    
        cout << "~~~~~~~~~WELCOME TO NUMBER GUESSING GAME~~~~~~~~~~" << endl;
        
        // Display the menu to select the difficulty level
        int difficulty_level;
        
        cout << "~~~~~~SELECT~~~~~~" << endl;
        cout << "Press 1 for Easy Level: " << endl;
        cout << "Press 2 for Medium Level: " << endl;
        cout << "Press 3 for Hard Level: " << endl;
        cout << "Enter your choice: ";
        cin >> difficulty_level;
    
        // Switch case to handle the difficulty level chosen by the user
        switch(difficulty_level)
        {
            case 1:  // Easy game
                cout << "~~~~~EASY LEVEL~~~~~" << endl;
                cout << endl;
                cout << "***Let's Start!!!***" << endl;
                
                randomNumber = rand() % 50; // Generate a random number within 50
                
                // Loop for the guessing game
                while(true){
                    attempts_count++;  // Increment the attempts count
                    cout << "Enter guess number within range ( 0 and 50 ): ";
                    cin >> guessNumber;
                    
                    // Check if the input is a number
                    if(cin.fail()) {
                        cin.clear();  // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore incorrect input
                        cout << "Invalid input! Please Enter a Number.\n";
                        continue;  // Skip the rest of the loop and ask for input again
                    }
                    
                    // Check if the number is within the valid range
                    else if(guessNumber < 0 || guessNumber > 50) {
                        cout << "OUT OF RANGE !! Please enter a number within range." << endl;
                        continue;  // Ask for input again
                    }
                    
                    // Provide hints based on the guess
                    if(guessNumber < randomNumber) {
                        cout << "Too Low! Try Again.\n";
                    } else if(guessNumber > randomNumber) {
                        cout << "Too High! Try Again.\n";
                    } else {
                        cout << "Congratulations! You Won.\n";
                        cout << "Number of attempts: " << attempts_count << endl;  // Display the number of attempts
                        break;  // Exit the loop if the user guesses correctly
                    }
                }
                break;
                
            case 2:  // Medium game
                cout << "~~~~~MEDIUM LEVEL~~~~~" << endl;
                cout << endl;
                cout << "***Let's Start!!!***" << endl;
                cout << "You have only 10 chances !!" << endl;
                
                randomNumber = rand() % 100; // Generate a random number within 100
                
                // Loop for the guessing game with a limit of 10 attempts
                while(attempts_count <= 10) {
                    attempts_count++;  // Increment the attempts count
                    cout << "Enter guess number within range ( 0 and 100 ): " << endl;
                    cin >> guessNumber;
                    
                    // Check if the input is a number
                    if(cin.fail()) {
                        cin.clear();  // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore incorrect input
                        cout << "Invalid input! Please Enter a Number.\n";
                        continue;  // Skip the rest of the loop and ask for input again
                    }
                    
                    // Check if the number is within the valid range
                    else if(guessNumber < 0 || guessNumber > 100) {
                        cout << "OUT OF RANGE !! Please enter a number within range.";
                        continue;  // Ask for input again
                    }
                    
                    // Provide hints based on the guess
                    if(guessNumber < randomNumber) {
                        cout << "Too Low! Try Again.\n";
                    } else if(guessNumber > randomNumber) {
                        cout << "Too High! Try Again.\n";
                    } else {
                        cout << "Congratulations! You Won.\n";
                        cout << "Number of attempts: " << attempts_count << endl;  // Display the number of attempts
                        break;  // Exit the loop if the user guesses correctly
                    }
                }
                
                // If the user runs out of attempts, display the correct number
                if (attempts_count > 10)
                    cout << "You've run out of attempts. The number was: " << randomNumber << endl;
                break;

            case 3:  // Hard game
                cout << "~~~~~HARD LEVEL~~~~~" << endl;
                cout << endl;
                cout << "***Let's Start!!!***" << endl;

                randomNumber = rand() % 200; // Generate a random number within 200

                // Loop for the guessing game with a limit of 7 attempts
                while(attempts_count <= 7) {
                    attempts_count++;  // Increment the attempts count
                    cout << "Enter guess number within range ( 0 and 200 ): ";
                    cout << "You have only 7 chances!!" << endl;
                    cin >> guessNumber;
                    
                    // Check if the input is a number
                    if(cin.fail()) {
                        cin.clear();  // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore incorrect input
                        cout << "Invalid input! Please Enter a Number.\n";
                        continue;  // Skip the rest of the loop and ask for input again
                    }
                    
                    // Check if the number is within the valid range
                    else if(guessNumber < 0 || guessNumber > 200) {
                        cout << "OUT OF RANGE !! Please enter a number within range.";
                        continue;  // Ask for input again
                    }
                    
                    // Provide hints based on the guess
                    if(guessNumber < randomNumber) {
                        cout << "Too Low! Try Again.\n";
                    } else if(guessNumber > randomNumber) {
                        cout << "Too High! Try Again.\n";
                    } else {
                        cout << "Congratulations! You Won.\n";
                        cout << "Number of attempts: " << attempts_count << endl;  // Display the number of attempts
                        break;  // Exit the loop if the user guesses correctly
                    }
                }
                
                // If the user runs out of attempts, display the correct number
                if (attempts_count > 7)
                    cout << "You've run out of attempts. The number was: " << randomNumber << endl;
                break;
            
            default:
                cout << "INVALID CHOICE!" << endl;  // Handle invalid menu choice
        }
        
        // Prompt to replay the game
        cout << "Do you want to replay? (y/n): ";
        cin >> replay_choice;
        
    } while(replay_choice == 'y' || replay_choice == 'Y');  // Continue the game if the user chooses 'y' or 'Y'
    
    return 0;  // End of the program
}
