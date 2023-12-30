#version 410

layout(location=0) out vec4 vFragColor;


layout(std140) uniform Modifier {
    float strength;
};

void main() {
    const vec3 color[6] = vec3[6](
        vec3(0.2f, 0.1f, 0.7f),
        vec3(0.2f, 0.1f, 0.7f),
        vec3(0.8f, 0.1f, 0.7f),
        vec3(0.2f, 0.9f, 0.13f),
        vec3(0.76f, 0.59f, 0.5f),
        vec3(0.41f, 0.5f, 0.7f));
    vFragColor = vec4(color[gl_PrimitiveID] * strength, 1.0);
}
