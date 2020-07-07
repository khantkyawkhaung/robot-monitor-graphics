/**
 * @file shader.hpp
 * @brief Shader program class taking main backend role in drawing
 * 
 * Compiles vertex and fragment shaders. Link the program. Run it using
 * loaded vertex buffer objects and make drawings.
 * 
 * @copyright Copyright (c) 2020 Khant Kyaw Khaung
 * 
 * @license{This project is released under the MIT License.}
 */


#pragma once
#ifndef __RMG_SHADER_H__
#define __RMG_SHADER_H__

#include <cstdint>
#include <string>


namespace rmg {

class Context;

namespace internal {

/**
 * @brief The shader program taking main backend role in drawing
 * 
 * Compiles vertex and fragment shaders. Link the program. Run it using
 * loaded vertex buffer objects and make drawings.
 */
class Shader {
  protected:
    uint32_t id = 0; ///< Shader program ID
    
  public:
    /**
     * @brief Default constructor
     */
    Shader() = default;
    
    /**
     * @brief Destructor
     */
    virtual ~Shader();
    
    /**
     * @brief Compiles and links shader program and assigns parameter IDs
     */
    virtual void load() = 0;
    
    /**
     * @brief Compiles a shader from file (Vertex shader or fragment shader)
     * 
     * @param type Shader type (GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, .etc)
     * @param path Path to shader file
     * 
     * @return ID of the compiled shader used to retrive it
     */
    static uint32_t compileShader(uint32_t type,
                                  const std::string &path);
    
    /**
     * @brief Compiles and links a shader program
     * 
     * @param vert Vertex shader file
     * @param frag Fragment shader file
     * 
     * @return Shader program ID
     */
    static uint32_t compileShaderProgram(const std::string &vert,
                                         const std::string &frag);
};

}}

#endif
