//blackdragonx61 / Mali

texture SceneTex;
sampler2D g_Sampler = sampler_state
{
    Texture = <SceneTex>;
    MinFilter = Linear;
    MagFilter = Linear;
    MipFilter = Linear;
};

float g_Time;
float g_Amplitude = 0.02;
float g_Frequency = 10.0;

struct VS_OUTPUT
{
    float4 Pos : POSITION;
    float2 Tex : TEXCOORD0;
};

float4 PS_Wave(VS_OUTPUT input) : COLOR
{
    float2 uv = input.Tex;

    uv.y += sin(uv.x * g_Frequency + g_Time) * g_Amplitude;
    uv.x += cos(uv.y * g_Frequency + g_Time) * g_Amplitude;

    return tex2D(g_Sampler, uv);
}

technique WaveTech
{
    pass P0
    {
        PixelShader = compile ps_3_0 PS_Wave();
    }
}
