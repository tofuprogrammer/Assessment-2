#pragma once

bool isAlphabetic(const std::string& input) {
    for (char c : input) {
        if (!isalpha(c)) {
            return false;  // If any character is not alphabetic, return false
        }
    }
    return true;  // All characters are alphabetic
}
