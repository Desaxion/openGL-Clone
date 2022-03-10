#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

uniform Material material;
uniform sampler2D texture_diffuse1;

void main() {
	FragColor = texture(texture_diffuse1, TexCoords);
}