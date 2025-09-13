//blackdragonx61 / Mali

sampler2D SceneSampler;
float time;
float speed = 0.2;

struct PS_IN
{
    float2 uv      : TEXCOORD0;
    float4 diffuse : COLOR0;
};

float4 PS(PS_IN input) : COLOR0
{
    float alpha = input.diffuse.a;
    float2 uv = input.uv - float2(time * speed, time * speed);
    float3 color = tex2D(SceneSampler, uv).rgb;
    return float4(color, alpha);
}

technique Render
{
    pass P0
    {
        PixelShader = compile ps_2_0 PS();
    }
}