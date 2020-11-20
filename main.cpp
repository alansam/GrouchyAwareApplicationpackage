//
//  digits.cpp
//  CF.StringsOfDigits
//
//  Created by Alan Sampson on 11/19/20.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std::literals::string_literals;

/// MARK: - Definitions.
enum base {
  BIN =  2, OCT =  8, DEC = 10, HEX = 16,
};

/// MARK: Template function display
template<class C_>
void display(C_ const & samples) {
  std::cout << "  function: "s << __func__ << std::endl;

  for (auto item : samples) {
    auto const base = item.first;
    auto const value = item.second.c_str();
    char * end;
    auto number = std::strtoull(value, &end, base);
    std::ostringstream oss;
    oss << "["s << std::dec << std::setw(2) << base
        << ", "s << std::setw(24) << std::left << value << "]: "s
        << std::internal
        << std::oct << std::setw(10) << number
        << std::dec << std::setw(10) << number
        << std::hex << std::setw(10) << number;

    std::cout << oss.str() << std::endl;
  }
  std::cout << std::endl;

  return;
}

/// MARK: - Implementation
/// MARK: main()
int main(int argc, const char * argv[]) {
  std::list<std::pair<base, std::string>> const samples {
    { DEC, "16"s, },
    { HEX, "0xff545c"s },
    { BIN, "111111110101010001011100"s, },
    { OCT, "7777"s },
  };

  // .................................................................
  std::cout << "template function call"s << std::endl;
  display<std::list<std::pair<base, std::string>>>(samples);

  // .................................................................
  /// MARK: lambda function to convert and report strings of numbers to numerics
  auto fn = [](auto item) {
    auto const base = item.first;
    auto const value = item.second.c_str();
    char * end;
    auto number = std::strtoull(value, &end, base);
    std::ostringstream oss;
    oss << "["s << std::dec << std::setw(2) << base
        << ", "s << std::setw(24) << std::left << value << "]: "s
        << std::internal
        << std::oct << std::setw(10) << number
        << std::dec << std::setw(10) << number
        << std::hex << std::setw(10) << number;

    std::cout << oss.str() << std::endl;
  };

  std::list<uint64_t> longs(samples.size());
  std::list<std::string> results(samples.size());

  // .................................................................
  std::cout << "range-based for loop"s << std::endl;
  {
    for (auto item : samples) {
      fn(item);
    }
  }
  std::cout << std::endl;

  // .................................................................
  std::cout << "std::for_each"s << std::endl;
  {
    std::for_each(samples.begin(), samples.end(), fn);
  }
  std::cout << std::endl;

  return 0;
}
