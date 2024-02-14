#include <iostream>
#include <string>
#include <cmath>

void binary_to_decimal() {
    std::string binary;
    int count = 0, result = 0, binary_size;

    while (true) {
        std::cout << "type a binary number >> ";
        std::cin >> binary;

        binary_size = binary.length();

        if (binary_size != 4 && binary_size != 8) {
            continue;
        }
        break;
    }

    for (int i = binary_size - 1; i >= 0; --i) {
        result += (binary[i] - '0') * (pow(2, count));
        count++;
    }
    std::cout << result;

    std::cout << "\npress enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void text_to_binary() {
    std::string text;

    std::cout << "type a text: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    std::string binary;

    int count = 0;

    for (char c : text) {
        for (int i = 7; i >= 0; --i) {
            binary.push_back(((c >> i) & 1) + '0');
            count++;

            if (count % 8 == 0) {
                binary.push_back(' '); 
            }
        }
    }

    std::cout << binary << std::endl;

    std::cout << "press enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void text_to_ascii() {
    std::string text;

    std::cout << "type a text: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    for(char c : text) {
        std::cout << static_cast<int>(c) << ' ';
    }

    std::cout << "\npress enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    int choice;

    while (true) {
        std::cout << "1 - binary to dec (4 or 8 bits)\n2 - text to binary\n3 - text to ascii\n";
        std::cout << ">> ";
        std::cin >> choice;

        if (choice < 0 || choice > 3) {
            continue;
        }
        break;
    }

    switch (choice) {
        case 1:
            binary_to_decimal();
            break;
        case 2:
            text_to_binary();
            break;
        case 3:
            text_to_ascii();
            break;
        default:
            std::cout << "invalid\n";
            break;
    }

    return 0;
}
