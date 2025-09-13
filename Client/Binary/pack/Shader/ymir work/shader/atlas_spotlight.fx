//blackdragonx61 / Mali

texture SceneTex : register(t0);

sampler2D SceneSampler = sampler_state
{
    Texture = <SceneTex>;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
    AddressU  = CLAMP;
    AddressV  = CLAMP;
};

float2 ScreenSize;
float2 TextureSize;

static const int MAX_SPOTS = 8;
float2 PixelCenters[MAX_SPOTS];
int SpotCount;

float Radius;
float DarknessMin = 0.0;
float DarknessMax = 0.8;

float Time;
float PulseSpeed = 3.0;

float4 main(float2 uv : TEXCOORD0) : COLOR0
{
    float2 screen_px = uv * ScreenSize;
    float aspectFix = TextureSize.y / TextureSize.x;

    float t = (sin(Time * PulseSpeed) * 0.5 + 0.5);
    float Darkness = lerp(DarknessMin, DarknessMax, t);

    float totalMask = 1.0;

    for (int i = 0; i < SpotCount; ++i)
    {
        float2 diff = screen_px - PixelCenters[i];
        diff.x *= aspectFix;

        float dist = length(diff);
        float mask = smoothstep(Radius, Radius * 1.05, dist);

        totalMask = min(totalMask, mask);
    }

    float4 color = tex2D(SceneSampler, uv);
    color.rgb *= (1.0 - Darkness * totalMask);

    return color;
}

technique AtlasSpotlight
{
    pass P0
    {
        PixelShader = compile ps_3_0 main();
    }
}
