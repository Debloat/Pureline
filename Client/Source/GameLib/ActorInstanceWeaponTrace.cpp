#include "StdAfx.h"
#include "ActorInstance.h"
#include "WeaponTrace.h"

void CActorInstance::TraceProcess()
{
    if (!m_WeaponTraceVector.empty())
    {
        for (auto it = m_WeaponTraceVector.begin(); it != m_WeaponTraceVector.end(); ++it)
        {
            CWeaponTrace * pWeaponTrace = (*it);
            pWeaponTrace->SetPosition (m_x, m_y, m_z);
            pWeaponTrace->SetRotation (m_fcurRotation);
            pWeaponTrace->Update (__GetReachScale());
        }
    }
}

void CActorInstance::RenderTrace()
{
    std::ranges::for_each (m_WeaponTraceVector, std::mem_fn (&CWeaponTrace::Render));
}

void CActorInstance::__DestroyWeaponTrace()
{
    std::ranges::for_each (m_WeaponTraceVector, CWeaponTrace::Delete);
    m_WeaponTraceVector.clear();
}

void CActorInstance::__ShowWeaponTrace()
{
    std::ranges::for_each (m_WeaponTraceVector, std::mem_fn (&CWeaponTrace::TurnOn));
}

void CActorInstance::__HideWeaponTrace()
{
    std::ranges::for_each (m_WeaponTraceVector, std::mem_fn (&CWeaponTrace::TurnOff));
}

