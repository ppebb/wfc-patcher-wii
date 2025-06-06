#pragma once

#include <wwfcUtil.h>

namespace mkw::System
{

#if RMC

class RaceConfig
{
public:
    enum GameMode {
        PrivateVersusRace = 7,
        PublicVersusRace = 8,
        PublicBattle = 9,
        PrivateBattle = 10,
    };

    enum BattleType {
        BalloonBattle = 0,
        CoinRunners = 1,
    };

    class RaceConfigPlayer
    {
    public:
        u8 _000[0xD8 - 0x00];
        u16 m_previousScore; // 0xD8
        u16 m_gpScore; // 0xDA
        u16 _0DC;
        short m_gpStarRankScore; // 0xDE
        u8 m_gpRank; // 0xE0
        u8 m_playerOrder; // 0xE1
        u8 m_finishPos; // 0xE2
        u8 _0E3[0xF0 - 0xE3];
    };

    static_assert(sizeof(RaceConfigPlayer) == 0xF0);

    class Scenario
    {
    public:
        bool isOnlineVersusRace() const
        {
            return m_gameMode == GameMode::PrivateVersusRace ||
                   m_gameMode == GameMode::PublicVersusRace;
        }

        bool isOnlineBattle() const
        {
            return m_gameMode == GameMode::PublicBattle ||
                   m_gameMode == GameMode::PrivateBattle;
        }

        bool isBalloonBattle() const
        {
            return m_battleType == BattleType::BalloonBattle;
        }

        bool isCoinRunners() const
        {
            return m_battleType == BattleType::CoinRunners;
        }

        u8 playerCount()
        {
            return m_playerCount;
        }

        u8 localPlayerCount()
        {
            return m_localPlayerCount;
        }

        RaceConfigPlayer* players()
        {
            return m_players;
        }

    private:
        /* 0x000 */ u8 _000[0x004 - 0x000];
        u8 m_playerCount; // 0x004
        u8 m_screenCount; // 0x005
        u8 m_localPlayerCount; // 0x006
        u8 m_hudCount2; // 0x007
        RaceConfigPlayer m_players[12]; // 0x008-0xB48
        /* 0xB48 */ u8 _B48[0xB50 - 0xB48];
        /* 0xB50 */ GameMode m_gameMode;
        /* 0xB54 */ u8 _B54[0xB58 - 0xB54];
        /* 0xB58 */ BattleType m_battleType;
        /* 0xB5C */ u8 _B5C[0xBF0 - 0xB5C];
    };

    static_assert(sizeof(Scenario) == 0xBF0);

    Scenario& raceScenario()
    {
        return m_raceScenario;
    }

    Scenario& menuScenario()
    {
        return m_menuScenario;
    }

    static RaceConfig* Instance()
    {
        return s_instance;
    }

private:
    /* 0x0000 */ u8 _0000[0x0020 - 0x0000];
    /* 0x0020 */ Scenario m_raceScenario;
    /* 0x0C10 */ Scenario m_menuScenario;
    /* 0x1800 */ u8 _1800[0x73F0 - 0x1800];

    static RaceConfig* s_instance
        AT(RMCXD_PORT(0x809BD728, 0x809B8F68, 0x809BC788, 0x809ABD68));
};

static_assert(sizeof(RaceConfig) == 0x73F0);

#endif

} // namespace mkw::System
