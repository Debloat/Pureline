//blackdragonx61 / Mali

texture SceneTex : register(t0);

sampler2D SceneSampler = sampler_state
{
    Texture = <SceneTex>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

float LumR = 0.299;
float LumG = 0.587;
float LumB = 0.114;

float4 PS_Greyscale(float2 Tex : TEXCOORD0) : COLOR
{
    float4 color = tex2D(SceneSampler, Tex);

    float luminance = dot(color.rgb, float3(LumR, LumG, LumB));

    return float4(luminance, luminance, luminance, color.a);
}

technique GrayTech
{
    pass P0
    {
        PixelShader = compile ps_3_0 PS_Greyscale();
    }
}