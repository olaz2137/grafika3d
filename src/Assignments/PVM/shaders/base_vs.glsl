#version 410

layout(location=0) in  vec4 a_vertex_position;
layout (location=1) in vec3 a_vertex_color;

out vec3 Color;

uniform mat4 PVM;

void main() {
    Color = a_vertex_color;
    gl_Position =  PVM * a_vertex_position;
}
