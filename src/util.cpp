#include <string>

std::string repeatString(std::string str, int amount) {
    std::string newStr = "";

    for(int i = 0; i < amount; i++) {
        newStr += str;
    }

    return newStr;
}