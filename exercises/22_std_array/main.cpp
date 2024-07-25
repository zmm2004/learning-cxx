#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == 5, "Fill in the correct value."); // The size of the array is 5.
        ASSERT(sizeof(arr) == sizeof(int) * 5, "Fill in the correct value."); // Total size is size of int (4 bytes) times 5.
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(arr)) == 0, "Fill in the correct values."); // Compare the data in the array.
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value."); // The size of the array is 8.
        ASSERT(sizeof(arr) == sizeof(double) * 8, "Fill in the correct value."); // Total size is size of double (8 bytes) times 8.
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value."); // The size of the array is 21.
        ASSERT(sizeof(arr) == 21, "Fill in the correct value."); // Total size is exactly 21 bytes.
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value."); // Compare the C-string with the array.
    }
    return 0;
}
