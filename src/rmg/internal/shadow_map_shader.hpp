/**
 * @file shadow_map_shader.hpp
 * @brief Generates an image representing the distance from sun at every pixel
 * 
 * @copyright Copyright (c) 2020 Khant Kyaw Khaung
 * 
 * @license{This project is released under the MIT License.}
 */


#pragma once
#ifndef __RMG_SHADOW_MAP_SHADER_H__
#define __RMG_SHADOW_MAP_SHADER_H__

#include "shader.hpp"

namespace rmg {
namespace internal {

/**
 * @brief Generates an image representing the distance from sun at every pixel
 */
class ShadowMapShader: public Shader {
  private:
    uint32_t idMVP;
    
  public:
    /**
     * @brief Default constructor
     */
    ShadowMapShader();
    
    /**
     * @brief Constructor with its container
     * 
     * @param ctx Container context
     */
    ShadowMapShader(Context* ctx);
    
    /**
     * @brief Destructor
     */
    virtual ~ShadowMapShader();
    
    /**
     * @brief Compile, link and assign program parameters
     */
    void load();
};

}}

#endif
