#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 texCoord;

void main() {
    gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    texCoord = coord;
}

