#include <iostream>
#include <string>

int main() {
  std::string name, verb, noun, adjective;

  // Prompt the user for different types of words
  std::cout << "Enter a name: ";
  std::cin >> name;

  std::cout << "Enter a verb: ";
  std::cin >> verb;

  std::cout << "Enter a noun: ";
  std::cin >> noun;

  std::cout << "Enter an adjective: ";
  std::cin >> adjective;

  // Generate the funny story
  std::cout << "Once upon a time, " << name << " decided to " << verb << " a " << noun << "." << std::endl;
  std::cout << "Unfortunately, the " << noun << " was " << adjective << " and " << name << " ended up getting " << verb << "ed by the " << noun << " instead!" << std::endl;

  return 0;
}
