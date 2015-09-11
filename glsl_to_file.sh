echo "// create from vertex.glsl and fragment.glsl using glsl_to_file.sh" > shaders_string.h
echo "" >> shaders_string.h
echo "#ifndef _SHADERS_STRING_H_" >> shaders_string.h
echo "" >> shaders_string.h
echo "const char* vertex_shader_string =" >> shaders_string.h
./glsl_to_string vertex.glsl >> shaders_string.h
echo ";" >> shaders_string.h
echo "" >> shaders_string.h
echo "const char* fragment_shader_string =" >> shaders_string.h
./glsl_to_string fragment.glsl >> shaders_string.h
echo ";" >> shaders_string.h
echo "" >> shaders_string.h
echo "#endif //#ifndef _SHADERS_STRING_H_" >> shaders_string.h
echo "" >> shaders_string.h
