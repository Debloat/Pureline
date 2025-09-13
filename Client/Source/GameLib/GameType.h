#pragma once

#include <string>

#include "../EterLib/TextFileLoader.h"
#include "../EterLib/CollisionData.h"

extern float g_fGameFPS;

extern std::string g_strResourcePath;
extern std::string g_strImagePath;

// Motion Key
#define MOTION_KEY                                  DWORD
#define MAKE_MOTION_KEY(mode, index)                (((DWORD)(((BYTE)(mode)) << 24) | ((DWORD)((WORD)(index))) << 8) | ((DWORD)((BYTE)(0))))
#define MAKE_RANDOM_MOTION_KEY(mode, index, type)   (((DWORD)(((BYTE)(mode)) << 24) | ((DWORD)((WORD)(index))) << 8) | ((DWORD)((BYTE)(type))))
#define GET_MOTION_MODE(key)                        ((BYTE)(((DWORD)(key) >> 24) & 0xFF))
#define GET_MOTION_INDEX(key)                       ((WORD)(((DWORD)(key) >> 8) & 0xFFFF))
#define GET_MOTION_SUB_INDEX(key)                   ((BYTE)(((DWORD)(key)) & 0xFF))
/*
#define MAKE_MOTION_KEY(mode, index)        MAKELONG(index, mode)
#define GET_MOTION_MODE(key)                HIWORD(key)
#define GET_MOTION_INDEX(key)               LOWORD(key)
*/

// Race Data
namespace NRaceData
{
    enum EJobs
    {
        JOB_WARRIOR,
        JOB_ASSASSIN,
        JOB_SURA,
        JOB_SHAMAN,
        JOB_MAX_NUM
    };

    // Character Attacking Data
    enum EAttackType
    {
        ATTACK_TYPE_SPLASH,
        ATTACK_TYPE_SNIPE,
    };
    enum EHitType
    {
        HIT_TYPE_NONE,
        HIT_TYPE_GREAT,
        HIT_TYPE_GOOD,
    };
    enum EMotionType
    {
        MOTION_TYPE_NONE,
        MOTION_TYPE_NORMAL,
        MOTION_TYPE_COMBO,
        MOTION_TYPE_SKILL,
    };

    using THitTimePosition = CDynamicSphereInstance;
    using THitTimePositionMap = std::map<float, THitTimePosition>;

    using TAttackData = struct SAttackData
    {
        int iAttackType;
        int iHittingType;
        float fInvisibleTime;
        float fExternalForce;
        float fStiffenTime;
        int iHitLimitCount;
    };

    using THitData = struct SHitData
    {
        float fAttackStartTime;
        float fAttackEndTime;

        float fWeaponLength;
        std::string strBoneName;

        THitTimePositionMap mapHitPosition;

        bool Load(CTextFileLoader & rTextFileLoader);
    };

    using THitDataContainer = std::vector<THitData>;

    using TMotionAttackData = struct SMotionAttackData : public SAttackData
    {
        int iMotionType;

        THitDataContainer HitDataContainer;
    };

    /////////////////////////////////////////////////////////////////////////////////
    // Character Attaching Collision Data
    enum ECollisionType
    {
        COLLISION_TYPE_NONE,

        COLLISION_TYPE_BODY,
        COLLISION_TYPE_ATTACKING,
        COLLISION_TYPE_DEFENDING,
        COLLISION_TYPE_SPLASH,
    };
    enum ECollisionShape
    {
        COLLISION_SHAPE_SPHERE,
        COLLISION_SHAPE_CYLINDER,
    };

    using TCollisionData = struct SCollisionData
    {
        int                 iCollisionType;
        CSphereCollisionInstanceVector  SphereDataVector;

        SCollisionData() {}
        virtual ~SCollisionData() {}
    };

    using TAttachingEffectData = struct SAttachingEffectData
    {
        std::string         strFileName;
        D3DXVECTOR3         v3Position;
        D3DXVECTOR3         v3Rotation;

        SAttachingEffectData() {}
        virtual ~SAttachingEffectData() {}
    };

    using TAttachingObjectData = struct SAttachingObjectData
    {
        std::string         strFileName;

        SAttachingObjectData() {}
        virtual ~SAttachingObjectData() {}
    };

    using TCollisionDataVector = std::vector<TCollisionData>;

    void DestroySystem();

    void SaveAttackData(FILE * File, int iTabCount, const TAttackData & c_rData);
    void SaveMotionAttackData(FILE * File, int iTabCount, const TMotionAttackData & c_rData);
    void SaveCollisionData(FILE * File, int iTabCount, const TCollisionData & c_rCollisionData);
    void SaveEffectData(FILE * File, int iTabCount, const TAttachingEffectData & c_rEffectData);
    void SaveObjectData(FILE * File, int iTabCount, const TAttachingObjectData & c_rObjectData);

    BOOL LoadAttackData(CTextFileLoader & rTextFileLoader, TAttackData * pData);
    BOOL LoadMotionAttackData(CTextFileLoader & rTextFileLoader, TMotionAttackData * pData);
    BOOL LoadCollisionData(CTextFileLoader & rTextFileLoader, TCollisionData * pCollisionData);
    BOOL LoadEffectData(CTextFileLoader & rTextFileLoader, TAttachingEffectData * pEffectData);
    BOOL LoadObjectData(CTextFileLoader & rTextFileLoader, TAttachingObjectData * pObjectData);

    /////////////////////////////////////////////////////////////////////////////////
    // Attaching Data
    enum EAttachingDataType
    {
        ATTACHING_DATA_TYPE_NONE,

        ATTACHING_DATA_TYPE_COLLISION_DATA,
        ATTACHING_DATA_TYPE_EFFECT,
        ATTACHING_DATA_TYPE_OBJECT,

        ATTACHING_DATA_TYPE_MAX_NUM,
    };

    using TAttachingData = struct SAttachingData
    {
        SAttachingData()
            : dwType(0)
            , isAttaching(false)
            , dwAttachingModelIndex(0)
            , pCollisionData(nullptr)
            , pEffectData(nullptr)
            , pObjectData(nullptr)
        {}
        DWORD dwType;

        BOOL isAttaching;
        DWORD dwAttachingModelIndex;
        std::string strAttachingBoneName;

        TCollisionData* pCollisionData;
        TAttachingEffectData* pEffectData;
        TAttachingObjectData* pObjectData;
    };

    using TAttachingDataVector = std::vector<TAttachingData>;

    void SaveAttachingData(FILE * File, int iTabCount, const TAttachingDataVector & c_rAttachingDataVector);
    BOOL LoadAttachingData(CTextFileLoader & rTextFileLoader, TAttachingDataVector * pAttachingDataVector);

    extern CDynamicPool<TCollisionData>         g_CollisionDataPool;
    extern CDynamicPool<TAttachingEffectData>   g_EffectDataPool;
    extern CDynamicPool<TAttachingObjectData>   g_ObjectDataPool;
};
