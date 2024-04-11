#include "pch.h"
#include "source.cpp"
#include <string>
TEST(q1, T1) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(5, 10);
    string org = "5-1 -> 6-1 -> 7-1 -> 8-1 -> 9-1 -> 10-1";
    EXPECT_EQ(result, org);
}
TEST(q1, T2) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(10, 5);
    string org = "10-1 -> 9-1 -> 8-1 -> 7-1 -> 6-1 -> 5-1";
    EXPECT_EQ(result, org);
}
TEST(q1, T3) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1T3.txt");
    string result = obj.GetPath(3, 11);
    string org = "3-1 -> 2-1 -> 2-2 -> 2-3 -> 3-3 -> 4-3 -> 5-3 -> 6-3 -> 7-3 -> 7-2 -> 7-1 -> 8-1 -> 8-2 -> 8-3 -> 9-3 -> 10-3 -> 11-3";
    EXPECT_EQ(result, org);
}

TEST(q1, T4) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(1, 23);
    string org = "1-1 -> 2-1 -> 2-2 -> 3-2 -> 4-2 -> 4-3 -> 5-3 -> 6-3 -> 6-2 -> 7-2 -> 7-1 -> 8-1 -> 9-1 -> 9-2 -> 9-3 -> 10-3 -> 11-3 -> 12-3 -> 12-2 -> 13-2 -> 14-2 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 19-2 -> 19-1 -> 20-1 -> 21-1 -> 22-1 -> 23-1";
    EXPECT_EQ(result, org);
}
TEST(q1, T5) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(1, 24);
    string org = "1-1 -> 2-1 -> 2-2 -> 3-2 -> 4-2 -> 4-3 -> 5-3 -> 6-3 -> 6-2 -> 7-2 -> 7-1 -> 8-1 -> 9-1 -> 9-2 -> 9-3 -> 10-3 -> 11-3 -> 12-3 -> 12-2 -> 13-2 -> 14-2 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 20-3 -> 21-3 -> 22-3 -> 23-3 -> 24-3";
    EXPECT_EQ(result, org);
}
TEST(q1, T6) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(16, 14);
    string org = "16-1 -> 17-1 -> 18-1 -> 19-1 -> 19-2 -> 19-3 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3";
    EXPECT_EQ(result, org);
}
TEST(q1, T7) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(11, 16);
    string org = "11-1 -> 10-1 -> 9-1 -> 9-2 -> 9-3 -> 10-3 -> 11-3 -> 12-3 -> 12-2 -> 13-2 -> 14-2 -> 14-3 -> 15-3 -> 16-3";
    EXPECT_EQ(result, org);
}
TEST(q1, T8) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(28, 14);
    string org = "28-2 -> 27-2 -> 26-2 -> 25-2 -> 24-2 -> 24-3 -> 23-3 -> 22-3 -> 21-3 -> 20-3 -> 19-3 -> 18-3 -> 17-3 -> 16-3 -> 15-3 -> 14-3";
    EXPECT_EQ(result, org);
}
TEST(q1, T9) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(14, 28);
    string org = "14-2 -> 14-3 -> 15-3 -> 16-3 -> 17-3 -> 18-3 -> 19-3 -> 20-3 -> 21-3 -> 22-3 -> 23-3 -> 24-3 -> 24-2 -> 25-2 -> 26-2 -> 27-2 -> 28-2";
    EXPECT_EQ(result, org);
}
TEST(q1, T10) {
    Transport_Layer_optimization obj;
    obj.ReadFile("Q1EVAL.txt");
    string result = obj.GetPath(11, 14);
    string org = "11-1 -> 10-1 -> 9-1 -> 9-2 -> 9-3 -> 10-3 -> 11-3 -> 12-3 -> 12-2 -> 13-2 -> 14-2";
    EXPECT_EQ(result, org);
}

TEST(q2, t1) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(58, obj.GetMinCost(1, 16));
}
TEST(q2, t2) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(49, obj.GetMinCost(19, 6));
}
TEST(q2, t3) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2T2.txt");
    EXPECT_EQ(58, obj.GetMinCost(4, 20));
}
TEST(q2, t4) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(34117, obj.GetMinCost(23, 11));
}
TEST(q2, t5) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(50396, obj.GetMinCost(1, 16));
}
TEST(q2, t6) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(79148, obj.GetMinCost(26, 3));
}TEST(q2, t7) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(22743, obj.GetMinCost(8, 13));
}TEST(q2, t8) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(1526, obj.GetMinCost(16, 15));
}TEST(q2, t9) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(71197, obj.GetMinCost(5, 26));
}TEST(q2, t10) {
    Transport_Cost_Calculator obj;
    obj.ReadFile("Q2Eval.txt");
    EXPECT_EQ(39645, obj.GetMinCost(25, 11));

}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}