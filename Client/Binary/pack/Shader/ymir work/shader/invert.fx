//blackdragonx61 / Mali

texture SceneTex;

sampler2D texSampler = sampler_state
{
    Texture = <SceneTex>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

float gTime;

float4 main(float2 texCoord : TEXCOORD0) : COLOR
{
    float4 color = tex2D(texSampler, texCoord);

    color.r = color.r * abs(sin(gTime));
    color.g = color.g * abs(sin(gTime + 1.0));
    color.b = color.b * abs(sin(gTime + 2.0));

    return color;
}

technique InvertTech
{
    pass P0
    {
        PixelShader = compile ps_2_0 main();
    }
}