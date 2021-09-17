#version 330 core

in vec2 texCoord;
in vec3 normal;
in vec3 fragPos;
in mat4 myModel;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

out vec4 FragColor;

void main() {
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;
    
    vec3 norm = normalize(mat3(transpose(inverse(myModel))) * normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = diff * lightColor;
    
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 256);
    vec3 specular = specularStrength * spec * lightColor;
    
    FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.4) * vec4((ambient + diffuse + specular), 1.0f);
}
