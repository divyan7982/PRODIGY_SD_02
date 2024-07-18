#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

void playNumberGuessingGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed the random number generator
    int number_to_guess = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int max_attempts = 10;

    std::cout << "Welcome to the Number Guessing Game! Try to guess the number I'm thinking of between 1 and 100." << std::endl;

    while (attempts < max_attempts) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (std::cin.fail() || guess < 1 || guess > 100) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Please enter a valid number between 1 and 100." << std::endl;
            continue;
        }

        attempts++;

        if (guess > number_to_guess) {
            std::cout << "Your guess is too high! Try again." << std::endl;
        } else if (guess < number_to_guess) {
            std::cout << "Your guess is too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number in " << attempts << " attempts!" << std::endl;
            break;
        }
    }

    if (attempts == max_attempts) {
        std::cout << "Sorry, you've reached the maximum number of attempts. The correct number was " << number_to_guess << "." << std::endl;
    }
}

int main() {
    char play_again;
    do {
        playNumberGuessingGame();
        std::cout << "Would you like to play again? (yes/no): ";
        std::string response;
        std::cin >> response;
        play_again = response[0];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
    } while (play_again == 'y' || play_again == 'Y');

    std::cout << "Thank you for playing! Goodbye!" << std::endl;
    return 0;
}
