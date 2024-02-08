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
#include "Engine/mesh_loader.h"

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

    stbi_set_flip_vertically_on_load(true);
    GLint width, height, channels;
    auto texture_file = std::string(ROOT_DIR) + "/Models/multicolor.png";
    auto img = stbi_load(texture_file.c_str(), &width, &height, &channels, 0);
    if (!img) {
        spdlog::warn("Could not read image from file `{}'", texture_file);
    }

    xe::ColorMaterial::init();

    set_camera(new Camera);
    set_controler(new CameraControler(camera()));

    int w, h;
    std::tie(w, h) = frame_buffer_size();
    camera_->perspective(glm::pi<float>()/4.0, (float)w/h, 0.1f, 100.0f);
    camera_->look_at(glm::vec3(2.0f, 0.0f, -0.5f), glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f));

    GLenum format;

    if (channels == 3)
        format = GL_RGB;
    else if (channels == 4) {
        format = GL_RGBA;
    }

    GLuint textures_ptr;
    glGenTextures(1, &textures_ptr);
    glBindTexture(GL_TEXTURE_2D, textures_ptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, img);
    glBindTexture(GL_TEXTURE_2D, 0);

    // A vector containing the x,y,z vertex coordinates for the triangle.
    std::vector<GLfloat> vertices = {
            0.5f, 0.5f, 0.0f,    0.5f, 0.191f,
            0.5f, -0.5f, 0.0f,   0.809f, 0.5f,
            -0.5f, -0.5f, 0.0f,  0.5f, 0.809f,

            -0.5f, -0.5f, 0.0f,  0.5f, 0.809f,
            -0.5f, 0.5f, 0.0f,   0.191f, 0.5f,
            0.5f, 0.5f, 0.0f,    0.5f, 0.191f,

            -0.5f, -0.5f, 0.0f,  0.5f, 0.809f,
            0.5f, -0.5f, 0.0f,   0.809f, 0.5f,
            0.0f, 0.0f, 1.0f,    1.0f, 1.0f,

            0.5f, -0.5f, 0.0f,   0.809f, 0.5f,
            0.5f, 0.5f, 0.0f,    0.5f, 0.191f,
            0.0f, 0.0f, 1.0f,    1.0f, 0.0f,

            0.5f, 0.5f, 0.0f,    0.5f, 0.191f,
            -0.5f, 0.5f, 0.0f,   0.191f, 0.5f,
            0.0f, 0.0f, 1.0f,    0.0f, 0.0f,

            0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
            -0.5f, 0.5f, 0.0f,   0.191f, 0.5f,
            -0.5f, -0.5f, 0.0f,  0.5f, 0.809f,
            };

    auto pyramid = new Mesh;

    pyramid->allocate_vertex_buffer(vertices.size() * sizeof(GLfloat), GL_STATIC_DRAW);
    pyramid->load_vertices(0, vertices.size() * sizeof(GLfloat), vertices.data());
    pyramid->vertex_attrib_pointer(0, 3, GL_FLOAT, 5 * sizeof(GLfloat), 0);
    pyramid->vertex_attrib_pointer(1, 2, GL_FLOAT, 5 * sizeof(GLfloat), 3 * sizeof(GLfloat));

    std::vector<GLushort> indices = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

    pyramid->allocate_index_buffer(indices.size() * sizeof(GLfloat), GL_STATIC_DRAW);
    pyramid->load_indices(0, indices.size() * sizeof(GLfloat), indices.data());

    pyramid->add_submesh(0, 6, new xe::ColorMaterial({1.0f, 1.0f, 1.0f, 1.0f}, textures_ptr, 0));
    pyramid->add_submesh(6, 9, new xe::ColorMaterial({1.0f, 1.0f, 1.0f, 1.0f}, textures_ptr, 1));
    pyramid->add_submesh(9, 12, new xe::ColorMaterial({1.0f, 1.0f, 1.0f, 1.0f}, textures_ptr, 2));
    pyramid->add_submesh(12, 15, new xe::ColorMaterial({1.0f, 1.0f, 1.0f, 1.0f}, textures_ptr, 3));
    pyramid->add_submesh(15, 18, new xe::ColorMaterial({1.0f, 1.0f, 1.0f, 1.0f}, textures_ptr, 4));

    // pyramid = xe::load_mesh_from_obj(std::string(ROOT_DIR) + "/Models/pyramid.obj",
    //                                  std::string(ROOT_DIR) + "/Models").get();
    add_submesh(pyramid);

    // GLuint transformationsIndex = glGetUniformBlockIndex(program, "Transformations");
    // glUniformBlockBinding(program, transformationsIndex, 1);

    glGenBuffers(1, &u_pvm_buffer_);
    OGL_CALL(glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_));
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), nullptr, GL_STATIC_DRAW);
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
    glBindBuffer(GL_UNIFORM_BUFFER, u_pvm_buffer_);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), &PVM[0]);
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
