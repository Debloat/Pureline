#pragma once

#include "AbstractSingleton.h"

class IAbstractChat : public TAbstractSingleton<IAbstractChat>
{
    public:
        IAbstractChat() {}
        virtual ~IAbstractChat() {}

        /* - CLIENT_LOCALE_STRING ------------------------------ */
        enum ESpecialColorType
        {
            CHAT_SPECIAL_COLOR_NORMAL,
            CHAT_SPECIAL_COLOR_DICE_0,
            CHAT_SPECIAL_COLOR_DICE_1,
        };
        /* ----------------------------------------------------- */

        /* - CLIENT_LOCALE_STRING ------------------------------
        bSpecialColorType
        */
        virtual void AppendChat (int iType, const char* c_szChat, BYTE bSpecialColorType = ESpecialColorType::CHAT_SPECIAL_COLOR_NORMAL) = 0;
        /* ----------------------------------------------------- */
};
