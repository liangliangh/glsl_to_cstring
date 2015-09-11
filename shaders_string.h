// create from vertex.glsl and fragment.glsl using glsl_to_file.sh

#ifndef _SHADERS_STRING_H_

const char* vertex_shader_string =
"\
\n\
#version 440 core\n\
\n\
uniform mat4   mat_transformation = mat4(1); // projection and model-view\n\
\n\
layout(location=0) in vec3  position;\n\
layout(location=1) in vec2  tex_coord_in;\n\
out vec2 tex_coord; // name based matching\n\
\n\
void main()\n\
{\n\
	gl_Position = mat_transformation * vec4(position, 1);\n\
	tex_coord = tex_coord_in;\n\
}\n\
\n\
"
;

const char* fragment_shader_string =
"\
\n\
#version 440 core\n\
\n\
uniform mat4   mat_transformation = mat4(1); // projection and modelview\n\
\n\
uniform vec4   tri_color = vec4(1,1,0, 1);\n\
uniform sampler2D texture0;\n\
in vec2 tex_coord; // name based matching\n\
\n\
layout(location=0) out vec4 frag_color;\n\
\n\
void main()\n\
{\n\
	vec4 texa = texture(texture0, tex_coord);\n\
	frag_color = mix(tri_color.rgb, texa.rgb, texa.a);\n\
}\n\
\n\
"
;

#endif //#ifndef _SHADERS_STRING_H_

