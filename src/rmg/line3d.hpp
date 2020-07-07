/**
 * @file line3d.hpp
 * @brief Draws a line in 3D space
 * 
 * Graphics without a polygon. Renders a straight through a special line
 * shader program. Just manipulate the locations of two end points, thickness
 * and color.
 * 
 * @copyright Copyright (c) 2020 Khant Kyaw Khaung
 * 
 * @license{This project is released under the MIT License.}
 */


#pragma once
#ifndef __RMG_LINE_3D_H__
#define __RMG_LINE_3D_H__

#include "object.hpp"
#include "math/vec3.hpp"


namespace rmg {

/**
 * @brief Draws a line in 3D space
 * 
 * Graphics without a polygon. Renders a straight through a special line
 * shader program. Just manipulate the locations of two end points, thickness
 * and color.
 */
class Line3D: public Object {
  private:
    Vec3 point1;
    Vec3 point2;
    float thickness;
    
  public:
    /**
     * @brief Default constructor
     */
    Line3D() = default;
    
    /**
     * @brief Constructor with thickness, color and 2 initial end-points
     * 
     * @param ctx Container context
     * @param t Line thickness
     * @param col RGBA color
     * @param p1 Position vector of point-1
     * @param p2 Position vector of point-2
     */
    Line3D(Context* ctx, float t, const Color &col=Color(1,1,1),
           const Vec3 &p1=Vec3(), const Vec3 &p2=Vec3());
    
    /**
     * @brief Sets the location of point-1
     * 
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param z Z-coordinate
     */
    void setPoint1(float x, float y, float z);
    
    /**
     * @brief Sets the location of point-2
     * 
     * @param x X-coordinate
     * @param y Y-coordinate
     * @param z Z-coordinate
     */
    void setPoint2(float x, float y, float z);
    
    /**
     * @brief Sets the location of point-1
     * 
     * @param p Position vector
     */
    void setPoint1(const Vec3 &p);
    
    /**
     * @brief Sets the location of point-2
     * 
     * @param p Position vector
     */
    void setPoint2(const Vec3 &p);
    
    /**
     * @brief Gets the location of point-1
     * 
     * @return Position vector
     */
    Vec3 getPoint1() const;
    
    /**
     * @brief Gets the location of point-1
     * 
     * @return Position vector
     */
    Vec3 getPoint2() const;
    
    /**
     * @brief Sets the line thickness
     * 
     * @param t Line thickness
     */
    void setThickness(float t);
    
    /**
     * @brief Gets the line thickness
     * 
     * @return Line thickness
     */
    float getThickness() const;
};

}

#endif
