#include <iostream>

class Solution {
public:
  // Assumptions:
  //  - Arch: Little endian
  //  - OS: Windows
  //  - Compiler: g++ ( C++11 or later )
  //  - unsigned long long is 64
  int concatenatedBinary(int n) {
    // limitation
    const int mod = 1'000'000'007;
    if (n > mod)
      return -1;

    unsigned long long value = 0;
    int offset = 0;

    for (int i = 1; i <= n; i++) {

      // little endian oriented offset size for `i`
      offset = 0;
      int offset_val = i;

      while (offset_val > 0) {
        offset_val = offset_val >> 1;
        offset++;
      }

      // value is unsigned, no risk of overflowing
      value = ((value << offset) | i) % mod;
    }

    return value;
  }
};

int main() {
  Solution solution;
  std::cout << solution.concatenatedBinary(42);
  return 0;
}