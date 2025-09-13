//blackdragonx61 / Mali

texture SceneTex : register(t0);

sampler2D SceneSampler = sampler_state
{
    Texture = <SceneTex>;
    MinFilter = POINT;
    MagFilter = POINT;
};

float2 ScreenSize = float2(800.0, 600.0);
float PixelSize = 16.0;

float4 PS_Pixelate(float2 Tex : TEXCOORD0) : COLOR
{
    float2 uv = Tex;
    uv = floor(uv * ScreenSize / PixelSize) * PixelSize / ScreenSize;

    return tex2D(SceneSampler, uv);
}

technique PixelateTech
{
    pass P0
    {
        PixelShader = compile ps_3_0 PS_Pixelate();
    }
}