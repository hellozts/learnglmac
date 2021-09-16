#version 330 core

in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 lightColor;

out vec4 FragColor;

void main() {
    FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.4) * vec4(lightColor, 1.0f);
}
