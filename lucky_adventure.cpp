#include <iostream>
#include <cstdlib>
#include <ctime>

int randomStep() {
    return std::rand() % 6 + 1;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int score = 0;

    std::cout << "=== Lucky Path ===\n";

    for (int round = 1; round <= 5; round++) {
        std::cout << "\nRound " << round << "\n";
        std::cout << "Press Enter to roll...";
        std::cin.ignore(round == 1 ? 0 : 1);

        int value = randomStep();
        std::cout << "You rolled: " << value << "\n";

        if (value >= 4) {
            score += value;
            std::cout << "Points gained!\n";
        } else {
            score -= 1;
            std::cout << "Small penalty.\n";
        }

        std::cout << "Current score: " << score << "\n";
    }

    std::cout << "\nFinal score: " << score << "\n";

    if (score >= 15)
        std::cout << "Excellent run!\n";
    else if (score >= 8)
        std::cout << "Nice effort!\n";
    else
        std::cout << "Try again!\n";

    return 0;
}
