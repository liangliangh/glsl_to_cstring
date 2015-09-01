usage:
make
./a.out shaderfile1 [file2 ...]


---------------------------- shader file a.glsl

#version 440 core

void main()
{
	gl_Position = vec4(0);
}


----------------------------- print c string
"\
\n\
#version 440 core\n\
\n\
void main()\n\
{\n\
	gl_Position = vec4(0);\n\
}\n\
\n\
"


