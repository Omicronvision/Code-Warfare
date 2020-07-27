uniform vec2 lightOrigin;
uniform vec4 lightColor;
uniform float lightAttenuation;
uniform vec2 screenResolution;
uniform sampler2D texture;

void main()
{
    vec2 baseDistance = gl_FragCoord.xy;
    baseDistance.y = screenResolution.y - baseDistance.y;
    float d = length(lightOrigin - baseDistance);
    float a = 1.0/(lightAttenuation * d);
    vec4 color = vec4(a, a, a, 1.0) * vec4(lightColor);
    vec4 t = texture2D(texture, gl_TexCoord[0].xy);
    if(t[0] > color[0]) color[0] = t[0];
    if(t[1] > color[1]) color[1] = t[1];
    if(t[2] > color[2]) color[2] = t[2];
    gl_FragColor = color;
}