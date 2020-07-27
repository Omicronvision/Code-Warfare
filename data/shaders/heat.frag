uniform sampler2D currentTexture;
uniform sampler2D distortionMapTexture;

uniform float time;
uniform float distortionFactor;
uniform float riseFactor;

void main()
{
	vec2 distortionMapCoordinate = gl_TexCoord[0].st;
	distortionMapCoordinate.t -= time * riseFactor;
	vec4 distortionMapValue = texture2D(distortionMapTexture, distortionMapCoordinate);
	vec2 distortionPositionOffset = distortionMapValue.xy;
	distortionPositionOffset -= vec2(0.5f, 0.5f);
	distortionPositionOffset *= 2.f;
	distortionPositionOffset *= distortionFactor;
	vec2 distortionUnused = distortionMapValue.zw;
	distortionPositionOffset *= (1.f - gl_TexCoord[0].t);
	vec2 distortedTextureCoordinate = gl_TexCoord[0].st + distortionPositionOffset;
	gl_FragColor = gl_Color * texture2D(currentTexture, distortedTextureCoordinate);	
}