#include <iostream> // Preprocessor directive <header file>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty, int MaxDifficulty)
{
    cout << "\n";
    cout << "==================\n";
    cout << "Vault layer " << Difficulty << " / " <<  MaxDifficulty << "\n";
    cout << "==================\n";
}

bool PlayGame(int Difficulty, int MaxDifficulty, int Tries)
{
    PrintIntroduction(Difficulty, MaxDifficulty);

    // Initialize codes A, B, and C with a random number
    // Modulus of rand() returns range between lower bound and value of modulus - 1
    int CodeA = (rand() % Difficulty) + Difficulty, CodeB = rand() % Difficulty + Difficulty, CodeC = rand() % Difficulty + Difficulty;

    // Show hints if user has made at least 2 attempts
    if (Tries == 2)
    {
        cout << "> Hint: " << CodeA << " x x\n";
    }
    else if (Tries > 2)
    {
        cout << "> Hint: " << CodeA << " " << CodeB << " x\n";
    }

    // Sum up and multiply codes A, B, and C
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Create int memory containers for guesses and its sum and product
    int GuessA, GuessB, GuessC;

    // Game directions
    cout << "\n- Enter 3-digit number to unlock.\n";
    cout << "- Code adds to " << CodeSum << " and multiplies to " << CodeProduct << ".\n\n";

    // User inputs three data separated by space(s) or line(s)
    cout << "Code: ";
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Escape sequence "\n" can be used to end a line, but if a variable is the last output, we can use endl
    cout << "\n> Your code sums up to " << GuessSum << " and multiplies to " << GuessProduct << ".\n";

    // Verify if guesses are correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) // compound statement, code block
    {
        cout << "> Correct! Unlocking vault layer " << Difficulty <<  ".\n";
        return true;
    }
    else
    {
        Tries++;
        cout << "> Incorrect code. Attempt(s): " << Tries << ".\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // new random sequence based on time

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    int Tries;
    

    while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty, Tries); // a type can be initialized with a function that returns that same data type, saving a line of code
        cin.clear(); // Clears any error generated from cin
        cin.ignore(); // Ignores input buffer
        
        if (bLevelComplete)
        {
            ++LevelDifficulty;
            Tries = 0; // reset tries
        }
        else // condition for entering wrong code
        {
            Tries++;
        }
        
    }

    cout << "> Vault unlocked successfully!\n";

    return 0;
}