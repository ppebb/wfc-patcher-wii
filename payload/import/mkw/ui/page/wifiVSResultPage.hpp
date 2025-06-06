#pragma once

#include "import/mkw/ui/ctrl/uicontrol.hpp"
#include "import/mkw/ui/section/sectionManager.hpp"
#include "page.hpp"
#include "pageId.hpp"

namespace mkw::UI
{
#if RMC

// class WiFiAwardResultItem : public LayoutUIControl
// {
// private:
//     u8 _0174[0x174];
// };

// static_assert(sizeof(WiFiAwardResultItem) == 0x174);

class WiFiVSResultPage : public Page
{
public:
    static const PageId id = PageId::WiFiVSResults;
    WiFiVSResultPage();
    ~WiFiVSResultPage() override;
    /* 0x044 */ u8 _0B[0x19C - 0x044];
    LayoutUIControl modeName;
    LayoutUIControl congratulations;
    LayoutUIControl results[12];
    bool isTeamVS;
    u8 localPlayerCount;
    u8 playerCount;
    u8 undefined[0x15fb - 0x15f6];
};

static_assert(sizeof(WiFiVSResultPage) == 0x15fc);

#endif

} // namespace mkw::UI
