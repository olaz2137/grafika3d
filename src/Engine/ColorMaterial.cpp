//
// Created by Piotr Białas on 02/11/2021.
//

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include "spdlog/spdlog.h"
#include "3rdParty/stb/stb_image.h"

#include "ColorMaterial.h"

namespace xe {
    GLint  ColorMaterial::uniform_map_Kd_location_ = 0;

    GLuint ColorMaterial::color_uniform_buffer_ = 0u;
    GLuint ColorMaterial::shader_ = 0u;

    void ColorMaterial::bind() {
        int use_map_Kd = 0;
        if (texture_ > 0) {
            glUniform1i(uniform_map_Kd_location_, texture_unit_);
            glActiveTexture(GL_TEXTURE0 + texture_unit_);
            glBindTexture(GL_TEXTURE_2D, texture_);
            use_map_Kd = 1;
        }
        glBindBufferBase(GL_UNIFORM_BUFFER, 0, color_uniform_buffer_);
        glUseProgram(program());
        glBindBuffer(GL_UNIFORM_BUFFER, color_uniform_buffer_);
        glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::vec4), &color_[0]);
        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::vec4), sizeof(bool), &use_map_Kd);
        glBindBuffer(GL_UNIFORM_BUFFER, 0u);

    }

    void ColorMaterial::unbind() {
        glBindBuffer(GL_UNIFORM_BUFFER, 0u);
        glBindTexture(GL_TEXTURE_2D, 0u);
    }

    void ColorMaterial::init() {


        auto program = xe::utils::create_program(
                {{GL_VERTEX_SHADER,   std::string(PROJECT_DIR) + "/shaders/color_vs.glsl"},
                 {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/color_fs.glsl"}});
        if (!program) {
            std::cerr << "Invalid program" << std::endl;
            exit(-1);
        }

        shader_ = program;

        glGenBuffers(1, &color_uniform_buffer_);

        glBindBuffer(GL_UNIFORM_BUFFER, color_uniform_buffer_);
        glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::vec4) + sizeof(GLint), nullptr, GL_STATIC_DRAW);
        glBindBuffer(GL_UNIFORM_BUFFER, 0u);
#if __APPLE__
        auto u_modifiers_index = glGetUniformBlockIndex(shader_, "Color");
        if (u_modifiers_index == -1) {
            std::cerr << "Cannot find Color uniform block in program" << std::endl;
        } else {
            glUniformBlockBinding(shader_, u_modifiers_index, 0);
        }
#endif

#if __APPLE__
        auto u_transformations_index = glGetUniformBlockIndex(shader_, "Transformations");
        if (u_transformations_index == -1) {
            std::cerr << "Cannot find Transformations uniform block in program" << std::endl;
        } else {
            glUniformBlockBinding(shader_, u_transformations_index, 1);
        }
#endif

        uniform_map_Kd_location_ = glGetUniformLocation(shader_, "map_Kd");
        if (uniform_map_Kd_location_ == -1) {
            spdlog::warn("Cannot get uniform {} location", "map_Kd");
        }
    }
        
}
