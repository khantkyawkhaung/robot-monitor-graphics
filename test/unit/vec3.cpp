#include <rmg/math/vec.hpp>
#include <gtest/gtest.h>


TEST(Vec3ConstructorTest, works) {
    rmg::Vec3 v1 = rmg::Vec3();
    ASSERT_EQ(0, v1.x);
    ASSERT_EQ(0, v1.y);
    ASSERT_EQ(0, v1.z);
    
    rmg::Vec3 v2 = rmg::Vec3(-6.35f, 17.467f, 0.532f);
    ASSERT_EQ(-6.350f, v2.x);
    ASSERT_EQ(17.467f, v2.y);
    ASSERT_EQ( 0.532f, v2.z);
    
    rmg::Vec2 a = {9.505f, -6.332f};
    rmg::Vec3 b = rmg::Vec3(a, 8.231f);
    ASSERT_EQ( 9.505f, b.x);
    ASSERT_EQ(-6.332f, b.y);
    ASSERT_EQ( 8.231f, b.z);
}




TEST(Vec3MagnitudeTest, works) {
    rmg::Vec3 v = {19.095f, -10.553f, 4.451f};
    EXPECT_NEAR(22.2665f, v.magnitude(), 0.0001f);
}


TEST(Vec3NormalizeTest, works) {
    rmg::Vec3 v = {-43.764f, 30.401f, 17.664f};
    rmg::Vec3 n = v.normalize();
    EXPECT_NEAR(-0.7796f, n.x, 0.0001f);
    EXPECT_NEAR( 0.5415f, n.y, 0.0001f);
    EXPECT_NEAR( 0.3147f, n.z, 0.0001f);
}


TEST(Vec3SummationTest, works) {
    rmg::Vec3 a = { 3.245f,  22.5031f, -9.3249f};
    rmg::Vec3 b = {14.3375f, -7.523f,  10.9544f};
    rmg::Vec3 c = a + b;
    EXPECT_NEAR(17.5825f, c.x, 0.0001f);
    EXPECT_NEAR(14.9801f, c.y, 0.0001f);
    EXPECT_NEAR( 1.6295f, c.z, 0.0001f);
}


TEST(Vec3SubtractionTest, works) {
    rmg::Vec3 a = {16.3569f, -8.7431f, 12.435f};
    rmg::Vec3 b = { 7.0503f, -6.446f,  -3.2565f};
    rmg::Vec3 c = a - b;
    EXPECT_NEAR( 9.3066f, c.x, 0.0001f);
    EXPECT_NEAR(-2.2971f, c.y, 0.0001f);
    EXPECT_NEAR(15.6915f, c.z, 0.0001f);
}


TEST(Vec3MultiplicationTest, works) {
    rmg::Vec3 a = {16.1159f, 8.8122f, -4.5105f};
    rmg::Vec3 b;
    b = a * 6.3211f;
    EXPECT_NEAR(101.8702f, b.x, 0.0001f);
    EXPECT_NEAR( 55.7028f, b.y, 0.0001f);
    EXPECT_NEAR(-28.5113f, b.z, 0.0001f);
    b = 6.3211f * a;
    EXPECT_NEAR(101.8702f, b.x, 0.0001f);
    EXPECT_NEAR( 55.7028f, b.y, 0.0001f);
    EXPECT_NEAR(-28.5113f, b.z, 0.0001f);
}


TEST(Vec3DivisionTest, works) {
    rmg::Vec3 a = {-30.5651f, 117.3502f, 43.0063f};
    rmg::Vec3 b;
    b = a / 12.103f;
    EXPECT_NEAR(-2.5254f, b.x, 0.0001f);
    EXPECT_NEAR( 9.6960f, b.y, 0.0001f);
    EXPECT_NEAR( 3.5534f, b.z, 0.0001f);
}


TEST(Vec3DotTest, works) {
    rmg::Vec3 a = {  4.567f, 7.536f, -10.230f};
    rmg::Vec3 b = {-12.090f, 8.446f,  -8.112f};
    EXPECT_NEAR(91.4198f, rmg::Vec3::dot(a, b), 0.0001f);
}


TEST(Vec3CrossTest, works) {
    rmg::Vec3 a = {  4.567f, 7.536f, -10.230f};
    rmg::Vec3 b = {-12.090f, 8.446f,  -8.112f};
    rmg::Vec3 c;
    c = rmg::Vec3::cross(a, b);
    EXPECT_NEAR( 25.2705f, c.x, 0.0001f);
    EXPECT_NEAR(160.7282f, c.y, 0.0001f);
    EXPECT_NEAR(129.6831f, c.z, 0.0001f);
    c = a * b;
    EXPECT_NEAR( 25.2705f, c.x, 0.0001f);
    EXPECT_NEAR(160.7282f, c.y, 0.0001f);
    EXPECT_NEAR(129.6831f, c.z, 0.0001f);
}




TEST(Vec3ConvertionTest, toVec2) {
    rmg::Vec3 a = {14.345f, 6.4344f, -9.7701f};
    rmg::Vec2 b = (rmg::Vec2) a;
    EXPECT_NEAR(14.3450f, b.x, 0.0001f);
    EXPECT_NEAR( 6.4344f, b.y, 0.0001f);
}

TEST(Vec3ConvertionTest, toVec4) {
    rmg::Vec3 a = {14.345f, 6.4344f, -9.7701f};
    rmg::Vec4 b = a;
    EXPECT_NEAR(14.3450f, b.x, 0.0001f);
    EXPECT_NEAR( 6.4344f, b.y, 0.0001f);
    EXPECT_NEAR(-9.7701f, b.z, 0.0001f);
    EXPECT_NEAR( 0.0000f, b.w, 0.0001f);
}