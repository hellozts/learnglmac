//
//  myShader.h
//  testopengl1
//
//  Created by 郑天省 on 2021/9/14.
//

#ifndef myShader_h
#define myShader_h

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

unsigned int SHADER_ID;

void checkCompileErrors(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

void initMyShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr) {
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    std::ifstream gShaderFile;
    
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    gShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    
    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        if(geometryPath != nullptr)
        {
            gShaderFile.open(geometryPath);
            std::stringstream gShaderStream;
            gShaderStream << gShaderFile.rdbuf();
            gShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ \n" << e.exception::what() << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();
    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    unsigned int geometry;
    if(geometryPath != nullptr)
    {
        const char * gShaderCode = geometryCode.c_str();
        geometry = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometry, 1, &gShaderCode, NULL);
        glCompileShader(geometry);
        checkCompileErrors(geometry, "GEOMETRY");
    }
    SHADER_ID = glCreateProgram();
    glAttachShader(SHADER_ID, vertex);
    glAttachShader(SHADER_ID, fragment);
    if(geometryPath != nullptr)
        glAttachShader(SHADER_ID, geometry);
    glLinkProgram(SHADER_ID);
    checkCompileErrors(SHADER_ID, "PROGRAM");
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    if(geometryPath != nullptr)
        glDeleteShader(geometry);
}

void useMyShader() {
    glUseProgram(SHADER_ID);
}

void setBoolMyShader(const std::string &name, bool value) {
    glUniform1i(glGetUniformLocation(SHADER_ID, name.c_str()), (int)value);
}

void setIntMyShader(const std::string &name, int value) {
    glUniform1i(glGetUniformLocation(SHADER_ID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void setFloatMyShader(const std::string &name, float value) {
    glUniform1f(glGetUniformLocation(SHADER_ID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void setVec2MyShader(const std::string &name, const glm::vec2 &value) {
    glUniform2fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, &value[0]);
}
void setVec2MyShader(const std::string &name, float x, float y) {
    glUniform2f(glGetUniformLocation(SHADER_ID, name.c_str()), x, y);
}
// ------------------------------------------------------------------------
void setVec3MyShader(const std::string &name, const glm::vec3 &value) {
    glUniform3fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, &value[0]);
}
void setVec3MyShader(const std::string &name, float x, float y, float z) {
    glUniform3f(glGetUniformLocation(SHADER_ID, name.c_str()), x, y, z);
}
// ------------------------------------------------------------------------
void setVec4MyShader(const std::string &name, const glm::vec4 &value) {
    glUniform4fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, &value[0]);
}
void setVec4MyShader(const std::string &name, float x, float y, float z, float w) {
    glUniform4f(glGetUniformLocation(SHADER_ID, name.c_str()), x, y, z, w);
}
// ------------------------------------------------------------------------
void setMat2MyShader(const std::string &name, const glm::mat2 &mat) {
    glUniformMatrix2fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void setMat3MyShader(const std::string &name, const glm::mat3 &mat) {
    glUniformMatrix3fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void setMat4MyShader(const std::string &name, const glm::mat4 &mat) {
    glUniformMatrix4fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


#endif /* myShader_h */
