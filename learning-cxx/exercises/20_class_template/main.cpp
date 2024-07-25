﻿

// READ: 类模板 <https://zh.cppreference.com/w/cpp/language/class_template>
#include "../exercise.h"
#include <cstring>
#include <stdexcept>

template<class T>
struct Tensor4D {
    unsigned int shape[4];
    T *data;

    Tensor4D(unsigned int const shape_[4], T const *data_) {
        std::memcpy(shape, shape_, 4 * sizeof(unsigned int));
        unsigned int size = 1;
        for (int i = 0; i < 4; ++i) {
            size *= shape[i];
        }
        data = new T[size];
        std::memcpy(data, data_, size * sizeof(T));
    }

    ~Tensor4D() {
        delete[] data;
    }

    // 禁止复制和移动
    Tensor4D(Tensor4D const &) = delete;
    Tensor4D(Tensor4D &&) noexcept = default;

    Tensor4D &operator+=(Tensor4D const &others) {
        // Check if shapes are compatible for broadcasting
        for (int i = 0; i < 4; ++i) {
            if (shape[i] != others.shape[i] && others.shape[i] != 1) {
                throw std::runtime_error("Shapes are not compatible for broadcasting.");
            }
        }

        unsigned int size_this = 1;
        unsigned int size_others = 1;

        for (int i = 0; i < 4; ++i) {
            size_this *= shape[i];
            size_others *= others.shape[i];
        }

        // Perform broadcasting and addition
        for (unsigned int i = 0; i < size_this; ++i) {
            unsigned int idx_this[4];
            unsigned int idx_others[4];
            unsigned int temp = i;

            for (int j = 0; j < 4; ++j) {
                idx_this[j] = temp / (shape[j] == 0 ? 1 : shape[j]);
                temp %= (shape[j] == 0 ? 1 : shape[j]);
                idx_others[j] = (others.shape[j] == 1) ? 0 : idx_this[j];
            }

            unsigned int index_others = 0;
            unsigned int stride_others[4] = {1, 1, 1, 1};
            for (int j = 2; j >= 0; --j) {
                stride_others[j] = stride_others[j + 1] * others.shape[j + 1];
            }

            for (int j = 0; j < 4; ++j) {
                index_others += idx_others[j] * stride_others[j];
            }

            data[i] += others.data[index_others];
        }

        return *this;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{1, 2, 3, 4};
        // clang-format off
        int data[]{
                1,  2,  3,  4,
                5,  6,  7,  8,
                9, 10, 11, 12,

                13, 14, 15, 16,
                17, 18, 19, 20,
                21, 22, 23, 24};
        // clang-format on
        auto t0 = Tensor4D<int>(shape, data);
        auto t1 = Tensor4D<int>(shape, data);
        t0 += t1;
        for (auto i = 0u; i < sizeof(data) / sizeof(*data); ++i) {
            ASSERT(t0.data[i] == data[i] * 2, "Tensor doubled by plus its self.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        float d0[]{
                1, 1, 1, 1,
                2, 2, 2, 2,
                3, 3, 3, 3,

                4, 4, 4, 4,
                5, 5, 5, 5,
                6, 6, 6, 6};
        // clang-format on
        unsigned int s1[]{1, 2, 3, 1};
        // clang-format off
        float d1[]{
                6,
                5,
                4,

                3,
                2,
                1};
        // clang-format on

        auto t0 = Tensor4D<float>(s0, d0);
        auto t1 = Tensor4D<float>(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == 7.f, "Every element of t0 should be 7 after adding t1 to it.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        double d0[]{
                1,  2,  3,  4,
                5,  6,  7,  8,
                9, 10, 11, 12,

                13, 14, 15, 16,
                17, 18, 19, 20,
                21, 22, 23, 24};
        // clang-format on
        unsigned int s1[]{1, 1, 1, 1};
        double d1[]{1};

        auto t0 = Tensor4D<double>(s0, d0);
        auto t1 = Tensor4D<double>(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == d0[i] + 1, "Every element of t0 should be incremented by 1 after adding t1 to it.");
        }
    }
}
