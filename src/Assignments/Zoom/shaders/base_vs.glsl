#version 410

layout(location=0) in  vec4 a_vertex_position;

out vec3 Color;

layout(std140) uniform Transformations {
    mat4 PVM;
};

void main() {
    gl_Position =  PVM * a_vertex_position;
}
