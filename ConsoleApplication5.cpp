#include <iostream>
#include <fstream>   // ifstream, ofstream
#include <iomanip>   // std::hex, std::dec

int main() {
    // 1) Створюємо вихідний файл для запису
    std::ofstream outFile("data.txt"); // можна вказати будь-яку назву

    if (!outFile.is_open()) {
        std::cerr << "Cannot open file for writing!\n";
        return 1;
    }

    int number = 100;

    // 2) Записуємо число 100 в десятковій та шістнадцятковій системах
    // Наприклад: "100 64"
    outFile << std::dec << number << ' '   // десяткове подання
        << std::hex << number;         // шістнадцяткове подання

    // 3) Закриваємо файл
    outFile.close();

    // 4) Відкриваємо файл як вхідний для читання
    std::ifstream inFile("data.txt");
    if (!inFile.is_open()) {
        std::cerr << "Cannot open file for reading!\n";
        return 1;
    }

    int decValue = 0;
    int hexValue = 0;

    // 5) Зчитуємо: перше число як десяткове, друге як шістнадцяткове
    inFile >> std::dec >> decValue;   // читаємо десяткове
    inFile >> std::hex >> hexValue;   // читаємо шістнадцяткове

    inFile.close();

    // Виводимо на екран (повертаємося до десяткової системи)
    std::cout << "Decimal value: " << std::dec << decValue << '\n';
    std::cout << "Hex value (as decimal): " << std::dec << hexValue << '\n';

    // Якщо хочемо показати шістнадцяткове подання на екран:
    std::cout << "Hex value (printed in hex): " << std::hex << hexValue << '\n';

    return 0;
}
