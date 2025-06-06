#pragma once

#include "wwfcCommon.h"

namespace wwfc::mkw::UI
{

#if RMC

class UIControl
{
private:
    u8 _098[0x98];
};

static_assert(sizeof(UIControl) == 0x98);

class LayoutUIControl : public UIControl
{
private:
    u8 _0174[0xDC];
};

static_assert(sizeof(LayoutUIControl) == 0x174);

#endif

} // namespace wwfc::mkw::UI
