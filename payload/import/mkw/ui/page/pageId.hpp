#pragma once

#if RMC

namespace wwfc::mkw::UI
{

// https://github.com/mkw-sp/mkw-sp/blob/main/payload/game/ui/PageId.hh
enum class PageId {
    WiFiVSResults = 0x44,
    MessagePopup = 0x4D,
    YesNoPopup = 0x4E,
};

} // namespace wwfc::mkw::UI

#endif // RMC