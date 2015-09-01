
#version 440 core

uniform mat4   mat_projection = mat4(1);
uniform mat4   mat_transformation = mat4(1); // projection and modelview

layout(r32ui) uniform uimageBuffer img_bgr_uchar;
layout(r16ui) uniform uimageBuffer img_depth_ushort;

uniform sampler2D tex_cicle;
uniform sampler2D tex_site;

uniform vec4  tri_color = vec4(1,1,0, 1);
uniform ivec2  resolution;
 
in vec2 tex_coord; // name based matching

//layout(location=0) out vec4 frag_color; // no out, modify buffer(img_bgr_uchar) directly

void main()
{
	float texa = texture(tex_cicle, tex_coord).x;
	
	if(texa==0) discard;
	
	int fxi = int(gl_FragCoord.x);
	int fyi = int(gl_FragCoord.y);
	float fd = gl_FragCoord.z;
	
	int findex = fyi * resolution.x + fxi;
	uint ud = imageLoad( img_depth_ushort, findex ).x;
	//ud = (findex%2==0) ? (ud & 0x00ffff) : (ud >> 16);
	float d0 = (ud==0) ? 0 : (1+mat_projection[3][2]/ud/2.0f);
	
	if(fd >= d0) discard;
	
	uint upixel = imageLoad( img_bgr_uchar, findex ).x;
	// the origin img is BGR
	vec3 rgb0 = vec3( ((upixel >> 16) & 0x000000ff) / 255.0f,
					  ((upixel >> 8 ) & 0x000000ff) / 255.0f,
					  ((upixel >> 0 ) & 0x000000ff) / 255.0f  );
	vec3 rgb = mix(rgb0, tri_color.rgb, texa * tri_color.a);
	upixel = uint(rgb.r*255.0f)<<16 | (uint(rgb.g*255.0f)<<8) | (uint(rgb.b*255.0f)<<0);
	imageStore( img_bgr_uchar, findex, uvec4(upixel, 0,0,0) );

	discard;
	
	//frag_color = tri_color;
}
