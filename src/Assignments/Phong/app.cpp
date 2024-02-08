//
// Created by pbialas on 25.09.2020.
//
#define STB_IMAGE_IMPLEMENTATION  1

#include "3rdParty/stb/stb_image.h"

#include "app.h"

#include <iostream>
#include <vector>
#include <tuple>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/constants.hpp"
#include "spdlog/spdlog.h"

#include "Application/utils.h"
#include "Engine/ColorMaterial.h"
#include "Engine/PhongMaterial.h"
#include "Engine/mesh_loader.h"
#include "Engine/texture.h"

void SimpleShapeApplication::init() {
    // A utility function that reads the shader sources, compiles them and creates the program object
    // As everything in OpenGL we reference program by an integer "handle".
    auto program = xe::utils::create_program(
            {{GL_VERTEX_SHADER,   std::string(PROJECT_DIR) + "/shaders/base_vs.glsl"},
             {GL_FRAGMENT_SHADER, std::string(PROJECT_DIR) + "/shaders/base_fs.glsl"}});

    if (!program) {
        std::cerr << "Invalid program" << std::endl;
        exit(-1);
    }

    xe::ColorMaterial::init();
    xe::PhongMaterial::init();

    set_camera(new Camera);
    set_controler(new CameraControler(camera()));

    int w, h;
    std::tie(w, h) = frame_buffer_size();
    camera_->perspective(glm::pi<float>()/4.0, (float)w/h, 0.1f, 100.0f);
    camera_->look_at(glm::vec3(1.0f, 0.0f, -3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

    add_submesh(xe::load_mesh_from_obj(std::string(ROOT_DIR) + "/Models/square.obj",
        std::string(ROOT_DIR) + "/Models"));

    auto light = new xe::PointLight(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), 1.0f, 0.5f); 
    add_light(*light);
    auto light2 = new xe::PointLight(glm::vec3(0.5f, 0.5f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f), 1.0f, 0.5f); 
    add_light(*light2);
    auto light3 = new xe::PointLight(glm::vec3(-0.5f, 0.5f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), 1.0f, 0.5f); 
    add_light(*light3);
    add_ambient(glm::vec3(0.1f, 0.1f, 0.1f));

    glGenBuffers(1, &u_lights_buffer_);
    glBindBuffer(GL_UNIFORM_BUFFER, u_lights_buffer_);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::vec3) + sizeof(GLuint) + sizeof(xe::PointLight)*p_lights_.size(), nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferBase(GL_UNIFORM_BUFFER, 2, u_lights_buffer_);

    glGenBuffers(1, &u_pvm_buffer_);
    OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_));
    glBufferData(GL_UNIFORM_BUFFER, 2*sizeof(glm::mat4)+sizeof(glm::mat3), nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferBase(GL_UNIFORM_BUFFER, 1, u_pvm_buffer_);

    M_ = glm::mat4(1.0f);
    M_ = glm::scale(M_, glm::vec3{1.0f, 1.0f, 1.0f});
    M_ = glm::rotate(M_, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    M_ = glm::translate(M_, glm::vec3{0.0f, 0.0f, 0.0f});

    // Setting the background color of the rendering window,
    // I suggest not to use white or black for better debuging.
    glClearColor(0.81f, 0.81f, 0.8f, 1.0f);

    // This setups an OpenGL vieport of the size of the whole rendering window.
    glViewport(0, 0, w, h);

    glUseProgram(program);
}

//This functions is called every frame and does the actual rendering.
void SimpleShapeApplication::frame() {
    // Binding the VAO will setup all the required vertex buffers.
    auto PVM = camera_->projection() * camera_->view() * M_;
    auto VM = camera_->view() * M_;
    auto R = glm::mat3(VM);
    auto N = glm::mat3(glm::cross(R[1], R[2]), glm::cross(R[2], R[0]), glm::cross(R[0], R[1]));
    glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), &VM[0]);
    glBufferSubData(GL_UNIFORM_BUFFER, 2*sizeof(glm::mat4), sizeof(glm::mat3), &N[0]);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    GLuint n_p_lights = p_lights_.size();

    glBindBuffer(GL_UNIFORM_BUFFER, u_lights_buffer_);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::vec3), &ambient_);
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::vec3), sizeof(GLuint), &n_p_lights);

    for (GLuint i = 0; i < n_p_lights; i++) {
        xe::PointLight& light = p_lights_[i];
        light.position_in_vs = glm::vec3(VM * glm::vec4(light.position_in_ws, 1.0f));

        auto lightOffset = sizeof(glm::vec3) + sizeof(GLuint) + i * sizeof(xe::PointLight);
        glBufferSubData(GL_UNIFORM_BUFFER, lightOffset, sizeof(xe::PointLight), &light);
    }

    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    for (auto m: meshes_)
        m->draw();
}

void SimpleShapeApplication::framebuffer_resize_callback(int w, int h) {
    Application::framebuffer_resize_callback(w, h);
    glViewport(0,0,w,h);
    camera_->set_aspect((float)w/h);
}

void SimpleShapeApplication::mouse_button_callback(int button, int action, int mods) {
    Application::mouse_button_callback(button, action, mods);

    if (controler_) {
        double x, y;
        glfwGetCursorPos(window_, &x, &y);

        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
            controler_->LMB_pressed(x, y);

        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
            controler_->LMB_released(x, y);
    }

}

void SimpleShapeApplication::cursor_position_callback(double x, double y) {
    Application::cursor_position_callback(x, y);
    if (controler_) {
        controler_->mouse_moved(x, y);
    }
}
