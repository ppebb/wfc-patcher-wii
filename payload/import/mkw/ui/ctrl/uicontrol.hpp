#pragma once

namespace mkw::UI
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

} // namespace mkw::UI
