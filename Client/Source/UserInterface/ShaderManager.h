/**
 * @file   ShaderManager.h
 * @author blackdragonx61 / Mali
 * @date   27.10.2025
 * __BL_SHADER__
 */

#pragma once

#include <functional>

class IShader
{
    public:
        enum class EType
        {
            WAVE,
            GRAY,
            PIXELATE,
            INVERT,
            ATLAS_SPOTLIGHT,
            UI_BLUR,
            WATER,
        };

        enum class ERenderType
        {
            GAME_SCREEN,
            ATLAS,
            UI,
            OTHER,
        };

        explicit IShader();
        virtual ~IShader();

        virtual void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const = 0;
        virtual EType GetType() const = 0;
        virtual ERenderType GetRenderType() const = 0;

        bool Load(const char* path);
        void Render(const std::function<void()>& func) const;
        void LostDevice() const;
        void ResetDevice() const;

        virtual void Show()
        {
            m_Visible = true;
        }
        virtual void Hide()
        {
            m_Visible = false;
        }

        ID3DXEffect* GetEffect() const
        {
            return m_Effect;
        }
        bool IsVisible() const
        {
            return m_Visible;
        }

    protected:
        ID3DXEffect* m_Effect;
        bool m_Visible;
};

class CWaveShader : public IShader
{
    public:
        CWaveShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::WAVE;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::GAME_SCREEN;
        }

        void SetAmplitude(float f)
        {
            m_Amplitude = f;
        }
        void SetFrequency(float f)
        {
            m_Frequency = f;
        }

    protected:
        float m_Amplitude;
        float m_Frequency;
};

class CGrayShader : public IShader
{
    public:
        CGrayShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::GRAY;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::GAME_SCREEN;
        }

        void SetLumR(float f)
        {
            m_LumR = f;
        }
        void SetLumG(float f)
        {
            m_LumG = f;
        }
        void SetLumB(float f)
        {
            m_LumB = f;
        }

    protected:
        float m_LumR;
        float m_LumG;
        float m_LumB;
};

class CPixelateShader : public IShader
{
    public:
        CPixelateShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::PIXELATE;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::GAME_SCREEN;
        }

        void SetPixelSize(float f)
        {
            m_PixelSize = f;
        }

    protected:
        float m_PixelSize;
};

class CInvertColorShader : public IShader
{
    public:
        CInvertColorShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::INVERT;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::OTHER;
        }
};

class CAtlasSpotlightShader : public IShader
{
    public:
        CAtlasSpotlightShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::ATLAS_SPOTLIGHT;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::ATLAS;
        }

        void SetPoints(std::vector<D3DXVECTOR2> v)
        {
            m_Points = v;
        }
        void SetTextureSize(D3DXVECTOR2 v)
        {
            m_TextureSize = v;
        }
        void SetRadius(float f)
        {
            m_Radius = f;
        }
        void SetDarknessMin(float f)
        {
            m_DarknessMin = f;
        }
        void SetDarknessMax(float f)
        {
            m_DarknessMax = f;
        }
        void SetPulseSpeed(float f)
        {
            m_PulseSpeed = f;
        }

    protected:
        D3DXVECTOR2 m_TextureSize;
        std::vector<D3DXVECTOR2> m_Points;
        float m_Radius;
        float m_DarknessMin;
        float m_DarknessMax;
        float m_PulseSpeed;
};

class CUIBlurShader : public IShader
{
    public:
        CUIBlurShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::UI_BLUR;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::UI;
        }

        void SetBlurStrength(float f)
        {
            m_BlurStrength = f;
        }

    protected:
        float m_BlurStrength;
};

class CWaterShader : public IShader
{
    public:
        CWaterShader();

        void ApplySettings(LPDIRECT3DBASETEXTURE9 inputTexture) const override;
        EType GetType() const override
        {
            return EType::WATER;
        }
        ERenderType GetRenderType() const override
        {
            return ERenderType::OTHER;
        }

        void SetSpeed(float f)
        {
            m_Speed = f;
        }

    protected:
        float m_Speed;
};

class CShaderManager : public CSingleton<CShaderManager>
{
    public:
        CShaderManager();
        ~CShaderManager();

        bool Initialize();
        void Destroy();

        void LostDevice();
        void RestoreDevice();

        void Begin();
        void End(IShader::ERenderType renderType);

        bool AddFX(IShader::EType type, const char* path);
        IShader* GetShader(IShader::EType type) const;

    private:
        bool __CreateResources();
        void __ReleaseResources();
        bool __LoadShaders();

    private:
        struct SQuadVertex
        {
            float x, y, z, rhw;
            float u, v;
        };

        LPDIRECT3DVERTEXBUFFER9 m_ScreenQuad;

        LPDIRECT3DTEXTURE9 m_RenderTextureA;
        LPDIRECT3DTEXTURE9 m_RenderTextureB;
        LPDIRECT3DSURFACE9 m_RenderSurfaceA;
        LPDIRECT3DSURFACE9 m_RenderSurfaceB;

        LPDIRECT3DSURFACE9 m_OriginalRenderTexture;

        std::unordered_map<IShader::EType, IShader*> m_ShaderMap;
};
