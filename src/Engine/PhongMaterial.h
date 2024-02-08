//
// Created by Piotr Białas on 02/11/2021.
//

#pragma once

#include <glad/gl.h>
#include <glm/glm.hpp>

#include "Application/utils.h"
#include "Material.h"

namespace xe {

    GLuint create_texture(const std::string &name);

    class PhongMaterial : public Material {
    public:
        PhongMaterial(const glm::vec4 color, GLuint texture, GLuint texture_unit) : color_(color), texture_(texture), texture_unit_(texture_unit) {}

        PhongMaterial(const glm::vec4 color, glm::vec4 Ka, glm::vec4 Ks, float Ns)
        : color_(color),
        Ka_(Ka),
        Ks_(Ks),
        Ns_(Ns)
        {}

        PhongMaterial(const glm::vec4 color) : color_(color) {}

        void bind();
        void unbind();

        static void init();

        static GLuint program() { return shader_; }

        void set_texture(GLuint texture) { texture_ = texture; };
        void set_texture_unit(GLuint texture_unit) { texture_unit_ = texture_unit; };

        GLuint get_texture() { return texture_; }
        GLuint get_texture_unit() { return texture_unit_; }

    private:
        static GLuint shader_;
        static GLuint color_uniform_buffer_;

        glm::vec4 color_;

        static GLint uniform_map_Kd_location_;
        GLuint texture_ = 0;
        GLuint texture_unit_ = 0;

        glm::vec4 Ka_;
        glm::vec4 Ks_;
        float Ns_;

    };


}
