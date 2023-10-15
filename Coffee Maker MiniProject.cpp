#include <iostream>

class CoffeeMaker {
private:
    int water;
    int milk;
    int coffee;

public:
    CoffeeMaker() : water(300), milk(200), coffee(100) {}

    void report() {
        std::cout << "Resources:" << std::endl;
        std::cout << "Water: " << water << "ml" << std::endl;
        std::cout << "Milk: " << milk << "ml" << std::endl;
        std::cout << "Coffee: " << coffee << "g" << std::endl;
    }

    bool isResourceSufficient(int waterNeeded, int milkNeeded, int coffeeNeeded) {
        if (water < waterNeeded) {
            std::cout << "Sorry, there is not enough water." << std::endl;
            return false;
        }
        if (milk < milkNeeded) {
            std::cout << "Sorry, there is not enough milk." << std::endl;
            return false;
        }
        if (coffee < coffeeNeeded) {
            std::cout << "Sorry, there is not enough coffee." << std::endl;
            return false;
        }
        return true;
    }

    void makeCoffee(int waterNeeded, int milkNeeded, int coffeeNeeded, const std::string& coffeeType) {
        if (isResourceSufficient(waterNeeded, milkNeeded, coffeeNeeded)) {
            water -= waterNeeded;
            milk -= milkNeeded;
            coffee -= coffeeNeeded;
            std::cout << "Here is your " << coffeeType << " ??. Enjoy!" << std::endl;
        }
    }

    void recipe(const std::string& coffeeType, int waterNeeded, int milkNeeded, int coffeeNeeded) {
        std::cout << "Recipe for " << coffeeType << ":" << std::endl;
        std::cout << "Water: " << waterNeeded << "ml" << std::endl;
        std::cout << "Milk: " << milkNeeded << "ml" << std::endl;
        std::cout << "Coffee: " << coffeeNeeded << "g" << std::endl;
    }
};

int main() {
    CoffeeMaker coffeeMaker;

    std::cout << "Coffee Maker Menu:" << std::endl;
    std::cout << "1. Espresso" << std::endl;
    std::cout << "2. Cappuccino" << std::endl;
    std::cout << "3. Report Resources" << std::endl;
    std::cout << "4. Exit" << std::endl;

    int choice;
    while (true) {
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                coffeeMaker.recipe("Espresso", 50, 0, 18);
                coffeeMaker.makeCoffee(50, 0, 18, "Espresso");
                break;
            case 2:
                coffeeMaker.recipe("Cappuccino", 100, 50, 15);
                coffeeMaker.makeCoffee(100, 50, 15, "Cappuccino");
                break;
            case 3:
                coffeeMaker.report();
                break;
            case 4:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option (1-4)." << std::endl;
                break;
        }
    }

    return 0;
}
