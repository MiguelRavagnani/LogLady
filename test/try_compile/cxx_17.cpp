#include<string_view>

constexpr int value() {
  return 0x42;
}

int main() {
  std::string_view string_view_variable{"string_view_variable"};
  return value();
}