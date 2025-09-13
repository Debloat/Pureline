//blackdragonx61 / Mali

texture SceneTex;

sampler2D texSampler = sampler_state
{
    Texture = <SceneTex>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

float BlurStrength = 0.005;

struct PS_IN
{
    float2 uv : TEXCOORD0;
};

float4 PS_BlurH(PS_IN IN) : COLOR
{
    float2 uv = IN.uv;
    float offs = BlurStrength;

    float4 c = tex2D(texSampler, uv) * 0.227027;

    c += tex2D(texSampler, uv + float2( offs, 0)) * 0.1945946;
    c += tex2D(texSampler, uv - float2( offs, 0)) * 0.1945946;

    c += tex2D(texSampler, uv + float2( offs*2, 0)) * 0.1216216;
    c += tex2D(texSampler, uv - float2( offs*2, 0)) * 0.1216216;

    c += tex2D(texSampler, uv + float2( offs*3, 0)) * 0.054054;
    c += tex2D(texSampler, uv - float2( offs*3, 0)) * 0.054054;

    c += tex2D(texSampler, uv + float2( offs*4, 0)) * 0.016216;
    c += tex2D(texSampler, uv - float2( offs*4, 0)) * 0.016216;

    return c;
}

float4 PS_BlurV(PS_IN IN) : COLOR
{
    float2 uv = IN.uv;
    float offs = BlurStrength;

    float4 c = tex2D(texSampler, uv) * 0.227027;

    c += tex2D(texSampler, uv + float2(0,  offs)) * 0.1945946;
    c += tex2D(texSampler, uv - float2(0,  offs)) * 0.1945946;

    c += tex2D(texSampler, uv + float2(0,  offs*2)) * 0.1216216;
    c += tex2D(texSampler, uv - float2(0,  offs*2)) * 0.1216216;

    c += tex2D(texSampler, uv + float2(0,  offs*3)) * 0.054054;
    c += tex2D(texSampler, uv - float2(0,  offs*3)) * 0.054054;

    c += tex2D(texSampler, uv + float2(0,  offs*4)) * 0.016216;
    c += tex2D(texSampler, uv - float2(0,  offs*4)) * 0.016216;

    return c;
}

technique Blur
{
    pass Horizontal
    {
        PixelShader = compile ps_2_0 PS_BlurH();
    }

    pass Vertical
    {
        PixelShader = compile ps_2_0 PS_BlurV();
    }
}