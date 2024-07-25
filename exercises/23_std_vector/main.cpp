#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value."); // The size of the vector is 5.
        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value."); // Size of the vector object itself, not the elements.
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // Compare the data in the vector.
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value."); // The size of the vector is 5.
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // Size of the vector object itself.
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // Compare the data in the vector.
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value."); // Size after adding one element.
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // Size of the vector object itself remains the same.
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value."); // Size after removing one element.
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // Size of the vector object itself remains the same.
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value."); // Check value at index 0.
            ASSERT(vec[1] == 2, "Fill in the correct value."); // Check value at index 1.
            ASSERT(vec[2] == 3, "Fill in the correct value."); // Check value at index 2.
            ASSERT(vec[3] == 4, "Fill in the correct value."); // Check value at index 3.
            ASSERT(vec[4] == 6, "Fill in the correct value."); // Check value at index 4.
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            vec.insert(vec.begin() + 1, 1.5); // Insert value 1.5 at index 1.
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 5}), "Make this assertion pass."); // Check if the vector is updated correctly.
            vec.erase(vec.begin() + 1); // Remove value at index 1.
            ASSERT((vec == std::vector<double>{1, 2, 3, 4, 5}), "Make this assertion pass."); // Check if the vector is updated correctly.
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == vec.size(), "Fill in the correct value."); // Capacity should be equal to size after shrinking.
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now."); // The vector should be empty.
            ASSERT(vec.size() == 0, "Fill in the correct value."); // Size should be 0 after clearing.
            ASSERT(vec.capacity() == 0, "Fill in the correct value."); // Capacity should also be 0 after clearing.
        }
    }
    {
        std::vector<char> vec(48, 'z'); // Initialize vector with 48 'z' characters.
        ASSERT(vec[0] == 'z', "Make this assertion pass."); // Check first element.
        ASSERT(vec[47] == 'z', "Make this assertion pass."); // Check last element.
        ASSERT(vec.size() == 48, "Make this assertion pass."); // Size of the vector.
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value."); // Size of the vector object itself.
        {
            auto capacity = vec.capacity();
            vec.resize(16); // Resize to 16, should reduce size but not affect capacity.
            ASSERT(vec.size() == 16, "Fill in the correct value."); // New size of the vector.
            ASSERT(vec.capacity() == capacity, "Fill in the correct value."); // Capacity should be unchanged.
        }
        {
            vec.reserve(256); // Increase capacity to 256.
            ASSERT(vec.size() == 16, "Fill in the correct value."); // Size should remain 16.
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // Capacity should be 256.
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value."); // Size should be 20 after adding 4 characters.
            ASSERT(vec.capacity() >= 256, "Fill in the correct value."); // Capacity should be at least 256.
            ASSERT(vec[15] == 'z', "Fill in the correct value."); // Check the element at index 15.
            ASSERT(vec[16] == 'a', "Fill in the correct value."); // Check the element at index 16.
            ASSERT(vec[17] == 'b', "Fill in the correct value."); // Check the element at index 17.
            ASSERT(vec[18] == 'c', "Fill in the correct value."); // Check the element at index 18.
            ASSERT(vec[19] == 'd', "Fill in the correct value."); // Check the element at index 19.
        }
    }

    return 0;
}
