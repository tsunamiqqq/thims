#include <iostream>

int main()
{
  long long t_shirts = 12;
  long long pants = 6;
  long long socks = 8;
  long long shoes = 3;

  long long ways = t_shirts * pants * socks * shoes;

  std::cout << "Способів: " << ways << std::endl;
  return 0;
}
