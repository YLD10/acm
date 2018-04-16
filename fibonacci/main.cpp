#include <iostream>
#include <limits>

int main()
{
  int n = 0;
  while (std::cin >> n) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    unsigned long long nex = 0, pre = 0, cur = 1; // »Á 1 2 3 ... , ‘Ú cur = 3, pre = 1, nex = 2
    for (int i=1; i <= n-1; ++ i) {
      pre = nex;
      nex = cur;
      if (i == 2) {
        pre = 1;
        nex = 1;
      }
      cur = nex + pre;
    }
    std::cout << cur << '\n';
  }
  return 0;
}
