#version 410

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_colour;

out vec3 colour;

uniform mat4 trans;

void main() {
	colour = vertex_colour;
	gl_Position = trans * vec4(vertex_position, 1.0);
}
