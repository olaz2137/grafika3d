#version 410

layout(location=0) out vec4 vFragColor;
layout(location=1) in vec3 Color;

layout(std140) uniform Modifier {
    float strength;
    vec3 color;
};

void main() {
    vFragColor = vec4(color * strength, 1.0);
}
