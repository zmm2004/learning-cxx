#include <exercise.h>

int main(int argc, char **argv) {
    using namespace std::string_literals;

    auto hello = "Hello"s;   // This is std::string type
    auto world = "world";    // This is const char[6] type

    // Use std::is_same with ::value
    ASSERT((std::is_same<std::decay<decltype(hello)>::type, std::string>::value), "Fill in the missing type.");
    ASSERT((std::is_same<std::decay<decltype(world)>::type, const char[6]>::value), "Fill in the missing type.");

    // Replacing the `?` with the correct string
    ASSERT(hello + ", " + world + '!' == "Hello, world!", "Fill in the missing string.");

    return 0;
}
