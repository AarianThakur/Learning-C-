#include <iostream>
#include <string>

class CoffeeMaker {
private:
    int water;
    int milk;
    int coffee;

public:
    CoffeeMaker() : water(300), milk(200), coffee(100) {}

    bool operator>>(const std::string& coffeeType) {
        if (coffeeType == "Espresso") {
            return makeCoffee(50, 0, 18, coffeeType);
        } else if (coffeeType == "Cappuccino") {
            return makeCoffee(100, 50, 15, coffeeType);
        } else {
            std::cout << "Invalid coffee type: " << coffeeType << std::endl;
            return false;
        }
    }

    bool makeCoffee(int waterNeeded, int milkNeeded, int coffeeNeeded, const std::string& coffeeType) {
        if (isResourceSufficient(waterNeeded, milkNeeded, coffeeNeeded)) {
            water -= waterNeeded;
            milk -= milkNeeded;
            coffee -= coffeeNeeded;
            std::cout << "Here is your " << coffeeType << " ??. Enjoy!" << std::endl;
            return true;
        }
        return false;
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

    friend std::ostream& operator<<(std::ostream& os, const CoffeeMaker& coffeeMaker);
};

std::ostream& operator<<(std::ostream& os, const CoffeeMaker& coffeeMaker) {
    os << "Resources:" << std::endl;
    os << "Water: " << coffeeMaker.water << "ml" << std::endl;
    os << "Milk: " << coffeeMaker.milk << "ml" << std::endl;
    os << "Coffee: " << coffeeMaker.coffee << "g" << std::endl;
    return os;
}

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
                if (coffeeMaker >> "Espresso") {
                    std::cout << coffeeMaker;
                }
                break;
            case 2:
                if (coffeeMaker >> "Cappuccino") {
                    std::cout << coffeeMaker;
                }
                break;
            case 3:
                std::cout << coffeeMaker;
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
