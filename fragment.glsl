
#version 440 core

uniform mat4   mat_transformation = mat4(1); // projection and modelview

uniform vec4   tri_color = vec4(1,1,0, 1);
uniform sampler2D texture0;
in vec2 tex_coord; // name based matching

layout(location=0) out vec4 frag_color;

void main()
{
	vec4 texa = texture(texture0, tex_coord);
	frag_color = mix(tri_color.rgb, texa.rgb, texa.a);
}
