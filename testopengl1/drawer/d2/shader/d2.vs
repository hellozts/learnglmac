#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 coord;
layout (location = 3) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 texCoord;
out vec3 normal;
out vec3 fragPos;
out mat4 myModel;

void main() {
    gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    texCoord = coord;
    normal = aNormal;
    myModel = model;
    fragPos = vec3(model * vec4(aPos, 1.0f));
}

