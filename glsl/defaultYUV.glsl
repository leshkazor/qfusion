// FXAA shader
// Original algorithm and code by Timothy Lottes

#include "include/common.glsl"
#include "include/uniforms.glsl"
#include "include/yuv.glsl"

varying vec2 v_TexCoord;

#ifdef VERTEX_SHADER

#include "include/attributes.glsl"
#include "include/vtransform.glsl"

void main(void)
{
	gl_Position = u_ModelViewProjectionMatrix * a_Position;
	v_TexCoord = a_TexCoord;
}

#endif // VERTEX_SHADER

#ifdef FRAGMENT_SHADER
// Fragment shader

uniform sampler2D u_YUVTextureY;
uniform sampler2D u_YUVTextureU;
uniform sampler2D u_YUVTextureV;

void main(void)
{
	gl_FragColor = vec4(YUV2RGB(vec3(
		texture2D(u_YUVTextureY, v_TexCoord).r,
		texture2D(u_YUVTextureU, v_TexCoord).r, 
		texture2D(u_YUVTextureV, v_TexCoord).r
	)), 1.0);
}

#endif // FRAGMENT_SHADER