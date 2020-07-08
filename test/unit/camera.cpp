#include <rmg/camera.hpp>

#include <gtest/gtest.h>

using namespace rmg;


/**
 * @brief Camera translation test
 * 
 * Only checks setter and getter. If getter returns the same value passed to
 * setter, the test is passed.
 */
TEST(Camera, translationAssert) {
    Camera cam = Camera();
    Vec3 v;
    cam.setTranslation(4.9f, -7.1f, 3.3f);
    v = cam.getTranslation();
    ASSERT_EQ( 4.9f, v.x);
    ASSERT_EQ(-7.1f, v.y);
    ASSERT_EQ( 3.3f, v.z);
    
    Vec3 p = Vec3(-5.0f, 3.2f, 14.3f);
    cam.setTranslation(p);
    v = cam.getTranslation();
    ASSERT_EQ(-5.0f, v.x);
    ASSERT_EQ( 3.2f, v.y);
    ASSERT_EQ(14.3f, v.z);
}


/**
 * @brief Camera rotation test
 * 
 * Only checks setter and getter. If getter returns the same value passed to
 * setter, the test is passed.
 */
TEST(Camera, rotationAssert) {
    Camera cam = Camera();
    cam.setRotation(0.96f, 0.65f, -2.50f);
    Euler rot = cam.getRotation();
    EXPECT_NEAR( 0.96f, rot.roll, 0.001f);
    EXPECT_NEAR( 0.65f, rot.pitch, 0.001f);
    EXPECT_NEAR(-2.50f, rot.yaw, 0.001f);
}

TEST(Camera, rotationAssert_pitchPositive90) {
    Camera cam = Camera();
    cam.setRotation(0.57f, M_PI/2, 1.51f);
    Euler rot = cam.getRotation();
    EXPECT_EQ(0, rot.roll);
    EXPECT_NEAR(M_PI/2, rot.pitch, 0.001f);
    EXPECT_NEAR(0.94f, rot.yaw, 0.001f);
}

TEST(Camera, rotationAssert_pitchNegative90) {
    Camera cam = Camera();
    cam.setRotation(-0.43f, -M_PI/2, 0.98f);
    Euler rot = cam.getRotation();
    EXPECT_EQ(0, rot.roll);
    EXPECT_NEAR(-M_PI/2, rot.pitch, 0.001f);
    EXPECT_NEAR(0.55f, rot.yaw, 0.001f);
}


/**
 * @brief Perspective FOV test
 * 
 * Only checks setter and getter. If getter returns the same value passed to
 * setter, the test is passed.
 */
TEST(Camera, perspectiveFOVAssert) {
    Camera cam = Camera();
    cam.setFieldOfView(radian(35.0f));
    float fov = cam.getFieldOfView();
    EXPECT_NEAR(radian(35.0f), fov, 0.0001f);
}


/**
 * @brief World space to clip space conversion test
 * 
 * Tests the work done by the view and projection matricies.
 * Although the setter and getter tests for the matricies pass, it can't
 * be ensured that the data stored inside are correct.
 */
TEST(Camera, worldToClip_default) {
    Camera cam = Camera();
    Vec3 p1 = cam.worldToClip(7.56f, -1.52f, 3.01f);
    // Camera space = (1.52, 3.01, -7.56)
    ASSERT_NEAR( 0.4854f, p1.x, 0.0001f);
    ASSERT_NEAR( 0.9611f, p1.y, 0.0001f);
    ASSERT_NEAR(-0.9283f, p1.z, 0.0001f);
    
    Vec3 p2 = cam.worldToClip(3.55f, 2.81f, -1.32f);
    // Camera space = (-2.81, -1.32, -3.55)
    ASSERT_NEAR(-1.9108f, p2.x, 0.0001f);
    ASSERT_NEAR(-0.8976f, p2.y, 0.0001f);
    ASSERT_NEAR(-0.5962f, p2.z, 0.0001f);
}

TEST(Camera, worldToClip_translated) {
    Camera cam = Camera();
    cam.setTranslation(-4.05f, -5.16f, 3.19f);
    Vec3 p = cam.worldToClip( 1.52f, -3.13f, 3.98f);
    // Camera space = (-2.03, 0.79, -5.57)
    EXPECT_NEAR(-0.8798f, p.x, 0.0001f);
    EXPECT_NEAR( 0.3424f, p.y, 0.0001f);
    EXPECT_NEAR(-0.8233f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_rotated) {
    Camera cam = Camera();
    cam.setRotation(30.4f, 41.3f, 155.7f, AngleUnit::Degree);
    Vec3 p = cam.worldToClip(-2.5543f, 0.8303f, -1.9611f);
    EXPECT_NEAR(-0.2926f, p.x, 0.0001f);
    EXPECT_NEAR( 0.0731f, p.y, 0.0001f);
    EXPECT_NEAR(-0.5488f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_transformed) {
    Camera cam = Camera();
    cam.setRotation(30.4f, 41.3f, 155.7f, AngleUnit::Degree);
    cam.setTranslation(-3.0f, 2.0f, 1.0f);
    Vec3 p = cam.worldToClip(-5.5543f, 2.8303f, -0.9611f);
    EXPECT_NEAR(-0.2926f, p.x, 0.0001f);
    EXPECT_NEAR( 0.0731f, p.y, 0.0001f);
    EXPECT_NEAR(-0.5488f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_perspectiveAspectChanged) {
    Camera cam = Camera();
    cam.setAspectRatio(640.0f/360.0f);
    // aspect = 9/16,  d = 2.414
    Vec3 p = cam.worldToClip(7.56f, -1.52f, 3.01f);
    // Camera space = (1.52, 3.01, -7.56)
    EXPECT_NEAR( 0.2730f, p.x, 0.0001f);
    EXPECT_NEAR( 0.9611f, p.y, 0.0001f);
    EXPECT_NEAR(-0.9283f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_perspectiveFOVChanged) {
    /**
     * The function involves context aspect ratio. So, if the perspective
     * matrix changed on aspect ratio change fails, this also fails.
     */
    Camera cam = Camera();
    cam.setAspectRatio(640.0f/360.0f);
    cam.setFieldOfView(radian(60));
    // aspect = 9/16,  d = 1/tan(30deg)
    Vec3 p = cam.worldToClip(3.55f, 2.81f, -1.32f);
    // Camera space = (-2.81, -1.32, -3.55)
    EXPECT_NEAR(-0.7712f, p.x, 0.0001f);
    EXPECT_NEAR(-0.6440f, p.y, 0.0001f);
    EXPECT_NEAR(-0.5962f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_perspectiveNearChanged) {
    Camera cam = Camera();
    cam.setMinimumDistance(2.5f);
    // A = 5/3,  B = 20/3
    Vec3 p = cam.worldToClip(7.56f, -1.52f, 3.01f);
    // Camera space = (1.52, 3.01, -7.56)
    EXPECT_NEAR( 0.4854f, p.x, 0.0001f);
    EXPECT_NEAR( 0.9611f, p.y, 0.0001f);
    EXPECT_NEAR(-0.7848f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_perspectiveFarChanged) {
    Camera cam = Camera();
    cam.setMinimumDistance(2.0f);
    cam.setMaximumDistance(100.0f);
    // A = 51/49,  B = 200/49
    Vec3 p = cam.worldToClip(60.55f, 12.01f, -9.62f);
    // Camera space = (-12.01, -9.62, -60.55)
    EXPECT_NEAR(-0.4788f, p.x, 0.0001f);
    EXPECT_NEAR(-0.3835f, p.y, 0.0001f);
    EXPECT_NEAR(-0.9734f, p.z, 0.0001f);
}

TEST(Camera, worldToClip_perspectiveChanged) {
    Camera cam = Camera();
    cam.setAspectRatio(400.0f/300.0f);
    cam.setPerspectiveProjection(radian(60), 2.0f, 50.0f);
    /**
     * aspect = 3/4,
     * d = 1/tan(30deg),
     * A = 13/12,
     * B = 25/6
     */
    Vec3 p = cam.worldToClip(46.321f, 17.57f, -12.42f);
    // Camera space = (-17.57, -12.42, -46.321)
    EXPECT_NEAR(-0.4927f, p.x, 0.0001f);
    EXPECT_NEAR(-0.4644f, p.y, 0.0001f);
    EXPECT_NEAR(-0.9934f, p.z, 0.0001f);
}