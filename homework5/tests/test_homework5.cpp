#include <gtest/gtest.h>
#include "../homework5.cpp"

TEST(FailingTest, FailingTest) {
    Time t(0, 0, 0);
    ASSERT_EQ(t.GetHours(), 1);

    t = Time(23, 0, 0);
    EXPECT_EQ(t.GetHours(), 21);
}

TEST(TimeConstructors, DefConstructor) {
    Time t;
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeConstructors, InitConstructor) {
    Time t(1, 2, 3);
    EXPECT_EQ(t.GetHours(), 1);
    EXPECT_EQ(t.GetMinutes(), 2);
    EXPECT_EQ(t.GetSeconds(), 3);
}

TEST(TimeConstructors, CopyConstructor1) {
    Time t1(1, 2, 3);
    Time t2(t1);
    EXPECT_EQ(t2.GetHours(), 1);
    EXPECT_EQ(t2.GetMinutes(), 2);
    EXPECT_EQ(t2.GetSeconds(), 3);
}

TEST(TimeConstructors, CopyConstructor2) {
    Time t3(-4, 5, 6);
    Time t4(t3);
    EXPECT_EQ(t4.GetHours(), -4);
    EXPECT_EQ(t4.GetMinutes(), 5);
    EXPECT_EQ(t4.GetSeconds(), 6);
}

TEST(TimeOperators, AssignmentOperator1) {
    Time t1(1, 2, 3);
    Time t2;
    t2 = t1;
    EXPECT_EQ(t2.GetHours(), 1);
    EXPECT_EQ(t2.GetMinutes(), 2);
    EXPECT_EQ(t2.GetSeconds(), 3);
}

TEST(TimeOperators, AssignmentOperator2) {
    Time t3(4, 5, 6);
    Time t2 = t3;
    EXPECT_EQ(t2.GetHours(), 4);
    EXPECT_EQ(t2.GetMinutes(), 5);
    EXPECT_EQ(t2.GetSeconds(), 6);
}


TEST(TimeOperators, AdditionOperator) {
    Time t(0, 0, 0);
    t += 60;
    t.Normalize();
    EXPECT_EQ(t.GetMinutes(), 1);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeOperators, AdditionOperatorWithBigNumber) {
    Time t(0, 0, 0);
    t += 86460;
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 1);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeOperators, SubtractionOperator) {
    Time t(0, 1, 0);
    t -= 60;
    t.Normalize();
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);

    t = Time(1, 0, 0);
    t -= 3600;
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);

    t = Time(1, 1, 1);
    t -= 3661;
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeOperators, SubtractionOperatorWithBigNumber) {
    Time t(1, 1, 1);
    t -= 3661;
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeToSeconds, ToSeconds3661) {
    Time t(1, 1, 1);
    EXPECT_EQ(t.ToSeconds(), 3661);
}

TEST(TimeToSeconds, ToSeconds1) {
    Time t(0, 0, 1);
    EXPECT_EQ(t.ToSeconds(), 1);
}

TEST(TimeToSeconds, ToSeconds60) {
    Time t(0, 1, 0);
    EXPECT_EQ(t.ToSeconds(), 60);
}

TEST(TimeToSeconds, ToSeconds3600) {
    Time t(1, 0, 0);
    EXPECT_EQ(t.ToSeconds(), 3600);
}

TEST(TimeNormalize, NormalizeSeconds) {
    Time t(0, 0, 60);
    t.Normalize();
    EXPECT_EQ(t.GetMinutes(), 1);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeNormalize, NormalizeMinutes) {
    Time t(0, 60, 0);
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 1);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeNormalize, NormalizeHours) {
    Time t(24, 0, 0);
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 0);
    EXPECT_EQ(t.GetMinutes(), 0);
    EXPECT_EQ(t.GetSeconds(), 0);
}

TEST(TimeNormalize, NormalizeHMS) {
    Time t(24, 60, 60);
    t.Normalize();
    EXPECT_EQ(t.GetHours(), 1);
    EXPECT_EQ(t.GetMinutes(), 1);
    EXPECT_EQ(t.GetSeconds(), 0);
}

// при отправке прокоментировать изменения