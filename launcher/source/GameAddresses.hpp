#pragma once

#include <gctypes.h>

#define GAME_ASM(_INST01, _INST02)                                             \
    (u32*) +[]() {                                                             \
        __asm__ volatile(_INST01 "; " _INST02 "; .long 0");                    \
        __builtin_unreachable();                                               \
    }

struct GameAddresses {
    const char* gameId;
    u32 addrAuthSendRequest;
    u32 addrNHTTPCreateRequest;
    u32 addrNHTTPSendRequest;
    u32 addrNHTTPDestroyResponse;
    u32 addrNASError;
    u32* loadAuthRequestAsm;
};

extern const GameAddresses GameAddressesList[];
extern const int GameAddressesListSize;