#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Checks.hpp"
#include "Clearer.hpp"
#include "Randomiser.hpp"
#include "Words.hpp"

int main() {
    while (true) {
        clearTerminal();
        bool correct = false;
        int attempts = 0;
        int maxAttempts;
        
        int gameChoice;
        std::cout << "Which game do you want to play?\n";
        std::cout << "1) Wordle\n";
        std::cout << "2) Nurdle\n";
        std::cout << "Enter 1 for Wordle, 2 for Nurdle: ";
        std::cin >> gameChoice;
        std::cout << '\n';
        
        while (gameChoice != 1 && gameChoice != 2) {
            std::cout << "Invalid input!\n";
            std::cout << "Enter 1 for Wordle, 2 for Nurdle: ";
            std::cin >> gameChoice;
        }
        
        if (gameChoice == 1) {
            std::string guessWord;
            std::string answerWord = words[random(0, 230)];
            maxAttempts = static_cast<int>(answerWord.length() + 1);
            std::vector<char> answerVector(answerWord.begin(), answerWord.end());
            int answerCounter[26] = {0};
            for (char character : answerWord) {
                answerCounter[character - 'a']++;
            }
            
            std::cout << "Welcome to Legally Distinct Wordle! Unlike original Wordle,  the length of the word you have to guess is varibale so you will be given one more attempt than the length of the word to guess it. For example, if the answers is six letters long, you'll be given seven attempts to guess it.\n";
            std::cout << "You have " << maxAttempts << " attempts to guess the " << answerWord.length() << " letter word.\n";
            std::cout << "If a letter is cyan, like this: (" << "\033[1;36m" << "a" << "\033[0m" << "), that means the letter is correct and in the right position.\n";
            std::cout << "If a letter is yellow, like this: (" << "\033[1;33m" << "b" << "\033[0m" << "), that means the letter is in the answer but it's in the wrong position.\n";
            std::cout << "If a letter has no special colour, like this: (c), that means you've guessed the character more times than it appears in the answer (if the letter appears in your guess more than once and it shows as blue or yellow earlier) or it doesn't appear in the answer at all.\n";
            std::cout << "Psst, for debugging purposes, the answer is " << answerWord << ".\n";
            
            while (attempts < maxAttempts && !correct){
                std::cout << "Enter a word: ";
                std::cin >> guessWord;
                
                if (std::cin.fail() || !isAlphabetic(guessWord)) {
                    std::cerr << "Invalid input!\n";
                    continue;
                }
                if (guessWord.length() != answerWord.length()) {
                    std::cerr << "Your guess does not match the length of the answer!\n";
                    std::cout << "The answer is " << answerWord.length() << " letters long.\n";
                    continue;
                }
                
                int guessCounter[26] = {0};
                
                std::transform(guessWord.begin(), guessWord.end(), guessWord.begin(), ::tolower);
                std::vector<char> guessVector(guessWord.begin(), guessWord.end());
                
                for (size_t counter = 0; counter < guessWord.length(); counter++) {
                    int characterIndex = guessWord[counter] - 'a';
                    
                    if (guessWord[counter] == answerWord[counter]) {
                        std::cout << "\033[1;36m" << guessWord[counter] << "\033[0m";
                        guessCounter[characterIndex]++;
                    }
                    else if (answerWord.find(guessWord[counter]) != std::string::npos) {
                        if (guessCounter[characterIndex] < answerCounter[characterIndex]) {
                            std::cout << "\033[1;33m" << guessWord[counter] << "\033[0m";
                            guessCounter[characterIndex]++;
                        }
                        else {
                            std::cout << guessWord[counter];
                        }
                    }
                    else {
                        std::cout << guessWord[counter];
                    }
                }
                std::cout << '\n';
                attempts++;
                if (guessWord == answerWord) {
                    correct = !correct;
                }
            }
            if (attempts == maxAttempts){
                std::cout << "You've run out of attempts! The correct word was " << answerWord << ".\n";
            }
            if (correct) {
                std::cout << "You've guessed correctly!";
            }
        }
            
        std::cout << '\n';
        std::cout << "Play again? (y/n): ";
        char playerStartChoice;
        std::cin >> playerStartChoice;
        if (playerStartChoice == 'y') {
            continue;
        }
        else if (playerStartChoice == 'n') {
            break;
        }
        else {
            std::cout << "Invalid input!\n";
            std::cout << "Play again? (y/n): ";
            std::cin >> playerStartChoice;
        }
    }
}
