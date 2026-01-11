#include <iostream>

/**
 * returns the number of you pass zero going from start to end
 * doesn't count if you land on zero
 * assumptions:
 * start is in range 0-99
 * end can be anything
 */
int times_passed_zero(int start, int end) {
  if (end < 0) {
    // we use (end + 1) because we want to ignore landing on 0.
    if (start == 0) {
      return -1 * (end + 1) / 100;
    } else {
      // we add 1 to the result because we also passed the 0 tick in the
      // current interval.
      return (-1 * (end + 1) / 100) + 1;
    }
  } else {
    // we use (end - 1) because landing on a multiple of 100
    // shouldn't count, but the 1-100 ticks after that should count.
    return (end - 1) / 100;
  }
}

int main() {
  char direction;
  int amount;
  int counter = 50;
  int answer = 0;

  while (std::cin >> direction >> amount) {
    std::cout << "beforecounter=" << counter << std::endl;
    std::cout << "direction=" << direction << std::endl;
    std::cout << "amount=" << amount << std::endl;
    int sign = direction == 'L' ? -1 : 1;
    int premod = counter + sign * amount;
    answer += times_passed_zero(counter, premod);
    // account for (potentially large) negative numbers
    // the result should be positive
    counter = ((premod % 100) + 100) % 100;
    if (counter == 0) {
      std::cout << "landed on 0\n";
      answer++;
    }
    std::cout << "aftercounter=" << counter << std::endl;
    std::cout << "answer=" << answer << std::endl;
    std::cout << "===" << std::endl;
  }
  std::cout << "answer=" << answer << std::endl;
}
