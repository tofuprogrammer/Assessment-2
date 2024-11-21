#pragma once

bool isAlphabetic(const std::string& input) {
    for (char c : input) {
        if (!isalpha(c)) {
            return false;  // If any character is not in the alphabet, return false
        }
    }
    return true;  // All characters in the user's input are in the alphabet
}
