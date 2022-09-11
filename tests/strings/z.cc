#include <gtest/gtest.h>
#include "../pvl/strings/z.hpp"

TEST(ZAlgo, aaaaaa) {
    std::string s = "aaaaaa";
    int expected[] = {6, 5, 4, 3, 2, 1};
    std::vector<int> z = pvl::compute_z(s);
    int n = s.length();
    for (int i = 1; i < n; i++) {
        EXPECT_EQ(expected[i], z[i]);
    }
}

TEST(ZAlgo, aabaacd) {
    std::string s = "aabaacd";
    int expected[] = {7, 1, 0, 2, 1, 0, 0};
    std::vector<int> z = pvl::compute_z(s);
    int n = s.length();
    for (int i = 1; i < n; i++) {
        EXPECT_EQ(expected[i], z[i]);
    }
}

TEST(ZAlgo, abababab) {
    std::string s = "abababab";
    int expected[] = {8, 0, 6, 0, 4, 0, 2, 0};
    std::vector<int> z = pvl::compute_z(s);
    int n = s.length();
    for (int i = 1; i < n; i++) {
        EXPECT_EQ(expected[i], z[i]);
    }
}

TEST(ZAlgo, aab$baabaa) {
    std::string s = "aab$baabaa";
    int expected[] = {10, 1, 0, 0, 0, 3, 1, 0, 2, 1};
    std::vector<int> z = pvl::compute_z(s);
    int n = s.length();
    for (int i = 1; i < n; i++) {
        EXPECT_EQ(expected[i], z[i]);
    }
}
