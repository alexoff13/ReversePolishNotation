#include <string>
#include "gtest/gtest.h"
#include "libRPN.h"

using namespace std;

TEST(libRPN,SimpleTest){
    string line="2+3^4+(48*4)";
    vector<string> IPE = transfer(line);
    double res = solution(IPE);
    ASSERT_EQ(res,275);
}

TEST(libRPN,TestDivusion){
    string line="(223+321)/32";
    vector<string> IPE = transfer(line);
    double res = solution(IPE);
    ASSERT_EQ(res,17);
}

TEST(libRPN,TestMultiply){
    string line="1235*212*(21-12)";
    vector<string> IPE = transfer(line);
    double res = solution(IPE);
    ASSERT_EQ(res,2356380);
}

TEST(libRPN,TestPower){
    string line="2^3+5^(2+24-20)";
    vector<string> IPE = transfer(line);
    double res = solution(IPE);
    ASSERT_EQ(res,15633);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}