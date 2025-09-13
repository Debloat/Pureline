#include "StdAfx.h"
#include "Base.h"

CBase::CBase()
{
    id = 0;
}

CBase::~CBase() = default;

bool CBase::isNumber() const
{
    return (id & MID_NUMBER) != 0 ? true : false;
}

bool CBase::isVar() const
{
    return (id & MID_VARIABLE) != 0 ? true : false;
}

bool CBase::isSymbol() const
{
    return (id & MID_SYMBOL) != 0 ? true : false;
}

